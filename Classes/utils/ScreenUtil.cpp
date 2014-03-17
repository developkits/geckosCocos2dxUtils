#include "ScreenUtil.h"
#include "cocos2d.h"
USING_NS_CC;
static CCPoint leftTop;		//���ϱ���Ļ����
static CCPoint leftBottom;	//���±���Ļ����
static CCPoint rightTop;	//�ұ���Ļ����
static CCPoint rightBottom;	//�ұ���Ļ����
static CCPoint center;		//���ĵ���Ļ����

ScreenUtil::ScreenUtil()
{
}

ScreenUtil::~ScreenUtil()
{
}

void ScreenUtil::setScreenSize(float width, float height, bool isFixHeight /*= true*/)
{
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	CCSize frameSize = pEGLView->getFrameSize();
	CCLOG("frameSize %f; %f", frameSize.width, frameSize.height);
	CCSize vSize = CCSizeMake(width, height);
	float scaleX = (float)frameSize.width / vSize.width;
	float scaleY = (float)frameSize.height / vSize.height;
	float scale = MAX(scaleX, scaleY);
	if (isFixHeight)
	{
		// �̶��߶�
		if (scaleX > scaleY) scale = scaleX / (frameSize.height / (float)vSize.height);
		else scale = scaleX / (frameSize.width / (float)vSize.width);
	}
	else
	{
		// �̶����
		if (scaleX > scaleY) scale = scaleY / (frameSize.height / (float)vSize.height);
		else scale = scaleY / (frameSize.width / (float)vSize.width);
	}
	CCLOG("scaleX, scaleY %f;%f", scaleX, scaleY);
	CCLOG("scale%f", scale);
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(vSize.width * scale, vSize.height * scale, kResolutionNoBorder);

	CCDirector* pDirector = CCDirector::sharedDirector();
	CCPoint visibleOrigin = pDirector->getVisibleOrigin();
	CCSize visibleSize = pDirector->getVisibleSize();
	leftBottom = ccp(visibleOrigin.x, visibleOrigin.y);
	leftTop = ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height);
	rightBottom = ccp(visibleOrigin.x + visibleSize.width, visibleOrigin.y);
	rightTop = ccp(visibleOrigin.x + visibleSize.width, visibleOrigin.y + visibleSize.height);
	center = ccp(visibleOrigin.x + (rightTop.x - leftTop.x) * .5, 
				visibleOrigin.y + (rightTop.y - rightBottom.y) * .5);
}

CCPoint ScreenUtil::getCenter()
{
	return center;
}

CCPoint ScreenUtil::getLeftTop()
{
	return leftTop;
}

CCPoint ScreenUtil::getLeftBottom()
{
	return leftBottom;
}

CCPoint ScreenUtil::getRightTop()
{
	return rightTop;
}

CCPoint ScreenUtil::getRightBottom()
{
	return rightBottom;
}
