#include "player.h"
#include "settings.h"

using std::pair;
using std::string;
using std::vector;

/**
 * @brief  Ввод данных в вектор
 *
 */
bool Player::input_data()
{
    string temp = input.input_data();
    if (temp == EXIT)
        return false;

    data.clear();
    for (auto c : temp)
        data.push_back(c - '0');
    return true;
}

void Player::set_data(const vector<int> &v)
{
    data = v;
}

void AskPlayer::init()
{
    set_data(rnd.random_vector());
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