#include<iostream>

using namespace std;

class String {
public:
	String() {
		cout << "String() 생성자 호출" << '\n';
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "String(const char *str) 생성자 호출" << '\n';
		len = strlen(str);
		strData = new char[len + 1]; // NULL문자를 고려해 len+1만큼 할당
		cout << "strData 할당 : " << (void*)strData << '\n';
		// void* 사용 하지 않을 경우 컴파일러가 char를 가르키는 포인터인지 문자열을 가르키는지 모른다.
		// void*의 역할은 가르키고 있는 주소값만 갖을 수 있도록 형변환(char를 가르키는 포인터로 알아볼 수 있도록)
		strcpy(strData, str); // 깊은 복사
	}
	String(const String &rhs) {
		// strData = rhs.strData;// 얕은 복사

		cout << "String(String &rhs) 생성자 호출" << '\n';
		strData = new char[rhs.len + 1]; // NULL문자를 고려해 len+1만큼 할당
		cout << "strData 할당 : " << (void*)strData << '\n';
		strcpy(strData, rhs.strData); // 깊은 복사
		len = rhs.len; // 깊은 복사
	}

	~String() {
		cout << "~String() 소멸자 호출" << '\n';
		delete[] strData;
		cout << "strData:해제됨" << (void*)strData << '\n';
		strData = NULL;
	}
	String &operator=(const String &rhs) {
		if (this != &rhs) {
			delete[] strData;
			strData = new char[rhs.len + 1]; // NULL문자를 고려해 len+1만큼 할당
			cout << "strData 할당 : " << (void*)strData << '\n';
			strcpy(strData, rhs.strData); // 깊은 복사
			len = rhs.len; // 깊은 복사
		}
		return *this;
	}
	char *GetStrData()const {
		return strData;
	}
	int GetLen() const{
		return len;
	}
private:
	char *strData; //동적할당한 배열을 가르키는 포인터
	int len; // 배열의 길이
};

int main()
{
	String s1("안녕");
	String s2(s1);// 복사 생성자
	String s3("Hello");
	s3.operator=(s3);

	cout << s1.GetStrData() << '\n';
	cout << s2.GetStrData() << '\n';
	cout << s3.GetStrData() << '\n';
	/*
		s2.strData가 따로 할당 되지 않았는데 안녕이라고 출력 -> why s1.strData에 들어있는 주소값이 똑같이 복사(얕은복사)
	*/
	return 0;
}