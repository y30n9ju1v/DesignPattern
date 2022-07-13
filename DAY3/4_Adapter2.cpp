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
// 아래 코드가 "클래스 어답터" 입니다.
class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void Draw() override { TextView::Show(); };
};

// 아래 코드가 "객체 어답터" 입니다.

class ShapeAdapter : public Shape
{
	TextView* txtView; // 핵심(포인터, 또는 참조)
public:
	ShapeAdapter(TextView* v) : txtView(v) {}

	void Draw() { txtView->Show(); }
};

int main()
{
	vector<Shape*> v;

	TextView tv("hello");	// TextView : 클래스
							// tv       : 객체

	// 이미 존재하던 tv를 도형편집기에 넣을수 있을까요 ?
//	v.push_back(&tv); // error. tv 는 TextView 타입인데..
						//		Shape로 부터 상속받지 않았다.
 
	v.push_back( new ShapeAdapter(&tv) ); // 이미 존재하는 객체를
										// 어답터로 쓰워서 연결
										// "젠더(돼지코)" 역활


}







