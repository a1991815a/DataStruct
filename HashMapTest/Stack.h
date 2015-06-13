#ifndef __STACK__
#define __STACK__

/*
	栈
	version 1.0
*/
#include "MemoryHandle.h"
#include "MemoryException.h"

template<typename _dTy>
class Stack{
//类型声明
public:
	typedef _dTy value_type;
	typedef size_t size_type;
	typedef _dTy* pointer;
	typedef const _dTy* const_pointer;
	typedef _dTy* iterator;
	typedef const _dTy* const_iterator;
	typedef _dTy& refence;
	typedef const _dTy& const_refence;
//节点定义
private:
	struct Node{
		Node(const_refence val):data(val),next(nullptr){};
		value_type data;
		Node* next;
	};

//构造函数
public:
	Stack(): mp_top(nullptr),mi_size(0){};

//公开API
public:
	void push(const_refence val);
	value_type pop();
	inline size_t size() const{return mi_size;};
//私有函数
private:

//栈顶指针
private:
	Node* mp_top;
	size_type mi_size;
};

template<typename _dTy>
typename Stack<_dTy>::value_type Stack<_dTy>::pop()
{
	THROW_OUTRANGE_EXCEPTION(mi_size != 0);
	Node* node = mp_top;
	value_type val = node->data;
	mp_top = mp_top->next;
	delete node;
	node = nullptr;
	mi_size--;
	return val;
}

template<typename _dTy>
void Stack<_dTy>::push(const_refence val)
{
	Node* node = nullptr;
	CHECK_MEMORY(node, new Node(val));

	if(IS_NULL(mp_top))
	{
		mp_top = val;
		mi_size++;
		return;
	}
	node->next = mp_top;
	mp_top = node;
	mi_size++;
}

#endif