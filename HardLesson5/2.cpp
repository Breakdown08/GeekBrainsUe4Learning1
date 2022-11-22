#include <iostream>
#include <string>
#include <set>
#include <vector>; 
#include <sstream>; 
using namespace std;




int main()
{
    string str = "Welcome to coding with art";

    stringstream ss(str);       // declare stringstream for string str
    string word;
    vector<string> words;
    int wordcount = 0;
    while (ss >> word) {
        for (auto ch : word)
        {
            if ((ch == '.') || (ch == '!') || (ch == '?'))
            {
                words.
            }
        }
        words.push_back(word);
    }
    cout << "No of words : " << wordcount << "\n";
    for (string word : words)
        cout << word << "\n";
    return 0;
}
