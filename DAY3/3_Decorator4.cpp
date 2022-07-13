#include <iostream>


class Item
{
public:
	virtual void Fire() = 0;
	virtual ~Item() {}
};


class SpaceShip : public Item
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 기능 추가 객체들은 공통의 특징이 많이 있을수 있습니다.
// 이 경우, "공통의 특징을 담은 기반 클래스를 제공하면 좋습니다."

class IDecorator : public Item
{
	Item* ship;
public:
	IDecorator(Item* s) : ship(s) {}
};

class LeftMissile : public IDecorator
{
public:
	LeftMissile(Item* s) : IDecorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public IDecorator
{
public:
	RightMissile(Item* s) : IDecorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};


int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);
	lm.Fire();

	RightMissile rm(&lm);
	rm.Fire();			 
}


