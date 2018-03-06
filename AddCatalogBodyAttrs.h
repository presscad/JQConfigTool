#pragma once
class AddCatalogBodyAttrs
{
public:
	AddCatalogBodyAttrs();
	~AddCatalogBodyAttrs();

private:
	static AddCatalogBodyAttrs* mInstance;
	CString m_layerName;			//�����Ķ����ı����ڵ�ͼ��
	CString m_textStyleName;		//�����Ķ����ı����ڵ�������ʽ
	double m_leftOffset;			//�����ı���Χ�������ѹ���ľ���
	double m_rightOffset;			//�����ı���Χ�Ҳ�����ѹ���ľ���
	bool m_isContentUseNumberSuffix;		//�����ı��Ƿ��Զ���ӵ������ֺ�׺
	
	void readConfig();
	AcDbObjectId getSelectedLayerId();
	AcDbObjectId getSelectedTextStyleId();

public:
	static AddCatalogBodyAttrs* GetInstance();
	bool start();
};

