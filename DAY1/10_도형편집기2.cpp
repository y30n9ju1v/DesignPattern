// 10_도형편집기2.cpp

#include <iostream>
#include <vector>
using namespace std;

// 요구사항: Draw 기능이 멀티 스레드에서 안전하게 동기화되어야 합니다.
#include <mutex>

// mutex m;
class Mutex {
public:
	void lock() { cout << "Mutex lock" << endl; }
	void unlock() { cout << "Mutex unlock" << endl; }
};

Mutex m;

// "공통성과 가변성의 분리" 설계 원칙
// : 변하는 것과 변하지 않는 것을 분리해야 합니다.
//  => 멤버 함수에서 분리하는 방법
//   - 변하지 않는 것을 일반 함수로 두고, 변하는 것을 가상 함수로 뽑아냅니다.
//   : Template Method Pattern, NVI(Non Virtual Interface)
//    변하지 않는 전체 알고리즘은 부모가 비가상함수를 통해 제공하고,
//    변하는 부분만 가상함수화해서 자식이 변경할 수 있도록 하는 설계 방법.

class Shape {
public:
	virtual ~Shape() {}

	void Draw() { 
		//m.lock();
		DrawImpl();
		//m.unlock();
	}

	virtual void DrawImpl()
	{
		cout << "Shape Draw" << endl;
	}

	virtual Shape* Clone() = 0;

};

class Rect : public Shape {
public:
	void DrawImpl() override {
		cout << "Rect Draw" << endl; 
	}

	// 공변 반환의 법칙
	// : 부모 멤버 함수의 반환값을 하위 클래스로 변경하는 것을 허용합니다.
	//  => 템플릿
	Rect* Clone() override { return new Rect(*this); }
};

class Circle : public Shape {
public:
	void DrawImpl() override { 
		cout << "Circle Draw" << endl; 
	}

	Circle* Clone() override { return new Circle(*this); }

};

class Triangle : public Shape {
public:
	void DrawImpl() override {
		cout << "Triangle Draw" << endl;
	}

	Triangle* Clone() override { return new Triangle(*this); }

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
		else if (cmd == 3) shapes.push_back(new Triangle);

		// 도형을 복제하고 싶습니다.
		else if (cmd == 8) {
			int index;
			cin >> index;

			shapes.push_back(shapes[index]->Clone());
			// Replace type code with polymorphism


			// Rect? Circle?
			//  => 아래 처럼 구현할 경우 새로운 도형이 추가될 때마다,
			//     코드는 변경되어야 합니다.
#if 0
			if (typeid(*shapes[index]) == typeid(Rect)) {
				shapes.push_back(new Rect(*static_cast<Rect*>(shapes[index])));
			}
			else if (typeid(*shapes[index]) == typeid(Circle)) {
				shapes.push_back(new Circle(*static_cast<Circle*>(shapes[index])));
			}
#endif
		}

		else if (cmd == 9) {
			// 다형성은 OCP를 만족합니다.
			// "새로운 기능이 추가되어도 기존 코드를 수정할 필요가 없습니다."
			for (Shape* p : shapes)
				p->Draw();
		}
	}

}