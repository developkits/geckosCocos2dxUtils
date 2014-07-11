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
	// Parameter: const char * name	plist�ļ�������������ǰ׺��ȥ����׺��
	// Returns:   MovieClip*
	//************************************
	static MovieClip* create(const char* name);

	//��ʼ��
	bool init(const char* name);

	//��֡
	void gotoAndStop(int frame);

	//************************************
	// Description:�ӵڼ�֡��ʼ���ŵ��ڼ�֡
	// Parameter: int start		��ʼ֡��
	// Parameter: int end		��β֡����Ĭ��0 Ϊ���ŵ����һ֡��
	// Parameter: float fps		֡Ƶ
	// Parameter: bool isLoop	�Ƿ�ѭ������
	// Returns:   void
	//************************************
	void gotoAndPlay(int start, int end = 0, float fps = .033f, bool isLoop = true);

	//��ͣ
	void stop();

	//����
	void play(float fps = .033f, bool isLoop = true);

	//��ǰ֡Ƶ
	float fps;

	//�Ƿ�ѭ��
	bool isLoop;
private:
	//���֡���ݵ��б�
	CCArray* frameList;
	//xml����
	tinyxml2::XMLDocument doc;
	//plist�ļ�������������ǰ׺��ȥ����׺��
	const char* mcName;
	//��ǰ֡
	int currentFrame;
	//��ʼ֡
	int startFrame;
	//����֡
	int endFrame;
	//��֡��
	int totalFrames;
	//��ʼ������֡
	void initFrame();
	//����֡
	void updateFrame();
	//ѭ��
	void loop(float dt);
};
#endif // !_MOVIE_CLIP_
