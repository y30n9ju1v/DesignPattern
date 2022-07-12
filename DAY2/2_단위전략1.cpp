// 37 page

template<typename T> class List
{
	// member data....
public:
	void push_front(const T& a)
	{
		// 방법 2. 멤버 함수 안에서 동기화 한다.(thread-safe class )
		mutex.lock();
		//...... next, prev 등의 멤버 조작
		mutex.unlock();
	}
};
List<int> st; // 전역변수는 멀티스레드에 안전하지 않습니다.

int main()
{
	// 방법 1. 멤버 함수 호출시 동기화 하거나. 
//	mutex.lock();
	st.push_front(10);
//	mutex.unlock();
}




