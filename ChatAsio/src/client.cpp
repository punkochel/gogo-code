#include <iostream>
#include <string>
#include <thread>
#include <asio.hpp>

#include "shared.hpp"

void readFromServer(asio::ip::tcp::socket& socket)
{
    try
    {
        char data[max_buffer_size];
        while (true)
        {
            asio::error_code error;
            size_t length = socket.read_some(asio::buffer(data), error);
            
            if (error == asio::error::eof)
            {
                std::cout << "\nConnection to the server was lost\n";
                break;
            }
            else if (error)
            {
                throw asio::system_error(error);
            }
            
            std::cout.write(data, length);
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Read error: " << e.what() << "\n";
    }
}

int main()
{
    try
    {
        asio::io_context io_context;
        asio::ip::tcp::socket socket(io_context);
        
        socket.connect(asio::ip::tcp::endpoint(asio::ip::make_address("127.0.0.1"), port));
        std::cout << "Chat connection successfuly! Write messages:\n";
        
        std::thread receiver(readFromServer, std::ref(socket));
        receiver.detach();
        
        std::string msg;
        while (std::getline(std::cin, msg))
        {
            msg += "\n";
            asio::write(socket, asio::buffer(msg));
        }
        
    } catch (const std::exception& e)
    {
        std::cerr << "Client error: " << e.what() << "\n";
    }
    return 0;
}
