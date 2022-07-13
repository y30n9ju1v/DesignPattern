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

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	// 파일에 쓸때 압축해서 쓰는 기능이 필요 합니다. 
	// 어떻게 하는 것이 최선 일까요 ?
	// 1. 데이타를 먼저 압축하고 쓰자
	// => 이런일을 자주 한다면 매번 해야 하니까 불편 합니다.

	// 2. FileStream 안에 "zippedWrite" 를 만들자.
	// => NetworkStream, PipeStream 에도 만들어야 한다.
	// => 요구사항이 생길때 마다 "기존 클래스를 변경"하는 것은 좋지 않다. OCP위반

	// 3. 모든 스트림의 기반 클래스인 "Stream" 에 제공하자.
	// => 요구사항이 생길때 마다 "기존 클래스를 변경"하는 것은 좋지 않다. OCP위반

	// 4. 기존 클래스에 변경없이, 기능을 추가하는 객체를 만들면 어떨까!!
	// => Decorator

	fs.Write("Hello"); // 파일에 그냥쓰기 
	
	ZipDecorator zd(&fs); // Stream 객체에 압축 기능 추가
	zd.Write("Hello");  // 1. Hello 를 압축하고 <= 추가된 기능
						// 2. fs.Write()로 쓰기

	EncryptDecorator ed(&zd);
	ed.Write("hello");  // 1. hello 를 암호와 하고 <= 추가된 기능
						// 2. zd.Write()에 전달

	// FileStream 뿐아니라 NetworkStream 등 모든 Stream 에 적용가능
}
// Decorator			저장소		
// ZipDecorator			FileStream
// EncryptDecorator		NetworkStream
//						PipeStream