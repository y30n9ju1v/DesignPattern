// 5_다형성5.cpp
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f1() {}
	virtual void f2() {}
};

class Derived : public Base {
public:
	void f1() override {}
	void f2() override final {}
	// 자식 클래스가 더 이상 오버라이딩이 불가능하도록 합니다.
};

class DerivedDerived : public Derived {
public:
	void f1() override {}
	// void f2() override {}
};