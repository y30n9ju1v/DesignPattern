// 방법 3. 정책 클래스 교체를 "인터페이스" 가 아닌 "템플릿 인자로"


// 정책 클래스를 교체 하는 2가지 방법
// 1. 인터페이스 기반으로 교체 : "strategy" 패턴
// 2. 템플릿 인자로 교체      : "policy base design"

// 장단점 - 잘 생각해 보세요

//				strategy			policy base
// 속도			가상함수기반(느리다)	인라인 함수(빠르다.)
// 실행시간 교체	실행시간 교체 가능		실행시간에 교체 할수 없다.
//				setSync(다른정책)

// 그런데, List 의 동기화 여부를 "실행시간에 교체" 할일은 없다.

// Policy Base Design 에서 정책 클래스는 "반드시 지켜야하는규칙"이 있게 되다.
// => 아래 List 의 동기화 정책은 반드시 "lock/unlock"이 필요하다.
// => 인터페이스로 만들지 않으므로, "문서화" 해야 한다.
//    이런 개념을 "named requirement" 라고 합니다.

// 주의!! 실제 "STL" 의 list는 "아래 처럼 되어있지 않습니다."
// => 1998 년 설계시는 "동기화는 고려하지 않고 디자인" 
// => 사용자가 사용시 동기화 해야 합니다.


// 인터페이스를 사용한다는 것은 "가상함수"를 사용한다는 의미
/*
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};
*/


template<typename T, typename ThreadModel = nolock> class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();

		//...... next, prev 등의 멤버 조작

		tm.unlock();
	}
};

//-----------------
// 다양한 동기화 방식의 동기화 정책을 담은 정책 클래스 제공
#include <mutex>

class mutex_locker 
{
	std::mutex m;
public:
	inline void lock()    { m.lock(); }
	inline void unlock()  { m.unlock(); }
};
class nolock
{
public:
	inline void lock() { }
	inline void unlock() {  }
};

//List<int, nolock>       st;
List<int>       st;
List<int, mutex_locker> st2;

int main()
{
	st.push_front(10);
}




