#include "init_random.h"

using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

int InitRand::random_number(int min, int max)
{
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(min, max);
    return uniform_dist(e1);
}

void InitRand::random_vector(vector<int> &v)
{
    bool flag{false};
    while (v.size() != 4)
    {
        int rand = random_number(0, 9);
        for (auto i : v)
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
        v.push_back(rand);
    }
}
