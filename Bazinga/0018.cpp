#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;

void f1()
{
	for (int i = 0; i < 100; i++)
	{
		std::lock_guard<std::mutex> lock(mtx);
		counter++;
		std::cout << "[F1]: " << counter << std::endl;
	}
}

void f2()
{
	for (int i = 0; i < 100; i++)
	{
		std::lock_guard<std::mutex> lock(mtx);
		counter++;
		std::cout << "[F2]: " << counter << std::endl;
	}
}

int main()
{
	std::thread t1(f1);
	std::thread t2(f2);
	t1.join();
	t2.join();
	return 0;
}