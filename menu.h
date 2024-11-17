// #ifndef MENU_H
// #define MENU_H

// class Menu
// {
//     int bull{0}, cow{0};
//     std::vector<int> find_numb, input_numb;

// public:
//     void init()
//     {
//         init_vector(find_numb);
//         // str_to_ivec(input_number(), input_numb);
//         find_number(input_numb);
//     }

//     void print()
//     {
//         for (auto i : input_numb)
//             std::cout << i << " ";
//         std::cout << std::endl;
//         for (auto i : find_numb)
//             std::cout << i << " ";
//         std::cout << std::endl;

//         std::cout << "\nbull: " << bull << " cow: " << cow << std::endl;
//     }

//     void find_number(const std::vector<int> &v)
//     {
//         for (size_t i = 0; i < 4; ++i)
//         {
//             if (find_numb[i] == v[i])
//                 ++bull;
//             else
//             {
//                 for (size_t h = 0; h < 4; ++h)
//                     if (v[i] == find_numb[h])
//                         ++cow;
//             }
//         }
//     }
// };

// #endif