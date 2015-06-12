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

#define PING_LINE(A) 

#define PRINT_LINE(A) cout << A << endl

string&& moveS(string& a){
	return std::move(a);
}

int _tmain(int argc, _TCHAR* argv[])
{
	string bb = SSUtils->format("likeqin %d, %s",5, "bb" );
	cout << bb.c_str() << endl;
	
	_getch();
	return 0;
}

