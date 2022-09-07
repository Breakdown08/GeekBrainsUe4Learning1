#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

class Person
{
public:
	void SetName(string _name)
	{
		name = _name;
	}
	void SetAge(int _age)
	{
		age = _age;
	}
	void SetWeight(int _weight)
	{
		weight = _weight;
	}
	string GetSex()
	{
		if (isMale == true) return "male";
		else return "female";
	}
	virtual void Print()
	{
		cout << name << endl << age << endl << GetSex() << endl << weight << endl;
	}
private:
	string name;
	int age;
	bool isMale;
	int weight;
};

class Student : public Person
{
public:
	Student(int& counter)
	{
		counter++;
	}
	void SetYear(int value)
	{
		year = value;
	}
	void IncreaseYear()
	{
		year++;
	}
	void Print() override
	{
		Person::Print();
		cout << year << endl << endl;
	}
private:
	int year = 2020;
};

class Fruit
{
public:
	Fruit()
	{

	}
	Fruit(string _color)
	{
		color = _color;
	}
	string getName()
	{
		return name;
	}
	string getColor()
	{
		return color;
	}
protected:
	void SetName(string _name)
	{
		name = _name;
	}
	void SetColor(string _color)
	{
		color = _color;
	}
private:
	string name;
	string color;
};

class Apple : public Fruit
{
public:
	Apple(string value) :Fruit(value)
	{
		SetName("apple");
	}
	Apple() : Fruit("some color")
	{
		SetName("apple");
	}
};

class Banana : public Fruit
{
public:
	Banana(string value) :Fruit(value)
	{
		SetName("banana");
	}
	Banana() : Fruit("yellow")
	{
		SetName("banana");
	}
};

class GrannySmith : public Fruit
{
public:
	GrannySmith(string value) :Fruit(value)
	{
		SetName("Granny Smith apple");
	}
	GrannySmith() :Fruit("green")
	{
		SetName("Granny Smith apple");
	}
	
};

int main()
{
	//----------------1-------------------
	int counter = 0;
	Student s1(counter);
	s1.SetName("Student1");
	s1.SetAge(21);
	s1.SetWeight(70);
	s1.IncreaseYear();
	Student s2(counter);
	s2.SetName("Student2");
	s2.SetAge(22);
	s2.SetWeight(67);
	s2.SetYear(2024);
	Student s3(counter);
	s3.SetName("Student3");
	s3.SetAge(23);
	s3.SetWeight(54);
	s3.IncreaseYear();
	s3.IncreaseYear();

	s1.Print();
	s2.Print();
	s3.Print();
	cout << counter << endl << endl;

	cout << "----------------------------------------------------" << endl;
	//----------------2-------------------
	Apple a("red");
	Banana b;
	GrannySmith c;
	/*
	Код, приведенный выше, должен давать следующий результат :
	My apple is red.
	My banana is yellow.
	My Granny Smith apple is green.
	*/
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	//----------------3-------------------
	//В игре блек джек должен быть реализован класс карты с полями (значение, масть, скрыта/открыта)
	//Класс игрока с массивом карт (можно динамическим), полем имени, счетчиком очков своей колоды, кошельком,
	//От класса игрока может наследоваться непосредственно Живой игрок, Живой диллер, AI игрок, AI диллер чтобы какой то функционал и поля были базовые
	// а методы могли быть переопределены или расширены дополнительной логикой, таким образом можно будет играть в разные режимы игры и в разных ролях 
	//Класс игры возможно через синглтон отслеживающий текущих игроков (можно тоже в массиве если мы все таки говорим о нескольких игроках в одной сессии) и их счетчики, 
	// хранящий основную колоду раздаваемых карт (либо их можно отдать дилеру), 
	// реализующий методы прекращения игры и другие возможные события (например переходы хода)
	// в нем так же будут работать рандомайзеры, расчет денег, расчет очков у любых из сторон
	//------------------------------------
}