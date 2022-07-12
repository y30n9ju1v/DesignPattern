#include <iostream>
#include <vector>

// 사용자 정의 allocator 를 만들때는 미리 약속된 규칙(함수이름)을 
// 지켜야 합니다.
// cppreference.com 에서 "1번째 화면 오른쪽에서 named requirement"
template<typename T>
class MyAlloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("allocate %d 개, %p\n", sz, p);

		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate %d 개, %p\n", sz, p);
		free(p);
	}
};





int main()
{
	std::vector<int, MyAlloc<int> > v(5);

	std::cout << "------------";

	v.resize(10); 

	std::cout << "------------";
}