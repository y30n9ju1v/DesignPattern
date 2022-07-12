#include <iostream>

// STL 의 원리
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;	// 메모리 할당기. 
				// 앞으로 모든 멤버 함수 에서는 메모리 할당/해지가 필요하면
				// 이 객체에 의존해야 합니다
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

		T* temp = ax.allocate(n); // 할당이 필요 할때
		//....
		ax.deallocate(temp, n); // 해지를 할때

	}
};

