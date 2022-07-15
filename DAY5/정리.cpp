// 정리 - 교재 마지막 페이지 참고(전체 패턴 목록)

// 핵심 1. 변하지 않는 것에서 변하는 것을 분리하는 것
//        (공통성과 가변성의 분리)

1. 변하는 것을 가상함수로 분리
   => 파생 클래스를 만들어서 가상함수를 재정의 하면 변경 가능.
//  template method : 알고리즘(정책)의 변화
//  factory method  : 어떤 객체를 생성할지 타입을 결정


2. 변하는 것을 다른 클래스로 분리
//  strategy : 객체가 사용하는 알고리즘의 교체
//  state    : 객체의 모든 동작을 교체
//  builder  : 복잡한 객체를 만드는데, 동일한 공정으로 만든다.
//				각 공정의 표현은 다를수 있다.


// 핵심 2. 재귀적 포함
// => A와 B를 묶고 싶다면 "공통의 기반 클래스를 설계 하라"

// composite : 재귀적 포함을 사용해서 "복합객체" 만들기
//				Folder/File, PopupMenu/MenuItem
// 
// decorator : 재귀적 포함을 사용한 객체에 동적 기능추가

// 핵심 3. 다양한 이유로 "간접층" 을 만드는 것

// 인터페이스의 변경     : adapter
// 사용하기 쉽게        : facade
// update 를 독립적으로 :  bridge
// 범용적인 용도의 대행자 : proxy


// 핵심 4. 통보, 열거, 방문, 중재

// 1의 변화를 N에 통보 : Observer

// 복합객체의 열거를 동일한 방법으로 : iterator

// 복합객체의 요소에 대한 연산을 수행 : visitor

// M : N의 관계를 1 : N의 관계로 변경 : mediator



// 각 패턴은 용도에 따라 3가지로 분류 됩니다

// 생성 패턴 5가지 
// => singleton, abstract factory, factory method, prototype, builder 

// 구조 패턴 7가지
// => composite, decorator
// => adapter, proxy, facade, bridge
// => flyweight 

// 행위 패턴 11가지 
// => strategy, template method   => 변하는 것 분리
// => iterator, visitor   
// => command, memento, 
// => mediator, chain of responsibility
// => state
// => observer, 
// => interpret => 컴파일러등을 만들때 사용. 지금은 거의 사용되지 않음.. 

