#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Stream
{
public:
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}

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
		printf("%s 쓰기\n", s.c_str());
	}
};
//------------------------
// 다양한 Stream 과 Stream 의 기능 추가 객체는 공통의 기반 클래스 필요
// => Stream 으로 부터 파생..

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override
	{
		std::string s2 = s + " 압축됨"; // 추가된 기능(압축) 실행후

		stream->Write(s2);			   // stream 객체 전달
	}
};
class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override
	{
		std::string s2 = s + " 암호화"; 
		stream->Write(s2);			   
	}
};



int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello"); 

	ZipDecorator zd(&fs); 
	zd.Write("Hello");  
						

	EncryptDecorator ed(&zd);
	ed.Write("hello");  
						
}
