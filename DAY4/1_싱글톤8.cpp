#include <iostream>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}









