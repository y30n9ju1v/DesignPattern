#include <iostream>
#include <thread>
#include <chrono>

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "start ctor" << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(10));

		std::cout << "end ctor" << std::endl;
	}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	static Cursor& getInstance()
	{
		std::cout << "start getInstance : " << std::this_thread::get_id()
			      << std::endl;

		static Cursor instance;

		std::cout << "end getInstance : " << std::this_thread::get_id()
			<< std::endl;
		return instance;
	}
};
int main()
{
	std::thread t1(&Cursor::getInstance);

	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::thread t2(&Cursor::getInstance);

	t1.join();
	t2.join();

}









