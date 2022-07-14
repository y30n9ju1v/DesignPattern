#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

// 이코드에서 배울 기술들

// 1. Rect::Create() 함수

//    new Rect;   이렇게 만들려면 "클래스이름"이 필요합니다.
//				  클래스 이름을 자료 구조에 문자열로 보관할수는 있습니다.
//			      그런데, 문자열로 객체 생성은 안됩니다.
//				  string s = "Rect";
//				  s 로 객체 생성 할수 없습니다.

//   auto f = Rect::Create; 
//	 f();		 이렇게 만들려면 함수 주소 필요.
//				 함수 주소는 자료구조 보관 가능하고
//			     보관된 주소로 객체 생성 가능.


// 2. 생성자 vs static 생성자(C#의 개념)

//    Rect r1;
//    Rect r2; // 생성자 호출.. 객체당 한번씩 호출됨. 객체 초기화

//    Rect::ar	// Rect 클래스에 대해 최초에 1회 호출
//				// Rect 클래스 자체의 초기화에 활용가능
//				// C++에는 없지만 C#에 있는 static 생성자 개념
//				// C++에서는 아래 와 같은 static 멤버 데이타로 유사하게 구현





class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
		using CREATOR = Shape * (*)();
	std::map<int, CREATOR> create_map; // {도형번호, 생성함수}
public:
	void Register(int type, CREATOR f) { create_map[type] = f; }


	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = (ret->second)();
		}
		return p;
	}
};

class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(type, f);
	}
};





// 현재 시스템에서 사용되는 모든 도형 클래스는 반드시 지켜야 하는 규칙이 생겼다.
// 규칙 코드를 자동생성하는 매크로를 제공하자.

#define DECLARE_SHAPE(classname)						\
	static Shape* Create() { return new classname; }	\
	static AutoRegister ar;

#define REGISTER_SHAPE(type, classname)		\
	AutoRegister classname::ar(type, &classname::Create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle)

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	DECLARE_SHAPE(Triangle)
};
REGISTER_SHAPE(3, Triangle)

// 번호 관리 측면에서 숫자는 한 곳에서 등록되는게 편리하지 않나요..?
// => 네 좋은 의견 입니다. 공장에게 도형 번호를 요청할수 있게 수정하면 좋습니다.
// => factory.getNextShapeNumber(); 같은 함수 제공


int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();

			}
		}
	}
}




