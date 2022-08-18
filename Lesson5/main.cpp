#include <iostream>


void PrintArray(double arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void PrintArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void Reverse(int a[], int n)
{
	if (n <= 1)
	{
		return;
	}
	else
	{
		int i = 0;
		int j = n - 1;
		while (i < j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			++i;
			--j;
		}
	}
}

void Shift(int a[], int n, int k)
{
		Reverse(a, n - k);
		Reverse(a + n - k, k);
		Reverse(a, n);
}



void FromOneToZero(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0)
			arr[i] = 1;
		else
			arr[i] = 0;
	}
}
void SetArrayValues(int arr[], int size, int step)
{
	arr[0] = 1;
	for (size_t i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + step;
	}
}
int arr3[8];
int arr4[5] = { 1, 2, 3, 4, 5 };

int main()
{
	const int SIZE = 5;
	double arr[SIZE] = { 2.2, 3.43, 3.36, 3.76, 2.221 };
	PrintArray(arr, SIZE);

	int arr2[10] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

	PrintArray(arr2, 10);
	FromOneToZero(arr2, 10);
	PrintArray(arr2, 10);

	SetArrayValues(arr3, 8, 3);
	PrintArray(arr3, 8);
	
	PrintArray(arr4, 5);
	Shift(arr4, 5, 2);
	PrintArray(arr4, 5);
}
