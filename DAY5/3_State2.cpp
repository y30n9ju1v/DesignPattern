#include <iostream>

// 방법 1. 획득한 아이템 종류에 따라 조건문 사용
// => 새로운 아이템이 추가되면 모든 동작 함수가 수정 되어야 한다.
// => OCP를 만족할수 없다.
// OCP : Open Close Principle
//       기능 확장에 열려있고(Open) 코드 수정에는 닫혀 있어야(Close) 한다는 원칙
class Charater
{
	int gold;
	int item;
public:
	void run() 
	{ 
		if ( item == 1 )
			std::cout << "run" << std::endl; 

		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack() 
	{ 
		if( item == 1)
			std::cout << "attack" << std::endl; 

		else if (item == 2)
			std::cout << "power attack" << std::endl;
	}
};


int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



