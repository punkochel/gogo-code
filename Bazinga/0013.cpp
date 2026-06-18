#include <iostream>
#include <algorithm>
#include <vector>
#include <format>

struct Player
{
    std::string nickname;
    int score;
    int ping;
};


int main()
{
	/*std::vector<int> arr = {3, 1, 2, 41, 12, 6, 7, 4, 9};
	bool has5 = std::any_of(arr.begin(), arr.end(), [](int a) { return a == 1; });
	std::cout << has5 << std::endl;
	int result = std::count_if(arr.begin(), arr.end(), [](int a) { return a < 10; });
	std::cout << result << std::endl;
	std::sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
	for (const auto& el : arr)
	{
		std::cout << el << std::endl;
	}*/

	int minScoreRequired = 100;
	int maxPingAllowed = 100;
	std::vector<Player> matchLobby;
	std::vector<Player> players = {
		{"Cheater_X", 99999, 40},
		{"Good_Player", 450, 50},
		{"Lagging_Guy", 120, 350},
		{"Newbie", 10, 90}
	};

	// std::transform(players.begin(), players.end(), players.begin(), [](Player& x) { x.ping -= 20; return x;});
	std::for_each(players.begin(), players.end(), [](Player& x) { x.ping -= 30; });
	players.erase(std::remove_if(players.begin(), players.end(), [](const Player& x) { return x.score > 9000; }), players.end());

	std::cout << "Players that have critical ping great 100: "
		<< std::count_if(players.begin(), players.end(), [](const Player& x) { return x.ping > 100; })
		<< std::endl;

	if (std::any_of(players.begin(), players.end(), [](const Player& x) { return x.score > 9000; }))
	{
		std::cout << "Cheater detected!\n";
	}

	std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) { return a.score > b.score; });

	std::copy_if(players.begin(), players.end(), std::back_inserter(matchLobby), [minScoreRequired, maxPingAllowed](const Player& x) {
		return x.score >= minScoreRequired && x.ping <= maxPingAllowed;
	});
	
	for (const auto& el : matchLobby)
	{
		std::cout << std::format("{} / {} / {}", el.nickname, el.score, el.ping) << std::endl;
	}
	return 0;
}