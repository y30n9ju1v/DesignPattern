// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 복잡한 객체(축구게임 캐릭터)를 만들때 사용하는 각 공정의 함수를
// 인터페이스로 설계
struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes makeShoes() = 0;
	
	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		// 그런데, 각 공정의 결과물은 builder 에 따라 달라집니다.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// 국가별 캐릭터를 만들때 사용할 다양한 빌더들
class Korean : public IBuilder
{
public:
	Hat     makeHat() override     { return Hat("갓"); }
	Uniform makeUniform() override { return Uniform("한복"); }
	Shoes   makeShoes() override   { return Shoes("고무신"); }
};
class American : public IBuilder
{
public:
	Hat     makeHat() override { return Hat("야구모자"); }
	Uniform makeUniform() override { return Uniform("양복"); }
	Shoes   makeShoes() override { return Shoes("구두"); }
};

int main()
{
	Korean k;
	American a;
	Director d;
	d.setBuilder(&k); // 국가 선택을 변경시.. 이 함수로 빌더객체를 변경

	Character c = d.construct();
	std::cout << c << std::endl;

}