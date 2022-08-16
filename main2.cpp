#include <iostream>

short int sivar = 10;
int ivar = 10132213;
long long lvar = 100'001'322;
char cvar = 'D';
bool bvar = true;
float fvar = 123.32f;
double dvar = 34.12;


enum class CrossZero : char
{
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_',
};

CrossZero array[3][3] =
{
    {CrossZero::EMPTY, CrossZero::EMPTY, CrossZero::EMPTY},
    {CrossZero::EMPTY, CrossZero::EMPTY, CrossZero::EMPTY},
    {CrossZero::EMPTY, CrossZero::EMPTY, CrossZero::EMPTY},
};


struct CrossZeroGame 
{
    const unsigned int MAP_SIZE = 3;
    CrossZero array[3][3];
    bool isGameFinished;
    bool isFirstPlayerWon;
    unsigned long long Player1Id, Player2Id;
    CrossZero Player1Stuff, Player2Stuff;
    unsigned int Player1Wins, Player2Wins;
};

union MyData
{
    int Int;
    float Float;
    char Char;
};
struct MyVariant
{
    MyData data;
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
};

int main()
{
    MyVariant var;
    var.data.Float = 14124.34f;
    var.isChar = 0;
    var.isFloat = 1;
    var.isInt = 0;
    std::cout << var.data.Float << std::endl;
    std::cout << var.data.Char << std::endl;
    std::cout << var.data.Int << std::endl;
    std::cout << "\n" << std::endl;
    var.data.Char = 'A';
    var.isChar = 1;
    var.isFloat = 0;
    var.isInt = 0;
    std::cout << var.data.Float << std::endl;
    std::cout << var.data.Char << std::endl;
    std::cout << var.data.Int << std::endl;
    std::cout << "\n" << std::endl;
    var.data.Int = 123;
    var.isChar = 0;
    var.isFloat = 0;
    var.isInt = 1;
    std::cout << var.data.Float << std::endl;
    std::cout << var.data.Char << std::endl;
    std::cout << var.data.Int << std::endl;
}