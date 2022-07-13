#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// STL 과 Adapter

// STL 에 list 가 있는데, 사용자가 stack 을 요구합니다.
// 1. stack 을 만들자
// 2. list 의 함수 이름을 변경해서 stack 처럼 보이게 하자.

// list 의 함수 이름 "push_back" 을 "push" 로 변경해서
// 스택처럼 보이게 하자.
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()     { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
}





