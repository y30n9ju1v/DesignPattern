#include <iostream>


// 모든 컨테이너의 반복자(열거자)가 지켜야 하는 인터페이스
template<typename T> struct IEnumerator
{
	virtual T& getObject() = 0;
	virtual bool moveNext() = 0;

	virtual ~IEnumerator() {}
};

// 모든 컨테이너가 지켜야 하는 규칙
template<typename T> struct IEnumerable   // 위코드와 이름 잘 구별하세요
{
	virtual IEnumerator<T>* getEnumerator() = 0;
	virtual ~IEnumerable() {}
};








template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
}