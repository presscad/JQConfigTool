#pragma once
#include "arxHeaders.h"
#include "dbents.h"

#ifndef  GOLD_EXPORT
#define  GOLD_EXPORT
#endif 

namespace GLayer
{

	//���ͼ���Ƿ����
	bool GOLD_EXPORT CheckLayer(AcDbDatabase* pDb, CString layerName);

    //��ȡͼ��
    AcDbObjectId GOLD_EXPORT GetLayer(AcDbDatabase* pDb, CString& layerName, bool isAutoCreate = false);

	//����ͼ��
	AcDbObjectId GOLD_EXPORT CreateLayer(AcDbDatabase* pDb, CString& layerName);
	AcDbObjectId GOLD_EXPORT CreateLayer(AcDbDatabase* pDb, CString layerName, int colorIndex, bool isPlot, bool isFrozen = false, bool isOff = false, bool isLock = false, bool isVPDFLT = false);

	//����ͼ��״̬
	bool GOLD_EXPORT SetStatusOfLayer(AcDbDatabase* pDb, CString strLayerName, bool isPlot, bool isOff, bool isFrozen = false, bool isLock = false);


};

namespace GTextStyle
{
	//���������ʽ�Ƿ����
	bool GOLD_EXPORT CheckTextStyle(AcDbDatabase* pDb, CString layerName);

	//��ȡ������ʽ
	AcDbObjectId GOLD_EXPORT GetTextStyle(AcDbDatabase* pDb, CString& textStyleName, bool isAutoCreate = false);

	//����������ʽ
	AcDbObjectId GOLD_EXPORT CreateTextStyle(AcDbDatabase* pDb, CString& textStyleName);
}