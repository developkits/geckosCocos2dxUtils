#pragma once
#ifndef	_SLOT_EFFECT_
#define _SLOT_EFFECT_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
//�ϻ���Ч���������ݣ�
class SlotEffect :public CCNode
{
public:
	SlotEffect();
	~SlotEffect();

	//************************************
	// Description:��ʼ���ϻ���Ч��
	// Parameter: int curIndex	��ʼ����λ��������
	// Parameter: int maxIndex	�ܵ�����������
	// Parameter: int loop		����ģʽ�Ĺ����������ڿ��ٹ��������ﵽ�����һ�����ٹ����������ܹ���������loop + 1
	// Parameter: float delay	���м�� ����
	// Parameter: int gapIndex	�������ٹ���֮ǰ������
	// Parameter: int addDelay	�������
	// Returns:   �Ƿ��ʼ��
	//************************************
	virtual bool init(int curIndex, int maxIndex, int loop = 1, float delay = 50, int gapIndex = 5, int addDelay = 200);
	//����
	static SlotEffect* create(int curIndex, int maxIndex, int loop = 1, float delay = 50, int gapIndex = 5, int addDelay = 200);
	//��ʼ
	void start(int targetIndex, bool reverse = false);
	//��ͣ
	void pause();
	//��ȡ��ǰ����
	int getCurIndex();
	//��ȡ��ǰ�������
	int getRandomIndex();
	//************************************
	// Description:��Ӽ���
	// Parameter: CCObject* target	ָ����ûص�������ָ��
	// Parameter: SEL_CallFunc func	�ص�����
	// Returns:   void
	//************************************
	void addEventListener(CCObject* target, SEL_CallFunc func);
private:
	//��ʼ����λ������
	int m_curIndex;
	//�ܵ���������
	int m_maxIndex;
	//����ģʽ�Ĺ�������
	int m_loop;
	//���м��
	float m_delay;
	//�������ٹ���֮ǰ������
	int m_gapIndex;
	//�Ƿ��������״̬
	bool isSlowing;
	//Ŀ������
	int m_targetIndex;
	//���ٹ����Ŀ�ʼ����
	int m_slowIndex;
	//�Ƿ���ʱ��
	bool m_reverse;
	//�������
	int m_randomIndex;
	//��ǰ��ʱ���ļ�����
	int currentCount;
	//���ӵļ��
	int addDelay;
	//�¼�Ŀ��
	CCObject* m_target;
	//�����ص�
	SEL_CallFunc func;
	//���·���
	void update(float dt);
	//************************************
	// Description: �������� ��һ����Χ��
	// Parameter: float num		��Ҫ����������
	// Parameter: float min		��С�ķ�Χ
	// Parameter: float range	���Χ
	// Returns:   float			�����������
	//************************************
	float fixNumber(float num, float min, float range);
};

#endif