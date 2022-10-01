#include <iostream>

class DivisionByZero
{
private:
    std::string m_error;
public:
    DivisionByZero() : m_error("second argument can not be ZERO") { }
    const char* getError() 
    { 
        return m_error.c_str(); 
    }
};


template < typename T >
T Div(T& a, T& b)
{
    if (b == 0)
    {
        throw DivisionByZero();
    };
    return a / b;
}


class Ex
{  
public:
    double x;
    Ex(double x) : x(x) { };
};

class Bar
{
private:
    double y;
public:
    Bar()
    {
        y = 0;
    }
    void Set(double a)
    {
        if ((y + a) > 100)
        {
            throw Ex(a * y);
        }
        else 
        {
            y = a;
        }
    }
};

int main()
{
    //------------------------------1-------------------------------
    int a, b;
    a = 18;
    b = 0;
    try
    {
        std::cout << Div(a, b) << std::endl;
    }
    catch (DivisionByZero&  exception)
    {
        std::cerr << "Error: " << exception.getError() << std::endl;
    }
    //------------------------------2-------------------------------
    std::cout << std::endl;
    Bar bar;
    int arg = 1;
    std::cout << "START TESTING" << std::endl;
    while (arg != 0)
    {
        std::cout << "input arg: " << std::endl;
        std::cin >> arg;
        try
        {
            bar.Set(arg);
        }
        catch (Ex exception)
        {
            std::cerr << "Error: " << exception.x << std::endl;
        }
    }
    return 0;
}