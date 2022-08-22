#include <iostream>
#include <fstream>
#include <string>

void PrintArr(int*& arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}	
void PrintArr(int**& arr, int m, int n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void FullArr(int*& arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = pow(2, i);
	}
}
void FullArr(int**& arr, int m, int n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			arr[i][j] = rand();
		}
	}
}
void AllocateMemory(int**& arr, int m, int n)
{
	if ((n > 0) && (m > 0))
	{
		arr = new (std::nothrow) int *[m];
		for (size_t i = 0; i < m; i++) 
		{
			arr[i] = new int[n];
		}
	}
}
void AllocateMemory(int*& arr, int n)
{
	if (n > 0)
	{
		arr = new (std::nothrow) int [n];
	}
}
void CleanMemory(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}
void CleanMemory(int**& arr, int m)
{
	for (size_t i = 0; i < m; i++) 
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}


int main()
{
	//-------------------1-----------------------------
	int* ptrArr = nullptr;
	int n;
	std::cout << "enter size array:";
	std::cin >> n;
	AllocateMemory(ptrArr, n);
	if (ptrArr != nullptr) 
	{
		FullArr(ptrArr, n);
		PrintArr(ptrArr, n);
		CleanMemory(ptrArr);
		std::cout << ptrArr << std::endl;
	}
	//--------------------2----------------------------
	int** matrixArr;
	const size_t mm = 4;
	const size_t nn = 4;
	AllocateMemory(matrixArr, mm, nn);
	FullArr(matrixArr, mm, nn);
	PrintArr(matrixArr, mm, nn);
	CleanMemory(matrixArr, mm);
	//---------------------3---------------------------
	std::string f1, f2;
	std::string text1 = "ornare arcu dui vivamus arcu felis bibendum ut tristique et egestas quis ipsum suspendisse ultrices gravida dictum fusce ut placerat orci nulla pellentesque dignissim enim sit amet venenatis urna cursus eget nunc scelerisque viverra mauris in aliquam sem fringilla ut morbi tincidunt augue interdum velit euismod in pellentesque massa placerat duis ultricies lacus sed turpis tincidunt id aliquet risus feugiat in ante metus dictum at tempor commodo ullamcorper a lacus vestibulum sed arcu non odio euismod lacinia at quis risus sed vulputate odio ut enim blandit volutpat maecenas volutpat blandit aliquam etiam erat velit scelerisque in dictum non consectetur a";
	std::string text2 = "nibh tellus molestie nunc non blandit massa enim nec dui nunc mattis enim ut tellus elementum sagittis vitae et leo duis ut diam quam nulla porttitor massa id neque aliquam vestibulum morbi blandit cursus risus at ultrices mi tempus imperdiet nulla malesuada pellentesque elit eget gravida cum sociis natoque penatibus";
	std::cout << "Enter first filename:";
	std::cin >> f1;
	std::cout << "Enter second filename:";
	std::cin >> f2;
	f1 += ".txt";
	f2 += ".txt";
	std::ofstream fout1(f1);
	fout1 << text1 << std::endl;
	fout1.close();
	std::ofstream fout2(f2);
	fout2 << text2 << std::endl;
	fout2.close();
	//----------------------4---------------------------
	std::string result;
	std::ifstream fin1(f1);
	if (fin1.is_open())
	{
		std::string buf;
		while (!fin1.eof())
		{
			std::getline(fin1, buf);
			std::cout << buf << std::endl;
			result += buf;
		}
		fin1.close();
	}
	result += "\n";
	std::ifstream fin2(f2);
	if (fin2.is_open())
	{
		std::string buf;
		while (!fin2.eof())
		{
			std::getline(fin2, buf);
			std::cout << buf << std::endl;
			result += buf;
		}
		fin2.close();
	}
	std::string concatfilename;
	std::cout << "Enter concat filename:";
	std::cin >> concatfilename;
	concatfilename += ".txt";
	std::ofstream fout3(concatfilename);
	fout3 << result << std::endl;
	fout3.close();
	//----------------------5-------------------------
	std::string filename, wordToFind;
	std::cout << "Input filename to find a word:" << std::endl;
	std::cin >> filename;
	std::cout << "Input your word to find:" << std::endl;
	std::cin >> wordToFind;
	std::ifstream fread(filename);
	if (fread.is_open())
	{
		std::string buf;
		while (!fread.eof())
		{
			std::getline(fread, buf);
			if (buf.find(wordToFind) != std::string::npos)
			{
				std::cout << "FILE CONTAINS A WORD: " << wordToFind << std::endl;
				break;
			}
		}
		fread.close();
	}
}