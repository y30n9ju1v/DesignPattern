#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// Image 객체를 만드는 static 멤버 함수
	// => 이제 객체는 아래 함수를 통해서만 만들수 있습니다.
	// => 객체를 "한곳"에서만 만든다는 것은 생성된 모든 객체를 "관리" 할수 있는
	//    기회가 생기게 됩니다.

	static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url)
	{
		if (image_map[url] == nullptr)
		{
			image_map[url] = new Image(url);
		}
		return image_map[url];
	}
//	static int image_count() { return 생성된image객체갯수; }
};
std::map<std::string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();
	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;
}



