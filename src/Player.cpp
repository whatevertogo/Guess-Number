#include "Player.h"

std::string Player::GetName() const
{
    return name;
}

void Player::SetName(const std::string& name)
{
    this->name = name;
}

int Player::GetPlay_Time() const
{
    return Play_Time;
}

void Player::SetPlay_Time(int play_time)
{
    Play_Time = play_time;
}