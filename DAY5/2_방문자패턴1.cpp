#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 방법 1. 
	for (auto& e : s)
	{
		e *= 2;
	}

	// 방법 2. 방문자 패턴 사용
	// => 복합객체가 가진 요소 한개에 대한 연산을 정의한 객체

	TwiceVisitor<int> tv; // 요소 한개의 값을 2배로 하는 방문자
	s.Accept(&tv);

	ShowVisitor<int> sv; // 요소 한개를 출력하는 방문자
	s.Accept(&sv);
	

	// 위 코드가 실행되려면
	// 1. 모든 컨테이너(list, vector)에는 Accept 가 있어야 한다.
	//    => 컨테이너의 인터페이스 필요
	// 
	// 2. Accept 는 다양한 방문자를 모두 받아들여야 한다.
	//    => "방문자(Visitor)의 인터페이스가 필요 하다.
}





