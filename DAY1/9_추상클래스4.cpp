// 9_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스 문제점
// : 변화에 대응하기 어렵습니다.
struct MP3 {
	virtual ~MP3() {}

	virtual void Play() = 0;
	virtual void Stop() = 0;

	// 인터페이스: 기본 구현을 제공하자.
	virtual void PlayOneMinute()
	{
		Play();
		// 1분후
		Stop();
	}
};

class Person {
public:
	void PlayMusic(MP3* p) {
		// p->Play();
		p->PlayOneMinute();
		p->Stop();
	}


};

class Android : public MP3 {
public:
	void Play() override { cout << "Play Music" << endl; }
	void Stop() override { cout << "Stop Music" << endl; }
};

class Apple : public MP3 {
public:
	void Play() override { cout << "Play Music" << endl; }
	void Stop() override { cout << "Stop Music" << endl; }
};

int main()
{
	Person person;
	Apple apple;
	Android android;

	person.PlayMusic(&android);
	person.PlayMusic(&apple);
}