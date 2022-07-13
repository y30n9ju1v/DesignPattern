#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 모든 종류의 Stream 은 사용법이 동일해야 한다.
// 인터페이스로 설계 합니다.
class Stream
{
public:
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}

	// 그외에 모든 Stream 의 공통의 특징도 제공합니다.
	// bool isopen() {} 등..
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

//	NetworkStream ns("200.200.200.100", 4000);
//	ns.Write("hello");

//	PipeStream ps("named pipe");
//	ps.Write("hello");

}