//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


// 모든 Graph 의 공통의 인터페이스
struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};



class Table
{
	std::vector<IGraph*> v;
	int value; // table 의 data 값
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			
			std::cin >> value; // 데이타가 수정되면

			notify(value);		// 등록된 모든 그래프에 통보 한다.
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



