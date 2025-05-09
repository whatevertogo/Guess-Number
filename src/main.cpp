#include "Player.h"
#include "Data.h" // 确保包含 DisplayRankings 函数的声明

#include "m_rand.h"

int main()
{
    Player player;
    unsigned int guess;
    unsigned int max_possible = 100;
    unsigned int min_possible = 1;
    int attempts = 0;

    // 设置随机数种子
    my_srand(static_cast<unsigned int>(time(0)));
    unsigned int random_num = my_rand() % 100 + 1;

    std::cout << "请输入你的名称: ";
    std::string name;
    std::cin >> name;
    player.SetName(name);

    std::cout << "欢迎来到猜数字游戏!请输入一个1到100之间的数字:\n";
    std::cin >> guess;

    do {
        if (guess > random_num) {
            std::cout << "你猜的数字太大了!请再试一次:\n";
            if (guess < max_possible)
                max_possible = guess;
        } else if (guess < random_num) {
            std::cout << "你猜的数字太小了!请再试一次:\n";
            if (guess > min_possible)
                min_possible = guess;
        } else {
            std::cout << "恭喜你!猜对了!\n";
            break;
        }
        std::cout << "提示：现在可能的数字范围是[" << min_possible << "," << max_possible << "]\n";
        std::cin >> guess;
        ++attempts;
    } while (guess != random_num);

    player.SetPlay_Time(attempts);
    savePlayerData(player);

    std::cout << "你是否想查看排行榜?\n";
    std::cout << "1. 查看排行榜\n";
    std::cout << "2. 退出游戏\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        DisplayRankings();
    }

    std::cout << "游戏结束!谢谢参与!\n";
    return 0;
}