#include <iostream>
#include <fstream>
#include <string>
#include "mylib.h"

#define CheckValue(a, b) ( (a) >= 0 && (a) < (b) ? "TRUE" : "FALSE" )
#define ARRAY_SIZE 5
#define SwapINT(a, b) (temp) = (a); (a) = (b); (b) = (temp);

void PrintIntArray(const int arr[], int size)
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void BubbleSort(int arr[], int size)
{
	int temp;
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				SwapINT(arr[j], arr[j + 1])
			}
		}
	}
}
#pragma pack(push,1)
struct Employee
{
	int Id;
	char LastName[128];
	char FirstName[128];
	char Patronymic[128];
	char State[64];
	char Sex;
	int Age;
	double Salary;
};
const char BINARY_FILE[9] = "dump.bin";
#pragma pack(pop)
int main()
{
	//-------------1----------------------
	float arr[4];
	MyLib::InitArray(arr, 4);
	MyLib::PrintArray(arr, 4);
	MyLib::CountArray(arr, 4);
	//-------------2----------------------
	std::cout << CheckValue(-1, 3) << std::endl;
	//-------------3----------------------
	int intArr[ARRAY_SIZE] = { 1, 3, 5, 7, 9 };
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "Set element arr[" << i << "]:";
		std::cin >> intArr[i];
	}
	PrintIntArray(intArr, ARRAY_SIZE);
	BubbleSort(intArr, ARRAY_SIZE);
	PrintIntArray(intArr, ARRAY_SIZE);
	//-------------4-----------------------
	Employee emp = {1235, "Ivanov", "Ivan", "Ivanovich", "Manager", 'M', 34, 56000};
	Employee empForRead = {0};
	std::cout << sizeof(emp) << std::endl;
	std::ofstream stream(BINARY_FILE, std::ios_base::binary);
	if (stream.is_open())
	{
		stream.write((char*)&emp, sizeof(emp));
		stream.close();
	}
	std::ifstream stream2(BINARY_FILE, std::ios_base::binary);
	if (stream2.is_open())
	{
		stream2.read((char*)&empForRead, sizeof(empForRead));
		stream2.close();
	}
	std::cout << empForRead.Id << std::endl;
	std::cout << empForRead.LastName << std::endl;
	std::cout << empForRead.FirstName << std::endl;
	std::cout << empForRead.Patronymic << std::endl;
	std::cout << empForRead.Age << std::endl;
	std::cout << empForRead.Sex << std::endl;
	std::cout << empForRead.State << std::endl;
	std::cout << empForRead.Salary << std::endl;
	std::cout << sizeof(empForRead) << std::endl;
}