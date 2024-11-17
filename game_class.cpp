#include "game_class.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void GameClass::init()
{
    InitRand().random_vector(find_numbers);
}

void GameClass::start()
{
    while (true)
    {
        clear();
        str_to_vec(in_data.input_data(), input_numbers);
        find_coincidences();
        print();
        if (bull == 4)
        {
            cout << "You win!" << endl;
            break;
        }
    }
}

/**
 * @brief преобразование строки в вектор
 *
 * @param s строка
 * @param v вектор
 */
void str_to_vec(const string &s, vector<int> &v)
{
    v.clear();
    for (auto c : s)
        v.push_back(c - '0');
}

/**
 * @brief Поиск быков и коров
 *
 */
void GameClass::find_coincidences()
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (find_numbers[i] == input_numbers[i])
            ++bull;
        else
        {
            for (size_t h = 0; h < 4; ++h)
                if (find_numbers[i] == input_numbers[h])
                    ++cow;
        }
    }
}

/**
 * @brief  Вывод отладочной информации
 *
 */
void GameClass::print() const
{
    for (auto i : find_numbers)
        cout << i << " ";
    cout << endl;

    for (auto i : input_numbers)
        cout << i << " ";
    cout << endl;

    cout << "bull: " << bull << " cow: " << cow << endl;
}
