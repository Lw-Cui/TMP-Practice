#include <iostream>
#include "infrastructure.hpp"
namespace {
	const int LEN = 10;
	int ans[LEN + 1][LEN + 1];
}

template<int big, int small> struct Gcd {
	static const int value = Gcd<small, big % small>::value;
};

template<int big> struct Gcd<big, 0> {
	static const int value = big;
};

template<int a, int b> struct FillGcd
	:public FillGcd<a - 1, b>, FillGcd<a, b - 1> {
	static const int value = Gcd<a, b>::value;
	static void fill() {
		ans[a][b] = value;
		FillGcd<a - 1, b>::fill();
		FillGcd<a, b - 1>::fill();
	}
};

template<int b> struct FillGcd<0, b> {
	static const int value = Gcd<0, b>::value;
	static void fill() {ans[0][b] = value;}
};

template<int a> struct FillGcd<a, 0> {
	static const int value = Gcd<a, 0>::value;
	static void fill() {ans[a][0] = value;}
};

int main(int argc, char *argv[], char *env[]) {
	FillGcd<LEN, LEN>::fill();
	return 0;
}