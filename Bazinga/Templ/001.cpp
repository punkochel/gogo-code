#include <iostream>
#include <memory>
#include <map>

enum Keys
{
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D
};

bool isPressed(Keys key)
{
	return true;
}

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class CommandForward : public Command
{
public:
	void execute() override
	{
		std::cout << "Forward\n";
	}
};

class CommandBack : public Command
{
public:
	void execute() override
	{
		std::cout << "Back\n";
	}
};

class CommandLeft : public Command
{
public:
	void execute() override
	{
		std::cout << "Left\n";
	}
};

class CommandRight : public Command
{
public:
	void execute() override
	{
		std::cout << "Right\n";
	}
};

class InputHandler
{
	std::map<Keys, std::unique_ptr<Command>> keys_;

public:
	InputHandler()
	{
		keys_.emplace(KEY_W, std::make_unique<CommandForward>());
		keys_.emplace(KEY_A, std::make_unique<CommandLeft>());
		keys_.emplace(KEY_S, std::make_unique<CommandBack>());
		keys_.emplace(KEY_D, std::make_unique<CommandRight>());
	}

	void bindKey(Keys key, std::unique_ptr<Command> cmd)
	{
		if (cmd)
		{
			keys_[key] = std::move(cmd);
		}
	}

	void handleInput()
	{
		for (const auto& [k, v] : keys_)
		{
			if (isPressed(k) && v)
			{
				v->execute();
			}
		}
	}
};

int main()
{
	InputHandler iHandler;
	for (int i = 0; i < 5; i++)
	{
		iHandler.handleInput();
	}

	iHandler.bindKey(KEY_W, std::make_unique<CommandBack>());
	for (int i = 0; i < 5; i++)
	{
		iHandler.handleInput();
	}
	return 0;
}