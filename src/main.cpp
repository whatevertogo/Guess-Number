#include <ctime>
#include <iostream>

#include "m_rand.h"

int main()
{
    unsigned int guess_number;
    unsigned int max_maybenumber = 100;
    unsigned int min_maybenumber = 1;
    // 使用自定义的随机数生成函数
    my_srand(static_cast<unsigned int>(time(0)));     // 设置随机数种子
    unsigned int random_number = my_rand() % 100 + 1; // 生成1到100之间的随机数
    std::cout << "欢迎来到猜数字游戏!请输入一个1到100之间的数字:" << "\n";
    std::cin >> guess_number;

    do
    {
        if (guess_number > random_number)
        {
            std::cout << "你猜的数字太大了!请再试一次:" << "\n";
            if (guess_number < max_maybenumber)
                max_maybenumber = guess_number;
        }
        else if (guess_number < random_number)
        {
            std::cout << "你猜的数字太小了!请再试一次:" << "\n";
            if (guess_number > min_maybenumber)
                min_maybenumber = guess_number;
        }
        else
        {
            std::cout << "恭喜你!猜对了!" << "\n";
            break;
        }
        std::cout<<"提示：现在可能的数字范围是["<<min_maybenumber<<","<<max_maybenumber<<"]\n";
        std::cin >> guess_number;

    } while (guess_number != random_number);

    return 0;
}
