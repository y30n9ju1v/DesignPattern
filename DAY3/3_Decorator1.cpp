// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 기존 기능을 수행하고..
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능수행
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm;
	lm.Fire();
}