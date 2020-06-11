#include<iostream>

using namespace std;

class Complex {
public:
	//초기화 목록
	
	
    //overloading 하지 않고 같은 기능으로 사용 가능 = defualt 매개변수
	//생성자 위임
	Complex() :real(0), imag(0) {}
    
    //overloading 가능
	Complex(double real_) :Complex() {
		real = real_;
	}
	Complex(double real_, double imag_) :Complex(real_) {
		imag = imag_;
	}

	double GetReal() {
		return real;
	}
	double GetImag() {
		return imag;
	}
	double SetReal(double real_) {
		real = real_;
	}
	double SetImag(double imag_) {
		imag = imag_;
	}
private:
	double real;
	double imag;
};


int main()
{

	return 0;
}