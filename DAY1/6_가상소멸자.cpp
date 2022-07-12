// 6_가상소멸자.cpp

#include <iostream>
using namespace std;

class Animal {
public:
	Animal() { cout << "Animal()" << endl; }
	virtual ~Animal() { cout << "~Animal()" << endl; }
};
// 부모 클래스는 반드시 가상 소멸자가 제공되어야 합니다.

class Dog : public Animal {
public:
	Dog() { cout << "Dog()" << endl; }
	virtual ~Dog() { cout << "~Dog()" << endl; }
	// ~Dog() override { cout << "~Dog()" << endl; }
};

// 1. 부모의 포인터를 통해 자식의 소멸자가 제대로 호출되지 않는 문제가 발생합니다.
//   > 소멸자가 정적 바인딩을 하기 때문에 발생하는 이슈 입니다.
// 2. 소멸자도 동적 바인딩 기반으로 호출되어야 합니다.
//   > 가상 소멸자
// 3. 부모의 소멸자가 가상이면, 자식의 소멸자도 가상입니다.

#include <memory>

int main()
{
	Animal* p2 = new Dog;

	shared_ptr<Animal> p(p2);

	// Dog d;
	// Animal* p = new Dog;

	// delete p;
	// Animal::~Animal()
}