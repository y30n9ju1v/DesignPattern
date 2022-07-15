// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// Bridge 패턴
// => 구현과 추상(간접층, 사용자가 사용하는 계층) 을 분리하여
//    상호 독립된 update 가 가능하게 한다.

// 변화와 요청이 많다면, 계층을 늘리면 해결된다는 의도!


// MP3 장비의 인터페이스
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;

	virtual ~IMP3() {}
};

class IPod : public IMP3	// 애플의 아이팟
{
public:
	void Play() { cout << "Play MP3 with IPod" << endl; }
	void Stop() { cout << "Stop" << endl; }
};

// People이 IMP3 를 직접 사용하게 하지말고
// 간접층(추상층, 사용자입장에서의 interface)를 제공한다.

class MP3
{
	IMP3* impl; // 실제 구현을 가리키는 포인터
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr)
			impl = new IPod;
	}
	void Play() { impl->Play(); }
	void Stop() { impl->Stop(); }
	void PlayOneMinute()
	{
		impl->Play();
		// 1분뒤에
		impl->Stop();
	}
};

class People
{
public:
	// 사용자는 구현계층을 바로 사용하지 말고
	// 간접층(추상층)을 사용
	void Use(MP3* p)
	{
		p->Play();
		p->Stop();

		// 그런데. 요구사항이 자주 변경/추가된다.
		// 1분 미리듣기 기능을 요청한다.
		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	MP3 mp3;
	p.Use(&mp3);
}


