#pragma once
#ifndef _MOVIE_CLIP_
#define _MOVIE_CLIP_
#include "cocos2d.h"
USING_NS_CC;
//���Ž����ص�
typedef void (CCObject::*SEL_COMPLETE_SELECTOR)(CCObject*);
#define complete_selector(_SELECTOR) (SEL_COMPLETE_SELECTOR)(&_SELECTOR)
//ӰƬ��������֡����cocos�Ķ���
class MovieClip:public CCSprite
{
public:
	MovieClip(void);
	~MovieClip(void);
	
	//************************************
	// Description: ����ӰƬ���� 
	// Parameter: const char * name		plist�ļ�������������ǰ׺��ȥ����׺��
	// Parameter: const char * fileType �����ļ����ͣ�1Ϊ.png, 2Ϊ.pvr, 3Ϊ.pvr.cc, 4Ϊjpg��
	// Parameter: const char * prefix	ǰ׺�����ַ���
	// Returns:   MovieClip*
	//************************************
	static MovieClip* create(const char* name, const char* fileType = ".png", const char* prefix = "");
	
	//����֡�����б���mc
	static MovieClip* create(CCArray* frameList);

	//��ʼ��
	bool init(const char* name, const char* fileType, const char* prefix);

	//����֡�����б��ʼ��
	bool initWithFrameList(CCArray* frameList);

	//��֡
	void gotoAndStop(int frame);

	//************************************
	// Description:�ӵڼ�֡��ʼ���ŵ��ڼ�֡
	// Parameter: int start			��ʼ֡��
	// Parameter: int end			��β֡����Ĭ��0 Ϊ���ŵ����һ֡��
	// Parameter: float fps			֡Ƶ
	// Parameter: bool isLoop		�Ƿ�ѭ������
	// Parameter: bool isReverse	�Ƿ����򲥷�
	// Returns:   void
	//************************************
	void gotoAndPlay(int start, int end = 0, float fps = .033f, bool isLoop = true, bool isReverse = false);

	//��ͣ
	void stop();

	//����
	void play(float fps = .033f, bool isLoop = true, bool isReverse = false);

	
	//************************************
	// Method:    playOnce		����һ��
	// Parameter: float fps		֡Ƶ
	// Parameter: bool distroy	�Ƿ�����
	// Returns:   void
	//************************************
	void playOnce(float fps = .033f, bool distroy = true, bool isReverse = false);

	//��ǰ֡Ƶ
	float fps;

	//�Ƿ�ѭ��
	bool isLoop;

	//��Ӽ���
	void addEventListener(CCObject* target, SEL_COMPLETE_SELECTOR completeFun);

	//��ǰ֡
	int currentFrame;

	//��֡��
	int totalFrames;
private:
	//���֡���ݵ��б�
	CCArray* frameList;
	//�ص�������Ŀ��
	CCObject* target;
	//�ص�����
	SEL_COMPLETE_SELECTOR completeFun;
	//plist�ļ�������������ǰ׺��ȥ����׺��
	const char* mcName;
	
	//�Ƿ����򲥷�
	bool isReverse;

	//��ʼ֡
	int startFrame;
	//����֡
	int endFrame;
	
	//�Ƿ񲥷�һ�κ�����
	bool distroy;
	//ǰ׺����
	const char* prefix;
	//��ʼ������֡
	void initFrame();
	//����֡
	void updateFrame();
	//ѭ��
	void loop(float dt);
};
#endif // !_MOVIE_CLIP_
