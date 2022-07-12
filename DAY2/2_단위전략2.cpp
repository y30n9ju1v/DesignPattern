
// 방법 1. 스레드 동기화 여부를 template method로 교체 가능하게..
//	=> 변하는 것을 가상 함수로.

template<typename T> class List
{
	// member data....
public:
	void push_front(const T& a)
	{
		lock();
		//...... next, prev 등의 멤버 조작
		unlock();
	}
	// 기본 구현은 동기화 안함.
	virtual void lock() {}
	virtual void unlock() {}
};
// 위 코드의 의도 : 동기화 하고 싶다면 List 파생 클래스를 설계해서
//					lock/unlock 을 재정의해서 동기화 방법을 제공해라!
#include <mutex>

template<typename T> class ThreadSafeList : public List<T>
{
	std::mutex m;
public:
	void lock() { m.lock(); }
	void unlock() { m.unlock(); }
};

//List<int> st; 
ThreadSafeList<int> st;

int main()
{
	st.push_front(10);
}




