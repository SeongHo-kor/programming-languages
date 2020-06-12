/*
정적할당 int a;
동적 할당 프로그램 실행 중에 메모리에 원하는 공간을 할당하는 것

-동적 할당 과정
1. new -> int, 배열등 저장할 수 있는 공간을 만들어 그 주소값을 return;
2. 그 주소값을 받는다.
3. delete->메모리 공간을 해제
*/

#include<iostream>

using namespace std;

// 객체의 동적할당
class Vector2 {
public:
	Vector2() :x(0), y(0) {
		cout << this << " : Vector2()" << '\n';
	}
	Vector2(const float x, const float y) :x(x), y(y) {
		cout << this << " : Vector2(const float x, const float y)" << '\n';
	}
	~Vector2() {
		cout << this << " : ~Vector2()" << '\n';
	}

	float GetX() const { return x; }
	float GetY()const { return y; }

private:
	float x;
	float y;
};

int main()
{

	// 변수의 동적할당
	int *a = new int(5);

	cout << a << ' ' << *a << '\n';

    // 변수의 메모리 해제
	delete a;

	
	// 배열의 동적할당
	int *arr;
	int len;

	cout << "동적할당할 배열 길이 입력: ";
	cin >> len;

	arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << '\n';
	}
    
    // 배열의 메모리 해제
	delete[] arr;

	Vector2 s1 = Vector2();
	Vector2 s2 = Vector2(3, 2);

	Vector2 *d1 = new Vector2();
	Vector2 *d2 = new Vector2(3, 2);

	cout << "(" << d1->GetX() << "," << d1->GetY() << ")" << '\n';
	cout << "(" << d2->GetX() << "," << d2->GetY() << ")" << '\n';
	
    // 객체의 메모리 해제
    delete d1;
	delete d2;
    /*
    소멸자 순서
    동적할당 d1 -> d2 -> 정적할당 s2 -> s3
    */
}
