// 방법 2. 변하는 것을 다른 클래스로
//  => "strategy(전략) 패턴"

struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

template<typename T> class List
{
	ISync* pSync = nullptr;
public:
	void setSync(ISync* p) { pSync = p; }

	void push_front(const T& a)
	{
		if (pSync != nullptr) pSync->lock();
 		//...... next, prev 등의 멤버 조작
		if (pSync != nullptr) pSync->unlock();
	}
};
//-----------------
// 다양한 동기화 방식의 동기화 정책을 담은 정책 클래스 제공
#include <mutex>

class mutex_locker : public ISync
{
	std::mutex m;
public:
	void lock() override   { m.lock(); }
	void unlock() override { m.unlock(); }
};

List<int> st;

int main()
{
	mutex_locker m;
	st.setSync(&m); // 동기화 정책 전달
	st.push_front(10);
}




