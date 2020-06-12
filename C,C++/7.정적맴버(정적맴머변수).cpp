// private내의 맴버매소드나 맴버변수에 접근하고 싶을 때 정적메소드로 사용
// 전역변수로 썼을 경우 프로그래밍 난잡 -> static을 사용하면 가능

#include<iostream>
using namespace std;


class Color {
public:
	Color() :r(0), g(0), b(0), id(idCounter++){}
	Color(float r, float g, float b) :r(r), g(g), b(b), id(idCounter++){}

	float GetR() { return r; }
	float GetG() { return g; }
	float GetB() { return b; }
	
	int GetID() { return id; }

	static Color MixColors(Color a, Color b) {
		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}
	static int idCounter;

private:
	float r;
	float g;
	float b;	
	int id;
};

int Color::idCounter = 1;

int main() {
	Color red(1, 0, 0);
	Color blue(0, 0, 1);

	Color purple = Color::MixColors(blue, red);

	cout << purple.GetR() << ' ' << purple.GetG() << ' ' << purple.GetB() << '\n';
	cout << red.GetID() << ' ' << blue.GetID() << ' ' << purple.GetID() << '\n';
}