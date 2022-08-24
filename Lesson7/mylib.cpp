#include <iostream>
namespace MyLib 
{
	void PrintArray(const float arr[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	void InitArray(float arr[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = (float)rand() / (RAND_MAX + 1) * (100 - -100);
		}
	}
	void CountArray(const float arr[], int size)
	{
		int positive = 0;
		int negative = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] >= 0)
			{
				positive += 1;
			}
			else negative = 1;
		}
		std::cout << "positive values: " << positive << " negative values: " << negative << std::endl;
	}
}