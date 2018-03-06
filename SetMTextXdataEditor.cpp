#include "StdAfx.h"
#include "SetMTextXdataEditor.h"
#include "sdk/GoldTools/GAttrMgr.h"
#include "sdk/GoldTools/GLockDocument.h"
#include "sdk/GoldTools/GPath.h"

SetMTextXdataEditor::SetMTextXdataEditor(CWnd* pParent)
	:BaseGridEditor(pParent)
{
}


SetMTextXdataEditor::~SetMTextXdataEditor()
{
}

bool SetMTextXdataEditor::InitGrid()
{
	SetWindowText(_T("�޸���������"));

	mGrid.InsertColumn(_T("��ǰ�ı�����"));
	mGrid.InsertColumn(_T("����ֵ"));
	mGrid.SetColumnWidthPercent(0, 50);
	mGrid.SetColumnWidthPercent(1, 50);
	mGrid.ExpandLastColumn();

	mGrid.SetFixedRowCount(1);
	mGrid.SetFixedColumnCount(1);
	mGrid.SetGridBkColor(RGB(255, 255, 255));
	mGrid.EnableSelection(FALSE);
	mGrid.SetTrackFocusCell(FALSE);
	mGrid.SetFrameFocusCell(FALSE);
	mGrid.SetColumnResize(false);
	UpdateGrid();
	return TRUE;
}

void SetMTextXdataEditor::UpdateGrid()
{
	mGrid.DeleteNonFixedRows();
	for (long i = 0; i < m_EntsIds.logicalLength(); i++)
	{
		AcDbEntity* pEnt = NULL;
		Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, m_EntsIds.at(i), AcDb::kForRead);
		if (es != eOk)
		{
			mGrid.InsertRow(_T("Unreadable AcDbEntity"));
			continue;
		}
		pEnt->close();
		int row = -1;
		if (pEnt->isKindOf(AcDbMText::desc()))
		{
			AcDbMText* pEnt_t = AcDbMText::cast(pEnt);
			row = mGrid.InsertRow(pEnt_t->contents());
		}
		else
		{
			row = mGrid.InsertRow(_T("Not AcDbMText"));
		}
		CString strKey = GAttrMgr::GetAttrKey(pEnt);
		mGrid.SetItemText(row, 1, strKey);
	}
	mGrid.ExpandColumnsToFit();
}

void SetMTextXdataEditor::OnOK()
{
	GLockDocument lockDoc;
	int len = m_EntsIds.logicalLength();
	for (int i = 0; i < len; i++)
	{
		AcDbObjectId id = m_EntsIds[i];
		CString value = mGrid.GetItemText(i + 1, 1);
		GAttrMgr::SetAttrKey(id, value);
	}

	CDialog::OnOK();
}

bool SetMTextXdataEditor::LoadData()
{
	ads_name ent;
	ads_point pnt;
	int ret = acedEntSel(_T("\nѡ�������ı�"), ent, pnt);
	if (ret != RTNORM)
	{
		return true;
	}

	m_EntsIds.setLogicalLength(0);

	AcDbObjectId id;
	acdbGetObjectId(id, ent);

	AcDbEntity* pEnt = NULL;
	Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, id, AcDb::kForRead);

	if (es != Acad::eOk)
	{
		return false;
	}
	pEnt->close();

	//����ǿ����
	if (pEnt->isKindOf(AcDbBlockReference::desc()))
	{
		AcDbObjectId blockTableRecord_id;
		AcDbBlockReference* pRef = AcDbBlockReference::cast(pEnt);

		//�ҵ����
		blockTableRecord_id = pRef->blockTableRecord();
		AcDbBlockTableRecord* pRec = NULL;
		es = acdbOpenAcDbObject((AcDbObject*&)pRec, blockTableRecord_id, AcDb::kForRead);
		if (es != Acad::eOk)
		{
			return false;
		}
		pRec->close();

		//��������е�����
		AcDbBlockTableRecordIterator* pIter = NULL;
		pRec->newIterator(pIter);

		for (; !pIter->done(); pIter->step())
		{
			AcDbEntity* pEntity = NULL;
			es = pIter->getEntity(pEntity, AcDb::kForRead);
			if (es != Acad::eOk)
			{
				continue;
			}
			pEntity->close();

			if (pEntity->isKindOf(AcDbMText::desc()))
			{
				m_EntsIds.append(pEntity->objectId());
			}
		}
		delete pIter;
	}
	//���������
	else if (pEnt->isKindOf(AcDbMText::desc()))
	{
		m_EntsIds.append(pEnt->objectId());
	}


	//����ǿ����,��Ҫ����ˢ����ʾ
	if (pEnt->isKindOf(AcDbBlockReference::desc()))
	{
		AcDbBlockReference* pRef = AcDbBlockReference::cast(pEnt);
		es = acdbOpenAcDbEntity((AcDbEntity*&)pRef, pRef->id(), AcDb::kForWrite);
		if (es == Acad::eOk)
		{
			pRef->recordGraphicsModified();
			pRef->close();
			pRef->draw();
		}
	}
	return true;
}

void SetMTextXdataEditor::HandleUserManual()
{
	GPath::OpenUserManual(_T("SetMTextXdataPageId"));
}