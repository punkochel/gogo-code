#include <iostream>
#include <memory>

class ConfigLoader
{
public:
	void loadConfig(const std::string& filename)
	{
		if (filename != "server.cfg")
		{
			throw std::runtime_error("Configuration file not found!");
		}
		std::cout << "Config server.cfg loaded successfully\n";
	}
};

int main()
{
	// int* temporaryBuffer = new int[1000];
	std::unique_ptr<int[]> temporaryBuffer;

	try
	{
		ConfigLoader l;
		l.loadConfig("wrong.cfg");
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	// delete [] temporaryBuffer;
	return 0;
}