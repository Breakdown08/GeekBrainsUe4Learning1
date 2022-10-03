#include <iostream>
#include <clocale>  
#include <sstream> // для stringstream
#include <optional>

struct Person
{
	std::string LastName;
	std::string FirstName;
	std::optional<std::string> Patronymic;
};
std::ostream& operator << (std::ostream& os, const Person& p)
{
	os << p.LastName << " " << p.FirstName;
	if (p.Patronymic)
	{
		os << " " << *p.Patronymic;
	}
	os << "/";
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

const std::string BINARY_FILE = "data.txt";

int main()
{
	setlocale(LC_ALL, "Russian");
	Person p;
	p.FirstName = "Кирилл";
	p.LastName = "Мищенко";
	p.Patronymic = "Александрович";
	std::cout << p << std::endl;
}