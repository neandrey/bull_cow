#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "init_random.h"
#include "input.h"

class Player
{
    InputData input;
    std::vector<int> data;

public:
    bool input_data();
    void set_data(const std::vector<int> &v);
    std::vector<int> get_data() const { return data; }
};

class AskPlayer : public Player
{
    InitRand rnd;

public:
    void init();
    std::pair<int, int> find_coincidences(const std::vector<int> &v);
};

class AnswerPlayer : public Player
{
};

#endif