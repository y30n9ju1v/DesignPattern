#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택" << std::endl;
		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}

	void add_menu(MenuItem* p) { v.push_back(p); }


	// 팝업메뉴를 선택할때 해야 할일을 생각해 보세요
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
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	
	
	PopupMenu pm("오늘의 메뉴");

	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command(); // 팝업 메뉴를 선택할때 
				  // 해야 할일을 생각해보세요.

}




