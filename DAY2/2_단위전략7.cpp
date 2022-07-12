#include <iostream>
#include <vector>

// 사용자 정의 allocator 를 만들때는 미리 약속된 규칙(함수이름)을 
// 지켜야 합니다.
// cppreference.com 에서 "1번째 화면 오른쪽에서 named requirement"
template<typename T>
class MyAlloc
{
public:

};



int main()
{
	std::vector<int, MyAlloc<int> > v(5);

	std::cout << "------------";

	v.resize(10); 

	std::cout << "------------";
}