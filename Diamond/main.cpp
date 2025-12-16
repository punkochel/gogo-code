#include <iostream>
#include <cmath>

class Diamond
{
	int height;
	char* matrix = nullptr;

	Diamond(const Diamond&) = delete;
	Diamond& operator=(const Diamond&) = delete;

	void setChar(int i, int j, char s)
	{
		matrix[i * height + j] = s;
	}

public:
	Diamond(int height)
		: height(height)
	{
		matrix = new char[height * height];

		int halfHeight = height / 2;
		for (int i = 0; i < height; ++i)
		{
		    for (int j = 0; j < height; ++j)
		    {
		        if (std::abs(i - halfHeight) + std::abs(j - halfHeight) == halfHeight)
		        {
		            setChar(i, j, '*');
		        }
		        else
		        {
		            setChar(i, j, ' ');
		        }
		    }
		}
	}

	~Diamond()
	{
		delete [] matrix;
	}

	void print() const
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				std::cout << matrix[i * height + j];
			}
			std::cout << "\n";
		}
	}
};

int main()
{
	int height = 0;
	std::cout << "Enter the odd height of the diamond: ";
	std::cin >> height;
	if (!height || height < 0)
	{
		std::cout << "The height of the diamond must be positive.\n";
		return 0;
	}
	if (!(height % 2))
	{
		std::cout << "The height of the diamond must be odd.\n";
		return 0;
	}

	Diamond diamond(height);
	diamond.print();
	return 0;
}
