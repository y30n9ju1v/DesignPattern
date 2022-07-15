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


