#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 복합객체(PopupMenu)는 개별객체(MenuItem, leaf)
// 뿐 아니라 복합객체 자신도 보관한다.
// => 복합객체와 개별객체는 공통의 기반 클래스가 필요 하다.

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {} // 기반 클래스의 소멸자는 항상 가상 함수 이어야 한다.

	std::string get_title() const { return title; }
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

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls"); // 화면 지우기

			int sz = v.size(); // 하위 메뉴 갯수

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;
			std::cout << "메뉴 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) // 종료 메뉴 선택
				break;  // 또는 return

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			// 선택된 메뉴를 실행합니다.
			// MenuItem 선택시 "command()"를 호출하기로 약속되어 있었습니다.
			v[cmd - 1]->command();

		}



	}
};






int main()
{
	MenuItem m1("참치김밥",   11);
	MenuItem m2("소고기김밥", 12);

	PopupMenu kimbam("김밥류");
	kimbam.add_menu(&m1);
	kimbam.add_menu(&m2);


	MenuItem m3("라면", 21);
	MenuItem m4("우동", 31);

	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&kimbam); // 핵심.. 잘 생각해 보세요..
	pm.add_menu(&m3);
	pm.add_menu(&m4);

	pm.command(); // 팝업 메뉴를 선택할때 
				  // 해야 할일을 생각해보세요.

}




