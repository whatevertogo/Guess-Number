// Game.cpp
#include "Game.h"

#include <iostream>
#include <limits>

#include "Data.h"
#include "m_rand.h"

namespace GameManager
{
void PlayGame(Player& player)
{
    unsigned int guess;
    unsigned int max_possible = MAX_NUMBER;
    unsigned int min_possible = MIN_NUMBER;
    int attempts = 0;

    my_srand(static_cast<unsigned int>(time(nullptr)));
    unsigned int random_num = my_rand() % MAX_NUMBER + MIN_NUMBER;

    std::cout << "欢迎来到猜数字游戏！请输入一个" << MIN_NUMBER << "到" << MAX_NUMBER << "之间的数字：\n";

    do
    {
        guess = GetValidInput(min_possible, max_possible);
        ++attempts;

        if (guess > random_num)
        {
            std::cout << "你猜的数字太大了！\n";
            max_possible = std::min(max_possible, guess - 1);
        }
        else if (guess < random_num)
        {
            std::cout << "你猜的数字太小了！\n";
            min_possible = std::max(min_possible, guess + 1);
        }
        else
        {
            std::cout << "恭喜你猜对了！\n";
            break;
        }

        std::cout << "提示：当前可能的数字范围是[" << min_possible << "," << max_possible << "]\n";

    } while (guess != random_num);

    player.SetPlay_Time(attempts); // 修正方法名
    Data::SavePlayerData(player);  // 使用正确的命名空间
}

unsigned int GetValidInput(unsigned int min, unsigned int max)
{
    unsigned int input;
    while (true)
    {
        std::cout << "请输入数字: ";
        if (std::cin >> input && input >= min && input <= max)
        {
            return input;
        }
        std::cout << "无效输入，请输入" << min << "到" << max << "之间的数字\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int ShowMenu()
{
    std::cout << "你是否想查看排行榜?\n"
              << "1. 查看排行榜\n"
              << "2. 退出游戏\n";

    return static_cast<int>(GetValidInput(1, 2));
}
} // namespace GameManager