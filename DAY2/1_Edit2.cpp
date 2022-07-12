#include <iostream>
#include <string>
#include <conio.h>

// 교재 28 page ~ 

// Edit 를 설계 할때는 사용자가 Validation 정책을 변경할수 있게 설계 되어야 합니다
// 방법 1. 
class Edit
{
	std::string data;
public:
	// 핵심 1. 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 부분을 찾아서 분리한다.
	// => 변하는 부분을 가상함수로 분리한다.
	virtual bool validate(char c)
	{
		return true;
	}
	
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (validate(c)) // 변하는 부분은 "가상함수호출" 로 
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};

// 이제 validation 정책을 변경하려면 "Edit"로 부터 파생 된 클래스를 제공합니다
// => 기존 클래스(Edit) 의 변경이 아닌
// => Edit 의 확장을 통한 기능의 변경
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



