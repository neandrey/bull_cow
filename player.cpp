#include "player.h"

using std::pair;
using std::string;
using std::vector;

/**
 * @brief  Ввод данных в вектор
 *
 */
void Player::input_data()
{
    data.clear();
    string temp = input.input_data();
    for (auto c : temp)
        data.push_back(c - '0');
}

void Player::set_data(const vector<int> &v)
{
    data = v;
}

void AskPlayer::init()
{
    this->set_data(rnd.random_vector());
}

/**
 * @brief Поиск быков и коров
 *
 */
pair<int, int> AskPlayer::find_coincidences(const std::vector<int> &v)
{
    int bull{0}, cow{0};
    for (size_t i = 0; i < 4; ++i)
    {
        if (this->get_data()[i] == v[i])
            ++bull;
        else
        {
            for (size_t h = 0; h < 4; ++h)
                if (this->get_data()[i] == v[h])
                    ++cow;
        }
    }
    return pair<int, int>(bull, cow);
}