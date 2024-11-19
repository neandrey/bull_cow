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
void GameClass::start_game()
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
#ifdef DEBUG
            debug_output();
#endif
            print_result();
            if (winner())
            {
                cout << "You win!" << endl;
                cout << "Хотите еще раз сыграть (y/n):";
                cin >> ch;
                cin.get();
                break;
            }
        }

    } while (ch != 'n');
}
/**
 * @brief  Вывод информации о быках и коровах
 *
 */
void GameClass::print_result()
{
    cout << "Быки: " << bull_cow.first
         << " Коровы: " << bull_cow.second
         << endl;
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

#ifdef DEBUG
/**
 * @brief  Вывод отладочной информации
 *
 */
void GameClass::debug_output() const
{
    // Искомое число
    cout << "Fn: ";
    for (auto i : p_ask.get_data())
        cout << i << " ";
    cout << endl;

    // Введенное пользователем
    cout << "In: ";
    for (auto i : p_answer.get_data())
        cout << i << " ";
    cout << endl;
}
#endif