// 2_const.cpp
#include <iostream>
using namespace std;

class Test {
private:
	int x_ = 10;
	int y_ = 20;

public:
	// 아래 멤버 함수를 통해서 내부의 값이 변경되지 않는다는 것을 보장합니다.
	// void print(const Test* const this)
	void print() const
	{
		// x,y 가 const로 취급됩니다.
		cout << this->x_ << ", " << this->y_ << endl;
	}

	void setX(int x)
	{
		// this->x_ = x;

	}


};

void foo(const Test* p)
{
	// const*를 통해 참조도리 경우도 상수 멤버 함수만 호출이 가능합니다.
	p->print();
}

void foo(const Test& t)
{
	// const&를 통해 참조될 경우도 상수 멤버 함수만 호출이 가능합니다.
	t.print();
}

int main()
{
	Test t1;
	t1.print();

	// 상수 객체는 상수 멤버 함수만 호출이 가능합니다.
	const Test t2;
	t2.print();
}