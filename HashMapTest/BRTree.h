#ifndef __BRTREE__
#define __BRTREE__
/*
�����
version 1.0
*/
#include <functional>



template<typename _dTy>
class BRTree{
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
		Node():lChild(nullptr),rChild(nullptr){};
		value_type data;
		Node* lChild;
		Node* rChild;
	};
//���캯��
public:
	BRTree():mp_root(nullptr),mi_size(0),fn_compare(nullptr){};

//����API
public:
	refence at(const_refence compare_val);
	const_refence at(const_refence compare_val) const;
	void insert(const_refence insert_val);
	void erase(const_refence del_val);

//˽�к���
private:
	//ע��ȶԷº���
	inline void setCompareFunc(std::function<bool(const_refence, const_refence)> func){fn_compare = func;};
	Node** getInsertPos(Node* node);			//�õ�����λ��


//�����
private:
	Node* mp_root;
	size_type mi_size;
	std::function<bool(const_refence, const_refence)> fn_compare;
};
#endif