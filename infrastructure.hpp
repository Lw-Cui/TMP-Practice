#ifndef _INFRASTRUCTURE_HPP_
#define _INFRASTRUCTURE_HPP_
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
#endif