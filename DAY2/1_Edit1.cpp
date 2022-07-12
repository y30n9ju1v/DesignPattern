#include <iostream>
#include <string>
#include <conio.h>

// 교재 28 page ~ 

// 사용자의 입력을 validation 하는 기능을 추가해 봅시다.
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

			if (c == 13) break; // enter key 입력  \r:enter, \n:개행

			if (isdigit(c)) // validation(숫자인지 확인)
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



