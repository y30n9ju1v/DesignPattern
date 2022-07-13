#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;


/*
template<typename T, typename C = std::deque<T> >
class stack
{
	C c;    // STL 의 모든 선형 컨테이너는 사용법이 동일하다.!!
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top()   { return c.back(); }
};
*/
#include <stack> // C++ 표준의 "stack" 이 위 처럼 만들어져 있습니다.
				// 흔히, "stack adapter" 라고 부릅니다.
				// 선형컨테이너를 스택 처럼 사용하도록 "인터페이스(함수이름)"을
				// 변경해 주는 도구입니다.

int main()
{
	std::stack<int> s; // std::deque  을 스택처럼 사용할수 있게 해달라는 것
	s.push(10);

	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
}





