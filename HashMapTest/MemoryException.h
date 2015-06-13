#ifndef __MEMORYEXCEPTION__
#define __MEMORYEXCEPTION__

/*
	ÄÚ´æÒì³£Àà
*/
#include "DataStructException.h"
#include "MemoryHandle.h"


#define THROW_MEMORY_EXCEPTION					\
MemoryException::throwException(THROW_EXCEPTION("memory is not enough!"))

#define CHECK_MEMORY(p, new_p)			\
p = new_p;								\
if(IS_NULL(p)){							\
	if(_memoryHandle->freeMemory())		\
	{									\
		p = new_p;						\
		if(IS_NULL(p))					\
			THROW_MEMORY_EXCEPTION;		\
	}else{								\
		THROW_MEMORY_EXCEPTION;			\
	}									\
}
	

class MemoryException: public DataStructException<std::runtime_error, MemoryException>{
public:
	MemoryException(const std::string& what)
		:DataStructException(what)
	{};
};

#endif