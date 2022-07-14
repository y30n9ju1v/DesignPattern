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

// slist 의 반복자
// => 1번째 요소를 가리키다가, 주어진 규칙에 따라 이동할수 있으면 됩니다.
template<typename T> 
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr)
		: current(p)
	{
	}
	// 인터페이스로 약속된 2개의 함수 구현
	T& getObject() override { return current->data; }

	bool moveNext() override
	{
		// 우리는 slist 이므로 아래 처럼이동
		// vector 등, 다른 구조라면 해당하는 구조에 맞게 이동
		current = current->next;
		return current != nullptr; // 끝에 도달여부
	}
};
//slist_enumerator<int> p(300번지);
//p.moveNext();
//int n = p.getObject();

// 모든 컨테이너에서는 반복자를 꺼낼수 있어야 한다.
template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IEnumerator<T>* getEnumerator()
	{
		// 1번째 요소를 가리키는 반복자 객체 반환
		return new slist_enumerator<T>(head);
	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IEnumerator<int>* p = s.getEnumerator();

	std::cout << p->getObject() << std::endl; // 40
	p->moveNext();
	std::cout << p->getObject() << std::endl; // 30

	delete p; // 좋지 않습니다.
			  // 결국 스마트 포인터 사용해야 합니다.
}
// 위 코드가 "C#", "삼성 타이젠(C++)" 이 사용하는 반복자 입니다.
// java, python, swift 등 대부분 언어도 함수 이름만 다를뿐 구현은 유사 합니다.
// 
// 그런데.. 생각해 볼 문제
// 1. moveNext()등이 인터페이스로 약속되므로 가상함수 입니다.
//    이동시 오버헤드 있습니다.

// 2. s.getEnumerator() 가 반복자를 "new"로 만들고 있습니다.
//    delete 해야 하지 않을까요?

// 3. 진짜 배열을 열거하는 방법과 다릅니다.
//    진짜 배열을 포인터를 사용하므로 ++ 로 이동