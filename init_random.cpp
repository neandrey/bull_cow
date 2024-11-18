#include "init_random.h"

using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

InitRand::InitRand(int _max, int _min, int _len)
    : max(_max), min(_min), len(_len) {}

int InitRand::random_number(int min, int max)
{
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(min, max);
    return uniform_dist(e1);
}

const vector<int> InitRand::random_vector()
{
    bool flag{false};
    rand_v.clear();
    while (rand_v.size() < len)
    {
        int rand = random_number(min, max);
        for (auto i : rand_v)
        {
            if (i == rand)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            flag = false;
            continue;
        }
        rand_v.push_back(rand);
    }
    return rand_v;
}
