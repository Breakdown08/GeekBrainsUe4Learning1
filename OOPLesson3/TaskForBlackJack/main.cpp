#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

enum class TSuit
{
	CLUBS, //КРЕСТИ
	DIAMONDS, //БУБИ
	HEARTS, //ЧЕРВИ
	SPADES //ПИКИ
};

enum class TCardValue : int
{
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10
};

class Card
{
public:
	TSuit suit;
	TCardValue value;
	bool isOpened = false;

	Card()
	{

	}

	void Flip()
	{
		isOpened = !isOpened;
	}

	int GetValue()
	{
		return (int)value;
	}
};

int main()
{
	Card someCard;
	someCard.value = TCardValue::ACE;
	someCard.suit = TSuit::SPADES;
	cout << someCard.isOpened << endl;
	someCard.Flip();
	cout << someCard.isOpened << endl;
	someCard.Flip();
	cout << someCard.isOpened << endl;
	someCard.Flip();
	cout << someCard.isOpened << endl;
	cout << endl << endl;
	cout << someCard.GetValue() << endl;
}