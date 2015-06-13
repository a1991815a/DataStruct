#ifndef __BRTREE__
#define __BRTREE__
/*
红黑树
version 1.0
*/
#include <functional>
#include "NullPointerException.h"



template<typename _dTy>
class BRTree{
	//友元
	friend class HashMap<_dTy>;
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
	enum CompareEnds
	{
		SMALLER,EQUAL,BIGGER
	};
	enum NodeColor
	{
		RED = 0, BLACK
	};
	struct Node{
		Node() :lChild(nil), rChild(nil), parent(nil), color(RED){};
		value_type data;
		Node* lChild;
		Node* rChild;
		Node* parent;
		NodeColor color;
	};
	//构造函数
public:
	BRTree() :nil(nullptr), mp_root(nil)， mi_size(0), fn_compare(nullptr){};

	//公开API
public:
	refence at(const_refence compare_val);
	const_refence at(const_refence compare_val) const;
	void insert(const_refence insert_val);
	void erase(const_refence del_val);

	//私有函数
private:
	//注册比对仿函数
	inline void setCompareFunc(std::function<CompareEnds(const_refence, const_refence)> func){ fn_compare = func; };
	//比较key值 a<b = SMALLER, a==b = EQUAL, a>b = BIGGER
	inline bool compare(const_refence a, const_refence b) const;
	void BR_Insert(Node* ins_node);				//插入节点
	void BR_Erase(Node* del_node);				//删除节点
	Node* BR_Select(Node* sel_node);			//查找节点
	void BR_Fix(Node* fix_node);				//重组树结构

//节点操作
private:
	void rotateLeft(Node* node);				//左旋转
	void rotateRight(Node* node);				//右旋转
	Node* getBrother(Node* node);				//获得叔叔节点
	Node* getParent(Node* node);				//获得父节点
	bool isLeftChild(Node* node) const;			//判断是否是左孩子
	inline setLChild(Node* node, Node* child){ node->lChild = child; child->parent = node; };
	inline setRChild(Node* node, Node* child){ node->rChild = child; child->parent = node; };
//内部数据
private:
	Node const* const nil;						//空节点
	Node* mp_root;								//根节点
	size_type mi_size;							//容器大小
	//比较仿函数
	std::function<CompareEnds(const_refence, const_refence)> fn_compare;
};

template<typename _dTy>
void BRTree<_dTy>::BR_Fix(Node* fix_node)
{
	THROW_NULLPOINTER_EXCEPTION(fix_node);
	if (getParent(fix_node) == nil)
	{
		fix_node->color = BLACK;
		return;
	}

	//父不为空且为红
	if (getParent(fix_node)->color == RED){
		Node* parent = getParent(fix_node);
		Node* grand_parent = getParent(parent);
		
		//祖父不为空
		if (grand_parent != nil)
		{
			Node* parent_bro = getBrother(parent);
			if (parent_bro == nil || parent_bro->color == BLACK){
				bool fix_flag = isLeftChild(fix_node);
				bool parent_flag = isLeftChild(parent);


			}
			else if (parent_bro->color == RED)
			{
				parent->color = BLACK;
				parent_bro->color = BLACK;
				grand_parent->color = RED;
			}
		}
		else//祖父为空
		{

		}

	}

}

template<typename _dTy>
void BRTree<_dTy>::BR_Insert(Node* ins_node)
{
	THROW_NULLPOINTER_EXCEPTION(ins_node);
	if (mp_root == nullptr)
		mp_root = ins_node;
	else
	{
		Node** node_ptr = &mp_root;
		while (*node_ptr != nil)
		{
			CompareEnds compare_end = compare(ins_node, **node_ptr);
			if (compare_end == SMALLER)
				node_ptr = &(*node_ptr)->lChild;
			else if (compare_end == BIGGER)
				node_ptr = &(*node_ptr)->rChild;
			else
			{
				(*node_ptr)->data = ins_node->data;
				delete ins_node;
				ins_node = nullptr;
				return;
			}
		}
		*node_ptr = ins_node;
	}
	BR_Fix(ins_node);
}

template<typename _dTy>
void BRTree<_dTy>::BR_Erase(Node* del_node)
{
	
}

template<typename _dTy>
Node* BRTree<_dTy>::BR_Select(Node* sel_node)
{
	Node* node = mp_root;
	CompareEnds compare_end;
	while (node != nil && (compare_end = compare(sel_node, node)) != EQUAL)
	{
		if (compare_end == SMALLER)
			node = node->lChild;
		else
			node = node->rChild;
	}
	return node;
}

template<typename _dTy>
bool BRTree<_dTy>::isLeftChild(Node* node) const
{
	if (node == node->parent->lChild)
		return true;
	return false;
}

template<typename _dTy>
void BRTree<_dTy>::rotateRight(Node* node)
{
	THROW_NULLPOINTER_EXCEPTION(node);
	THROW_NULLPOINTER_EXCEPTION(node->parent);
	THROW_OPERATE_EXCEPTION(isLeftChild(node));
	Node* parent = getParent(node);
	Node* grand_parent = getParent(parent);
	setLChild(grand_parent, node);
	setLChild(parent, node->rChild);
	setRChild(node, parent);
}

template<typename _dTy>
void BRTree<_dTy>::rotateLeft(Node* node)
{
	THROW_NULLPOINTER_EXCEPTION(node);
	THROW_NULLPOINTER_EXCEPTION(node->parent);
	THROW_OPERATE_EXCEPTION(!isLeftChild(node));
	Node* parent = getParent(node);
	Node* grand_parent = getParent(parent);
	setRChild(grand_parent, node);
	setRChild(parent, node->lChild);
	setLChild(node, parent);
}

template<typename _dTy>
Node* BRTree<_dTy>::getBrother(Node* node)
{	
	THROW_NULLPOINTER_EXCEPTION(node);
	bool isLChild = isLeftChild(node);
	node = getParent(node);
	if (isLChild)
		node = node->rChild;
	else
		node = node->lChild;

	return node;
}

template<typename _dTy>
Node* BRTree<_dTy>::getParent(Node* node)
{
	THROW_NULLPOINTER_EXCEPTION(node);
	node = node->parent;
	return node;
}

template<typename _dTy>
bool BRTree<_dTy>::compare(const_refence a, const_refence b) const
{
	if (fn_compare)
		return fn_compare(a, b);
	if (a < b)
		return SMALLER;
	else if (a > b)
		return BIGGER;
	else
		return EQUAL;
}



#endif