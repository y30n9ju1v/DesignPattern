// 방법 3. 정책 클래스 교체를 "인터페이스" 가 아닌 "템플릿 인자로"

// 인터페이스를 사용한다는 것은 "가상함수"를 사용한다는 의미
/*
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};
*/


template<typename T, typename ThreadModel > class List
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

List<int, nolock>       st;
List<int, mutex_locker> st2;

int main()
{
	st.push_front(10);
}




