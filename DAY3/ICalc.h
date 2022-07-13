// ICalc.h
#pragma once

// 이 모델을 가지고 여러개 서버를 사용하는 경우.
// 모든 인터페이스에는 수명을 관리하는 함수가 필요 하게 된다.
// 기반 클래스(인터페이스)로 분리하자

struct IRefCount
{
	// 객체의 수명을 참조계수로 관리하고..
	// 약한 결합(인터페이스)를 사용해서 객체를 사용하기로 했다면
	// 인터페이스 안에 반드시 객체의 수명을 관리하는 함수의 선언이 포함되어야 합니다
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};
struct ILed : public IRefCount
{
	virtual void LedOn() = 0;
	virtual void LedOff() = 0;
	virtual ~ILed() {}
};
