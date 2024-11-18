#ifndef INIT_RANDOM_H
#define INIT_RANDOM_H
#include <random>
#include <vector>

class InitRand
{
    int max{0}, min{0}, len{0};
    std::vector<int> rand_v;
    static int random_number(int min, int max);

public:
    InitRand(int _max = 9, int _min = 0, int _len = 4);
    const std::vector<int> random_vector();
};

#endif