#define USING_GUI
#include "cppmaster.h"

// proxy 패턴    : 기존 요소를 대신하는 대행자를 만드는 패턴
// remote proxy : 원격지 서버를 대신하는 클래스!

// proxy : 함수 호출(Add()) 를 명령코드(1)로 변경해서 서버에 전달
// stub  : 도착한 명령 코드를 다시 함수호출로 변경(서버의 handler 가 stub)

// 흔히, "proxy-stub" 통신 이라고 표현하곤 합니다.

// 원격지 서버의 역활을 대신할 클래스를 설계 합니다.
class CalcProxy
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





