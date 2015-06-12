#ifndef __MEMORYHANDLE__
#define __MEMORYHANDLE__
#include <functional>

#define IS_NULL(A) (A == nullptr)


#define _memoryHandle MemoryHandle::getInstance()
#define destroy_memoryHandle MemoryHandle::destroyThis()

class MemoryHandle{
public:
	static MemoryHandle* getInstance();
	static void destroyThis();
	inline void setFunctionHandle(std::function<void(void)> func){memory_handle = func;};
	inline bool freeMemory();
private:
	MemoryHandle():memory_handle(nullptr){};
private:
	static MemoryHandle* _instance;
	std::function<void(void)> memory_handle;
};

MemoryHandle* MemoryHandle::_instance = nullptr;

MemoryHandle* MemoryHandle::getInstance()
{
	if(IS_NULL(_instance))
		_instance = new MemoryHandle();
	return _instance;
}

void MemoryHandle::destroyThis()
{
	if(!IS_NULL(_instance))
	{
		delete _instance;
		_instance = nullptr;
	}
}

bool MemoryHandle::freeMemory()
{
	if(IS_NULL(memory_handle))
		return false;
	memory_handle();
	return true;
}

#endif