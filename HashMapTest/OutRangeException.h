#ifndef __OUTRANGEEXCEPTION__
#define __OUTRANGEEXCEPTION__

/*
	越界异常类
*/
#include "DataStructException.h"

#define THROW_OUTRANGE_EXCEPTION OutRangeException::throwException("out of range!")

class OutRangeException: public DataStructException<std::out_of_range, OutRangeException>{
public:
	OutRangeException(const std::string& what):DataStructException(what){};
};
#endif