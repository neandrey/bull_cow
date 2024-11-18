#include "game_class.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * @brief  загадываем число
 *
 */
void GameClass::init()
{
    p_ask.init();
}

/**
 * @brief  Цикл игры
 *
 */
void GameClass::start()
{
    while (true)
    {
        clear();
        p_answer.input_data();
        bull_cow = p_ask.find_coincidences(p_answer.get_data());
        debug_output();
        if (bull_cow.first == 4)
        {
            cout << "You win!" << endl;
            break;
        }
    }
}

/**
 * @brief  Вывод отладочной информации
 *
 */
void GameClass::debug_output() const
{
    for (auto i : p_ask.get_data())
        cout << i << " ";
    cout << endl;

    for (auto i : p_answer.get_data())
        cout << i << " ";
    cout << endl;

    cout << "bull: " << bull_cow.first << " cow: " << bull_cow.second << endl;
}
