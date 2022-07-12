// 1_thiscall.cpp

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	// void set(Point* const this, int a, int b)
	void set(int a, int b)
	{	
		// int c = a + b;

		x = a;  // this->x = a;
		y = b;  // this->y = b;
	}	

	// 정적 멤버 함수: 객체를 생성하지 않아도 호출이 가능합니다.
	//   - this가 전달되지 않습니다.
	static void foo(int a)
	{
		// x = a;   // this->x = a; 가 되어야 하는데, this가 없습니다.
	}
};

int main()
{
	Point p1, p2;

	p1.set(10, 20);  // Point::set(&p1, 10, 20)
	p2.set(30, 40);  // Point::set(&p2, 10, 20)



}