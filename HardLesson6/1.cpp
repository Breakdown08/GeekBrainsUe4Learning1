#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;

std::mutex coutMutex;

template <typename T>
void pcout(T data)
{
	coutMutex.lock();
	std::cout << data << std::endl;
	coutMutex.unlock();
}


void doSomething(int number) {
	while (true)
	{
		pcout(number);
		this_thread::sleep_for(1s);
	}
}
int main()
{
	thread th1(doSomething, 1);
	thread th2(doSomething, 2);
	thread th3(doSomething, 3);
	th1.join();
	th2.join();
	th3.join();
}