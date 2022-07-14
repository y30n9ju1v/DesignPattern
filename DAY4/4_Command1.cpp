#include <iostream>
#include <vector>
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
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

//----------------------
// Command 패턴 : 명령을 캡슐화 해서, 명령의 저장/취소/복구가 가능하게 한다.

struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v; // 참조 입니다.
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {} // 이름같아도 됩니다.

	void Execute() {}
};






int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
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




