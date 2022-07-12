// 2_메뉴1.cpp  - 55 page
#include <iostream>

// 아래 코드는 쉽습니다... 
// 그런데
// 1. 메뉴가 추가되면.. 여러곳이 수정되어야 합니다.
// 2. 특정 메뉴에 대한 하위 메뉴가 있다면.. 코드가 복잡해 집니다.

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


