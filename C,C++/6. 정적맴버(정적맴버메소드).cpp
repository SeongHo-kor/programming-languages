// static: 정적 <-> 동적
// 전역함수가 있는데 전역함수가 class와 밀접한 관련이 있고 
// private 내의 맴버매소드나 맴버변수에 접근하고 싶을 때 정적메소드로 사용

#include<iostream>
using namespace std;

//float R G B

class Color {
public:
	Color() :r(0), g(0), b(0) {};
	Color(float r, float g, float b) :r(r), g(g), b(b) {}

	float GetR() { return r; }
	float GetG() { return g; }
	float GetB() { return b; }

	static Color MixColors(Color a, Color b) {
		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}

private:
	float r;
	float g;
	float b;
};



int main() {
    Color red(1, 0, 0);
	Color blue(0, 0, 1);
	Color purple = Color::MixColors(blue, red);

	cout << purple.GetR() << ' ' << purple.GetG() << ' ' << purple.GetB() << '\n';
}