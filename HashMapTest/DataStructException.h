#ifndef __DATASTRUCTEXCEPTION__
#define __DATASTRUCTEXCEPTION__

/*
	数据结构异常基类模板
*/
#include <windows.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include "string_utils.h"

#define THROW_EXCEPTION(A) SSUtils->format(A ## "\nFILE:%s\nLINE:%d",__LINE__,__FILE__).c_str()

template<typename _base, typename _child>
class DataStructException: public _base{
public:
	DataStructException(const std::string& what):_base(what){};
	void print() const;
	static void throwException(const std::string& what) const;
};

template<typename _base, typename _child>
void DataStructException<_base, _child>::throwException(const std::string& what) const
{
	throw _child(what);
}

template<typename _base>
void DataStructException<_base>::print() const
{
#ifdef _CONSOLE
	std::cerr << this->what << std::endl;
#else
	OutputDebugStringA(this->what);
	OutputDebugStringA("\n");
#endif
}

#endif