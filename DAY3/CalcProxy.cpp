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

// 빌드하는 법
// 1. visual studio 의 C/C++ 컴파일러의 이름은 cl.exe 입니다.
// 2. 시작 버튼을 누르고 "visual studio 폴더"를 찾으세요..
//    => 개발자 명령 프롬프트(Develop Command prompt) 를 실행하세요
// 3. 실행되는 창에서 cl 이라고 입력후 enter 해보세요

// 4. 현재 소스가 있는 폴더로 이동 하세요.
// 드라이브 이동 : D: 하고 enter
// 폴더이동     : cd \   루트로
//			    cd 원하는 폴더

// cl CalcProxy.cpp /LD /link user32.lib kernel32.lib gdi32.lib

// /LD   : DLL로 빌드해달라.
// /link : 해당 라이브러리와 링크해달라(IPC를 위해 윈도우즈API 사용)


