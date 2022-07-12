#include <iostream>
#include <vector>
#include <allocators> // C++ 표준 메모리 할당기

int main()
{
	// 메모리 할당 방법
	// 방법 1. new / delete 를 직접 사용
	int* p1 = new int[10];
	delete[] p1;



	// 방법 2. allocator 사용
	std::allocator<int> ax;    // C++표준 메모리 할당기
								// (내부적으로는 new/delete 사용)

	int* p2 = ax.allocate(10); // int 10개 할당해 달라
								// 결국 "new int[10]"

	ax.deallocate(p2, 10); // "delete[] p2"

}