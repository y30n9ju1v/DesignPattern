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

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back(CreateShape()); }
	bool CanUndo() override { return true; }

	void Undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
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

// 여러개 명령을 저장했다가 한번에 실행하는 매크로 명령
class MacroCommand : public ICommand   // Composite 패턴!
{
	std::vector<ICommand*> v;
public:
	void addCommand(ICommand* p) { v.push_back(p); }

	void Execute()
	{
		for (auto p : v)
			p->Execute();
	}
};

#include <stack>

int main()
{
	std::vector<Shape*> v;


	MacroCommand* mc1 = new MacroCommand;

	mc1->addCommand(new AddRectCommand(v));
	mc1->addCommand(new AddCircleCommand(v));
	mc1->addCommand(new DrawCommand(v));

	mc1->Execute(); // 3개의 명령을 한번에 실행


	MacroCommand* mc2 = new MacroCommand;


	mc2->addCommand(new AddRectCommand(v));
	mc2->addCommand( mc1 ); //  ? 에 적고 싶은것은 ?
	mc2->Execute();




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




