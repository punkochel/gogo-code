#include <iostream>
#include <mutex>
#include <thread>

int totalServerScore = 0;
std::mutex scoreMutex;

void addScores(int amount, int iterations)
{
	for (; iterations > 0; iterations--)
	{
		std::lock_guard<std::mutex> lock(scoreMutex);
		totalServerScore += amount;
	}
}

int main()
{
	std::thread t1(addScores, 5, 100000);
	std::thread t2(addScores, 2, 100000);
	t1.join();
	t2.join();

	std::cout << "Result: " << totalServerScore << std::endl;
	return 0;
}