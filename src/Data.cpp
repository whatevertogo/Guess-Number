#include "Data.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>


namespace Data
{
void SavePlayerData(const Player& player)
{
    std::ofstream out("player_data.txt", std::ios::app);
    if (!out.is_open())
    {
        throw std::ios_base::failure("无法打开文件进行写入");
    }
    out << player.GetName() << " " << player.GetPlay_Time() << "\n";
    out.close();
}

void DisplayRankings()
{
    std::ifstream in("player_data.txt");
    if (!in.is_open())
    {
        throw std::ios_base::failure("无法打开文件进行读取");
    }

    std::vector<std::pair<std::string, int>> players;
    std::string name;
    int play_time;

    while (in >> name >> play_time)
    {
        players.emplace_back(name, play_time);
    }
    in.close();

    std::sort(players.begin(), players.end(), [](const auto& a, const auto& b) { return a.second < b.second; });

    std::cout << "排行榜:\n";
    for (size_t i = 0; i < players.size(); ++i)
    {
        std::cout << i + 1 << ". 玩家: " << players[i].first << ", 游戏次数: " << players[i].second << " 次\n";
    }
}
} // namespace Data