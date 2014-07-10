#pragma once
#ifndef _MOVIE_CLIP_
#define _MOVIE_CLIP_
#include "cocos2d.h"
using namespace tinyxml2;
USING_NS_CC;
//ӰƬ��������֡����cocos�Ķ���
class MovieClip:public CCSprite
{
public:
	MovieClip(void);
	~MovieClip(void);
	
	//************************************
	// Method:    create	����ӰƬ����
	// Parameter: const char * xmlFileName	xml�ļ� ���Ҫ���starling�е�������ͬ
	// Returns:   MovieClip*
	//************************************
	static MovieClip* create(const char* xmlFileName);

	//��ʼ��
	bool init(const char* xmlFileName);
private:
	//���֡���ݵ��б�
	CCArray* frameList;
	//xml����
	tinyxml2::XMLDocument doc;
};
#endif // !_MOVIE_CLIP_
