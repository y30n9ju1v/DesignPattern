// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
// 상속 : 객체에 기능 추가가 아닌 클래스에 기능 추가
// 포함 : 클래스가 아닌 객체에 기능을 추가하는 것
class LeftMissile
{
	SpaceShip* ship; // "포인터" 또는 "참조" 로 해야 합니다.
					 // 기존에 존재하던 객체를 "가리킬것" 이라는 의미
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // 기존 객체의 기능을 사용하고.
		std::cout << "Fire Left Missile" << std::endl; //새로운 기능추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss); // ss 라는 객체에 새로운 기능을 추가하겠다는 의미.
	lm.Fire();			 // 객체를 "기능추가 객체(포장지, Decorator)"에 전달	
				
				// lm은 우주선은 아니고, 우주선에 "기능"을 추가하는 객체 입니다.
}


