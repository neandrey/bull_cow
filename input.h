#ifndef INPUT_CLASS_H
#define INPUT_CLASS_H
#include <string>
#include <vector>
#include <iostream>

class InputData
{
    std::string s_data;
    bool is_diff();
    bool is_digit();

public:
    const std::string &input_data();
};

#endif