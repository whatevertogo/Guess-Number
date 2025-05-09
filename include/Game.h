// Game.h
#pragma once

#include "Player.h"

namespace GameManager
{
/**
 * @brief 游戏配置常量
 */
constexpr unsigned int MAX_NUMBER = 100;
constexpr unsigned int MIN_NUMBER = 1;

/**
 * @brief 运行游戏主逻辑
 * @param player 玩家对象
 */
void PlayGame(Player& player);

/**
 * @brief 显示游戏菜单
 * @return 用户选择的选项
 */
int ShowMenu();

/**
 * @brief 获取用户输入并验证
 * @param min 最小值
 * @param max 最大值
 * @return 验证后的用户输入
 */
unsigned int GetValidInput(unsigned int min, unsigned int max);
} // namespace GameManager