#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	using FP = ICalc * (*)();
	FP f = (FP)ec_get_function_address(addr, "CreateProxy");
	ICalc* p = f(); 
	return p;
}

// 참조계수를 자동으로 관리하는 스마트포인터를 도입합니다.
// 스마트 포인터 : 포인터 역활의 객체, 생성/복사/대입/소멸의 과정에서 추가 기능수행
template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)       : obj(p) {}
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) {}

	~AutoPtr() {}
};

int main()
{
	AutoPtr<ICalc> p1 = ReloadProxy();
	AutoPtr<ICalc> p2 = p1;
}



/*
int main()
{
	ICalc* pCalc = ReloadProxy(); 

	pCalc->AddRef();		// 참조 계수 증가

	ICalc* pCalc2 = pCalc;	// 포인터를 복사해도

	pCalc2->AddRef();		// 참조계수 증가

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	pCalc->Release(); 

	std::cout << "------------" << std::endl;
	pCalc2->Release(); 

}


*/


