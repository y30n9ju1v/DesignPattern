#include <iostream>

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 자신이 먼저 처리를 시도 한다.
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	// 문제를 처리하는 함수
	virtual bool HandleRequest(int problem) = 0;
};

//--------------
class TenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem)
	{
		std::cout << "TenHandler Start" << std::endl;

		if (problem == 10)
		{
			std::cout << "TenHandler 가 처리 완료" << std::endl;
			return true;
		}
		return false;
	}
};
class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem)
	{
		std::cout << "OddHandler Start" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "OddHandler 가 처리 완료" << std::endl;
			return true;
		}
		return false;
	}
};
int main()
{
	TenHandler h1;
	OddHandler h2;
	h1.next = &h2;

	// 문제가 발생하면 1번째 팀에게 전달
//	h1.Handle(10); 
//	h1.Handle(11);
	h1.Handle(12);
}
// 위 패턴이 "Chain Of Responsibility" 입니다.



