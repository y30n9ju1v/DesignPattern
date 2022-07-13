#include <iostream>
#include <algorithm>
#include <functional>  // std::bind 를 위한 헤더.
using namespace std::placeholders; // _1, _2 를 사용하기 위해

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수..

    // std::bind : M항 인자를 N 항 인자로 변경하는 도구(단, M > N )

    // std::bind( M항함수, M개인자 )

    std::bind(&foo, 1, 2, 3, 4) (); // foo(1,2,3,4) 의 의미
    //|<- 이 결과가 새로운 함수 ->|     // 즉, 4항 함수 => 0항 함수로변경


    std::bind(&foo, 4, _1, 8, _2)(10, 20); // foo(4, 10, 8, 20) 의 의미
    //|<- 이 결과가 새로운 2항함수 ->|          // 4항 함수 => 2항 함수로 변경

    
    // 아래 코드 완성해 보세요   4항 함수 => 3항 함수로 변경한것
    std::bind(&foo, _2 , _3 , 2 , _1 )(3, 8, 9); // foo(8, 9, 2, 3)
}










// github.com/codenuri/hddp 

// "DAY3_사전소스.zip" 받으시면 됩니다.

// 압축 풀고 "DAY3" 프로젝트 여시면 됩니다.

// "server" 프로젝트는 오후에 사용할 예정입니다.
