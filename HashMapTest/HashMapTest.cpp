// HashMapTest.cpp : 定义控制台应用程序的入口点。
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
SSUtils->format("行数%d,文件%s",__LINE__,__FILE__)

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

