#include "EnterFrame.h"
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
//������ʱ���Ľڵ�
static Node* node = NULL;
//֡Ƶ
static float fps = 0.0;
//���溯��ָ���vecotr
static vector<SEL_CallFunc> funcVect;
EnterFrame::EnterFrame(void)
{
}

EnterFrame::~EnterFrame(void)
{
}

void EnterFrame::init(CCNode* container, float fps )
{
	fps = fps;
	CCLog("fps%f", fps);
	if(!node)
	{
		node = new Node();
		container->addChild(node);
	}
	EnterFrame::start();
}

void EnterFrame::start()
{
	node->schedule(schedule_selector(Node::loop), fps);
}

void EnterFrame::stop()
{
	node->unschedule(schedule_selector(Node::loop));
}

void EnterFrame::push( SEL_CallFunc callfunc )
{
	//ɾ����������Ԫ��
	EnterFrame::pop(callfunc);
	funcVect.push_back(callfunc);
}

void EnterFrame::pop( SEL_CallFunc callfunc )
{
	vector<SEL_CallFunc>::iterator it = find(funcVect.begin(), funcVect.end(), callfunc);
	if (it != funcVect.end()) funcVect.erase(it);
}

void EnterFrame::clear()
{
	funcVect.clear();
}

void Node::loop(float dt)
{
	//CCLog("size%i", funcVect.size());
	//funcVect.size() Ϊ�޷���int
	for (unsigned int i = 0; i < funcVect.size(); i++)
	{
		//��Ա������ָ��һ��Ҫ��ĳ������������
		(this->*funcVect[i])();
	}
}
