#include "input.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

bool InputData::is_digit()
{
    for (auto c : s_data)
        if (!isdigit(c))
            return false;
    return true;
}

const string &InputData::input_data()
{
    while (true)
    {
        std::cout << "Введите число: ";
        getline(cin, s_data);
        if ((s_data.size() == 4) && is_digit() && is_diff())
            break;
        else if (s_data.size() != 4)
        {
            cout << "Ожидается 4-х знаковое число" << endl;
        }
        else if (!is_digit())
        {
            cout << "Только числа (0-9):" << endl;
        }
        else if (!is_diff())
        {
            cout << "В числе имееются совпадения: " << endl;
        }
        cin.clear();
        while (cin.get() != '\n')
        {
        };
    }
    return s_data;
}