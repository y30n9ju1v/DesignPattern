// 5_다형성4.cpp

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void go() { cout << "Animal go" << endl; }
};

class Dog : public Animal {
public:
	// 1. 부모의 함수가 가상함수이면, 자식이 오버라이딩한 함수도 가상함수입니다.

	// 2. override: C++11
	//   : 부모가 제공하는 함수를 오버라이딩한 것인지 컴파일 체크 가능합니다.
	//   : 자식 클래스가 재정의하는 함수는 반드시 가상함수이어야 합니다.
	// virtual void go() override { cout << "Dog go" << endl; }
	void go() override { cout << "Dog go" << endl; }
};

int main()
{
	Animal* p = new Dog;
	p->go();
}
