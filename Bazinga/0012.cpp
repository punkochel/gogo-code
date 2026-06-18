#include <iostream>
#include <format>

struct ConnectEvent
{
    std::string nickname;
    std::string ipAddress;
};

struct DeathEvent
{
    std::string killer;
    std::string victim;
    int weaponId;
};

class Logger
{
public:
    template <typename T>
    void log(const T& event) const
    {
        std::cout << "No object for logged\n";
    }

    template <>
    void log(const ConnectEvent& event) const
    {
        std::cout << std::format("[CONNECT]: Player {} connected with IP: {}", event.nickname, event.ipAddress);
    }

    template <>
    void log(const DeathEvent& event) const
    {
        std::cout << std::format("[DEATH]: {} killed {} with weaponID: {}", event.killer, event.victim, event.weaponId);
    }
};

int main()
{
    ConnectEvent ce = {"Donald_Duck", "127.0.0.1"};
    DeathEvent de = {"Walter_White", "Jesse_Pinkman", 31};
    Logger logger;
    logger.log(ce);
    logger.log(de);
    return 0;
}