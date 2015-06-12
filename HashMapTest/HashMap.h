#ifndef __HASHMAP__
#define __HASHMAP__
#include <utility>

template<typename _kTy, typename _dTy>
class HashMap{
//类型声明
public:
	typedef _kTy key_type;
	typedef _dTy value_type;
	typedef size_t size_type;
	typedef std::pair<_kTy,_dTy>* pointer;
	typedef const std::pair<_kTy,_dTy>* const_pointer;
	typedef std::pair<_kTy,_dTy>* iterator;
	typedef const std::pair<_kTy,_dTy>* const_iterator;
	typedef std::pair<_kTy,_dTy>& refence;
	typedef const std::pair<_kTy,_dTy>& const_refence;

//节点定义
private:
	struct Node{
		Node():next(nullptr){};
		Node(Node* _next):next(_next){};

		std::pair<_kTy,_dTy> data;
		Node* next;
	};

//
public:

//哈希散列算法
private:
	size_type getHashIndex(key_type key);
	size_type getHashIndex(char* key);
	size_type getHashIndex(const char* key);
	size_type getHashIndex(string& key);
	size_type getHashIndex(const string& key);
//哈希表序列
private:
	Node* mp_hashmap;
};



#endif