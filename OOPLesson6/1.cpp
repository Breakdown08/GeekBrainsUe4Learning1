#include <iostream>
#include <ctype.h> // isdigit()
#include <sstream> // stringstream
using namespace std;

int main()
{
    string user_string_num = "";

    int is_num = 0,
        decimal_count = 0,
        user_converted_num;

    bool is_num_bool = 0,
        contains_spaces = false;

    do
    {
        cout << "Enter a number: ";
        getline(cin, user_string_num);

        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i])) // если встретился пробел то запомним об этом
                contains_spaces = true;
        }

        if (user_string_num[0] == '-') // допускаем возможность использования знака:   -912
        {
            is_num++;

            if (user_string_num[1] == '0') // запрещаем юзать ноль после отр. знака
                is_num = 0;
        }

        if ((user_string_num[0] == '0' && isdigit(user_string_num[1]))) // запрещаем юзать ноль с цифрами после него: 0934939
            is_num = 0;
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;
                if (user_string_num[i] == '.')
                    decimal_count++;
            }
        }

        if (decimal_count == 1) //если нарвались на точки то тоже запрещаем: 66.7  8..9.9.9..9.9
            is_num = 0;

        if (is_num == user_string_num.size() && contains_spaces == false) //если количество встреченных чисел равно размеру строки и нет пробелов
        {
            stringstream str_stream_object(user_string_num);
            str_stream_object >> user_converted_num;

            is_num_bool = 1;

            cout << "IT'S OK!!" << endl;

        }
        else
        {
            cout << endl
                << "Value is NOT number"
                << endl;

            is_num_bool = 0;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;

        }

    } while (is_num_bool == 0);

    return 0;
}