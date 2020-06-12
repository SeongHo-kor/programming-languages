//const
//1. 매개변수의 상수의 상수화(모든 함수)
//2. 매서드(클래스의 포함된 함수)의 상수화(맴버 매서드)
// 변하지 않는 변수, 매서드를 const로 상수화 하기.

#include<iostream>

using namespace std;

class Account{
public:
	Account() :money(0) {}
	Account(int money) : money(money) {}

	//매개변수의 상수화
	void Deposit(const int d) {
		money += d;
		cout << d << " 원을 예금했다." << '\n';
	}
	void Withdraw(int d) {
		if (money >= d) {
			money -= d;
			cout << d << " 원을 인출했다." << '\n';
		}
	}
	//맴버 매서드의 상수화
	int ViewMoney() const{
		return money;
	}

private:
	int money;
};

int main() {
	Account doodle(100);
	doodle.Deposit(100);
	doodle.Withdraw(20);
	cout << doodle.ViewMoney() << '\n';
}