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
// 방법 3. 함수 포인터 기반으로 이벤트를 처리.. - 가장 C++ 스러운 방식
//											하지만 까다롭습니다.

class MenuItem : public BaseMenu
{
	int id;

	// 핵심 : "일반함수", "멤버함수"등 모든 종류의 함수의 주소(또는 참조)를
	//		 담을수 있는 범용적인 용도의 "함수 포인터"가 필요 합니다.

	// C# : delegate,
	// swift : Selector 등의 도구가 있는데..
	
	// C++은 없었습니다. 그래서
	// 1. 직접 만들거나
	// 2. C++11에서 나온 "std::function"을 사용하면 됩니다.


	void(*handler)(); // 이렇게 하면 일반함수는 되는데,, 멤버 함수를 등록할수 없습니다.
	
	void(Camera::*handler)(); // 이렇게 하면 멤버 함수 등록가능합니다.
							// 그런데, 멤버함수를 호출하려면 객체가 있어야합니다
	Camera* target;

public:

	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		handler(); // 일반함수

		(target->*handler2)(); // 멤버 함수..
	}
};



int main()
{
	PopupMenu* root = new PopupMenu("root");

	root->add_menu(new MenuItem("HD", 11));
	root->add_menu(new MenuItem("FHD", 12));

	root->command();

	delete root;
}




