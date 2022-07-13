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
	// C++, python : 지원
	// C#, java    : 지원 안함(단 인터페이스의 경우 다중 상속가능)
	C1 c1;
	C2 c2;
	Shape* p1 = &c1;
//	Shape* p2 = &c2; // (char*)&c2 + sizeof(1번째기반 클래스 X);

	// 상속관계 고려 하지 말고, 무조건 &c2 주소를 Shape* 에 담겠다는 의도
	// 강제적변환(reinterpret - 다시 해석하겠다)
	Shape* p2 = reinterpret_cast<Shape*>(&c2);

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;

}