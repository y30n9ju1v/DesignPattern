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

// 어답터 패턴의 종류
// 클래스 어답터 : 
// 객체   어답터 : 

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void Draw() override { TextView::Show(); };
};

int main()
{
	vector<Shape*> v;

	TextView tv("hello");	// TextView : 클래스
							// tv       : 객체

	// 이미 존재하던 tv를 도형편집기에 넣을수 있을까요 ?
	v.push_back(&tv); // ??
 



}







