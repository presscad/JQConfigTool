#pragma once
#include "arxHeaders.h"

class AddRoleSignBox
{
public:
	AddRoleSignBox();
	~AddRoleSignBox();

private:
	static AddRoleSignBox* mInstance;
	bool m_isUseSameHyperLinkAndName;			//��һ�ڶ��ֶ��Ƿ���ͬ����ͬʡȥ�û���д�ڶ��ֶβ���
	bool m_isAutoContinue;		//�����Ƿ��Զ���������
	CString m_layerName;			//������ǩ��������ͼ��

	void readConfig();
	AcDbObjectId getSelectedLayerId();
	
public:
	static AddRoleSignBox* GetInstance();
	void start();

};

