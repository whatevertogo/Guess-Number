#include <iostream>

#include "Data.h"
#include "Game.h"
#include "Player.h"


int main()
{
    try
    {
        Player player;
        std::string name;

        std::cout << "请输入你的名称: ";
        std::getline(std::cin, name);
        player.SetName(name);

        GameManager::PlayGame(player);

        if (GameManager::ShowMenu() == 1)
        {
            Data::DisplayRankings(); // 使用正确的命名空间
        }

        std::cout << "游戏结束！谢谢参与！\n";
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "错误：" << e.what() << '\n';
        return 1;
    }
}