#include <iostream>

// STL 의 원리
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;	
public:
	void resize(int n)
	{
		// C++ : 사용자가 전달한 클래스에 약속된 함수만 있으면 에러 아님
		// C#, java, swift : 사용자가 클래스 만들때 제약을 지키겠다고 표기해야 한다.
		//					C#의 경우 인터페이스 상속이 필요 하다.
		T* temp = ax.allocate(n); 
		//....
		ax.deallocate(temp, n); 

	}
};

template<typename T> struct MyAlloc //  where T  : IAllocator
{
	// allocate, deallocate
};

vector<int, MyAlloc<int>> v;
vector<int, int> v;
