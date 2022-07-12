// 1_thiscall3.cpp
#include <iostream>
using namespace std;


class Dialog {
public:
	// void open(Dialog* this)
	void open() {
		cout << "Dialog open" << endl;
	}

	void close() {
		cout << "Dialog close" << endl;
	}

	// void()
	// : 정적 멤버 함수는 일반 함수와 시그니처가 동일합니다.
	//  - 일반 함수 포인터를 통해 정적 멤버 함수를 호출할 수 있습니다.
	static void foo()
	{
		cout << "Dialog foo" << endl;
	}
};

int main()
{
	// void (*fp3)(Dialog*) = &Dialog::open;
	// : 사용이 불가능합니다.

	void (*fp2)() = &Dialog::foo;
	fp2();


	// 1. 멤버 함수 포인터 타입을 만드는 방법
	void (Dialog:: * fp)();

	// 2. 멤버 함수의 주소를 얻는 방법
	fp = &Dialog::open;

	// 3. 멤버 함수를 호출하기 위해서는 반드시 객체가 필요합니다.
	//  => 멤버 함수 포인터를 통해 멤버 함수를 호출하기 위해서는 반드시
	//     객체가 필요합니다.
	Dialog dlg;
	(dlg.*fp)();  // .*
	
	
	Dialog* pDlg = &dlg;
	(pDlg->*fp)(); // ->*

}



#if 0
// 멤버 함수와 멤버 함수 포인터 이야기
int add(int a, int b) { return a + b; }

// int n;
// : C++에서는 이름을 제외한 나머지가 타입입니다.

// int x[3];
// : int[3]

// int add(int a, int b)
// : int(int a, int b)
int main()
{
	int(*fp)(int, int) = &add;
	int result = (*fp)(10, 20);
	
	int(*fp2)(int, int) = add;
	result = fp(10, 20);
	
	cout << result << endl;
}
#endif