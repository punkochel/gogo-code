#include <iostream>
#include <vector>

std::vector<int> filterEven(const std::vector<int>& arr)
{
	std::vector<int> v;
	for (auto n : arr)
	{
		if (!(n % 2))
		{
			bool f = false;
			for (auto res : v)
			{
				if (res == n)
				{
					f = true;
					break;
				}
			}

			if (!f)
			{
				v.push_back(n);
			}
		}
	}
	return v;
}

int main()
{
	std::vector<int> numbers = {1, 2, 2, 4, 4, 5, 6, 6};
	auto arr = filterEven(numbers);

	for (auto n : arr)
	{
		std::cout << n << "\n";
	}
	return 0;
}
