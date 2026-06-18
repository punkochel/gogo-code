#include <iostream>

void smartSwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int a = 5;
	int b = 10;
	smartSwap(a, b);
	std::cout << a << " " << b << std::endl;
	return 0;
}