#include <iostream>

template <typename T, int Capacity>
class StaticBuffer
{
	T data[Capacity];
	int currentSize = 0;

public:
	bool add(const T& item)
	{
		if (currentSize < Capacity)
		{
			data[currentSize] = item;
			currentSize++;
			return true;
		}

		return false;
	}

	int size() const
	{
		return currentSize;
	}

	int capacity() const
	{
		return Capacity;
	}

	void print() const
	{
		for (int i = 0; i < currentSize; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	StaticBuffer<int, 3> buff;
	buff.add(10);
	buff.add(20);
	buff.add(30);
	if (!buff.add(40))
	{
		std::cout << "Buffer is full\n";
	}

	buff.print();
	return 0;
}