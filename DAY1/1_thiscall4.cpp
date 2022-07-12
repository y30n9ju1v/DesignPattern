// 1_thiscall4.cpp
#include <Windows.h>

#include <iostream>
using namespace std;

class Thread {
public:
	void run() {
		CreateThread(0, 0, &foo, this, 0, 0);
	}

	// 1. 일반 함수 포인터를 통해 정적 멤버 함수를 참조할 수 있습니다.
	static DWORD __stdcall foo(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// 2. 정적 멤버 함수안에서 일반 멤버 함수를 호출이 불가능합니다.
		// : this를 명시적으로 전달합니다.
		self->threadLoop();
		return 0;
	}

	virtual bool threadLoop() { return false; }
};

//----------------------
class MyThread : public Thread {
public:
	virtual bool threadLoop()
	{
		cout << "MyThread threadLoop" << endl;
		return true;
	}
};


int main()
{
	MyThread t;
	t.run();   // 이 순간 스레드가 생성되어서 가상함수인 threadLoop()를 호출해야 합니다.

	getchar();
}

#if 0
DWORD __stdcall foo(void* p)
{
	while (1) {
		cout << "foo thread" << endl;
		Sleep(1000);
	}
	
	return 0;
}

int main()
{
	CreateThread(0, 0, &foo, 0, 0, 0);
	while (1) {
		cout << "main thread" << endl;
		Sleep(500);
	}
	
}
#endif