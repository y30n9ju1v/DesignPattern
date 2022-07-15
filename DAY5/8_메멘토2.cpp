// 8_메멘토 - 178
#include <iostream>
#include <vector>


class Graphics
{
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::vector<Memento*> v; // 또는 map, unordered_map등

	int penWidth = 1;
	int penColor = 0;
	int temporary_data;
public:
	int Save()
	{
		Memento* p = new Memento;
		p->penColor = penColor;
		p->penWidth = penWidth;
		v.push_back(p);

		return v.size(); //몇번째 저장했는가를 token으로
						 // 이코드 보다는 map<key, Memento*> 가 좋긴합니다.
	}
	void Restore(int token)
	{
		penColor = v[token - 1]->penColor;
		penWidth = v[token - 1]->penWidth;
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // 객체의 상태를 저장했다가 복구 할수 있게 한다.
						  // "memento" 패턴
						  // 캡슐화를 위배 하지 않고
							// (즉,객체가 내부적으로 스스로 보관한다는 의미)
	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);
}









