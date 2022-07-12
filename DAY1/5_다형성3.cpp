// 5_다형성3.cpp
#include <iostream>
using namespace std;

class Animal {
public:
	virtual void go() { cout << "Animal go" << endl; } // 1
};

class Dog : public Animal {
public:
	// 부모가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.
	// : 함수 오버라이딩
	virtual void go()
	{
		cout << "Dog go" << endl; // 2
	}
};

// Animal* p = ...;
// p->go();
// => 함수 바인딩
//   : 어떤 함수를 호출할지 결정하는 것

// 1) 정적 바인딩(static binding)
//  : 컴파일러가 p의 타입을 보고, 컴파일 타임에 결정하는 것
//  => 컴파일러가 결정하기 때문에, 인라인화가 가능하기 때문에 빠릅니다.
// 
// 2) 동적 바인딩(dynamic binding)
//  : 컴파일러가 p가 실행시간에 어떤 변수의 타입을 가지고 있는지 조사하는 코드를 삽입하고,
//    실행시간에 변수의 타입에 기반해서 함수를 호출하는 것
//  => 인라인화가 불가능하기 때문에, 상대적으로 호출이 느립니다.

int main()
{
	Animal a; Dog d;
	Animal* p = &a;
	p->go();

	p = &d;
	p->go();
}


#if 0
int main()
{
	Animal a;
	a.go();   // 1

	Dog d;
	d.go();   // 2
}
#endif