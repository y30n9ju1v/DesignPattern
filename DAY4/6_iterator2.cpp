#include <iostream>

int main()
{
	slist<int> s = { 1,2,3,4,5 }; // 모든 요소가 떨어진 메모리

	vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 연속된 메모리

	// 연속된 메모리를 사용하는 컨테이너와 
	// 연속되지 않은 메모리를 사용하는 컨테이너는
	// 요소의 순회 방법이 다릅니다.
	
	// iterator 패턴
	// => 컨테이너의 내부구조에 상관없이 동일한 방법으로 
	//    요소를 열거하게 하자.

	// 핵심 1. 모든 컨테이너는 반복자라는 객체를 꺼낼수 있어야 한다.
	list반복자   p1 = s.getEnumerator();
	vector반복자 p2 = v.getEnumerator();


	// 모든 반복자는 사용법이 같아야 합니다.
	// => 모든 반복자의 함수 이름을 약속하기 위한
	//    인터페이스가 있어야 한다는 의미. 
	int n1 = p1.getObject();
	int n2 = p2.getObject();

	p1.moveNext();
	p2.moveNext();

}





