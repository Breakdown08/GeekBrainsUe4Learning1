#include <iostream>

extern int a, b, c, d;
//int a{ 3 }, b{ 1 }, c{ 7 }, d{ 4 };
float result;
int var{ 24 };
int array[3][3][3] =
{
    { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } },
    { { 1, 2, 3 }, { 5, 777, 7 }, { 1, 2, 3 } },
    { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } }
};
int * ptr;


int main()
{
    ptr = & array[1][1][1];
    result = a * (b + (float(c) / d));
    std::cout << result << std::endl;
    std::cout << ((var < 21) ? var - 21 : (var - 21) * 2) << std::endl;
    std::cout << *ptr << std::endl;
}