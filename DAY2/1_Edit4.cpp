#include <iostream>
#include <string>
#include <conio.h>

// 질문) 일급함수(함수포인터)로 validation 함수를 파라미터로 getData로 넘기는 방식으로 
// 설계하는 것 중 어떤게 더 나을까요?

class Edit
{
	std::string data;
	
	using VALIDATOR = bool(*)(char); // 함수포인터타입
	
	VALIDATOR validate = nullptr; // 함수 포인터 변수
public:
	void setValidator(VALIDATOR val) { validate = val; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if ( validate == nullptr || validate(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};

bool validate(char c) { return isdigit(c); }


int main()
{
	Edit e;
	e.setValidator(&validate);

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



