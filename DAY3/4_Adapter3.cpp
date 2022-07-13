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
// 상속으로 구현한 클래스 어답터 : stack 이 list 의 모든 기능을
//							외부에 노출하게 된다. 
//							현재 코드에서는 좋지 않다.
/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()     { return std::list<T>::back(); }
};
*/
// 포함을 사용한 어답터 : stack 입장에서는 list의 기능을 외부에 노출하지 않는다.
template<typename T> class stack
{
//	std::list<T>* c; // 이렇게 포인터 또는 참조 라면 외부에 있던
					 // list 를 접근하게 되므로 객체에 대한 변경

	std::list<T> c;  // 이렇게 값으로 되어 있으면 결국 "클래스 어답터" 입니다.
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
//	std::list<int> st = { 1,2,3 }; // 이미 존재하는 st 객체를
									// 스택처럼 사용할수 있어야
									// 객체 어답터 입니다.
	stack<int> s;
	s.push(10);

//	s.push_front(20); // ?? 사용할수 있게 해야 할까요 ?
}





