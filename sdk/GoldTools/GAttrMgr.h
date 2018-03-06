#pragma once
#include <string>
#include <map>
#include "arxHeaders.h"

#ifndef  GOLD_EXPORT
#define  GOLD_EXPORT
#endif 

#ifdef UNICODE
#define gstring std::wstring
#else
#define gstring std::string
#endif

namespace GAttrMgr
{
	//��ȡʵ��key
	CString GOLD_EXPORT GetAttrKey(AcDbEntity* pText);

	//����ʵ��key
	Acad::ErrorStatus SetAttrKey(AcDbObjectId objId, const CString strKey);
	Acad::ErrorStatus SetAttrKey(AcDbEntity* pEnt, const CString strKey);
	
	//ȥ����ȡ���Ķ����ı��еĿ����ַ���
	CString GOLD_EXPORT RemoveFormatChars(CString& contents);

	//��ȡ�ı����ݣ������������ַ�
	CString GOLD_EXPORT GetMText(AcDbMText* pText);

	//����MText�ı�ֵ
	void GOLD_EXPORT SetMText(AcDbMText* pText, CString& text);

	//��ȡ������ʽ��ȱ���
	double GOLD_EXPORT GetTextStyleWidthFactor(AcDbObjectId& id);

	//��ȡ���������ԣ���isReturnUrlΪfalseʱ���صĵ��ǳ���������Ϊtrueʱ���ص��ǳ����ӵ�url��Ĭ��ֵΪfalse�� 
	CString GetRole(AcDbEntity* pEnt, bool isReturnUrl = false);
};
