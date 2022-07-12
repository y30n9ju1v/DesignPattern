#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리
// 2. 변하는 것을 다른 클래스로 분리 - 변해야 하므로 교체가 가능해야 한다.
//								- 인터페이스 기반의 약한 결합을 사용해야 한다.

// 모든 validation 정책은 아래 인터페이스를 구현해야 한다.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; };

	virtual ~IValidator() {}
};
// 주민 등록번호 : 9211 1     확인

class Edit
{
	std::string data;
	
	IValidator* pVal = nullptr;
public:
	void setValidator(IValidator* p) { pVal = p; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pVal == nullptr || pVal->iscomplete(data))   ) break;

			if ( pVal == nullptr || pVal->validate(data,c) ) // 값의 유효성 확인을 외부의 
			{							  // 다른 객체에 위임.
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};
// 이제 다양한 validation 정책을 담은 정책 클래스를 제공하면 됩니다.
class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}
};
int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v);  // edit 에 validation 정책 연결

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



