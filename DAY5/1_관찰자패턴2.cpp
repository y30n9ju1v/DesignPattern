//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


// 모든 Graph 의 공통의 인터페이스
struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};

// Table 이 다루는 데이타의 형태가 변경되어도
// 관찰자 패턴의 기본 로직은 동일하다
// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계한다.

// 관찰의 대상을 "Subject" 라고 합니다.
class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	virtual ~Subject() {}
};

// 이제 관찰자 패턴을 사용하려면 "Subject" 로 부터 파생되면 됩니다.
class Table : public Subject
{
	int value; // table 의 data 값
public:
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
	void Update(int n) override
	{
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



