#pragma once
#include <string>

/**
 * @brief 玩家类
 *
 */
class Player
{
public:
    Player()
        : name("")
        , Play_Time(0)
    {
    }
    ~Player() {}
    /**
     * @brief Get the Name Player
     *
     * @return std::string
     */
    std::string GetName() const;
    /**
     * @brief Set the Name Player
     *
     * @param name
     */
    void SetName(const std::string& name);
    /**
     * @brief Get the Play Time Player
     *
     * @return int
     */
    int GetPlay_Time() const;
    /**
     * @brief Set the Play Time Player
     *
     * @param play_time
     */
    void SetPlay_Time(int play_time);

private:
    std::string name;
    int Play_Time;
};