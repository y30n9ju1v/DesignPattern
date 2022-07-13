#include <iostream>

class Shape
{
	int data;
};

class X
{
	int x;
};

class C1 : public Shape, public X 
{
	int c1;
};
class C2 : public X, public Shape
{
	int c2;
};
int main()
{
	// 다중 상속이 좋지는 않지만 
	// C++, python :지원
	// C#, java    : 지원 안함(단 인터페이스의 경우 다중 상속가능)
	C1 c1;
	C2 c2;

	Shape* p1 = &c1;
	Shape* p2 = &c2;

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;

}