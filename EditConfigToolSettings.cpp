#include "StdAfx.h"
#include "EditConfigToolSettings.h"
#include "sdk/GoldTools/GPath.h"

EditConfigToolSettings::EditConfigToolSettings(CWnd* pParent)
	:BaseGridEditor(pParent)
{
	LoadData();
}


EditConfigToolSettings::~EditConfigToolSettings()
{
}

bool EditConfigToolSettings::InitGrid()
{
	SetWindowText(_T("ѡ��"));

	SetWindowPos(0, 0, 0, 620, 450, SWP_NOMOVE | SWP_NOZORDER);

	mGrid.InsertColumn(_T("��Ŀ"));
	mGrid.InsertColumn(_T("ֵ"));
	mGrid.SetColumnWidthPercent(0, 50);
	mGrid.SetColumnWidthPercent(1, 50);
	mGrid.ExpandLastColumn();

	mGrid.SetRowHeight(0, 25);
	mGrid.SetGridBkColor(RGB(255, 255, 255));
	mGrid.EnableSelection(FALSE);
	mGrid.SetTrackFocusCell(FALSE);
	mGrid.SetFrameFocusCell(FALSE);
	mGrid.SetColumnResize(false);
	UpdateGrid();
	return TRUE;
}

void EditConfigToolSettings::UpdateGrid()
{
	mGrid.DeleteNonFixedRows();
	for (int i = 0; i < m_allRowInfos.size(); i++)
	{
		int row = mGrid.InsertRow(m_allRowInfos[i].displayName);
		mGrid.GetCell(row, 0)->SetState(GVIS_READONLY);
		if (m_allRowInfos[i].iniKey.IsEmpty())
		{
			mGrid.GetCell(row, 0)->SetBackClr(RGB(200, 200, 200));
			mGrid.GetCell(row, 1)->SetBackClr(RGB(200, 200, 200));
			mGrid.GetCell(row, 1)->SetState(GVIS_READONLY);
		}
		else
		{
			mGrid.SetItemText(row, 1, m_allRowInfos[i].curIniValue);
		}
	}
	mGrid.ExpandColumnsToFit();
}

bool EditConfigToolSettings::LoadData()
{
	m_allRowInfos.clear();
	AddData(_T(""), _T(""), _T("Ŀ¼�������"));
	AddData(_T("AddCatalogBodyAttrs"), _T("LeftOffset"), _T("�������ѹ������ (ȱʡֵΪ0.0)"));
	AddData(_T("AddCatalogBodyAttrs"), _T("RightOffset"), _T("�Ҳ�����ѹ������ (ȱʡֵΪ0.0)"));
	AddData(_T("AddCatalogBodyAttrs"), _T("IsContentUseNumberSuffix"), _T("�ı��Ƿ��Զ���ӵ������ֺ�׺ (ȱʡֵΪ1)"));
	AddData(_T("AddCatalogBodyAttrs"), _T("DefaultLayer"), _T("Ĭ��ͼ�� (ȱʡʱ,ʹ��CAD��ǰ)"));
	AddData(_T("AddCatalogBodyAttrs"), _T("DefaultTextStyle"), _T("Ĭ��������ʽ (ȱʡʱ,ʹ��CAD��ǰ)"));

	AddData(_T(""), _T(""), _T("����ǩ����"));
	AddData(_T("AddRoleSignBox"), _T("IsUseSameHyperLinkAndName"), _T("��һ�ڶ��ֶ�ʼ�ձ�����ͬ (ȱʡֵΪ1)"));
	AddData(_T("AddRoleSignBox"), _T("IsAutoContinue"), _T("�Զ�������һ������ (ȱʡֵΪ0)"));
	AddData(_T("AddRoleSignBox"), _T("DefaultLayer"), _T("Ĭ��ͼ�� (ȱʡʱ,ʹ��CAD��ǰ)"));

	AddData(_T(""), _T(""), _T("��������ת����"));
	AddData(_T("TransTextToMText"), _T("XOffset"), _T("x����ƫ�� (ȱʡֵΪ0.2)"));
	AddData(_T("TransTextToMText"), _T("YOffset"), _T("y����ƫ�� (ȱʡֵΪ0.0)"));
	AddData(_T("TransTextToMText"), _T("IsSetSingleLine"), _T("�ı�ʼ�ձ��ֵ��� (ȱʡֵΪ1)"));

	AddData(_T(""), _T(""), _T("��ȡ�������������ļ�"));
	AddData(_T("ArchiveAllFonts"), _T("DefaultSavePath"), _T("�洢·�� (ȱʡʱ,ʹ�ó���ǰ)"));
	return true;
}

bool EditConfigToolSettings::AddData(CString iniGroupName, CString iniKey, CString displayName)
{
	RowInfo rowInfo;
	rowInfo.iniGroupName = iniGroupName;
	rowInfo.iniKey = iniKey;
	rowInfo.displayName = displayName;
	CString curIniValue;
	::GetPrivateProfileString(iniGroupName, iniKey, _T(""), curIniValue.GetBuffer(MAX_PATH), MAX_PATH, ConfigFile);
	curIniValue.ReleaseBuffer();
	rowInfo.curIniValue = curIniValue;
	m_allRowInfos.push_back(rowInfo);
	return true;
}

void EditConfigToolSettings::OnOK()
{
	CDialog::OnOK();
	for (int i = 0; i < m_allRowInfos.size(); i++)
	{
		CString newValue = mGrid.GetItemText(i, 1);
		if (!m_allRowInfos[i].iniKey.IsEmpty())
			::WritePrivateProfileString(m_allRowInfos[i].iniGroupName, m_allRowInfos[i].iniKey, newValue, ConfigFile);
	}
}

void EditConfigToolSettings::HandleUserManual()
{
	GPath::OpenUserManual(_T("EditConfigToolSettingsPageId"));
}