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




int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



