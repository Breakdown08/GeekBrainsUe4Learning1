#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>
#include <ctime>

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
	std::ostream_iterator<T> out_it(std::cout, ", ");
	std::copy(vec.begin(), vec.end(), out_it);
	std::cout << std::endl;
}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

std::vector<double> InstanceDoubleVector(int min, int max)
{
	std::vector<double> vec;
	for (size_t i = 0; i < 5; i++)
	{
		vec.push_back(fRand(min, max));
	}
	return vec;
}

std::vector<int> DoubleToIntVector(const std::vector<double> doubleVec) 
{
	std::vector<int> intVec;
	std::transform(doubleVec.begin(), doubleVec.end(), std::back_inserter(intVec), [](double value) { return (int)value; });
	return intVec;
}

int main()
{
	srand(time(NULL));

	std::vector<double> doubleVec = InstanceDoubleVector(-50, 50);
	PrintVector(doubleVec);
	std::vector<int> intVec = DoubleToIntVector(doubleVec);
	PrintVector(intVec);
}
