#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 75 page.. 
// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관했다가 화면에 이쁘게 출력해 주는 클래스
class TextView
{
	// 폰트종류, 크기, 색상, 스타일
	string data;
public:
	TextView(string s) : data(s) {}

	void Show() { cout << data << endl; }
};

// TextView tv("hello");
// tv.Show(); 



 

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { cout << "Draw Rect" << endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { cout << "Draw Circle" << endl; }
};

// 도형편집기 시스템에, 사각형, 원 뿐 아니라 "Text" 를 관리하는 기능도 필요하다.
// 도형 편집기 : 화면 출력시 "Draw()" 사용
// TextView  : 화면 출력시 "Show()" 사용
// 즉, 인터페이스(함수이름)이 다르다.

// 어답터(Adapter) 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서 
//					    시스템이 요구하는 조건으로 변경한다.

// 어답터 패턴의 종류
// 클래스 어답터 : 
// 객체   어답터 : 

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 코드가 "Show" 라는 함수 이름을 "Draw" 이름으로 변경한것
	void Draw() override { TextView::Show(); };
};

int main()
{
	vector<Shape*> v;
	v.push_back(new Text("hello"));

	v[0]->Draw();
}







