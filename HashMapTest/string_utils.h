#ifndef __STRING_UTILS__
#define __STRING_UTILS__

/*
	字符串转换工具
	version 1.0
*/
#include <string>

#define SSUtils string_utils::getInstance()

class string_utils{
public:
	static string_utils* getInstance();
	static void destroyThis();
private:
	static string_utils* _instance;

private:
	enum FormatTypes
	{
		UNKNOW = 0,INT, FLOAT, STRING
	};

//窄字符工具
public:
	int toInt(const char* str) const;
	float toFloat(const char* str) const;

	int toInt(const std::string& str) const;
	float toFloat(const std::string& str) const;

	std::string toString(const int _int) const;
	std::string toString(const float _float) const;

//格式化工具
	std::string format(const std::string& str, ...) const;
	std::string vformat(const std::string& str, va_list ap) const;
private:
	FormatTypes judgeSymbol(const char* _symbol) const;
	FormatTypes searchSymbol(const char* str, int len, int& offset) const;
};

inline int parseInt(const char* str){
	return SSUtils->toInt(str);
}

inline float parseFloat(const char* str){
	return SSUtils->toFloat(str);
}

inline int parseInt(const std::string& str){
	return SSUtils->toInt(str);
}

inline float parseFloat(const std::string& str){
	return SSUtils->toFloat(str);
}

inline std::string parseString(const int _int){
	return SSUtils->toString(_int);
}

inline std::string parseString(const float _float){
	return SSUtils->toString(_float);
}


#endif