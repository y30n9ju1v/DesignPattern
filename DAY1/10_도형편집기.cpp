// 10_도형편집기.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 모든 도형을 타입화하면 편리합니다.
// 2. 모든 도형의 공통의 부모가 있다면, 모든 도형을 묶어서 관리할 수 있습니다.
//   "동종을 보관하는 컨테이너" => Upcasting

// 3. 모든 자식의 공통의 특징이 있다면, 반드시 부모에도 있어야 합니다.
//    그래야 부모 포인터로 묶어서 사용할 때 해당 특징을 이용할 수 있습니다.
//    : LSP(Liskov Substitution Principle) 
//    => 자식의 공통의 기능이 반드시 부모로부터 비롯되어야 한다.

// 4. 부모의 함수중 자식이 재정의하는 모든 함수는 반드시 가상함수 이어야 합니다.
//    "가상 함수가 아닌 함수는 재정의하지 말라" => Effective C++ 격언

// 5. 부모 클래스는 반드시 가상 소멸자를 제공해야 합니다.

class Shape {
public:
	virtual ~Shape() {}

	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape {
public:
	void Draw() override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape {
public:
	void Draw() override { cout << "Circle Draw" << endl; }
};

int main()
{
	// vector<Rect*> rects;
	// vector<Circle*> circles;

	vector<Shape*> shapes;
	int cmd;

	while (1)
	{
		cin >> cmd;

		if (cmd == 1) shapes.push_back(new Rect);
		else if (cmd == 2) shapes.push_back(new Circle);

		else if (cmd == 9) {
			for (Shape* p : shapes)
				p->Draw();
		}
	}

}