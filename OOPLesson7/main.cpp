#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	void SetDay(int day)
	{
		this->day = day;
	};
	void SetMonth(int month)
	{
		this->month = month;
	};
	void SetYear(int year)
	{
		this->year = year;
	};
	Date(int day, int month, int year) : day(day), month(month), year(year) {}
	Date()
	{

	}
	int Day()
	{
		return day;
	};
	int Month()
	{
		return month;
	};
	int Year()
	{
		return year;
	};
	friend ostream& operator<< (ostream& out, Date* date);
};
ostream& operator<< (ostream& out, Date* date)
{
	out << date->Day() << "." << date->Month() << "." << date->Year();
	return out;
}

void SwapDate(shared_ptr<Date>& ptr1, shared_ptr<Date>& ptr2)
{
	std::shared_ptr<Date> temp = std::make_shared<Date>(ptr1->Day(), ptr1->Month(), ptr1->Year());
	ptr1 = std::move(ptr2);
	ptr2 = std::move(temp);
}

shared_ptr<Date> OlderDate(shared_ptr<Date>& d1, shared_ptr<Date>& d2)
{
	if (d2->Year() >= d1->Year())
	{
		if (d2->Month() >= d1->Month())
		{
			if (d2->Day() >= d1->Day())
			{
				return d2;
			}
			else
			{
				return d1;
			}
		}
		else if (d2->Day() >= d1->Day())
		{
			return d2;
		}
		else
		{
			return d1;
		}
	}
	else if (d2->Month() >= d1->Month())
	{
		if (d2->Day() >= d1->Day())
		{
			return d2;
		}
		else
		{
			return d1;
		}
	}
	else if (d2->Day() >= d1->Day())
	{
		return d2;
	}
	else
	{
		return d1;
	}
}

int main()
{
	//------------------------1--------------------------------------
	std::shared_ptr<Date> today = std::make_shared<Date>(25,9,2022);
	cout << today << endl;
	std::shared_ptr<Date> date = std::move(today);
	cout << date << endl;
	if (today == nullptr)
	{
		cout << "today is NULL" << endl;
	}
	if (date == nullptr)
	{
		cout << "!!!!" << endl;
	}
	//------------------------2--------------------------------------
	std::shared_ptr<Date> date1 = std::make_shared<Date>(25, 9, 2022);
	std::shared_ptr<Date> date2 = std::make_shared<Date>(1, 10, 2022);
	cout << date1 << endl;
	cout << date2 << endl;

	cout << endl;

	std::swap(date1, date2);
	cout << date1 << endl;
	cout << date2 << endl;

	cout << endl;

	SwapDate(date1, date2);
	cout << date1 << endl;
	cout << date2 << endl;

	cout << endl << endl;
	cout << OlderDate(date1, date2) << endl;
}