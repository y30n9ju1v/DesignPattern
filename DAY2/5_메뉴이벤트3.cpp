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
// 방법 2. 변하는 것을 다른 클래스로

// 메뉴 이벤트를 처리하고 싶은 클래스는 반드시 아래 인터페이스를 구현해야 한다.
struct IMenuListener
{
	virtual void command() = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int id;

	IMenuListener* pListener = nullptr;
public:
	void setListener(IMenuListener* p) { pListener = p; }

	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		// 메뉴가 선택되었음을 "등록된 리스너객체"에게 알려준다.(약속된 함수 호출)
		if (pListener)
			pListener->command();
	}
};
//======================
// 이제 사용자가 만드는 클래스에 메뉴를 처리하고 싶다면 
// IMenuListener 인터페이스를 구현해야 합니다.
class Camera : public IMenuListener
{
public:
	void command() override
	{
		std::cout << "Camera command" << std::endl;
		_getch();
	}
};

int main()
{
	Camera* camera = new Camera;
	PopupMenu* root = new PopupMenu("root");

	MenuItem* p1 = new MenuItem("hd", 11);
	MenuItem* p2 = new MenuItem("fhd", 12);

	// 각 메뉴에 이벤트를 처리할 객체를 등록합니다.
	p1->setListener(camera);
	p2->setListener(camera);

	root->add_menu(p1);
	root->add_menu(p2);
	
	root->command();

	delete root;
}




