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
	ICalc* pCalc = ReloadProxy(); // 처음으로포인터를 얻으면

	pCalc->AddRef();		// 참조 계수 증가

	ICalc* pCalc2 = pCalc;	// 포인터를 복사해도

	pCalc2->AddRef();		// 참조계수 증가


	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	// 사용후에는 delete 가 아니라 참조 계수 감소
	pCalc->Release();  // 참조계수가 0이 아닌 1인 상태

	std::cout << "------------" << std::endl;
	pCalc2->Release(); // 이때 파괴..




//	delete pCalc; // 좋은 코드일까요 ?
				  // DLL 내부에서 new 를 했으므로 
				  // delete 도 DLL 내부에서 하는 것이 좋습니다.
}





