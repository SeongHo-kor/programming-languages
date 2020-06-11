// struct vs class
// class는 자료저장 + 자료처리 = 변수 + 함수 -> 변수와 함수를 묶놓은  타입
// class(타입)는 특정한 용도를 수행하기 위한 변수와 함수를 모아둔 틀(자료형)
// object(객체)는 그 틀을 이용하여 찍어낸 개체(변수, 메모리상의 공간)
#include<iostream>

using namespace std;

class TV
{
public:
    void on(){
        powerON=true;
        cout<<"TV를 켰습니다."<<'\n';
    }
    void off() {
		powerOn = true;
		cout << "TV를 껏습니다." << '\n';
	}
	void setVolume(int vol) {
		if (vol >= 0 && vol <= 100)
		{
			volume = vol;
			cout << "볼륨을" << vol << "(으)로 바꿨습니다" << '\n';
		}
	}
	void setChannel(int ch) {
		if (ch >= 0 && ch <= 100)
		{
			Channel = ch;
			cout << "채널을" << ch << "(으)로 바꿨습니다" << '\n';
		}
	}
private:
    bool powerON;
    int Channel;
    int Valume;
};

int main()
{
    TV LG;
    LG.on();
    LG.setChannel(10);
    LG.setVolume(50);
    LG.off();
    // class TV의 맴버변수 Volume는 접근 불가능, 메소드를 이용해 접근가능
    // 캡슐화: 내부적인 속성은 보호하면서 외부 사용자들이 내부적인 속성을 접근 할 수 있는 인터페이스를 제공하는 것
}