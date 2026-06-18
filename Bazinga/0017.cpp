#include <iostream>
#include <algorithm>
#include <vector>
#include <optional>

struct Player
{
    std::string nickname;
    int score;
    int ping;
};

std::optional<Player> findPlayerByName(const std::vector<Player>& p, const std::string& n)
{
	auto it = std::find_if(p.begin(), p.end(), [n](const Player& x) { return x.nickname == n; });
	if (it != p.end())
	{
		return *it;
	}
	return std::nullopt;
}

int main()
{
	std::vector<Player> players = {
		{"Cheater_X", 99999, 40},
		{"Good_Player", 450, 50},
		{"Lagging_Guy", 120, 350},
		{"Newbie", 10, 90}
	};

	auto res = findPlayerByName(players, "Newbie");
	if (res.has_value())
	{
		std::cout << res.value().nickname << " — " << res.value().score << std::endl;
	}

	res = findPlayerByName(players, "Ghost");
	if (!res.has_value())
	{
		std::cout << "Player not found!\n";
	}
}