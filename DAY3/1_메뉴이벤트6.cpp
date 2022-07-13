#include <iostream>
#include <functional>
using namespace std::placeholders;


void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void close(int a, int b)
	{
		printf("Dialog close : %d, %d\n", a, b);
	}
};

int main()
{
	// 함수 포인터는 "유연성이 부족" 해서 불편합니다.
//  void(*f)(int) = &f1; // ok

//	f = &f2; // error. f에는 인자가 한개인 함수의 주소만 담을수 있는데
			//         f2의 인자는 2개 입니다.
				
	// C++11 부터 함수 포인터의 일반화 버전인 "std::function" 이 제공됩니다.

	// void(*)(int) : 함수 포인터 타입
	// void(int)    : 함수 타입

	std::function<void(int)> f;

	f = &f1;	// ok
	f(10);		// f1(10)
}












