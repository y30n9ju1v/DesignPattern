// 8_RTTI.cpp
#include <iostream>
#include <string>
using namespace std;

// RTTI(Run Time Type Information)
//  : type_info 구조체는 가상 함수 테이블에 저장됩니다.
// 
// 1. type_info 구조체
// 2. typeid 연산자
//   1) 타입
//   2) 객체

class Animal {
public:
	 virtual ~Animal() {}
};

class Dog : public Animal {
public:
	int age = 10;
};

class Cat : public Animal {
public:
	string name = "Cat";
};

#if 0
int main()
{
	Animal* p = new Cat; //new Dog;

	// 가상 함수 테이블이 없으면 사용할 수 없습니다.
	Cat* p2 = dynamic_cast<Cat*>(p);
	cout << p2 << endl;
	if (p2) {
		cout << p2->name << endl;
	}


}
#endif

#if 0
int main()
{
	Animal* p = new Cat;

	// p가 Dog라면
	const type_info& t1 = typeid(Dog);  // 클래스
	const type_info& t2 = typeid(*p);   // 객체

	cout << t2.name() << endl;

	if (t1 == t2)
	{
		cout << "Dog 타입입니다.." << endl;
		Dog* p2 = static_cast<Dog*>(p);
		cout << p2->age << endl;
	}
	else if (typeid(*p) == typeid(Cat))
	{
		cout << "Cat 타입입니다.." << endl;

		Cat* p3 = static_cast<Cat*>(p);
		cout << p3->name << endl;
	}

	



}
#endif