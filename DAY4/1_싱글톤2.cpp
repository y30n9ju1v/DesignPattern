#include <iostream>
// 싱글톤을 만드는 코드를 매크로로 제공 - "helper.h"
#define MAKE_SINGLETON(classname)						\
private:												\
	classname() {}										\
	classname(const classname&) = delete;				\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& getInstance()						\
	{													\
		static classname instance;						\
		return instance;								\
	}


class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
}








