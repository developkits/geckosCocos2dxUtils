#pragma once
#ifndef _SCREEN_UTIL_
#define _SCREEN_UTIL_
#include "cocos2d.h"
USING_NS_CC;
class ScreenUtil
{
public:
	ScreenUtil();
	~ScreenUtil();
	/**
	* ������Ļ��С
	* @width	��Ļ���
	* @height	��Ļ�߶�
	*/
	static void setScreenSize(float width = 960, float height = 640, bool isFixHeight = true);

	/*��Ļ���ĵ����*/
	static CCPoint getCenter();

	/*��Ļ���Ͻ����*/
	static CCPoint getLeftTop();

	/*��Ļ���½����*/
	static CCPoint getLeftBottom();

	/*��Ļ���Ͻ����*/
	static CCPoint getRightTop();
	
	/*��Ļ���½����*/
	static CCPoint getRightBottom();

	static float getLeft();

	static float getRight();

	static float getBottom();

	static float getTop();
};
#endif
