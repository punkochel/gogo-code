#include <iostream>
#include <fstream>
#include <filesystem>
#include <format>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void writeToFile(const std::string& filename)
{
	if (std::filesystem::exists(filename))
	{
		return;
	}

	json data;
	data["user"] = "Troy_McClure";
	data["password"] = "sezamopen";

	std::ofstream file(filename);
	if (file.is_open())
	{
		file << data.dump(4);
		file.close();
		std::cout << "The data was written to a file\n";
	}
	else
	{
		std::cout << "[O] Error opening file\n";
	}
}

void readFromFile(const std::string& filename)
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		json data;
		file >> data;
		file.close();

		std::string username = data["user"];
		std::string password = data["password"];

		std::cout << std::format("User: {}\nPassword: {}\n", username, password);
	}
	else
	{
		std::cout << "[R] Error opening file\n";
	}
}

int main()
{
	const std::string filename = "config.json";
	writeToFile(filename);
	readFromFile(filename);
	return 0;
}
