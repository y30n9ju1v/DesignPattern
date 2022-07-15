#include <iostream>
#include <vector>

// Table 이 변경시 그래프를 다시 그리려면 Graph 에서 Table의 데이타를 알아야 합니다
// Table 이 Graph 에 전달 하는 방식          : Push 방식
// Graph 가 Table 에 접근 해서 꺼내 가는 방식 : Pull 방식

class Subject; // 클래스 전방 선언

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}

	// 그래프도 자신이 연결된 Table(Subject)를 알아야 접근할수 있다.
	Subject* subject; 
};

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p);
		p->subject = this;
	}
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	virtual ~Subject() {}
};


class Table : public Subject
{

	int value; // table 의 data 값
public:

	// Table이 가진 다양한 데이타를 꺼낼수 있는 함수 제공
	int getData() const { return value; }   


	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};



//----------------------
class BarGraph : public IGraph
{
public:
	// Table 변경시 아래 함수가 호출됩니다. 이때
	// 1. Table 의 어떤 데이타가 변경되었는지 함수 인자로도 통보 받을수 있고
	// 2. 이 함수 안에서 Table의 멤버 함수를 호출해서 얻어도 됩니다.

	void Update(int n) override
	{
	//	int data = subject->getData();  // error
		// subject 는 Table을 가리키지만 타입이
		// Subject* 입니다. 
		// 그래서, Table 고유의 멤버에 접근이 안됩니다.

		// 그래서 항상 이 디자인에서는 캐스팅이 등장하게 됩니다.
		Table* table = static_cast<Table*>(subject);

		int data = table->getData();

		// MFC의 "Doc/View" 구조, QT "Model/View"
		// java, C# 의 MVC 등이 모두 이 패턴인데..
		// 항상 캐스팅이 등장하는 됩니다.



		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};




class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

class LineGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Line Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "-";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;

	// 그래프 객체를 만들고 Table에 부착
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	LineGraph lg; t.attach(&lg);

	t.edit(); // Table 편집 모드로 .. 
}



