#include "string_utils.h"
#include <sstream>
#include <stdarg.h>

#pragma warning( disable: 4244)

string_utils* string_utils::_instance = nullptr;

string_utils* string_utils::getInstance()
{
	if (_instance == nullptr)
		_instance = new string_utils();
	return _instance;
}

void string_utils::destroyThis()
{
	if (_instance){
		delete _instance;
		_instance = nullptr;
	}
}

int string_utils::toInt(const char* str) const
{
	return atoi(str);
}

int string_utils::toInt(const std::string& str) const
{
	return toInt(str.c_str());
}

float string_utils::toFloat(const char* str) const
{
	return atof(str);
}

float string_utils::toFloat(const std::string& str) const
{
	return toFloat(str.c_str());
}

std::string string_utils::toString(const int _int) const
{
	std::string str;
	std::stringstream ss;
	ss << _int;
	ss >> str;
	return std::forward<std::string>(str);
}

std::string string_utils::toString(const float _float) const
{
	std::string str;
	std::stringstream ss;
	ss << _float;
	ss >> str;
	return std::forward<std::string>(str);
}

std::string string_utils::format(const std::string str, ...) const
{
	va_list ap;
	va_start(ap, str);
	std::string out_text = vformat(str, ap);
	va_end(ap);
	return std::forward<std::string>(out_text);
}

std::string string_utils::vformat(const std::string& str, va_list ap) const
{
	std::string out_text = "";
	int offset = 0;
	int left = 0;
	FormatTypes type = UNKNOW;
	while ((type = searchSymbol(str.c_str(), str.size(), offset)) != UNKNOW)
	{
		out_text += str.substr(left, offset - left - 2);
		left = offset;
		switch (type)
		{
		case string_utils::INT:
			out_text += parseString(va_arg(ap, int));
			break;
		case string_utils::FLOAT:
			out_text += parseString((float)va_arg(ap, double));
			break;
		case string_utils::STRING:
			out_text += va_arg(ap, const char*);
			break;
		case string_utils::UNKNOW:
		default:
			break;
		}
	}
	return std::forward<std::string>(out_text);
}

string_utils::FormatTypes string_utils::judgeSymbol(const char* _symbol) const
{
	if (_symbol[0] != '%')
		return UNKNOW;
	if (_symbol[1] == 's')
		return STRING;
	else if (_symbol[1] == 'd')
		return INT;
	else if (_symbol[1] == 'f')
		return FLOAT;
	return UNKNOW;
}

string_utils::FormatTypes string_utils::searchSymbol(const char* str, int len, int& offset) const
{
	while (offset < len - 1)
	{
		if (str[offset] == '%')
		{
			FormatTypes type = UNKNOW;
			if ((type = judgeSymbol(&str[offset])) != UNKNOW)
			{
				offset += 2;
				return type;
			}
		}
		offset++;
	}

	return UNKNOW;
}
