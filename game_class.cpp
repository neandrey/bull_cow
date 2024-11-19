#include "game_class.h"

using std::cin;
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
void GameClass::game_start()
{
    char ch = 'a';
    do
    {
        init();
        while (true)
        {
            clear();

            if (!p_answer.input_data())
            {
                ch = 'n';
                break;
            }

            bull_cow = p_ask.find_coincidences(p_answer.get_data());

            debug_output();

            if (winner())
            {
                cout << "You win!" << endl;
                cout << "Хотите еще раз сыграть (y/n):";
                cin >> ch;
                break;
            }
        }

    } while (ch != 'n');
}

/**
 * @brief Проверка на выигрыш
 *
 * @return true
 * @return false
 */
bool GameClass::winner()
{
    return (bull_cow.first == 4) ? true : false;
}

/**
 * @brief Сброс значения коров и быков
 *
 */
void GameClass::clear()
{
    bull_cow.first = 0;
    bull_cow.second = 0;
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
