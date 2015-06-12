#ifndef __STACK__
#define __STACK__

/*
	ջ
	version 1.0
*/
#include "MemoryHandle.h"
#include "MemoryException.h"

template<typename _dTy>
class Stack{
//��������
public:
	typedef _dTy value_type;
	typedef size_t size_type;
	typedef _dTy* pointer;
	typedef const _dTy* const_pointer;
	typedef _dTy* iterator;
	typedef const _dTy* const_iterator;
	typedef _dTy& refence;
	typedef const _dTy& const_refence;
//�ڵ㶨��
private:
	struct Node{
		Node(const_refence val):data(val),next(nullptr){};
		value_type data;
		Node* next;
	};

//���캯��
public:
	Stack(): mp_top(nullptr),mi_size(0){};

//����API
public:
	void push(const_refence val);
	value_type pop();
	inline size_t size() const{return mi_size;};
//˽�к���
private:

//ջ��ָ��
private:
	Node* mp_top;
	size_type mi_size;
};

template<typename _dTy>
typename Stack<_dTy>::value_type Stack<_dTy>::pop()
{

}

template<typename _dTy>
void Stack<_dTy>::push(const_refence val)
{
	Node* node = nullptr;
	CHECK_MEMORY(node, new Node(val));
	
	if(IS_NULL(mp_top))
	{
		mp_top = val;
		return;
	}
	node->next = mp_top;
	mp_top = node;
}

#endif