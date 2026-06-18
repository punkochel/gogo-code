#include <iostream>
#include <vector>

template <typename T>
T calculateSum(const std::vector<T>& v)
{
	T sum = T();
	for (const auto& el : v)
	{
		sum += el;
	}

	return sum;
}

int main()
{
	std::vector<int> iv = {3, 1, 41, 11, 3, 15, 2};
	std::vector<double> dv = {3.14, 5.1, 22.53, 13.2};
	std::vector<std::string> sv = {"Donald", "Duck", "Chip", "Johny"};

	std::cout << calculateSum(iv) << std::endl;
	std::cout << calculateSum(dv) << std::endl;
	std::cout << calculateSum(sv) << std::endl;
	return 0;
}
