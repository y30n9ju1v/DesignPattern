#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 
#include <memory>

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
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }

	~AutoPtr() { if (obj) obj->Release(); }

	// 스마트 포인터의 핵심 : -> 와 * 연산자를 재정의해서 진짜 포인터처럼 보이게하다.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	// C++ 표준에 이미 스마트 포인터가 있습니다.
	// AutoPtr 만들지 말고 shared_ptr 사용하면 안되나요 ?

	std::shared_ptr<ICalc> p1(ReloadProxy());
				// => 자동삭제 기능이 있지만!!
				// => 소멸자에서 "delete" 합니다.
				// => 즉, new 는 DLL에서 했는데..
				// => delete 는 실행파일에서 하고 있는 것입니다.

	AutoPtr<ICalc> p2(ReloadProxy());
				// => 이 스마트 포인터는 소멸자에서 "delete" 가 아니라
				// => Release() 호출입니다.
				// => Release()는 DLL내부 함수이고, 참조계수가 0되면 delete
				// => 즉, delete를 DLL 내부에서 합니다.

}






