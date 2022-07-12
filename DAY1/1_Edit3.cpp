#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리
// 2. 변하는 것을 다른 클래스로 분리 - 변해야 하므로 교체가 가능해야 한다.
//								- 인터페이스 기반의 약한 결합을 사용해야 한다.

// 모든 validation 정책은 아래 인터페이스를 구현해야 한다.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; };

	virtual ~IValidator() {}
};
// 주민 등록번호 : 9211 1     확인


class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (isdigit(c)) 
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



