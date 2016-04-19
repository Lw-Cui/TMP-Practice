#include <iostream>
#include "infrastructure.hpp"
template<int ti, int tsum> struct Sum {
	static const int value = tsum;
	static const int i = ti;
	typedef Sum<ti + 1, ti + tsum> NEXT;
};
template<typename STATEMENT> struct Cond {
	static const int Max = 100;
	static const bool RET = (STATEMENT::i <= Max);
};
int main(int argc, char *argv[], char *env[]) {
	std::cout << _WHILE<Cond, Sum<1, 0>>::RET::value << std::endl;
	return 0;
}