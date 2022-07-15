#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// 핵심 
// list      : 모든 요소가 동일한 타입입니다.
//			   => 그래서 visit(T& v) 처럼 함수가 한개면 됩니다.
// 
// PopupMenu : 요소의 타입이 다릅니다.

class MenuItem;
class PopupMenu;  // 클래스 전방 선언

struct IMenuVisitor
{
	virtual void visit(MenuItem* mi) = 0;
	virtual void visit(PopupMenu* pm) = 0;

	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void Accept(IMenuVisitor* visitor) = 0;
	virtual ~IAcceptor() {}
};

class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}

	void Accept(IMenuVisitor* visitor) override
	{
		// MenuItem 은 다른 메뉴를 포함하지 않는다.
		// 그냥 자신만 방문자에 전달
		visitor->visit(this); 
	}
};




class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	void Accept(IMenuVisitor* visitor) override
	{
		// 나를 보내고
		visitor->visit(this);

		// 방문자를 다시 내가 가진 모든 요소에 방문 시킨다.
		for (auto& e : v)
		{
			e->Accept(visitor); 
		}
	}




	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};


// 이제 "메뉴 한개에 대한 연산"을 정의한 방문자들을 만들어서 사용하면 됩니다.

class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	void visit(MenuItem* mi) {}  // 메뉴아이템 방문시 할일은 없다.

	void visit(PopupMenu* pm) 
	{
		std::string s = "[ " + pm->get_title() + " ]";

		pm->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	PopupMenuTitleChangeVisitor v; // 팝업메뉴의 타이틀을 변경하는 방문자

	root->Accept(&v);


	root->command();

}




