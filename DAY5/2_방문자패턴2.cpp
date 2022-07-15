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
	void visit(T& v) override {}
};




int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.Accept(&tv);

	ShowVisitor<int> sv; 
	s.Accept(&sv);

}





