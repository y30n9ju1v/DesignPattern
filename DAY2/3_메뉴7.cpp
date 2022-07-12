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

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택" << std::endl;
		_getch();
	}
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


int main()
{
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	//	root->add_menu(pm2);
	pm1->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	// 메뉴를 추가하려면 아래 처럼 한줄만 추가하면 된다.
	pm1->add_menu(new MenuItem("8K", 14));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	// 이제 시작하려면 ?
	root->command(); // 최상위 메뉴를 선택


	// 위 코드는 모든 메뉴 객체가 new로 만들었으므로 "delete"가 필요 합니다.
	// 
	// 방법 1. vector< std::shared_ptr<BaseMenu> > 처럼 스마트 포인터 사용
	//		=> 제일 좋습니다.
	
	// 방법 2. 최상위 메뉴만 delete 하고.. 나머지는 
	//		  PopupMenu 의 소멸자에서 "자신의 하위메뉴를 delete" 하기로 약속
	// => 이 경우 모든 "메뉴 객체"는 new 로 만들어야 한다는 규칙이 생긴것 입니다.
	delete root;

	// C++ : 객체 생성시 "스택" 또는 "힙" 에 만들수 있다.
	//      => 그래서 항상 혼란 스럽다
	// .
	// C#, java, python : 모든 객체는 new 로 만든다는 "한가지 방법"
	//					게다가, 삭제도 자동으로
	//					너무 쉽다.!!




	// 근데.. 왜 new로 하나요 ? 아래 처럼 그냥 스택에 만들지
	{
//		MenuItem m("HD", 11); // 수명이 정해져 있습니다.
							  // 블럭을 벗어나면 무조건 파괴 됩니다.

//		new MenuItem("HD", 11); // 하지만 이 객체는 
								// 내가 지울때 까지 메모리에 남아있습니다.
								// "아주 자유 롭습니다."
	}

}




