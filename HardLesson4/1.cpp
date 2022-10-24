#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void insert_sorted(std::vector<T>& vec, const T& item)
{
	vec.push_back(item);
	sort(vec.begin(), vec.end(), [](T& a, T& b) { return (a < b);});
}

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	int value = 5;
	std::vector<double> v1{ 0.45, 0.1, 0.27, 0.11124, 6.76 };
	std::vector<int> v2{ 3, 1, 8, 2 };
	insert_sorted(v1, static_cast<double>(value));
	insert_sorted(v2, value);
	PrintVector(v1);
	PrintVector(v2);

}