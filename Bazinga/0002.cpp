#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void print_container(const T& cnt)
{
	if (cnt.size())
	{
		std::string s = "START: ";
		auto mul_2 = [](int x) { return x * 2; };
		for (const auto& i : cnt)
		{
			s += std::to_string(mul_2(i));
			s += " ";
		}
		std::cout << s << std::endl;
	}
}

int main()
{
	std::vector<int> v;
	v.reserve(10);
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });

	print_container(v);
	return 0;
}