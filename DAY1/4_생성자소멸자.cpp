// 4_생성자소멸자.cpp
#include <iostream>
using namespace std;

class Base {
public:
	// Base() { cout << "Base()" << endl; } => 기본 생성자
	Base(int) { cout << "Base(int)" << endl; }

	~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:

	// 정확한 원리: 자식의 생성자의 앞부분(초기화리스트)에 부모의 생성자를 호출하는 기계어 코드를
	//            컴파일러가 생성해줍니다.
	//   > 부모가 기본 생성자를 제공하지 않을 경우, 명시적으로 부모의 생성자를 호출해야 합니다.
	Derived() : Base(42)
	{ cout << "Derived()" << endl; }
	
	// 자식의 소멸자의 마지막 부분에 부모의 소멸자를 호출하는 기계어 코드를 컴파일러가 생성해줍니다.
	~Derived() 
	{
		cout << "~Derived()" << endl;
		// Base::~Base()
	}
};

// Base()
// Derived()
// ~Derived()
// ~Base()

int main()
{
	Derived d;
	// Deribed::Derived()
}