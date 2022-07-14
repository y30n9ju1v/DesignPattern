
template<typename T> 
class LimitCount
{
	static int cnt;
public:
	LimitCount() { if (++cnt > 5) throw 1; }
	~LimitCount() { --cnt; }
};
template<typename T> int LimitCount<T>::cnt = 0;


class Mouse : public LimitCount<Mouse>
{
};
class Keyboard : public LimitCount<Mouse>
{
};
int main()
{
	Mouse m[3];
	Keyboard k[3];
}