// CRTP.cpp
// 상속 받을 때, static 변수나 함수는 
// 각 상속 받은 클래스의 것으로 종속 되는건가요?

// 객체를 5개만 만들게 하고 싶다.
class LimitCount
{
	static int cnt;
public:
	LimitCount() { if (++cnt > 5) throw 1; }
	~LimitCount() { --cnt; }
};
int LimitCount::cnt = 0;

// Mouse 와 Keyboard 도 5개만 만들게 하고 싶다.
class Mouse : public LimitCount
{
};
class Keyboard : public LimitCount
{
};
int main()
{
	Mouse m[3];
	Keyboard k[3];
}