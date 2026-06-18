#include <iostream>

class BanException : public std::runtime_error
{
public:
	BanException(const std::string& msg)
		: std::runtime_error(msg) {}
};

class InvalidCommandException : public std::runtime_error
{
public:
	InvalidCommandException(const std::string& msg)
		: std::runtime_error(msg) {}
};

class CommandProcessor
{
public:
	void executeCommand(const std::string& cmd, bool isPlayerBanned)
	{
		if (isPlayerBanned)
		{
			throw BanException("Player is banned and cannot use commands!");
		}

		if (cmd[0] != '/')
		{
			throw InvalidCommandException("Commands must start with '/'!");
		}

		std::cout << "Executing command: " << cmd << std::endl;
	}
};

int main()
{
	CommandProcessor cmd;

	try
	{
		cmd.executeCommand("/help", true);
		cmd.executeCommand("/help", false);
		cmd.executeCommand("carpass", true);
		cmd.executeCommand("carpass", false);
	}
	catch (const BanException& e)
	{
		std::cout << "[SCURITY ERROR]: " << e.what() << std::endl;
	}
	catch (const InvalidCommandException& e)
	{
		std::cout << "[SYNTAX ERROR]: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}