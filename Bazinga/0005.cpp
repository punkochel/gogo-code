#include <iostream>
#include <map>
#include <vector>

void printElementFrequencies(const std::vector<int>& v)
{
	std::map<int, int> m;
	for (auto& n : v)
	{
		m[n]++;
	}

	for (const auto& [k, v] : m)
	{
		std::cout << k << " occurs " << v << " times\n";
	}
}

int main()
{
	std::vector<int> v = {4, 1, 4, 2, 1, 4, 3};
	printElementFrequencies(v);
	return 0;
}
