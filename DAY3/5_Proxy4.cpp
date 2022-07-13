#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

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


// 위 CalcProxy 클래스는 누가 제작하는 걸까요 ?

// 1. 클라이언트 제작자
// 2. 서버 제작자 => 정답
// Proxy 는 서버 제작자가 작성해서
// 클라이언트 제작자들에게 배포 하는 것입니다.

int main()
{
	// 아래 코드처럼 클라이언트에서 proxy 이름을 바로 사용하면
	// "강한결합(tightly coupling)" 입니다.
	// 새로운 proxy 가 나오면 client 코드가 수정되어야 합니다.
	// CalcProxy* pCalc = new CalcProxy;

	// proxy 변경시, 코드수정이 없으려면 약한결합(loosely coupling)
	// 이 되어야 합니다.
	// 즉, 인터페이스 기반으로 사용해야 합니다

	ICalc* pCalc = new ? ;



	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





