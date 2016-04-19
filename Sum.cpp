#include <iostream>
template<bool Cond, typename THEN, typename ELSE> struct _IF {};
template<typename THEN, typename ELSE> 
struct _IF<true, THEN, ELSE> {typedef THEN RET;};
template<typename THEN, typename ELSE> 
struct _IF<false, THEN, ELSE> {typedef ELSE RET;};
template<template<typename> class COND, typename STATEMENT>
struct _WHILE {
	template<typename STATE> struct _STOP {typedef STATE RET;};
	typedef typename _IF <
		COND<STATEMENT>::RET, 
		_WHILE<COND, typename STATEMENT::NEXT>,
		_STOP<STATEMENT>
	>::RET::RET RET;
};

template<int ti, int tsum> struct Sum {
	static const int value = tsum;
	static const int i = ti;
	typedef Sum<ti + 1, ti + tsum> NEXT;
};
template<typename STATEMENT> struct Cond {
	static const int Max = 10;
	static const bool RET = (STATEMENT::i <= Max);
};
int main(int argc, char *argv[], char *env[]) {
	std::cout << _WHILE<Cond, Sum<1, 0>>::RET::value << std::endl;
	return 0;
}