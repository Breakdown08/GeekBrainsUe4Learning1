#include <iostream>
#include <string>

using namespace std;

template <class T>
class Pair1
{
private:
	T first;
	T second;
public:
	Pair1(T _first, T _second)
	{
		first = _first;
		second = _second;
	}
	T First() const
	{
		return first;
	}
	T Second() const
	{
		return second;
	}
};

template <class T1, class T2>
class Pair
{
protected:
	T1 first;
	T2 second;
public:
	Pair(T1 _first, T2 _second)
	{
		first = _first;
		second = _second;
	}
	Pair()
	{
		
	}
	T1 First() const
	{
		return first;
	}
	T2 Second() const
	{
		return second;
	}
};

template <class T>
class StringValuePair : public Pair<string, T>
{
public:
	StringValuePair(string s, T _type) : Pair<string, T>(s, _type){}
};


int main(int argc, char* argv[])
{
	//--------------------------1--------------------------------
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.First() << ' ' << p1.Second() << '\n';
	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.First() << ' ' << p2.Second() << '\n';
	//--------------------------2--------------------------------
	Pair<int, double> pp1(6, 7.8);
	cout << "Pair: " << pp1.First() << ' ' << pp1.Second() << '\n';
	const Pair<double, int> pp2(3.4, 5);
	cout << "Pair: " << pp2.First() << ' ' << pp2.Second() << '\n';
	//--------------------------3--------------------------------
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.First() << ' ' << svp.Second() << '\n';

	return 0;
}