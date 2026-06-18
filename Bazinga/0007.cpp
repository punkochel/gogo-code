#include <iostream>
#include <vector>
#include <memory>

class Employee
{
protected:
	std::string name;

public:
	Employee(const std::string& name)
		: name(name)
	{
	}

	virtual ~Employee() = default;
	virtual double calculateSalary() const = 0;

	const std::string& getName() const
	{
		return name;
	}
};

class FullTimeEmployee : public Employee
{
	double monthlySalary;

public:
	FullTimeEmployee(const std::string& name, double monthlySalary)
		: Employee(name)
		, monthlySalary(monthlySalary)
	{
	}

	double calculateSalary() const override
	{
		return monthlySalary;
	}
};

class ContractEmployee : public Employee
{
	double hourlyRate;
	int hoursWorked;

public:
	ContractEmployee(const std::string& name, double hourlyRate, int hoursWorked)
		: Employee(name)
		, hourlyRate(hourlyRate)
		, hoursWorked(hoursWorked)
	{
	}

	double calculateSalary() const override
	{
		return hourlyRate * hoursWorked;
	}
};

int main()
{
	std::vector<std::unique_ptr<Employee>> staff;
	staff.push_back(std::make_unique<FullTimeEmployee>("Donald", 5000));
	staff.push_back(std::make_unique<FullTimeEmployee>("Robert", 4350));
	staff.push_back(std::make_unique<ContractEmployee>("Jessica", 25, 160));
	staff.push_back(std::make_unique<ContractEmployee>("Diana", 22.5, 180));

	for (const auto& em : staff)
	{
		std::cout << em->getName() << " - $" << em->calculateSalary() << std::endl;
	}
	return 0;
}
