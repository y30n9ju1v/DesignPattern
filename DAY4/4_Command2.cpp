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

struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

// 도형을 추가하는 명령은 유사한 코드가 많이 있습니다.
// 유사한 코드가 많다면 기반클래스를 만들어서 제공합니다.
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back( CreateShape() ); }
	bool CanUndo() override { return true; }

	void Undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
	// Factory Method 패턴 : 객체를 만들기 위한 인터페이스를 제공하고 사용하지만
	//					    어떤 종류의 객체를 만들지는 파생 클래스가 결정한다.
	// template method 와 동일한 모양이지만, 변하는 가상함수가 하는 일이
	// 알고리즘의 변경이 아닌 "객체의 종류"를 결정한다.
	virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; // 생성자 상속

	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; 

	Shape* CreateShape() override { return new Circle; }
};



class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override
	{
		for (auto p : v) p->draw();
	}
	bool CanUndo() override { return true; }

	void Undo() override
	{
		system("cls");
	}
};


#include <stack>

int main()
{
	std::vector<Shape*> v;

	ICommand* pCmd = nullptr;

	std::stack<ICommand*> undo_stack;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pCmd = new AddRectCommand(v);
			pCmd->Execute();

			undo_stack.push(pCmd);
		}
		else if (cmd == 2)
		{
			pCmd = new AddCircleCommand(v);
			pCmd->Execute();

			undo_stack.push(pCmd);
		}
		else if (cmd == 9)
		{
			pCmd = new DrawCommand(v);
			pCmd->Execute();

			undo_stack.push(pCmd);
		}
		else if (cmd == 0)
		{
			if (!undo_stack.empty())
			{
				pCmd = undo_stack.top();

				undo_stack.pop();

				if (pCmd->CanUndo())
					pCmd->Undo();

				delete pCmd; 
			}
		}
	}
}




