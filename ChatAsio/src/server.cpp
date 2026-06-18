#include <iostream>
#include <thread>
#include <set>
#include <memory>
#include <mutex>
#include <asio.hpp>

#include "shared.hpp"

std::set<std::shared_ptr<asio::ip::tcp::socket>> clients;
std::mutex clients_mutex;

void session(std::shared_ptr<asio::ip::tcp::socket> sock)
{
    try
    {
        char data[max_buffer_size];
        while (true)
        {
            asio::error_code error;
            size_t length = sock->read_some(asio::buffer(data), error);
            
            if (error == asio::error::eof)
            {
            	std::lock_guard<std::mutex> lock(clients_mutex);
            	clients.erase(sock);
                std::cout << "Client disconnected\n";
                break;
            }
            else if (error)
            {
                throw asio::system_error(error);
            }

            std::vector<std::shared_ptr<asio::ip::tcp::socket>> clients_copy;
            {
            	std::lock_guard<std::mutex> lock(clients_mutex);
            	clients_copy.assign(clients.cbegin(), clients.cend());
            }

            for (const auto& client : clients_copy)
            {
            	try
            	{
            		asio::write(*client, asio::buffer(data, length));
            	}
            	catch(...)
            	{
            	}
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Session error: " << e.what() << "\n";
    }
}

int main()
{
	asio::io_context io_context;
	asio::ip::tcp::acceptor acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
	std::cout << "Server started. Port: " << port << std::endl;

	while (true)
	{
		asio::ip::tcp::socket socket(io_context);
		acceptor.accept(socket);
		std::cout << "Client connected\n";
		auto sock_ptr = std::make_shared<asio::ip::tcp::socket>(std::move(socket));
		std::lock_guard<std::mutex> lock(clients_mutex);
		clients.insert(sock_ptr);
		std::thread(session, sock_ptr).detach();
	}
	return 0;
}
