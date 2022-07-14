#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* sInstance;
public:
	static Cursor& getInstance()
	{
		mtx.lock();
		if (sInstance == nullptr)
		{
			sInstance = new Cursor;
		}
		mtx.unlock();
		return *sInstance;
	}
};
std::mutex Cursor::mtx;
Cursor* Cursor::sInstance = nullptr;




int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








