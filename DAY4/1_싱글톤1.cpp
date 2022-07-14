// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
// => 오직 한개의 객체만 존재하고
// => 어디서든 동일한 방법으로 객체에 접근할수 있다.(Cursor::getInstance())

// 싱글톤 패턴에 대한 좋지 않은 시선 
// => 결국 전역 변수 이다.!! 전역변수는 좋지 않다.

// 싱글톤을 구현하는 방법은 아주 다양합니다.
// 아래 처럼 "static 지역변수"로 구현하는 모양 
// => effective-C++ 의 저자인 "scott-meyer" 가 처음 제안..
// => "mayer's singleton" 이라고 합니다.


class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사 생성자와 대입연산자도 "컴파일러가 자동생성할수 없게 한다"
	
	// C++98 시절 방법 
	// => 사용자가 "private 영역에 선언만" 만든다.
	// 1. 사용자가 선언했으므로 컴파일러는 제공안함
	// 2. 복사 생성자를 사용하는 코드가 없으면 문제 없음
	// 3. 복사 생성자를 사용하는 코드가 있으면 링크에러 - 결국 복사될수 없다는의미
//private:
//	Cursor(const Cursor& c);
//	Cursor& operator=(const Cursor&);

	// C++11 이후
	// 결국 위 기술의 의도는 "컴파일러가 복사 생성자를 만들지 못하게" 하려는 의도
	// C++11 부터는 함수 삭제 문법 사용
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
				// 복사 생성자를 삭제 하면 관례적으로 대입연산자도 삭제 합니다.

	// 규칙 3. 오직 한개의 객체를 생성해서 반환하는 "static 멤버 함수"
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // "복사생성자" 호출..
					// 이렇게 만드는 것도 할수 없게 해야 합니다.
					// 복사 생성자를 삭제 하면 error.


//	Cursor c1, c2;
}








