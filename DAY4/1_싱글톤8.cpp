#include <iostream>

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor()" << std::endl;
	}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance; // error. 이 코드는 에러 지만
	static Cursor instance;  // 이 코드는 에러 아닙니다.

public:
	static Cursor& getInstance()
	{
//		static Cursor instance; // 이 코드는 
								// 이 함수가 처음 실행될때 생성자가 호출됩니다.
		return instance;
	}
};
Cursor Cursor::instance;

int main()
{
//	Cursor& c1 = Cursor::getInstance();
//	Cursor& c2 = Cursor::getInstance();

}









