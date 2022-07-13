// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 
#include <atomic> 

class CalcProxy : public ICalc
{
	int server_handle;
	
	std::atomic<int> ref_cnt = 0; // 참조계수. 멀티스레드 안전

public:

	void AddRef() { ++ref_cnt; }

	void Release() { if (--ret_cnt == 0) delete this; }

	~CalcProxy() { std::cout << "~CalcProxy" << std::endl; }



	CalcProxy()
	{
		server_handle = ec_find_server("Calc");
	}
	int Add(int a, int b) { return ec_send_server(server_handle, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server_handle, 2, a, b); }
};

extern "C" __declspec(dllexport)  
ICalc * CreateProxy()
{
	return new CalcProxy;
}

