// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 

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

// Client 제작자는 "DLL의 이름"을 알지만 DLL안에 어떤 클래스가 있는지 알수 없습니다.
// 그래서 "new 클래스이름"을 할수 없습니다.
// DLL 안에 "약속된 이름"의 함수를 만들고 그 안에서 객체를 생성합니다
// DLL 이 update 되어도 "최소한 이 함수 이름" 은 반드시 지켜야 합니다.
extern "C" __declspec(dllexport)   // 윈도우 DLL 에서 함수 노출시 필요
ICalc* CreateProxy()
{
	return new CalcProxy;
}

