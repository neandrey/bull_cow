#ifndef INIT_RANDOM_H
#define INIT_RANDOM_H
#include <random>
#include <vector>

class InitRand
{
    static int random_number(int min, int max);

public:
    static void random_vector(std::vector<int> &v);
};

#endif