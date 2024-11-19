#ifndef GAME_CLASS_H
#define GAME_CLASS_H
#include <vector>
#include <iostream>
#include "input.h"
#include "player.h"

class GameClass
{

    InputData in_data;
    AskPlayer p_ask;
    AnswerPlayer p_answer;
    std::pair<int, int> bull_cow{0, 0};

public:
    void init();
    void start_game();
    void clear();
    bool winner();
    int get_bull() const { return bull_cow.first; }
    int get_cow() const { return bull_cow.second; }
    void print_result();

#ifdef DEBUG
    void debug_output() const;
#endif
};
#endif