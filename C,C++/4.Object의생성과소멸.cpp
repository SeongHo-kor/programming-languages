// 생성자란? 객체가 생성될 때 자동으로 호출되는 함수
// 소멸자란? 객체가 소멸될 때 자동으로 호출되는 함수
// 생성자의 역할? 맴버변수 초기화
// 소멸자의 역할? 메모리 해제

#include<iostream>

using namespace std;

class MyClass{
public:
	MyClass() {
		cout << "생성자가 호출되었다." << '\n';
	}
	~MyClass() {
		cout << "소멸자가 호출되었다." << '\n';
	}

};

//MyClass GlobalObj;

void testlocalObj(){
	cout << "함수 시작!!" << '\n';
	MyClass localObj;
	cout << "함수 끝!!" << '\n';
}

int main() {
	cout << "main 함수 시작!!" << '\n';
	testlocalObj();
	cout << "main 함수 끝!!" << '\n';
	return 0;
}