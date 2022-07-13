// Decorator - 65 page
#include <iostream>

// 객체와 기능 추가 객체는 공통의 기반 클래스가 필요 하다.

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

class LeftMissile : public Item
{
	Item* ship;					 
public:
	LeftMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); 
		std::cout << "Fire Left Missile" << std::endl; 
	}
};

class RightMissile : public Item
{
	Item* ship;
public:
	RightMissile(Item* s) : ship(s) {}

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

//	RightMissile rm(&ss); // 이 코드는 당연하고
	RightMissile rm(&lm); // 이 코드가 되면 좋지 않을까요 ?
	rm.Fire();			  // 기능을 추가한 객체에 다시 기능추가
}


