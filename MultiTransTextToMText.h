#pragma once

class MultiTransTextToMText
{
public:
	MultiTransTextToMText();
	~MultiTransTextToMText();

private:
	static MultiTransTextToMText* mInstance;
	double m_xOffset;		//xƫ����ֵ
	double m_yOffset;		//yƫ����ֵ
	bool m_isSetSingleLine;		//�Ƿ��޶����У����޶���������ı�widthΪ0.0

	void readConfig();

public:
	static MultiTransTextToMText* GetInstance();
	void start();
};

