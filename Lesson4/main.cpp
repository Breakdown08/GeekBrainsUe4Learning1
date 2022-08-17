#include <iostream>

int a, b, sum, result, simple, year;
const std::string TRUE = "true";
const std::string FALSE = "false";
const int a2 = 9;
const int b2 = 1;
bool isPrime = true;
const int SIZE_MATRIX = 3;
int matrix[SIZE_MATRIX][SIZE_MATRIX] =
{
    {0, 0, 0}, 
    {0, 0, 0},
    {0, 0, 0},
};
int main()
{
    //-----------ПЕРВОЕ-----------------
    std::cin >> a;
    std::cin >> b;
    sum = a + b;
    if (sum >= 10 && sum <= 20)
    {
        std::cout << TRUE << std::endl;
    }
    else
    {
        std::cout << FALSE << std::endl;
    }

    //-----------ВТОРОЕ-----------------
    if (a2 == 10 && b2 == 10)
    {
        std::cout << TRUE << std::endl;
    }
    else if ((a2 + b2) == 10)
    {
        std::cout << TRUE << std::endl;
    }
    else
    {
        std::cout << FALSE << std::endl;
    }

    //-----------ТРЕТЬЕ-----------------
    std::cout << "Your numbers: ";
    for (size_t i = 1; i <= 50; i += 2) 
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    //-----------ЧЕТВЕРТОЕ---------------
    for (size_t i = 0; i < SIZE_MATRIX; i++) //заполнение единицами
    {
        matrix[i][i] = 1;
    }
    for (size_t i = 0; i < SIZE_MATRIX; i++) //вывод
    {
        for (size_t j = 0; j < SIZE_MATRIX; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //--------------ПЯТОЕ----------------
    std::cout << "Input your simple value:" << std::endl;
    std::cin >> simple;
    if (simple > 1)
    {
        for (int i = 2; i < simple; i++)
        {
            if (simple % i == 0) isPrime = false;
        }
    }
    else
        isPrime = false;
    if (isPrime == true) std::cout << "value is SIMPLE:" << std::endl;
    else std::cout << "value is NOT SIMPLE:" << std::endl;

    //--------------ШЕСТОЕ----------------
    std::cout << "Input your year:" << std::endl;
    std::cin >> year;
    if ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0))
    {
        std::cout << "year is leap" << std::endl;
    }
    else std::cout << "year is not leap" << std::endl;
}