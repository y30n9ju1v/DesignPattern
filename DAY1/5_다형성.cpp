// 5_다형성.cpp
#include <iostream>
using namespace std;

class Animal {

};

class Dog : public Animal {

};

// 1. Upcasting
// 2. is-a
//     자식 클래스 is a 부모 클래스
// 3. Upcasting은 public 상속에서만 허용됩니다.
int main()
{
	Animal a; Dog d;

	// 부모의 포인터 타입을 통해 자식 객체의 주소를 담을 수 있습니다.
	Animal* p = &d;

	// 부모의 포인터 타입을 자식의 포인터 타입으로의 암묵적인 변환을 허용하지 않습니다.
	// => 명시적인 캐스팅이 필요합니다.
	Dog* p2 = static_cast<Dog*>(p);
}