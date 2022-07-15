#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std;
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function< void(void*) >;

	std::map<std::string, std::vector<HANDLER> > notif_map; // 이 자료구조가 핵심 입니다.
public:
	void addObserver(std::string key, HANDLER handler)
	{
		notif_map[key].push_back(handler);
	}

	void postNotificationWithName(std::string key, void* hint)
	{
		std::vector<HANDLER>& v = notif_map[key];
		// 등록된 모든 함수 호출
		for (auto f : v)
			f(hint);
	}

	// global 통보센터라는 개념을 만들어 봅시다.
	// 문서화 할때 "global 통보센터를 얻으려면 defaultCenter() 함수를 호출해라" 라고 문서화 합니다.
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter nc;
		return nc;
	}
};
//----------------------------------------------
void foo(void* p)        { cout << "foo : " << (int)p << endl; }
void goo(void* p, int a) { cout << "goo : " << (int)p << endl; }

int main()
{
	// 아래 처럼 사용자가 만들어도 되고(Local 통보센터)
	NotificationCenter nc;

	// 아래 처럼 오직 한개만 존재하는 global 통보센터 도 얻을수 있게 합시다.
	NotificationCenter& center = NotificationCenter::defaultCenter();

	// 도전 과제.
//	nc.addObserver("LOWBATTERY", &foo, NEWTHREAD );

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0) );

	nc.addObserver("LOWBATTERY", [](void* p) { std::cout << "lambda " << reinterpret_cast<long long>(p) << std::endl; } );

	nc.addObserver("DISCONECT_WIFI", &foo);


	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}

// 오늘 나온 패턴
// Composite 패턴
// Chain Of Responsibility : 책임의 전가

// 어제 : template method, strategy, prototype, adapter
// 
// 내일 : 간접층, proxy, facade, bridge, adapter, decorator...  

