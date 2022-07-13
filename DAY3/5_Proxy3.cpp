#define USING_GUI
#include "cppmaster.h"

// RPC( Remote Procedure Call ) 
// => 다른 프로세스의 함수를 호출하는 개념
// => java 의 RMI ( Remote Method Invocation )

// 서버와 Proxy 는 동일한 함수이름를 사용하는것을
// 약속하기 위해 인터페이스 설계
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class CalcProxy : public ICalc
{
	int server_handle;
public:
	CalcProxy()
	{
		server_handle = ec_find_server("Calc");
	}
	int Add(int a, int b) { return ec_send_server(server_handle, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server_handle, 2, a, b); }
};

int main()
{
	CalcProxy* pCalc = new CalcProxy;

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





