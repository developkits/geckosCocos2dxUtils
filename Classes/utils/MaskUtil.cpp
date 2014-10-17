#include "MaskUtil.h"

MaskUtil::MaskUtil()
{
}

MaskUtil::~MaskUtil()
{
}

CCSprite* MaskUtil::createMaskedSprite(CCSprite* src, CCSprite* mask, bool sameSize)
{
	assert(src);
	assert(mask);

	CCSize srcContent = src->getContentSize();

	CCRenderTexture * rt = CCRenderTexture::create(srcContent.width, srcContent.height, kTexture2DPixelFormat_RGBA8888);
	//�ж������Ƿ���Ҫ��ԭʼͼƬһ����С
	if (sameSize)
	{
		CCSize maskContent = mask->getContentSize();
		float ratiow = srcContent.width / maskContent.width;
		float ratioh = srcContent.height / maskContent.height;
		mask->setScaleX(ratiow);
		mask->setScaleY(ratioh);
	}

	//����λ�ù���
	mask->setPosition(ccp(srcContent.width / 2, srcContent.height / 2));
	src->setPosition(ccp(srcContent.width / 2, srcContent.height / 2));

	//���û��ģʽ
	ccBlendFunc blendFunc2 = { GL_ONE, GL_ZERO };
	mask->setBlendFunc(blendFunc2);
	ccBlendFunc blendFunc3 = { GL_DST_ALPHA, GL_ZERO };
	src->setBlendFunc(blendFunc3);
	//��ʼ����
	rt->begin();
	mask->visit();
	src->visit();
	rt->end();
	//��ȡ���ƺ��sprite
	CCSprite * retval = CCSprite::createWithTexture(rt->getSprite()->getTexture());
	//��ת�»��Ƶ�sprite����Ϊ���Ƴ��ľ������µߵ���
	retval->setFlipY(true);
	return retval;
}
