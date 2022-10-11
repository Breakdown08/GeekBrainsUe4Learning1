#include <iostream>
#include <clocale>  
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Timer.h"

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
                for (auto& item : setToFind)
                {
                    if (ch == item)
                    {
                        return true;
                    }
                }
                return false;
            });
    }


    static int ForAndFind(const std::string& s, const std::string& setToFind)
    {
        int count = 0;
        for (auto& ch: s)
        {
            if (setToFind.find(ch) != std::string::npos)
            {
                count++;
                continue;
            }
        }
        return count;
    }


    static int DoubleFor(const std::string& s, const std::string& setToFind)
    {
        int count = 0;
        for (auto& chi : setToFind)
        {
            for (auto& chj : s)
            {
                if (chi == chj)
                {
                    count++;
                }
            }
        }
        return count;
    }


    int CountVowels(int (*foo)(const std::string& s, const std::string& setToFind), std::string title = "unknown function")
    {
        const std::string vowels = "АУОЫЭЯЮЁИЕауоыэяюёие";
        int count = 0;
        Timer timer(title);
        for (auto& str : strings)
        {
            count += foo(str, vowels);
        }
        timer.print();
        return count;
        
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream file(DATA_FILE);
    FileReader fr(file);
    std::cout << fr.CountVowels(FileReader::CountIfAndFind, "CountIf and Find") << std::endl;
    std::cout << fr.CountVowels(FileReader::CountIfAndFor, "CountIf and For") << std::endl;
    std::cout << fr.CountVowels(FileReader::ForAndFind, "For and Find") << std::endl;
    std::cout << fr.CountVowels(FileReader::DoubleFor, "Double For") << std::endl;

    /*
    CountIf and Find:       214.58 ms
    155075
    CountIf and For:        498.945 ms
    155075
    For and Find:   159.271 ms
    155075
    Double For:     273.12 ms
    155075
    */

}
















