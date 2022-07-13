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

	f(10);		// f1(10),  f는 결국 함수 포인터와 동일해 보입니다.

	// 하지만, function 은 bind의 결과를 담을수 있습니다.
//	f = &f2; // error...

	f = std::bind(&f2, 10, _1); // 이항 함수를 단항 함수로 고정해서 
								// f에 등록
	f(5); // f2(10, 5);


	// 아래 코드 완성해 보세요
	// 1. f3이 3항 이므로 이어지는 인자는 3개가 되어야 합니다.
	// 2. 3항을 1항으로 변경해야 하므로 "_1" 까지만 사용되어야 합니다
	f = std::bind(&f3, 2 , _1 , 2);

	f(5);  // f3(2, 5, 3);


	// 멤버 함수도 사용가능 합니다.
	// 단, 이때는 함수 인자뿐아니라 객체도 같이 고정되어야 합니다.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, 0, _1);

	f(5);	// dlg.close(0, 5);
			// (객체포인터->*멤버함수)(0, 5);
}











// effective c++에서 bind는 앞서 추론문제와 성능 문제가 있다고 
// 쓰지 말라고 했던거 같은데요 실제 c++에서 커링을 구현하기 위해 어떻게 하나요?
// => 가변인자 템플릿과 람다 표현식으로 주로 구현합니다.
// => bind 대신 "람다표현식을 사용하라" 고 되어 있는데..
//    성능이 이슈가 되는 부분이 아니면(가끔 사용되는 코드) 많이 사용됩니다.











