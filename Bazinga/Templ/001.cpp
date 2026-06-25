#include <iostream>
#include <memory>

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
	std::unique_ptr<Command> keyW_;
	std::unique_ptr<Command> keyA_;
	std::unique_ptr<Command> keyS_;
	std::unique_ptr<Command> keyD_;

public:
	InputHandler()
		: keyW_(std::make_unique<CommandForward>())
		, keyA_(std::make_unique<CommandLeft>())
		, keyS_(std::make_unique<CommandBack>())
		, keyD_(std::make_unique<CommandRight>())
	{
	}

	void bindKey(Keys key, std::unique_ptr<Command> cmd)
	{
		switch (key)
		{
			case KEY_W:
				keyW_ = std::move(cmd);
				break;
			case KEY_A:
				keyA_ = std::move(cmd);
				break;
			case KEY_S:
				keyS_ = std::move(cmd);
				break;
			case KEY_D:
				keyD_ = std::move(cmd);
				break;
		}
	}

	void handleInput()
	{
		if (isPressed(KEY_W))
		{
			keyW_->execute();
		}
		else if (isPressed(KEY_A))
		{
			keyA_->execute();
		}
		else if (isPressed(KEY_S))
		{
			keyS_->execute();
		}
		else if (isPressed(KEY_D))
		{
			keyD_->execute();
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