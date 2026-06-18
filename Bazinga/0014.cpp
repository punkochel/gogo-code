#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> numbers = {1, 2, 3, 4};
	std::vector<int> squares(numbers.size());

	std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int x) { return x * x; });
	for (const auto& el : squares)
	{
		std::cout << el << std::endl;
	}

	numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 != 0; }), numbers.end());
	for (const auto& el : numbers)
	{
		std::cout << el << std::endl;
	}
	return 0;
}
