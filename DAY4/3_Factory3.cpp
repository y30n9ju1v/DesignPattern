#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

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

// 공장에 제품(도형)을 자동등록할때 사용할 클래스
class AutoRegister
{
public:
	AutoRegister(int type, Shape*(*f)() )
	{
		ShapeFactory::getInstance().Register(type, f);
	}
};

// main 함수 보다 전역변수의 생성자가 먼저 호출됩니다.
// AutoRegister ar(1, &Rect::Create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }


	// static 멤버 데이타의 특징을 잘 생각 해보세요
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

// 위 코드의 의미
// Rect의 생성자(Rect()) : Rect 객체를 생성할때 마다 호출
// ar 의 생성자          : Rect 타입에 대해 최초에 1회 실행됨
//							=> 다른 일부 객체지향언어에 있는 "static 생성자"











class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);

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




