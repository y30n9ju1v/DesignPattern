// 8_메멘토 - 178
#include <iostream>


// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.

	// 1. 함수인자로 전달하자.
	// => windows의 gdi+ 라는 라이브러리가 이렇게 되어 있습니다.

	g.DrawLine(0, 0, 100, 100, red, 10);  // 색상, 두께 전달
	g.DrawLine(0, 0, 200, 200, blue, 20); // 색상, 두께 전달


	// 2. Graphics 객체의 속성값으로 관리하자.
	// => 애플의 cocoa touch 라이브러리가 이렇게 되어 있습니다.
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
}









