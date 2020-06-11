#include<iostream>

using namespace std;

int n;

void set() {
	::n = 10; // 명시적 전역변수
}

namespace doodle {
	int n;
	void set() {
		//doodle::n = 20;
		n = 20; // 전역변수의 n or doodle의 n
	}
	namespace google {
		int n;
		void set()
		{
			//google::n = 30
			//::n = 30;//전역변수의 n;
			n = 30;
		}
	}
}

// 특정한 namespace 안에서 변수,함수의 소속을 밝히지 않았을 경우 
// 자기 자신이 속해있는 namespace로 지정;

int main()
{
	::set();
	doodle::set();
	doodle::google::set();
	cout << ::n << '\n';
	cout << doodle::n << '\n';
	cout << doodle::google::n << '\n';
}

