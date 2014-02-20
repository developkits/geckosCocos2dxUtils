#pragma once
#ifndef _MATH_UTIL_
#define _MATH_UTIL_
#include <vector>
using namespace std;
using std::vector;
class MathUtil
{
public:
	MathUtil();
	~MathUtil();
	/**
	* �������� ��һ����Χ��
	* @param	num     ��Ҫ����������
	* @param	min     ��С�ķ�Χ
	* @param	range   ���Χ
	* @return  �����������
	*/
	static float fixNumber(float num, float min, float range);

	/**
	* ��׼���Ƕ�ֵ��������ĽǶ�ֵ���س�һ��ȷ������ 0 ~ 360 ֮������֡�
	*
	* <pre>
	* MathUtil::fixAngle(380); // ���� 20
	* MathUtil::fixAngle(-340); // ���� 20
	* </pre>
	*
	* �÷�������ɲ鿴 ��Flash MX ����봴��ʵ�֡��ĵ�69ҳ��
	*/
	static float fixAngle(float angle);

	/**
	* ��ȡ�׳�
	* @param	num     ��ײ��ֵ
	*/
	static unsigned int getFactorial(unsigned int num);

	/**
	* б�ʹ�ʽ
	* @param	x1 �����
	* @param	y1
	* @param	x2
	* @param	y2
	* @return  ��Ӧ��б��
	*/
	static float getSlope(float x1, float x2, float y1, float y2);

	/**
	* ����ת���ɽǶ�  radians -> degrees
	*
	* @param radians ����
	* @return ��Ӧ�ĽǶ�
	*/
	static float rds2dgs(float radians);

	/**
	* �Ƕ�ת���ɻ��� degrees -> radians
	*
	* @param degrees �Ƕ�
	* @return ��Ӧ�Ļ���
	*/
	static float dgs2rds(float degrees);
	
	/**
	* ��֪3�����ĳ�߶�Ӧ�ĽǵĽǶ�
	* CosC=(a^2+b^2-c^2)/2ab
	* CosB=(a^2+c^2-b^2)/2ac
	* CosA=(c^2+b^2-a^2)/2bc
	*
	* @param	vect ���������Ӧ�ĽǶȵ�vect
	* @param	a ��
	* @param	b ��
	* @param	c ��
	*/
	static void MathUtil::threeSidesMathAngle(vector<float>&vect, float a, float b, float c);

	/**
	* ������ת��ʽ
	* @param	vect		����vect
	* @param	cx			���ĵ�x����
	* @param	cy			���ĵ�y����
	* @param	x			��Ҫ��ת�������x����
	* @param	y			��Ҫ��ת�������y����
	* @param	sin			sin(��ת�Ƕ�);
	* @param	cos			cos(��ת�Ƕ�);
	* @param	reverse		�Ƿ���ʱ����ת
	*/
	static void MathUtil::rotate(vector<float>&vect, float cx, float cy,
									float tx, float ty,
									float angle, bool reverse);
};
#endif
