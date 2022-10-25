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

std::vector<double> InstanceDoubleVector(int min, int max, int size = 100)
{
	std::vector<double> vec(size);
	std::generate(vec.begin(), vec.end(), [min, max]() { return fRand(min, max); });
	return vec;
}

std::vector<int> DoubleToIntVector(const std::vector<double> doubleVec)
{
	std::vector<int> intVec;
	std::transform(doubleVec.begin(), doubleVec.end(), std::back_inserter(intVec), [](double value) { return (int)value; });
	return intVec;
}

double CountError(const std::vector<double>& a, const std::vector<int>& b)
{
	double sum = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		sum += pow((a[i] - b[i]), 2);
	}
	return sum;
}

int main()
{
	srand(time(NULL));
	std::vector<double> doubleVec = InstanceDoubleVector(-50, 50, 100);
	// PrintVector(doubleVec);
	std::vector<int> intVec = DoubleToIntVector(doubleVec);
	// PrintVector(intVec);
	std::cout << CountError(doubleVec, intVec) << std::endl;
}
