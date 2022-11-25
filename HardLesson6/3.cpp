#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <time.h>
#include <random>
#include <ctime>
using namespace std;


int intRand(int max)
{
	return rand() % max;
}


void CheckHouse(const vector<int>& source)
{
	for (auto item : source)
	{
		cout << item << " ";
	}
	cout << endl;
}

int FindExpensiveItemPosition(vector<int>& source)
{
	int max = 0;
	int position = 0;
	for (size_t i = 0; i < source.size(); i++)
	{
		if (max < source[i])
		{
			max = source[i];
			position = i;
		}
	}
	return position;
}

void bringItemToHome(vector<int>& source) {
	while (true)
	{
		this_thread::sleep_for(1s);
		source.push_back(intRand(100));
		CheckHouse(std::ref(source));
	}
}

void stealItemFromHome(vector<int>& source) {
	while (true)
	{
		this_thread::sleep_for(0.5s);
		int position = FindExpensiveItemPosition(std::ref(source));
		if (source.size() != 0)
		{
			source.erase(source.begin() + position);
		}
	}
}

int main()
{
	srand(time(NULL));
	vector<int> houseItems = { 1, 11, 3, 4, 2 };
	thread thief(stealItemFromHome, std::ref(houseItems));
	thread owner(bringItemToHome, std::ref(houseItems));
	thief.join();
	owner.join();
}