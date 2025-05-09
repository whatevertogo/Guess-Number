#pragma once
#include "Player.h"

namespace Data
{
/**
 * @brief 保存玩家数据
 * @param player 要保存的玩家对象
 */
void SavePlayerData(const Player& player);

/**
 * @brief 加载玩家数据
 */
void LoadPlayerData();

/**
 * @brief 显示排行榜
 */
void DisplayRankings();
} // namespace Data