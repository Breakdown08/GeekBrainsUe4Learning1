#include <iostream>
#include <cstdint>

class Power
{
public:
	void Set(double n1, double n2)
	{
		d1 = n1;
		d2 = n2;
	}
	void Calculate()
	{
		std::cout << pow(d1, d2) << std::endl;
	}
private:
	double d1 = { 1.4 };
	double d2 = { 2.6 };
};

class RGBA
{
public:
	RGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
	{
		m_red = r;
		m_green = g;
		m_blue = b;
		m_alpha = a;
	}
	std::uint8_t m_red = { 0 };
	std::uint8_t m_green = { 0 };
	std::uint8_t m_blue = { 0 };
	std::uint8_t m_alpha = { 255 };

	void Print()
	{
		std::cout << "( " << (int)m_red << ", " << (int)m_green << ", " << (int)m_blue << ", " << (int)m_alpha << " )" << std::endl;
	}
};

class Stack
{
public:
	void reset()
	{
		for (size_t i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
		size = 0;
	}
	bool push(int n)
	{
		if (size < 10)
		{
			arr[size] = n;
			size++;
			return true;
		}
		else
			return false;
	}
	void pop()
	{
		if (size <= 0)
		{
			std::cout << "STACK IS EMPTY!!!";
		}
		else
		{
			arr[size - 1] = 0;
			size--;
		}

	}
	void print()
	{
		std::cout << "(";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i];
			if (i < size - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << ")" << std::endl;
	}

private:
	size_t size = 0;
	int arr[10];
};

int main()
{
	//------------------1------------------------
	Power p;
	p.Calculate();
	p.Set(2, 5);
	p.Calculate();
	std::cout << "----------------" << std::endl;
	//------------------2------------------------
	RGBA rgba(111, 86, 32, 220);
	rgba.Print();
	std::cout << "----------------" << std::endl;
	//------------------3------------------------
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
}