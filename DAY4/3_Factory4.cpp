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




