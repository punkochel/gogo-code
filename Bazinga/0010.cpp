#include <iostream>

template <typename T>
class SafeValue
{
	T value;

public:
	SafeValue(const T& initValue)
		: value(initValue)
	{
	}

	const T& getValue() const
	{
		return value;
	}

	void setValue(const T& newValue)
	{
		value = newValue;
	}

	void print() const
	{
		std::cout << "[SafeValue]: " << value << std::endl;
	}
};

int main()
{
	SafeValue iv(100);
	SafeValue sv(std::string("SAMP"));
	sv.setValue("open.mp");

	iv.print();
	sv.print();
	return 0;
}
