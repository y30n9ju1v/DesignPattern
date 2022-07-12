// 9_추상클래스.cpp
#include <iostream>
using namespace std;

// 추상 클래스
//  : 순수 가상 함수를 1개 이상 가지고 있는 클래스
//  > 인스턴스화가 불가능합니다.
class Animal {
public:
	virtual ~Animal() {}

	// 부모 입장에서는 구현을 제공할 필요가 없고,
	// 자식 클래스가 반드시 오버라이딩 해야 하는 함수는 
	// "순수 가상 함수"가 좋습니다.
	virtual void cry() = 0;
};

// 부모가 제공하는 순수 가상함수를 재정의하지 않으면, 
// 자식 클래스도 추상 클래스입니다.
class Dog : public Animal {
public:
	void cry() override {}
};

class Camera {
//	int age;
public:
	virtual ~Camera() {}

	virtual void Take() = 0;

//	int GetAge() const { return age; }
};

int main()
{
	// Animal a;
	Dog d;

}