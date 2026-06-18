#include <iostream>

class BankAccount {
	std::string accountNumber;
	double balance;

public:
	BankAccount(const std::string& accountNumber, double balance)
		: accountNumber(accountNumber)
		, balance(balance)
	{
	}

	void deposit(double amount)
	{
		if (amount <= 0)
			return;

		balance += amount;
	}

	bool withdraw(double amount)
	{
		if (amount <= 0 || balance < amount)
			return false;

		balance -= amount;
		return true;
	}

	double getBalance() const
	{
		return balance;
	}
};

int main()
{
	BankAccount client("UA12345", 1000.0);
	if (!client.withdraw(1500))
	{
		std::cout << "No money\n";
	}
	client.deposit(600);
	client.withdraw(1200);
	std::cout << client.getBalance() << std::endl;
	return 0;
}
