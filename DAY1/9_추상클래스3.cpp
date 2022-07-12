// 9_추상클래스3.cpp
#include <iostream>
using namespace std;

// 객체 지향 5대 원칙
//  => SOLID
//  1) SRP(Single Reponsibility Principle)
//    - 단일 책임의 원칙
// 
//  2) OCP(Open Close Principle)
//    - 개방 폐쇄의 원칙
// 
//  3) LSP(Liskov Substitution Principle)
//    - 리스코프 치환 원칙
//    : 자식의 공통된 기능은 부모로부터 비롯되어야 한다.
// 
//  4) ISP(Interface Segregation Principle)
//    - 인터페이스 분리 원칙
//    : 범용 인터페이스보다는 세분화된 인터페이스가 좋다.
// 
//  5) DIP(Dependency Inversion Principle)
//    - 의존 관계 역전 원칙
//    : 클라이언트는 구체적인 타입을 직접 이용하는 것이 아니라
//      추상 개념에 의존해야 한다.

// 1. Camera
//    카메라 사용자와 카메라 제작자 사이의 규칙을 먼저 설계해야 합니다.
//   => 인터페이스, 프로토콜
//   => 교체 가능한 유연한 설계!
//   => OCP(Open Close Principle, 개방 폐쇄 원칙) 만족합니다.
//    : 확장에는 열려 있어야 하고, 수정에는 닫혀 있어야 한다.
//     - "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다" 원칙


struct ICamera {
	virtual ~ICamera() {}

	virtual void StartRecording() = 0;
	virtual void StopRecording() = 0;
};

// 2. 진짜 카메라는 존재하지 않지만, 규칙대로만 사용하면 됩니다.
class Car {
	ICamera* camera;
public:
	Car(ICamera* p) : camera(p) {}

	void Go()
	{
		camera->StartRecording();

		camera->StopRecording();
	}
};

// 3. 모든 카메라는 반드시 ICamera의 인터페이스를 구현해야 합니다.
// "인터페이스는 상속한다 라고 하지않고 인터페이스를 구현한다"라고 합니다.
class Camera : public ICamera {
public:
	void StartRecording() override
	{
		cout << "Start Recording" << endl;
	}

	void StopRecording() override
	{
		cout << "Stop Recording" << endl;
	}
};

class HDCamera : public ICamera {
public:
	void StartRecording() override
	{
		cout << "Start Recording" << endl;
	}

	void StopRecording() override
	{
		cout << "Stop Recording" << endl;
	}
};

int main()
{
	HDCamera camera;
	Car car(&camera);

	car.Go();
}
