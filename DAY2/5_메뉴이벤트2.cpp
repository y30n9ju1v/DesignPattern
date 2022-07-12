// 3_메뉴7

#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;
};



class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	~PopupMenu()
	{
		for (auto p : v)
			delete p;
	}




	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command()
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
			std::cout << "메뉴 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;
			v[cmd - 1]->command();
		}
	}
};
//=============================================
// 방법 1. 변하는 것을 가상함수로...
// => 가능한 방법이지만.. 
// => 메뉴예제에 적용하면 파생클래스의 갯수가 너무 많아진다.
// => 메뉴가 50개라면 "MenuItem"의 파생 클래스도 50개 필요

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		doCommand();
	}
	virtual void doCommand() {}
};

class HDMenu : public MenuItem
{
public:
	// C++11 이전의 코딩 스타일
//	HDMenu(const std::string& s, int n) : MenuItem(s, n) {}
	
	// C++11 부터는 "생성자 상속" 문법 사용
	using MenuItem::MenuItem; // 이 코드가 위와 동일한 효과

	void doCommand() override 
	{ 
		std::cout << "change HD" << std::endl; 
		_getch();
	}
};
class FHDMenu : public MenuItem
{
public:
	using MenuItem::MenuItem;
	void doCommand() override
	{
		std::cout << "change FHD" << std::endl;
		_getch();
	}
};
int main()
{
	PopupMenu* root = new PopupMenu("root");

	root->add_menu(new HDMenu("HD", 11));
	root->add_menu(new FHDMenu("FHD", 12));

	root->command();

	delete root;
}




