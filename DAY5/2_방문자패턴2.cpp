#include <iostream>
#include <list>
#include <vector>

// 방문자(Visitor)의 인터페이스
template<typename T> struct IVisitor
{
	virtual void visit(T& v) = 0;

	virtual ~IVisitor() {}
};


// 이제 다양한 방문자를 설계 합니다.
// 방문자는 "요소 한개에 대한 연산" 을 정의 하면 됩니다.
template<typename T> class TWiceVisitor : public IVisitor<T>
{
public:
	void visit(T& v) override { v *= 2; }
};
//=====================================
// 복합객체는 방문자를 받아 들여야 합니다.
template<typename T> struct IAccept
{
	virtual void Accept(IVisitor<T>* visitor) = 0;
	virtual ~IAccept() {}
};

// STL은 방문자 패턴을 사용하지 않고 있습니다.
// list 를 확장해서 방문자 패턴의 기능 추가
template<typename T> 
class MyList : public std::list<T>, public IAccept<T>
{
public:
	void Accept(IVisitor<T>* visitor) override
	{
		// 방문자 : 한개의 요소에 대한 연산 수행
		// 따라서, 자신의 모든 요소를 방문자에 전달합니다.
		for (auto& e : *this)
			visitor->visit(e);

	}
};







int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.Accept(&tv);

	ShowVisitor<int> sv; 
	s.Accept(&sv);

}





