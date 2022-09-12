#include <iostream>
#include <cstdint>
#include <string>

#define PI 3.14159265

using namespace std;

class Figure
{
	virtual double area() = 0;
};

class Parallelogram : Figure
{
private:
	double angle;
public:
	Parallelogram()
	{

	}
	Parallelogram(double _a, double _b, double _angle)
	{
		width = _a;
		height = _b;
		angle = _angle;
	}
	Parallelogram(double _width, double _height)
	{
		width = _width;
		height = _height;
	}
	double width, height;
	double area() override
	{
		return width * height * sin(angle * PI/180);
	}
};

class Rectangle : Parallelogram
{
public:
	Rectangle(double _width, double _height) : Parallelogram(_width, _height)
	{

	}
	double area() override
	{
		return width * height;
	}
};

class Square : Parallelogram
{
public:
	Square(double side)
	{
		width = side;
	}
	double area() override
	{
		return width * width;
	}
};
class Rhombus : Parallelogram
{
private:
	double diag1, diag2;
public:
	Rhombus(double d1, double d2) : Parallelogram(d1, d2)
	{
		diag1 = d1;
		diag2 = d2;
	}
	double area() override
	{
		return (diag1 * diag2) / 2;
	}
};

class Circle : Figure
{
private:
	const double pi = 3.14;
	double radius;
public:
	Circle(double _radius)
	{
		radius = _radius;
	}

	double area() override
	{
		return pi * (radius * radius);
	}
};


class Car
{
public:
	string company;
	string model;
public:
	Car()
	{
		cout << "DEFAULT BASE CONSTRUCTOR" << endl;
	}
	Car(string company, string model)
	{
		this->company = company;
		this->model = model;
		cout << "BASE CONSTRUCTOR WITH ARGS" << endl;
	}
};
class PassengerCar : virtual public Car
{
public:
	PassengerCar()
	{
		cout << "DEFAULT PASSANGER CAR CONSTRUCTOR" << endl;
	}
	PassengerCar(string company, string model) : Car(company, model)
	{
		cout << "PASSANGER CAR CREATED" << endl;
	}
};
class Bus : virtual public Car
{
public:
	Bus()
	{
		cout << "DEFAULT BUS CONSTRUCTOR" << endl;
	}
	Bus(string company, string model) : Car(company, model)
	{
		cout << "BUS CREATED" << endl;
	}
};
class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(string company, string model) : Car(company, model)
	{
		cout << "MINIVAN CREATED" << endl;
	}
};


class Fraction
{
private:
	int numerator, denominator;
	Fraction Swap()
	{
		Fraction fr;
		fr.numerator = this->denominator;
		fr.denominator = this->numerator;
		return fr;
	}

public:
	Fraction() = default;
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		if (denominator == 0)
		{
			this->denominator = 1;
		}
		else
		{
			this->denominator = denominator;
		}
	}
	Fraction operator-() const
	{
		return Fraction(-numerator, denominator);
	}
	friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
	friend Fraction operator- (const Fraction& f1, const Fraction& f2);
	friend Fraction operator* (const Fraction& f1, const Fraction& f2);
	friend Fraction operator/ (const Fraction& f1, const Fraction& f2);

	bool operator==(const Fraction f)
	{
		Fraction thisFr = Reduce();
		Fraction fr = f.Reduce();
		int totalDenominator = thisFr.denominator * fr.denominator;
		thisFr.numerator = thisFr.numerator * (totalDenominator / thisFr.denominator);
		fr.numerator = fr.numerator * (totalDenominator / fr.denominator);
		if (thisFr.numerator == fr.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Fraction f)
	{
		if (!operator==(f))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Fraction f)
	{
		Fraction thisFr = Reduce();
		Fraction fr = f.Reduce();
		int totalDenominator = thisFr.denominator * fr.denominator;
		thisFr.numerator = thisFr.numerator * (totalDenominator / thisFr.denominator);
		fr.numerator = fr.numerator * (totalDenominator / fr.denominator);
		if (thisFr.numerator > fr.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Fraction f)
	{
		if (!operator>(f))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(const Fraction f)
	{
		Fraction thisFr = Reduce();
		Fraction fr = f.Reduce();
		int totalDenominator = thisFr.denominator * fr.denominator;
		thisFr.numerator = thisFr.numerator * (totalDenominator / thisFr.denominator);
		fr.numerator = fr.numerator * (totalDenominator / fr.denominator);
		if (thisFr.numerator < fr.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const Fraction f)
	{
		if (!operator<(f))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Fraction Reduce() const
	{
		int _numerator = numerator;
		int _denominator = denominator;
		for (size_t i = abs(denominator) - 1; i >= 2; i--)
		{
			if (numerator % i == 0 && denominator % i == 0)
			{
				_numerator = numerator / i;
				_denominator = denominator / i;
				break;
			}
		}
		return Fraction(_numerator, _denominator);
	}
	void Print() const
	{
		cout << numerator << "/" << denominator << endl;
	}
	void ReducedPrint() const
	{
		Fraction fr;
		fr = this->Reduce();
		cout << fr.numerator << "/" << fr.denominator << endl;
	}
};

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	int totalDenominator;
	if (f1.denominator != f2.denominator)
	{
		totalDenominator = f1.denominator * f2.denominator;
	}
	else
	{
		totalDenominator = f1.denominator;
	}
	return Fraction(f1.numerator * (totalDenominator / f1.denominator) + f2.numerator * (totalDenominator / f2.denominator), totalDenominator).Reduce();
}
Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	int totalDenominator;
	if (f1.denominator != f2.denominator)
	{
		totalDenominator = f1.denominator * f2.denominator;
	}
	else
	{
		totalDenominator = f1.denominator;
	}
	return Fraction(f1.numerator * (totalDenominator / f1.denominator) - f2.numerator * (totalDenominator / f2.denominator), totalDenominator).Reduce();
}
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator).Reduce();
}
Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	Fraction swapFr = f2;
	swapFr = swapFr.Swap();
	return Fraction(f1.numerator * swapFr.numerator, f1.denominator * swapFr.denominator).Reduce();
}


int main()
{
	//--------------------------1---------------------------------
	Parallelogram par(10, 8, 30);
	cout << par.area() << endl;
	Rectangle rec(2, 3);
	cout << rec.area() << endl;
	Square sqr(3);
	cout << sqr.area() << endl;
	Circle circ(3);
	cout << circ.area() << endl;
	Rhombus rmb(3, 5);
	cout << rmb.area() << endl;
	//--------------------------2---------------------------------
	cout << endl;
	Minivan m("SOME_COMPANY", "SUPER_MINIVAN");
	//--------------------------3---------------------------------
	cout << endl;
	Fraction fr1(3, 5);
	Fraction fr2(4, 9);
	Fraction frSum = fr1 + fr2;
	Fraction frExt = fr1 - fr2;
	Fraction frDiv = fr1 / fr2;
	Fraction frMult = fr1 * fr2;
	frSum.Print();
	frExt.Print();
	frDiv.Print();
	frMult.Print();
	Fraction fr3(20, 40);
	Fraction fr4(5, 10);
	cout << (fr3 > fr4) << endl;
	cout << (fr3 < fr4) << endl;
	cout << (fr3 >= fr4) << endl;
	cout << (fr3 <= fr4) << endl;
	cout << (fr3 == fr4) << endl;
	cout << (fr3 != fr4) << endl;
}