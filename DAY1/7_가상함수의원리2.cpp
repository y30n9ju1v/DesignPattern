// 7_가상함수의원리2.cpp
#include <iostream>
using namespace std;

class A
{
	int a;
public:
	virtual void hoo() { cout << "A hoo" << endl; }
	virtual void foo() { cout << "A foo" << endl; }
};

class B
{
	int b;
public:
	virtual void goo() { cout << "B goo" << endl; }
};

int main()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);

	p->goo(); // (p->vptr)[0]()
}