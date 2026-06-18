#include <iostream>
#include <initializer_list>
#include <vector>
#include <algorithm>

template <typename T>
class ModernArray
{
	std::vector<T> data_;

public:
	ModernArray(std::initializer_list<T> list)
		: data_(list)
	{
	}

	ModernArray& operator+=(const ModernArray& rhs)
	{
		data_.insert(data_.end(), rhs.data_.cbegin(), rhs.data_.cend());
		return *this;
	}

	ModernArray& operator+=(const T& rhs)
	{
		data_.push_back(rhs);
		return *this;
	}

	ModernArray& operator-=(const T& rhs)
	{
		if (std::count(data_.cbegin(), data_.cend(), rhs))
		{
			std::erase(data_, rhs);
		}
		return *this;
	}

	T& operator[](int index)
	{
		return data_[index];
	}

	const T& operator[](int index) const
	{
		return data_[index];
	}

	auto size() const -> decltype(data_.size())
	{
		return data_.size();
	}

	friend std::ostream& operator<<(std::ostream& os, const ModernArray<T> array)
	{
		for (const auto& el : array.data_)
		{
			os << el << " ";
		}
		os << "\n - Total: " << array.data_.size();

		return os;
	}
};

template <typename T>
inline ModernArray<T> operator+(ModernArray<T> lhs, const ModernArray<T>& rhs)
{
	lhs += rhs;
	return lhs;
}

int main()
{
	ModernArray arr1 = {83, 62, 10, 75};
	ModernArray arr2 = {1, 3, 5};
	arr1 += arr2;
	std::cout << arr1 << std::endl;
	arr1 -= 3;
	arr1 -= 10;
	std::cout << arr1 << std::endl;
	arr1[1]++;
	std::cout << arr1[1] << std::endl;

	return 0;
}