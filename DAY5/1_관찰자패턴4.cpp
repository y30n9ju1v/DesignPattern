#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}

	Subject* subject;

	// MFC/QT 에 GetDocument() 라는 함수가 있습니다.
	virtual Subject* getSubject() { return subject; }
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
	// 가상함수 재정의시 반환 타입을 변경할수 있다.. 라는 문법이 있습니다.
	Table* getSubject() override 
	{
		return static_cast<Table*>(subject); 
	}

	void Update(int n) override
	{
		Table* table = getSubject(); // 자신과 연결된
									// Subject(Table)의 포인터 얻기

		int data = table->getData();


		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};



int main()
{
	Table t;

	BarGraph bg; t.attach(&bg);

	t.edit(); 
}



