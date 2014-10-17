#pragma once
#ifndef _MASK_UTIL_
#define _MASK_UTIL_
#include "cocos2d.h"
USING_NS_CC;
class MaskUtil
{
public:
	MaskUtil();
	~MaskUtil();

	//************************************
	// Description: ��������
	// Parameter: CCSprite * src		��Ҫ�����ֵľ���
	// Parameter: CCSprite * mask		���־���
	// Parameter: bool sameSize			���ص��µ����־����Ƿ�ͱ����ֵľ����ССͬ
	// Returns:   CCSprite*				���»��Ʊ����־���
	//************************************
	static CCSprite* createMaskedSprite(CCSprite* src, CCSprite* mask, bool sameSize = false);
};
#endif
