#include <iostream>
#include <vector>

int getSecondValue(const std::vector<int> vec)
{
	int value = vec.at(0);
	bool flag = false;
	for (auto i : vec)
	{
		if (i > value && !flag)
		{
			value = i;
			flag = true;
		}
	}
	return value;
}

int main()
{
	std::vector<int> v = {10, 5, 20, 20, 8};
	std::cout << getSecondValue(v) << std::endl;
	return 0;
}
