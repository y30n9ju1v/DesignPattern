#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); 
	using FP = ICalc * (*)();

	FP f = (FP)ec_get_function_address(addr, "CreateProxy");

	ICalc* p = f(); // DLL 내부에서 new CalcProxy 하므로.. 
					// 사용후에는 delete 해야 하지 않을까요?

	return p;
}

int main()
{
	ICalc* pCalc = ReloadProxy();

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

//	delete pCalc; // 좋은 코드일까요 ?
				  // DLL 내부에서 new 를 했으므로 
				  // delete 도 DLL 내부에서 하는 것이 좋습니다.
}





