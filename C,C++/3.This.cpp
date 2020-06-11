/* this pointer의 역할

 객체 내의 함수 PrintThis()에서 this pointer를 사용하게 되면
 this가 속해있는 객체의 주소값을 가르킨다.

*/

/* this pointer의 사용 이유

   class a         class b
   함수            함수

    객체 하나를 만들 때마다 함수를 만들면 메모리 많이 차지하는 문제
    메모리상으로 각 객체 밖의 메모리에 함수가 존재. 
    즉, 각 객체에서 PrintThis()의 함수를 실행해도  같은 메모리에서 가져온다.

    this pointer로 실행한 함수의 PrintThis()함수가  어느 객체에서 실행하는지 알기 위해서 사용

*/

#include<iostream>

using namespaces std;

class MYClass{
public:
    void PrintThis(){
        cout <<"나의 주소는" << this <<'\n';
    }
};

int main()
{
    MYClass a,b;
    cout << "a의 주소는" << &a << '\n';
    cout << "b의 주소는" << &b << '\n'; 

    a.PrintThis();
    b.PrintThis();
}