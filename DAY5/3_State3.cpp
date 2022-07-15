#include <iostream>

// 방법 2. 변하는 것을 가상함수로!!

class Charater
{
	int gold;
	int item;
public:
	void run() { doRun(); }
	void attack() { doAttack(); }

	virtual void doRun()   { std::cout << "run" << std::endl; }
	virtual void doAttack() { std::cout << "attack" << std::endl; }
};
// 이제 각 아이템 별로 동작을 변경해야 하므로 파생 클래스에서 가상함수 재정의
class RedItemCharacter : public Charater
{
public:
	void doRun() override { std::cout << "fast run" << std::endl; }
	void doAttack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedItemCharacter; // 기존 캐릭터가 아이템 획득아니라..!!
							// 새로운 캐릭터를 만든 것
							// 우리에게 필요한 것은
							// 상태는 유지(기존 객체 사용) 하는데
							// 동작(멤버 함수)만 교체하고 싶은것
	p->run();
	p->attack(); 
}



