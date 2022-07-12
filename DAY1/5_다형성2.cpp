// 5_다형성2.cpp
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
	int getAge() const { return 10; }
};

class Dog : public Animal {};
class Cat : public Animal {};

// 1. 동종을 처리하는 함수를 만들 수 있습니다.
int GetAge(Animal* p)
{
	return p->getAge();
}

int main()
{
	vector<Dog*> dogs;
	vector<Cat*> cats;

	// 2. 동종을 보관하는 컨테이너를 사용할 수 있습니다.
	vector<Animal*> animals;


	Dog d; Cat c;
	cout << GetAge(&d) << endl;
	cout << GetAge(&c) << endl;
}




#if 0
class Dog {
public:
	int getAge() const { return 10; }
};

class Cat {
public:
	int getAge() const { return 20; }
};

int GetAge(Dog* p)
{
	return p->getAge();
}

int GetAge(Cat* p)
{
	return p->getAge();
}
#endif