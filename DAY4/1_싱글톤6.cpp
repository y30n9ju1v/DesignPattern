#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern (C++ IDioms)

// => 기반 클래스 설계시 파생 클래스의 이름을 사용할수 있게 하는 기술
// => 기반 클래스가 템플릿 인데, 파생 클래스 만들때 자신의 이름을 템플릿 인자로
//    전달하는 기술

template<typename TYPE>
class Singleton
{
protected:
	Singleton() {}

private:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex mtx;
	static TYPE* sInstance;  // <<=====
public:
	static TYPE& getInstance() // <====
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (sInstance == nullptr)
		{
			sInstance = new TYPE;  // <===
		}
		return *sInstance;
	}
};
template<typename TYPE> std::mutex Singleton<TYPE>::mtx;
template<typename TYPE> TYPE* Singleton<TYPE>::sInstance = nullptr;


// Keyboard 도 힙에 만드는 싱글톤 기법을 사용하고 싶다.
class Keyboard : public Singleton< Keyboard >
{

};



int main()
{
}








