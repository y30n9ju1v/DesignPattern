// 6_Mediator - 중재자 패턴 
#include <iostream>

// Mediator(중재자 패턴)
// => 객체간의 상호 관계가 복잡하면 중재자를 만들어라.
// => M:N의 관계를 1:N의 관계로 변경(1:중재자)
// 
// => M:N => 객체들이 서로 모두를 알아야 한다.
//    1:N => 중재자만 객체들을 알면 된다.

// => 모든 규칙은 중재자만 알면 된다.

// Observer : 1의 변화는 모두에게 알림
// Mediator : 협력자들의 변화를 다른 협력자에게 알리거나
//            협력자들의 변화를 가지고 판단을 수행








// GUI 라이브러리중에 아래 같은 것이 있다고 생각해 봅시다.
class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

class MyCheck : public CheckBox
{
public:
	void ChangeState() override 
	{
		// 여기서 버튼 enable 정책을 구현합니다.
		if (GetCheck())
			std::cout << "button enable" << std::endl;
		else 
			std::cout << "button disable" << std::endl;
	}
};

int main()
{
	MyCheck c;
	c.SetCheck(false);  // 사용자가 마우스로 체크를 눌렀다고 가정. 
	c.SetCheck(true);
}



