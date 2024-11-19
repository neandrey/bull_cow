#include "input.h"
#include "settings.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * @brief Проверка на дублирование
 *
 * @return true
 * @return false
 */
bool InputData::is_diff()
{
    for (size_t h = 0; h < s_data.size(); ++h)
    {
        for (size_t i = 0; i < s_data.size(); ++i)
        {
            if (h == i)
                continue;
            else if (s_data[h] == s_data[i])
                return false;
        }
    }
    return true;
}

/**
 * @brief Проверка на число
 *
 * @return true
 * @return false
 */
bool InputData::is_digit()
{
    for (auto c : s_data)
        if (!isdigit(c))
            return false;
    return true;
}

/**
 * @brief Чтение данных из командной строки
 *
 * @return const string&
 */
const string &InputData::input_data()
{
    while (true)
    {
        std::cout << "Введите угадываемое число или " << EXIT
                  << " для выхода: ";
        getline(cin, s_data);
        if (s_data == EXIT ||
            (s_data.size() == LEN) && is_digit() && is_diff())
            break;
        else if (!is_digit())
        {
            cout << "Ожидаются числа или " << EXIT
                 << " для выхода : " << endl;
        }
        else if (s_data.size() != LEN)
        {
            cout << "Ожидается " << LEN << " значное число" << endl;
        }
        else if (!is_diff())
        {
            cout << "В числе имеются совпадения: " << endl;
        }
        cin.clear();
        while (cin.get() != '\n')
        {
        };
    }
    return s_data;
}