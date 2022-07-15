// 실제 구현은 담은 클래스 
// Point의 모든 기능은 여기서 구현
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 



// 아래 클래스는 사용자가 사용하게 되는 간접층(추상층, Bridge)입니다.
// Point.h
//#include "PointImpl.h" // 이렇게 하지 않고
class PointImpl; // 이렇게만 해도 포인터 변수는 사용가능

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h" 

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }




// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

// 위와 같이 "Point" 간접층을 만들면
// 1. 컴파일 속도가 빨라집니다 
//  => PointImpl.h 가 변경되어도  CLient 코드는 재 컴파일이 필요 없다.

// 2. 완벽한 정보은닉이 가능하다.

// 이 기술을

// "PIMPL" 이라고도 부릅니다.

// Point to IMPLementation
// 
// "컴파일러 방화벽" 이라고도 합니다.


// 객체지향 디자인의 핵심 3. "간접층을 만드는 것"
// 왜?? 어떤 이유로 간접층을 만드는데.. 이유(의도)가 뭔데..
// 
// 
// 사용자	 ===> stack ======>	list			// 함수이름을 변경해서 다른것처럼
//											// 보이게 . "Adapter 패턴"
// 
// 사용자	 ===> TCPServer ==>	Socket, IPAddress... // 사용하게 쉽게..
//												// 한개의 포괄적 인터페이스
//												// facade
// 
// 사용자	 ===> CalcProxy ==>	CalcServer	// 다양한 용도의 "범용적인 대행자"
//										// Proxy
// 
// 사용자	 ===> MP3 ========>	IMP3	// update 를 편리하게 하기 위해서
									// 구현과 추상의 상호 독립적 update
									// bridge




