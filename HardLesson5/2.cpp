#include <iostream>
#include <string>
#include <set> 
#include <sstream>; 
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    string str = "Первое предложение. Второе предложение из пяти слов!";
    stringstream ss(str);
    string word;
    int wordCount = 0;
    while (ss >> word) {
        cout << word << " ";
        wordCount++;
        for (auto ch : word)
        {
            if ((ch == '.') || (ch == '!') || (ch == '?'))
            {
                cout << " (Слов в предложении: " << wordCount << ")" << endl;
                wordCount = 0;
                break;
            }
        }
    }
}
