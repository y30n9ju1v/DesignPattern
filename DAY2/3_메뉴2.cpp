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
	MenuItem(const std::string& s) : title(s) {}

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
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	m1.command(); // 김밥 선택
}




