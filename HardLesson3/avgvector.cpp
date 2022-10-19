#include <iostream>
#include <clocale>  
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <unordered_set>


using namespace std;
list<double> listOfFloat = { 0.5, 0.5, 0.25, 0.75, 0.5, 0.5, 0.5 };

const void PrintList(list<double>& list)
{
    for (auto& item : list) { cout << item << " "; } cout << endl;
}

void AddAvg(list<double>& list)
{
    auto lambda = [&](double a, double b) {return a + b / list.size(); };
    double avg = accumulate(list.begin(), list.end(), 0.0, lambda);
    list.push_back(avg);
}



int main()
{
    setlocale(LC_ALL, "Russian");
    PrintList(listOfFloat);
    AddAvg(listOfFloat);
    PrintList(listOfFloat);
    AddAvg(listOfFloat);
    PrintList(listOfFloat);
}


