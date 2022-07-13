// 1_메뉴이벤트8 - 5번 복사하세요
#include <iostream>
#include <algorithm>
#include <functional> 
using namespace std::placeholders; 

void foo(int a, int& b)
{
    b = 100;
}

int main()
{
    int n = 0;

    std::function<void(int)> f;

    f = std::bind(&foo, _1, n);

    f(5); // foo(5, n) 일까 ?  foo(5, 0) 일까 ?

    std::cout << n << std::endl;

}

