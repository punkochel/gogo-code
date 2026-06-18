#include <iostream>

using namespace std::string_literals;

template <typename T>
void logInfo(T value)
{
	std::cout << "Value: "<< value << ", Size: " << sizeof(T) << " bytes\n";
}

template <>
void logInfo<std::string>(std::string value)
{
	std::cout << "Value: "<< value << ", Size: " << value.size() << " bytes\n";
}

int main()
{
	logInfo(42);
	logInfo(3.14);
	logInfo("The Walking Dead"s);
	return 0;
}
