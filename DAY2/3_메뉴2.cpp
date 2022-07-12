#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 메뉴 항목 한개를 관리하는 클래스
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title; }

	// 메뉴를 선택할때 호출되는 함수
	void command()
	{
		std::cout << get_title() << " 메뉴 선택" << std::endl;
		_getch();
	}
};

int main()
{
	// 핵심 : 메뉴 항목 하나가 "객체" 입니다.
	//		 메뉴 항목이 20개 라면 20개의 객체를 생성하면 됩니다.
	//	     메뉴가 선택(실행)되게 하려면 command()를 호출하면 됩니다.
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	m1.command(); // 김밥 선택
}




