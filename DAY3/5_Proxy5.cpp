#define USING_GUI
#include "cppmaster.h"

// 이제 클라이언트 제작자는 서버 제작자에게 2개의 파일을 받으시면 됩니다.

// ICalc.h       : 인터페이스가 담긴 헤더 파일
// CalcProxy.dll : Proxy 코드가 있는 DLL 

#include "ICalc.h" // 1. 헤더를 포함하고

// 2. DLL을 로드해서 약속된 함수를 호출한후 Proxy를 만들어서 사용
ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); // linux : dlopen()
												// windows : LoadLibrary()

	// DLL 안에서 약속된 함수 찾기
	using FP = ICalc* (*)();
	
	FP f = (FP)ec_get_function_address(addr, "CreateProxy");
										// linux : dlsym()
									  // windows : GetProcAddress()

	ICalc* p = f(); // Proxy 객체 생성

	return p;
}

int main()
{
	ICalc* pCalc = ReloadProxy();

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





