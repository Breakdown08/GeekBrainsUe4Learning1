#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <clocale>  
#include <optional>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // для stringstream
#include <iomanip>
#include <algorithm>

struct Person
{
    std::string LastName;
    std::string FirstName;
    std::optional<std::string> Patronymic;
};
std::ostream& operator << (std::ostream& os, const Person& p)
{
    int width = 15;
    os << std::setw(width) << p.LastName << " " << std::setw(width) << p.FirstName;
    if (p.Patronymic)
    {
        os << " " << std::setw(width) << *p.Patronymic;
    }
    else
    {
        os << " " << std::setw(width) << "";
    }
    return os;
}

bool operator < (const Person& p1, const Person& p2)
{
    return tie(p1.LastName, p1.FirstName, p1.Patronymic) <
        tie(p2.LastName, p2.FirstName, p2.Patronymic);
}

bool operator == (const Person& p1, const Person& p2)
{
    return tie(p1.LastName, p1.FirstName, p1.Patronymic) ==
        tie(p2.LastName, p2.FirstName, p2.Patronymic);
}

struct PhoneNumber
{
    int state;
    int city;
    std::string number;
    std::optional<int> additional;
};

std::ostream& operator << (std::ostream& os, const PhoneNumber& n)
{
    os << "+" << n.state << "(" << n.city << ")" << n.number;
    if (n.additional)
    {
        os << " " << *n.additional;
    }
    return os;
}

bool operator < (const PhoneNumber& n1, const PhoneNumber& n2)
{
    return tie(n1.state, n1.city, n1.number, n1.additional) <
        tie(n2.state, n2.city, n2.number, n2.additional);
}

bool operator == (const PhoneNumber& n1, const PhoneNumber& n2)
{
    return tie(n1.state, n1.city, n1.number, n1.additional) ==
        tie(n2.state, n2.city, n2.number, n2.additional);
}


const std::string DATA_FILE = "data.txt";

class PhoneBook
{
public:
    std::vector<std::pair<Person, PhoneNumber>> storage;

    PhoneBook(std::ifstream& stream)
    {

        if (stream.is_open())
        {

            Person person;
            PhoneNumber phone;
            std::pair<Person, PhoneNumber> pair;
            while (!stream.eof())
            {
                std::string row;
                std::stringstream rowStream;
                std::string personString;
                std::string personPatronymic;
                std::string phoneState;
                std::string phoneCity;
                std::string phoneNumber;
                std::string phoneAdditional;
                std::getline(stream, row);
                rowStream << row;
                std::getline(rowStream, personString, ';') >> phoneState >> phoneCity >> phoneNumber >> phoneAdditional;
                phone.additional.reset();
                phone.state = NULL;
                phone.city = NULL;
                phone.number = "";
                phone.state = std::stoi(phoneState);
                phone.city = std::stoi(phoneCity);
                phone.number = phoneNumber;
                if (phoneAdditional != "")
                {
                    phone.additional = std::stoi(phoneAdditional);
                }
                rowStream.clear();
                rowStream << personString;
                personPatronymic = "";
                person.FirstName = "";
                person.LastName = "";
                person.Patronymic = std::nullopt;
                rowStream >> person.LastName >> person.FirstName >> personPatronymic;
                if (personPatronymic != "")
                {
                    person.Patronymic = personPatronymic;
                }
                rowStream.clear();
                pair.first = person;
                pair.second = phone;
                storage.push_back(pair);
            }
            stream.close();
        }
    }
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(std::string lastname)
    {
        std::tuple<std::string, PhoneNumber> tuple;
        int entryCount = 0;
        PhoneNumber phoneNumber;
        for (auto item : storage)
        {
            if (item.first.LastName == lastname)
            {
                entryCount++;
                phoneNumber = item.second;
            }
        }
        if (entryCount > 0)
        {
            if (entryCount == 1)
            {
                std::get<PhoneNumber>(tuple) = phoneNumber;
            }
            else
            {
                std::get<std::string>(tuple) = "found more than 1";
                std::get<PhoneNumber>(tuple) = phoneNumber;
            }
        }
        else
        {
            std::get<std::string>(tuple) = "not found";
        }
        return tuple;
    }

    void ChangePhoneNumber(const Person& p, const PhoneNumber& ph)
    {
        for (auto& item : storage)
        {
            if (item.first == p)
            {
                item.second = ph;
            }
        }
    }

    struct SortPerson
    {
        bool operator() (std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2)
        {
            return (p1.first < p2.first);
        }
    } custom_sortPerson;

    struct SortPhone
    {
        bool operator() (std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2)
        {
            return (p1.second < p2.second);
        }
    } custom_sortPhone;

    void SortByPhone()
    {
        std::sort(storage.begin(), storage.end(), custom_sortPhone);
    }
    void SortByName()
    {
        std::sort(storage.begin(), storage.end(), custom_sortPerson);
    }


    friend std::ostream& operator<< (std::ostream& out, const PhoneBook& phoneBook);

};
std::ostream& operator<< (std::ostream& out, PhoneBook& phoneBook)
{
    for (size_t i = 0; i < phoneBook.storage.size(); i++)
    {
        out << phoneBook.storage[i].first << " " << phoneBook.storage[i].second << std::endl;
    }
    return out;
}

class TestPhoneNumber : public testing::Test {
protected:
    PhoneNumber* phone;
    void SetUp() override {
        phone = new PhoneNumber{ 7, 911, "1234567" };
    }
    void TearDown() override {
        delete phone;
    }
    
};

class TestBook : public testing::Test {
protected:
    
    PhoneBook* book;
    void SetUp() override {
        std::ifstream file(DATA_FILE);
        book = new PhoneBook(file);
    }
    void TearDown() override {
        delete book;
    }

};


TEST_F(TestPhoneNumber, HasValue)
{
    ASSERT_EQ(phone->additional.has_value(), false);
}

TEST_F(TestPhoneNumber, AddAdditional)
{
    phone->additional = 12;
    ASSERT_EQ(phone->additional.has_value(), true);
}

TEST_F(TestBook, CheckSortByName)
{
    book->SortByName();
    ASSERT_EQ(book->storage[0].first.LastName, "Ivanov");
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    std::ifstream file(DATA_FILE);
    PhoneBook book(file);
    std::cout << book;
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;
    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;
    std::cout << "-----GetPhoneNumber-----" << std::endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона
    //человека, либо строку с ошибкой
    auto print_phone_number = [&book](const std::string& surname)
    {
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (std::get<0>(answer).empty())
            std::cout << std::get<1>(answer);
        else
            std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };
    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", std::nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;

    PhoneNumber testphone{ 7, 911, "1234567", 12 };
    std::cout << testphone << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
