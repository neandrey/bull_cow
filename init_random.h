#ifndef INIT_RANDOM_H
#define INIT_RANDOM_H
#include <random>
#include <vector>
#include "settings.h"

class InitRand
{
    int max{0}, min{0}, len{0};
    std::vector<int> rand_v;
    static int random_number(int min, int max);

public:
    InitRand(int _max = MAX_NUMBER, int _min = MIN_NUMBER, int _len = LEN);
    const std::vector<int> random_vector();
};

#endif