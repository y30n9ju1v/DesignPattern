// 4_생성자소멸자2.cpp
#include <iostream>

class Animal
{
// public:
protected:
	Animal(int age) {}
};

class Dog : public Animal {
public:
	Dog(int age) : Animal(age) {}

	Dog() : Animal(0) {}
};

// protected 생성자 의도: 자신은 만들 수 없지만(추상적 존재),
//                       자식 클래스는 만들 수 있게 하고 싶다.
//  MFC: CObject / Android: RefBase

int main()
{
	// Animal a(10);
	Dog b(20);
}