#include <iostream>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;



	static Cursor* sInstance;
public:
	static Cursor& getInstance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new Cursor;
		}
		return *sInstance;
	}
};
Cursor* Cursor::sInstance = nullptr;




int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








