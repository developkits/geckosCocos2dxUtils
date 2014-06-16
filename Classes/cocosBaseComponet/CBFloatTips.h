#ifndef _FLOAT_TIPS_
#define _FLOAT_TIPS_
#define g_tips CBFloatTips::getInstance()
#include <cocos-base.h>
#include <cocos2d.h>
USING_NS_CC;
class CBFloatTip :public CCNodeRGBA
{
public:
	CBFloatTip();
	~CBFloatTip();
	//������������
	void setContent(const char* content);
	CREATE_FUNC(CBFloatTip);
private:
	CCSprite*		m_bg;		//����
	CCLabelTTF*		m_tf;		//�ı�
};

class CBFloatTips : public CCSceneExtension
{
public:
	enum tip_state
	{
		state_show,
		state_hide
	};
	CBFloatTips(void);
	~CBFloatTips(void);
	CREATE_SCENE_FUNC(CBFloatTips);
	/**
	 * ��ʾƯ������
	 * @param	content	����
	 */
	void show(const char* content);

	/**
	 * ����
	 */
	void hide(CCNode* pNode);

	void onExitScene();

	static CBFloatTips* getInstance();

private:
	tip_state		m_state;	//��ǰ��ʾ״̬
	//Ʈ������	
	CCArray* ftAry;
};

#endif
