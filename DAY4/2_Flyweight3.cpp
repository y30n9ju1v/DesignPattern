#include <iostream>
#include <string>
#include <map>
#include "helper.h"


class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};

// Image 객체의 생성과 관리는 별도의 클래스에서..
class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)
	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		// image_map["키값"] 으로 적으면 "키값"이 없는경우, "키값"생성이 됩니다.
		// 단지, "키값"이 있는지만 조사하려면 아래 처럼하는 것이 좋습니다.

		auto ret = image_map.find(url); // 이렇게 조사한후

		if (ret == image_map.end())		// 이렇게 비교해서 없는지 확인!!
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = ret->second;  // <== 이부분이 빠졌네요..


		// 참고 : C++20 부터는 좋은 멤버 함수가 추가됩니다.(contain)
//		if ( !image_map.contain(url) ) {}

		return img; 
	}
	//....
};




int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;
}



