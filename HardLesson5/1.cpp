#include <iostream>
#include <string>
#include <set>

using namespace std;

//multiset<string> words{ "5", "22", "5", "2", "3", "4", "22", "5", "1", "3"};
multiset<int> words{ 3, 2, 4, 3, 1, 22, 5 };

template <typename _iter>
void PrintUnique(_iter start, _iter end)
{
	_iter iter_i = start;
	_iter iter_j;
	size_t i = 0;
	size_t j;
	size_t _end = std::distance(start, end);
	while (i < _end)
	{
		size_t counter = 0;
		iter_j = start;
		j = 0;
		while (j < _end)
		{
			if (*iter_i == *iter_j)
			{
				counter++;
			}
			iter_j++;
			j++;
		}
		cout << *iter_i << " ";
		for (size_t c = 0; c < counter; c++) //пропускаем ровно столько, сколько встретилось число
		{
			iter_i++;
			i++;
		}
	}
	cout << endl;
}


int main()
{
	PrintUnique(words.begin(), words.end());
}
