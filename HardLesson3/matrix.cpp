#include <iostream>
#include <clocale>  
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <random>
#include <ctime>


using namespace std;

class Matrix
{
private:
    vector<vector<double>> matrix;
    size_t size;
    const double eps = 1e-9;
public:
    Matrix(const size_t& n)
    {
        size = n;
        int max = 50;
        int min = -50;
        for (size_t i = 0; i < n; i++)
        {
            vector<double> v;
            for (size_t j = 0; j < n; j++)
            {
                int value =  min + (rand() % static_cast<int>(max - min + 1));
                v.push_back(value);
            }
            matrix.push_back(v);
        }
    }
    Matrix(string s) //Захардкоженная матрица чисел для тренировки
    {
        if (s == "3") //тут определитель будет 312
        {
            size = 3;
            matrix.push_back(vector<double>{8, 16, 10});
            matrix.push_back(vector<double>{4, 14, 2});
            matrix.push_back(vector<double>{2, 10, 6});
        }
        else //тут -144
        {
            size = 4;
            matrix.push_back(vector<double>{4, 6, -2, 4});
            matrix.push_back(vector<double>{1, 2, -3, 1});
            matrix.push_back(vector<double>{4, -2, 1, 0});
            matrix.push_back(vector<double>{6, 4, 4, 6});
        }

    }

    void Print()
    {
        cout << endl;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            vector<int> v;
            for (size_t j = 0; j < matrix.size(); j++)
            {
                cout << matrix[i][j] << "   ";
            }
            cout << endl;
        }
    }


    double Det()
    {
        double det = 1; //переменная определителя матрицы
        for (size_t i = 0; i < size; i++) //цикл, итерирующий локализацию матрицы (прямой ход)
        {
            // находим строку с максимальным первым элементом
            int iMax = i;
            for (size_t j = i + 1; j < size; j++)
            {
                if (abs(matrix[j][i]) > abs(matrix[iMax][i])) //сравниваем по модулю первые элементы текущей и следующей строк
                {
                    iMax = j;
                }
            }
            if (abs(matrix[iMax][i]) < eps) //если элемент очень близок к нулю, пропустим строку
            {
                continue;
            }
            for (size_t k = 0; k < size; ++k) //производим смену строк
            {
                swap(matrix[i][k], matrix[iMax][k]);
            }
            if (i != iMax) //если случилась перестановка строк, инвертируем знак
            {
                det = -det;
            }
            //-----------------------------------------------------------------------------------
            double pivotElement = matrix[i][i]; //переменная ведущего элемента
            for (size_t k = i; k < size; k++) //цикл по строкам
            {
                //pivotElement = matrix[i][pivotIndex];
                if (k != i) //если строка под единицей, будем её обнулять
                {
                    double firstElement = matrix[k][i]; //запомним первый элемент строки
                    for (size_t j = i; j < size; j++) //цикл по столбцам
                    {
                        if ((i != size - 1)) //элементы при локализации матрицы меньше чем 2х2 учитываться не будут
                        {
                            matrix[k][j] -= matrix[i][j] * firstElement; //из последующих строк вычитаем главную строку умноженную на первый элемент текущей строки
                        } //таким образом получается ноль
                    }
                }
                else //работаем с главной строкой локализованной матрицы
                {
                    for (size_t j = i; j < size; j++) //цикл по столбцам
                    {
                        if ((i != size - 1)) //элементы при локализации матрицы меньше чем 2х2 учитываться не будут
                        {
                            matrix[k][j] /= pivotElement; //строка делится на свой первый элемент чтобы получить единицу в первом элементе
                        }
                    }
                    det *= pivotElement; //наращиваем домножением переменную определителя
                }
            }
        }
        Print();
        return det;
    }
};




int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout << "РАНДОМНАЯ МАТРИЦА nхn" << endl;
    Matrix matrix1(3);
    matrix1.Print();
    cout << matrix1.Det() << endl;
    cout << "Статичная матрица 3х3" << endl;
    Matrix matrix2("3");
    matrix2.Print();
    cout << matrix2.Det() << endl;
    cout << "Статичная матрица 4х4" << endl;
    Matrix matrix3("BLABLA");
    matrix3.Print();
    cout << matrix3.Det() << endl;
}


