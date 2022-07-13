// Decorator - 65 page
#include <iostream>

// Composite 와 Decorator 의 클래스 다이어그램은 유사합니다.

// 결국 A가 B뿐 아니라 A자신도 받을수 있는
// 재귀적 포함 형태의 구조 입니다.
// => 이렇게 하기 위해 A, B의 공통의 기반 클래스 필요..

// 그런데.. "왜 재귀적 포함을 사용"하는가? 라는 의도가 다릅니다.

// Composite : 재귀적 포함을 사용해서 "복합객체" 를 만들겠다는 의도
//             PopupMenu, Folder 등..

// Decorator : 객체에 동적으로 기능을 추가하기 위해 사용


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


