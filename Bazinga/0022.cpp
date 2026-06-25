#include <iostream>

class Copy
{
	int* p;

public:
	Copy()
		: p(new int[20])
	{
	}

	Copy(const Copy& x)
		: p(new int[20])
	{
		for (int i = 0; i < 20; i++)
		{
			p[i] = x.p[i];
		}
	}

	~Copy()
	{
		delete [] p;
	}
};

class Int
{
	int value;

public:
	Int(int value)
		: value(value)
	{
		// std::cout << "Created\n";
	}

	~Int()
	{
		// std::cout << "~Deleted\n";
	}

	int get() const
	{
		return value;
	}

	Int operator+(const Int& rhs)
	{
		return Int(value + rhs.value);
	}

	Int operator-(const Int& rhs)
	{
		return Int(value - rhs.value);
	}

	Int operator*(const Int& rhs)
	{
		return Int(value * rhs.value);
	}

	Int operator/(const Int& rhs)
	{
		if (rhs.value == 0)
		{
			return *this;
		}
		return Int(value / rhs.value);
	}
};

int main()
{
	Int v1(4);
	Int v2(6);
	Int v3 = 2;
	Int v = v1 + v2 * v2 / v3;
	std::cout << v.get() << std::endl;
	return 0;
}