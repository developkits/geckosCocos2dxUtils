#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Random
{
public:
	Random(void);
	~Random(void);
	 /**
     * ���� a - b֮����������������  max(a, b)
     * @param a
     * @param b
     * @return ���� a < b, [a, b)
     */
	static float randomFloat(float a, float b);
};

