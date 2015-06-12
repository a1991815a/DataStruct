#ifndef __BRTREE__
#define __BRTREE__
/*
红黑树
version 1.0
*/
#include <functional>



template<typename _dTy>
class BRTree{
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
		Node():lChild(nullptr),rChild(nullptr){};
		value_type data;
		Node* lChild;
		Node* rChild;
	};
//构造函数
public:
	BRTree():mp_root(nullptr),mi_size(0),fn_compare(nullptr){};

//公开API
public:
	refence at(const_refence compare_val);
	const_refence at(const_refence compare_val) const;
	void insert(const_refence insert_val);
	void erase(const_refence del_val);

//私有函数
private:
	//注册比对仿函数
	inline void setCompareFunc(std::function<bool(const_refence, const_refence)> func){fn_compare = func;};
	Node** getInsertPos(Node* node);			//得到插入位置


//根结点
private:
	Node* mp_root;
	size_type mi_size;
	std::function<bool(const_refence, const_refence)> fn_compare;
};
#endif