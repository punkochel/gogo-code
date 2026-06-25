#include <iostream>
#include <string>
#include <memory>

class Magazine
{
	const unsigned capacity_; // magazine size for bullets
	unsigned bullets_; // bullets inside magazine

public:
	Magazine(unsigned capacity, unsigned bullets)
		: capacity_(capacity)
		, bullets_(bullets)
	{
	}

	unsigned takeBullets(unsigned amount = 1) noexcept
	{
		const unsigned bulletsToTake = std::min(amount, bullets_);
		bullets_ -= bulletsToTake;

		return bulletsToTake;
	}
};

class Weapon
{
	std::string name_;

public:
	Weapon(const std::string& name)
	 	: name_(std::move(name))
	{
	}
};

class Firearm : public Weapon
{
	unsigned barrels_;
	unsigned bullets_;
	std::unique_ptr<Magazine> magazine_;

	void loadBulletsInBarrels() noexcept
	{
		bullets_ += magazine_->takeBullets();
	}

public:
	Firearm(const std::string& name, unsigned barrels)
		: Weapon(name)
		, barrels_(barrels)
		, bullets_(0)
		, magazine_(std::make_unique<Magazine>(30, 5))
	{
	}

	bool shot() noexcept
	{
		if (bullets_)
		{
			std::cout << "Firearm: Shot\n";
			--bullets_;
			this->loadBulletsInBarrels();
			return true;
		}

		std::cout << "Firearm: No bullets\n";
		this->loadBulletsInBarrels();

		return false;
	}
};


int main()
{
	Firearm ak47(std::string("AK-47"), 1);
	for (int i = 0; i < 20; i++)
	{
		std::cout << i << "-> ";
		ak47.shot();
	}
	return 0;
}