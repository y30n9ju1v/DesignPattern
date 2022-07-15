// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};

struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------

// WinDialog 와 OSXDialog 는 유사한 코드가 많습니다.
// 동일한 코드는 "기반 클래스"로 제공하면 편리합니다.
class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit  = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// 객체를 만들기 위한 인터페이스를 정의 하고 사용하지만
	// 어떤 객체를 만들지는 파생클래스가 결정.
	// "Factory Method" 패턴
	// "Template Method" 와 유사하지만, 알고리즘의 변경이 아닌 "생성될 객체의 타입"을 결정
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit()   = 0;
};

class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit()     override { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	// IButton* 대신 OSXButton* 으로 재정의해도 됩니다. => 좋습니다.
	// 이런 기술을 "공변 반환" 의 법칙 이라고 합니다.
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit()     override { return new OSXEdit; }
};


int main(int argc, char** argv)
{

}








