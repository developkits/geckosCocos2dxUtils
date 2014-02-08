#include "StringUtil.h"
#include "cocos2d.h"
#include <stdio.h>
using namespace std;
StringUtil::StringUtil(void)
{
}


StringUtil::~StringUtil(void)
{
}

bool StringUtil::isWhiteSpace( string* str )
{
	if (*str == " " || *str == "\t" || 
		*str == "\r" || *str == "\n") return true;
	return false;
}

void StringUtil::lTrim( string* target )
{
	int length = 0;
	//创建一个元素的string
	string str = string(1, target->at(length));
	while(StringUtil::isWhiteSpace(&str))
	{
		length++;
		str = string(1, target->at(length));
	}
	target->replace(0, length, "");
}

void StringUtil::rTrim( string* target )
{
	int length = target->length() - 1;
	string str = string(1, target->at(length));
	while(StringUtil::isWhiteSpace(&str))
	{
		length--;
		str = string(1, target->at(length));
	}
	target->replace(length, target->length() - 1, "");
}

void StringUtil::trim( string* target )
{
	StringUtil::lTrim(target);
	StringUtil::rTrim(target);
}

void StringUtil::zfill( string* str, unsigned int width /*= 2*/ )
{
	if(str == NULL ) return;
	unsigned int slen = str->length();
	if( slen >= width )	return;
	//查找负号 并保存状态。
	bool negative = false;
	string nStr = "-";
	size_t found = str->find(nStr);
	if(found != str->npos)
	{
		//如果找到了
		negative = true;
		str->replace(0, 1, "");
	}
	int len = width - slen;
	for( int i = 0; i < len; i+=1 )
	{
		*str = '0' + *str;
	}
	if( negative ) 	*str = '-' + *str;
}

void StringUtil::reverse( string* str )
{
	if(str->length() == 1) return;
	std::reverse(str->begin(), str->end());
}
