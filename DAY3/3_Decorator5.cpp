#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const char* buff) 
	{
		printf("%s 쓰기\n", buff);
	}
};

int main()
{
	// C++은 소멸자를 활용하면 자동으로 자원 관리를 할수 있습니다.
	FileStream fs("a.txt");


	// C 언어는 사용자가 직접 자원을 관리해야 합니다
//	FILE* f = fopen("a.txt", "wt");
//	fclose(f);
}