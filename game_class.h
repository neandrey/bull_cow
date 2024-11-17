#ifndef GAME_CLASS_H
#define GAME_CLASS_H
#include <vector>
#include <iostream>
#include "input.h"
#include "init_random.h"

class GameClass
{
    InputData in_data;
    int bull{0}, cow{0};
    std::vector<int> find_numbers, input_numbers;

public:
    void init();
    void start();
    void clear() { bull = cow = 0; }

    void find_coincidences();
    void print() const;
    int get_bull() const { return bull; }
    int get_cow() const { return cow; }
};

static void str_to_vec(const std::string &s, std::vector<int> &v);
#endif