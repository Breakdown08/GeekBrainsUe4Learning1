#include <iostream>
#include <clocale>  
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // для stringstream
#include <iomanip>
#include <algorithm>
#include <unordered_set>

const std::string DATA_FILE = "war_and_peace.txt";

class FileReader
{
private:
    std::vector<std::string> strings;
public:


    FileReader(std::ifstream& stream)
    {
        if (stream.is_open())
        {
            while (!stream.eof())
            {
                std::string row;
                std::getline(stream, row);
                strings.push_back(row);
            }
            stream.close();
        }
    }
    

    static int CountIfAndFind(const std::string& s, const std::string& setToFind)
    {
        return std::count_if(s.begin(), s.end(), [&](char ch) 
            { 
                return setToFind.find(ch) != std::string::npos;
            });
    }


    static int CountIfAndFor(const std::string& s, const std::string& setToFind)
    {
        return std::count_if(s.begin(), s.end(), [&](char ch)
            {
                for (auto item : setToFind)
                {
                    if (ch == item)
                    {
                        return true;
                    }
                }
                return false;
            });
    }


    static int ForAndFind(std::string s)
    {

    }


    static int DoubleFor(std::string s)
    {

    }


    int CountVowels(int (*foo)(const std::string& s, const std::string& setToFind))
    {
        const std::string vowels = "АУОЫЭЯЮЁИЕауоыэяюёие";
        int count = 0;
        for (auto& str : strings)
        {
            count += foo(str, vowels);
        }
        return count;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream file(DATA_FILE);
    FileReader fr(file);
    std::cout << fr.CountVowels(FileReader::CountIfAndFind) << std::endl;
    std::cout << fr.CountVowels(FileReader::CountIfAndFor) << std::endl;
}
















