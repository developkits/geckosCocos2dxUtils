#pragma once
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
	static void setScreenSize(float width, float height, bool isFixHeight = true);
};

