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
	AutoPtr(T* p = nullptr)       : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }

	~AutoPtr() { if (obj) obj->Release(); }

	// 스마트 포인터의 핵심 : -> 와 * 연산자를 재정의해서 진짜 포인터처럼 보이게하다.
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};
int main()
{
	AutoPtr<ICalc> p1 = ReloadProxy(); // AutoPtr<ICalc> p1( ReloadProxy() );
	AutoPtr<ICalc> p2 = p1;

	int n = p1->Add(10, 20); // 이 코드가 되어야 합니다.

	std::cout << n << std::endl;
}
// 위코드가 결국 아래 코드와 동일합니다.
// 그런데, 스마트포인터 덕분에 "AddRef/Release" 의 호출이 자동으로 됩니다.
// 단, 위 AutoPtr 에는 대입연산자도 만들어야 합니다(숙제로 해보세요)
// C++11 가능하신 분은 "move" 도 제공해 보세요


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


