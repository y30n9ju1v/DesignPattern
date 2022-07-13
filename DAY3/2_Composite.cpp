#include <iostream>
#include <vector>
#include <string>

// 복합 객체(Folder)는 개별 객체(File)을 보관하지만
// 복합 객체 자신도 보관할수 있습니다.
// => 복합객체와 개별객체는 공통의 기반 클래스가 필요합니다.

class Item
{
	std::string name;
public:
	Item(const std::string& n) : name(n) {}

	// 파일은 자신만의 크기가 있고
	// 폴더는 자신만의 크기는 없지만, 크기를 구할수는 있습니다.
	virtual int get_size() const = 0;
};
// 결국 위 코드는 "BaseMenu" 의 코드 형태와 거의 유사한 모양입니다.

class File : public Item
{
	int size;
public:
	File(const std::string& name, int sz) : Item(name), size(sz) {}

	int get_size() const override { return size; }
};

class Folder : public Item
{
	std::vector<Item*> v; // Composite 패턴의 핵심.. "Item*" 보관
public:
	Folder(const std::string& name) : Item(name) {}

	void add_item(Item* p) { v.push_back(p); }

	int get_size() const override
	{
		// 구현해 보세요 - 핵심!!
	}
};

// 아래 함수 이름 변경해서 실행해 보세요(getSize => get_size, 
//								   addItem => add_item)
// Item 에 가상소멸자 추가해 주세요 "virtual ~Item(){}"

int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	cout << f2->getSize() << endl; // 20
	cout << fo1->getSize() << endl; // 10
	cout << root->getSize() << endl; // 30
}

