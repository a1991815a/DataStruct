// HashMapTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <functional>
#include <exception>
#include <iostream>
#include <conio.h>
#include "string_utils.h"
#include <string>
using namespace std;

#define PING_LINE() \
SSUtils->format("����%d,�ļ�%s",__LINE__,__FILE__)

string&& moveS(){
	string aa = "bb";
	return std::forward<string>(aa);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << __FILE__ << endl;
	string bb = PING_LINE();

	cout << bb.c_str() << endl;

	function<void(void)> ss = [](){
		cout << "aa" << endl;
	};

	ss();


	_getch();
	return 0;
}

