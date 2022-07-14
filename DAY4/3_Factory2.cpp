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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 클래스가 자신의 객체를 만드는 "static 멤버 함수"를 제공하는 기술은
	// 아주 유용하고 널리 사용됩니다.
	static Shape* Create() { return new Rect; }
};
// Rect객체를 만드는 방법
// 1. Rect* p1 = new Rect;
// 2. Rect* p2 = Rect::Create();

/*
void fn(int arg)
{
	// 함수인자(arg)따라 다른 도형을 만들고 싶다.
	// 단, 미래에 만들어질 도형까지 !!
	if (arg == 1) new Rect; //이렇게 하면 클래스 이름을 알아야 합니다
							// 미래의 도형은 클래스 이름을 알수 없습니다.
}
*/
/*
void fn(Shape* (*f)())
{
	Shape* p = f(); // 객체 생성
}
fn( &Rect::Create ); // 이 코드는 결국 "클래스이름"을 인자로 보내는 의미 입니다.
fn( &Triangle::Create);
*/

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
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
			// ret 는 요소의 포인터 이므로 pair 의 포인터입니다.
			// pair.first 가 key, pair.second 가 value(함수포인터)
			p = (ret->second)();  
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();

	// 이제 공장에 제품(도형)을 등록후에 사용합니다.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);


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




