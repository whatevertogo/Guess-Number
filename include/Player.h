#pragma once
#include <string>

class Player
{
public:
    Player()
        : name("")
        , Play_Time(0)
    {
    }
    ~Player() {}

    std::string GetName() const;
    void SetName(const std::string& name);

    int GetPlay_Time() const;
    void SetPlay_Time(int play_time);

private:
    std::string name;
    int Play_Time;
};