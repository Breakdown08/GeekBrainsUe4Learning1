#include <iostream>
#include <thread>
using namespace std;

int ReturnCalcValue(int& x)
{
	while (x <= 15485863)
	{
		x++;
	}
	return x;
}

void doCalc(int& x) 
{
	int localX = ReturnCalcValue(x);
}

void doPrint(const int& x)
{
	while (x <= 15485863)
	{
		cout << x << endl;
	}
}

int main()
{
	int i = 0;
	thread th1(doPrint, std::ref(i));
	thread th2(doCalc, std::ref(i));
	th1.join();
	th2.join();
}