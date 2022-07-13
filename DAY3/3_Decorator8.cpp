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
		printf("%s ¾²±â\n", s.c_str());
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
