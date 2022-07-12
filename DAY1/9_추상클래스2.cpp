// 9_추상클래스2.cpp
#include <iostream>
using namespace std;

class Camera {
public:
	void StartRecording() { cout << "Start Recording" << endl; }
	void StopRecording() { cout << "Stop Recording" << endl; }
};



class HDCamera {
public:
	void StartRecording() { cout << "Start Recording" << endl; }
	void StopRecording() { cout << "Stop Recording" << endl; }
};

// 1. Car 클래스는 Camera 클래스와 강한 결합이 형성되어 있습니다.
//  "강한 결합": 의존하는 클래스의 구체적인 타입을 사용합니다.
//  "약한 결합 / 느슨한 결합": 의존하는 클래스의 구체적인 타입이 아니라 추상 타입을 사용합니다.

class Car {
	HDCamera* camera;
public:
	Car(HDCamera* p) : camera(p) {}

	void Go()
	{
		camera->StartRecording();

		camera->StopRecording();
	}
};

int main()
{
	HDCamera camera;
	Car car(&camera);

	car.Go();
}