#include <iostream>
#include <clocale>  
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template < typename T >
void Swap(T*& first, T*& second)
{
    T* temp = first;
    first = second;
    second = temp;
}

void PrintPointers(vector<const int*>& v, bool pointers = false)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (pointers)
        {
            cout << v[i] << " ";
        }
        else
        {
            cout << *v[i] << " ";
        }
    }
    cout << endl;
}

template < typename T >
void SortPointers(vector<T*>& vec)
{
    sort(vec.begin(), vec.end(), [](T* a, T* b)
        {
            return (*a < *b);
        });
}

int main()
{    
    setlocale(LC_ALL, "Russian");
    cout << "------------------------1-------------------------" << endl;
    int a, b;
    int* first;
    int* second;
    a = 10;
    b = 12;
    first = &a;
    second = &b;
    cout << "Адреса:" << endl;
    cout << first << " | " << second << endl;
    cout << "Значения по адресу:" << endl;
    cout << *first << " | " << *second << endl;
    cout << "Переменные:" << endl;
    cout << a << " | " << b << endl;
    Swap(first, second);
    cout << "-----------------------------------" << endl;
    cout << "Адреса:" << endl;
    cout << first << " | " << second << endl;
    cout << "Значения по адресу:" << endl;
    cout << *first << " | " << *second << endl;
    cout << "Переменные:" << endl;
    cout << a << " | " << b << endl;
    cout << "------------------------2-------------------------" << endl;
    int v1, v2, v3, v4, v5, v6;
    v1 = 40; v2 = 10; v3 = 100; v4 = 90; v5 = 20; v6 = 25;
    vector<const int*> pointers = { &v1, &v2, &v3, &v4, &v5, &v6 };
    PrintPointers(pointers); //отображение значений
    PrintPointers(pointers, true); //отображение адресов
    cout << endl;
    SortPointers(pointers);
    PrintPointers(pointers);
    PrintPointers(pointers, true);
}