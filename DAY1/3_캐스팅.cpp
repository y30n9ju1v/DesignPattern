// 3_캐스팅.cpp
#include <iostream>
using namespace std;

// 1. C++의 캐스팅은 목적에 따라서 다르게 사용해야 합니다.
//  1) static_cast
//    : 다른 타입 간의 변환에 사용됩니다.
//      연관성 있는 변환만 허용됩니다.
//  2) reinterpret_cast
//    : 메모리 재해석 목적
//  3) const_cast
//    : 상수성을 제거하는 목적으로 사용합니다.
//     - 타입의 불일치 문제를 해결하기 위해 사용합니다.
//  4) dynamic_cast
//   : RTTI(Run Time Type Information)

void print(int* p)
{
	cout << *p << endl;
}

int main()
{
	// int* p = (int*)malloc(sizeof(int));
	int* p1 = static_cast<int*>(malloc(sizeof(int)));

	int n = 0x12345678;
	// char* p2 = static_cast<char*>(&n); // error!
	char* p2 = reinterpret_cast<char*>(&n);
	printf("%x %x %x %x\n", p2[0], p2[1], p2[2], p2[3]);

	const int c = 100;

	// int* p3 = static_cast<int*>(&c); // error!
	// int* p3 = reinterpret_cast<int*>(&c); // error!
	int* p3 = const_cast<int*>(&c);
	// *p3 = 200;
	print(p3);
}