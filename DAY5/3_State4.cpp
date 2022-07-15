#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로!

// 캐릭터는 아이템 획득여부에 따라 동작이 변경된다.
// 변경되어야 하는 동작(함수)들을 인터페이스로 설계
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// jump(), slide()  등 변해야 하는 모든 멤버함수를 여기에 추가
};

class Charater
{
	int gold;
	int item;
	IState* state;
public:
	void setState(IState* p) { state = p; }

	// 캐릭터의 모든 동작을 "상태 객체"에 위임합니다.
	void run() { state->run(); }
	void attack() { state->attack(); }
};
// 아이템에 따라 동작을 정의한 수많은 상태 객체를 만들면 됩니다.
class NoItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class RedItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};
class BlueItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
class StarItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
int main()
{
	NoItem ni;
	RedItem ri;
	BlueItem bi;
	StarItem si;

	Charater* p = new Charater;
	p->setState(&ni);
	p->run();
	p->attack();

	// 이제 아이템 획득 여부에 따라 동작을 변경합니다.
	p->setState(&bi);
	p->run();
	p->attack();

	p->setState(&si);
	p->run();
	p->attack();

	p->setState(&ni);
	p->run();
	p->attack();

	// 위 코드의 의미
	// 객체가 
	// 1. "상태(멤버데이타)는 변경되지 않는데"
	// 2. "동작(멤버함수)" 가 변경됩니다.
	//    완전히 다른 클래스를 사용하는 것 처럼 보이게 됩니다.
}











// 변하는 것을 다른 클래스로 분리해서
// 인터페이스 기반으로 교체하는 패턴은 3개가 있습니다.

// strategy(전략) : 객체가 사용하는 "정책(알고리즘)" 을 변경한다.
//						=> Edit/IValidator 예제
// 
// state(상태)    : 객체의 모든(대부분) 동작을 변경한다.
//					마치 다른 클래스를 사용하는 것 처럼 보이게 된다.
// 
// builder(빌더)  : 복잡한 객체를 만드는 데, 동일한 공정으로 만든다.
//			       각 공정의 결과는 달라질수 있다.


