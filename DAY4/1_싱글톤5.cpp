#include <iostream>
#include <mutex>

// mutex 등을 사용할때, lock/unlock 을 직접 하면
// 예외 등이 발생시 "deadlock" 의 위험이 있습니다.

// 항상 자원 관리는 "생성자/소멸자"를 사용해서 자동화 해야 합니다
// 이런 기술을 "RAII" 라고 부릅니다.

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
};



class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* sInstance;
public:


	static Cursor& getInstance()
	{
//		lock_guard<std::mutex> g(mtx);  // 생성자에서 mtx.lock() 수행
										// 소멸자에서 mtx.unlock() 
										// 
		std::lock_guard<std::mutex> g(mtx); // 이미 C++ 표준에 있습니다

	//	mtx.lock();		
		if (sInstance == nullptr)
		{
			sInstance = new Cursor;
		}
		//	mtx.unlock();


		return *sInstance;
	}


};
std::mutex Cursor::mtx;
Cursor* Cursor::sInstance = nullptr;




int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








