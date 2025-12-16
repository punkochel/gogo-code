#include <iostream>
#include <cmath>
#include <vector>

class Diamond
{
	int height;
	std::vector<char> matrix;

public:
	Diamond(int height)
		: height(height)
	{
		matrix.reserve(height * height);

		int halfHeight = height / 2;
		for (int i = 0; i < height; ++i)
		{
		    for (int j = 0; j < height; ++j)
		    {
		        if (std::abs(i - halfHeight) + std::abs(j - halfHeight) == halfHeight)
		        {
		            matrix.push_back('*');
		        }
		        else
		        {
		           	matrix.push_back(' ');
		        }
		    }
		}
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
	if (height <= 0)
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
