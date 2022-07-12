#include <iostream>
using namespace std;

// 1. 가상 함수를 가지는 모든 객체의 크기는 포인터 크기(8바이트)만큼 추가됩니다.
// 2. 가상 함수 테이블을 가리키는 포인터입니다.
// 3. 가상 함수 비용
//   1) 객체의 크기가 포인터 크기만큼 증가합니다. (가상함수 테이블 포인터)
//   2) 가상 함수 테이블 크기는 가상 함수의 개수에 의해 결정됩니다.
//      "가상함수의 개수" * "멤버 함수 포인터" * 타입

class Animal {
	int age;
	int color;
public:
	virtual void go() {}
	virtual void foo() {}
};

class Dog : public Animal {
	int gender;
public:
	void go() override {}
};

int main()
{
	cout << sizeof(Animal) << endl; // 8 -> 16

	Animal* p = new Dog;
	p->go();  // (p->vptr)[0]();

	p->foo(); // (p->vptr)[1]();
}