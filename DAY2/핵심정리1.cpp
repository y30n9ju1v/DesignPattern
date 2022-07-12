// 핵심정리1

// 디자인 패턴의 핵심 1. 변하지 않은 코드 내부의 변하는 부분을 분리 하는것

// A. 변하는 것을 가상함수로
//	=> 파생 클래스를 만들어서 가상함수를 재정의 하라.
//  => "template method"
//  => 도형 편집기 Shape/Rect 의 Draw
//  => 실행시간 교체 안되고, 변하는 것(정책)를 다른 클래스에서는 사용못함


// B. 변하는 것을 다른 클래스로
//    => 정책(변하는것)을 담은 클래스를 교체하는 기술
//    1. 인터페이스를 만들어서 교체
//		=> 가상함수 기반 느리다.
//		=> 실행시간 교체 가능.  e.setValidate(&v1);
//						     e.setValidate(&v2);
//		=> Edit/IValidator 예제
//      => 전략 패턴(strategy)
// 
//	  2. 템플릿 인자로 교체.
//		=> Policy Base Design
// 		=> 빠르다. 
//		=> 실행시간 교체 안됨
//		=> vector 와 allocator,  List/mutex_locker

//List<int, nolock> s; // s는 항상 nolock 의 lock/unlock 만 사용가능합니다.
					// s를 mutex_locker를 사용하게 하는 방법은 없습니다.

// 디자인 패턴 : 언어에 무관하게 객체지향 프로그램에서 사용되는 디자인 기법
//             => template method, strategy

// Idioms : 각 언어의 특징을 맞게 사용되는 디자인 기법
//				=> C++ idioms, java idioms


// 속도 : 가상 함수 < 일반 함수 < 인라인 치환
// strategy vs policy base => 가상 함수 vs 인라인 치환 으로 생각 하세요

