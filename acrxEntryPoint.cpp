// (C) Copyright 1990-2002 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.h
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "sdk/GoldTools/GPath.h"
#include "Shlwapi.h"
#include "WinBase.h"
#include "AddRoleSignBox.h"
#include "MultiTransTextToMText.h"
#include "SetMTextXdataEditor.h"
#include "MultiSearchAndEditMText.h"
#include "AddCatalogBodyAttrs.h"
#include "MultiRenameSymbolRecord.h"
#include "ArchiveAllFonts.h"
#include "EditConfigToolSettings.h"
#include "SearchSignBox.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

CString ConfigFile;
CString DataPath;

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CJQConfigToolApp : public AcRxArxApp {

public:
	CJQConfigToolApp () : AcRxArxApp () {
	}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		CString appDataPath = GPath::GetGoldAppDataPath();
		ConfigFile = appDataPath + _T("config\\JQConfigTool.ini");
		DataPath = appDataPath + _T("Data\\");
		CString folder = GPath::GetFilePath(ConfigFile);
		if (!PathFileExists(folder))
			CreateDirectory(folder, NULL);
		CopyFile(GPath::GetGoldAppPath() + _T("..\\config\\JQConfigTool.ini"), ConfigFile, TRUE);
		if (!PathIsDirectory(DataPath))
			CreateDirectory(DataPath, NULL);
		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;
		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}


	static void ConfigToolMultiTransTextToMText()
	{
		MultiTransTextToMText::GetInstance()->start();
	}

	static void ConfigToolSetMTextXdata()
	{
		CAcModuleResourceOverride res;
		SetMTextXdataEditor mTextEditor(acedGetAcadFrame());
		if (!mTextEditor.LoadData())
		{
			acutPrintf(_T("��ȡ�ڲ�ʵ����Ϣ�������󣬲�����ȡ��"));
			return;
		}
		mTextEditor.DoModal();
	}

	static void ConfigToolMultiSearchAndEditMText()
	{
		CAcModuleResourceOverride res;
		MultiSearchAndEditMText multiModifyMText(acedGetAcadFrame());
		if (!multiModifyMText.LoadBlockData())
		{
			AfxMessageBox(_T("��ȡ����Ϣ�������󣬲�����ȡ��"));
			return;
		}
		if (!multiModifyMText.LoadLayerData())
		{
			AfxMessageBox(_T("��ȡͼ����Ϣ�������󣬲�����ȡ��"));
			return;
		}
		if (!multiModifyMText.LoadTextStyleData())
		{
			AfxMessageBox(_T("��ȡ������ʽ�������󣬲�����ȡ��"));
			return;
		}
		multiModifyMText.DoModal();
	}

	static void ConfigToolAddCatalogBodyAttrs()
	{
		AddCatalogBodyAttrs::GetInstance()->start();
	}

	static void ConfigToolAddRoleSignBox()
	{
		AddRoleSignBox::GetInstance()->start();
	}

	static void ConfigToolMultiRenameBlock()
	{
		CAcModuleResourceOverride res;
		MultiRenameSymbolRecord renameDlg(acedGetAcadFrame());
		if (!renameDlg.LoadData(MultiRenameSymbolRecord::BlockTable))
		{
			AfxMessageBox(_T("��ȡ����¼�������󣬲�����ȡ��"));
			return;
		}
		renameDlg.DoModal();
	}

	static void ConfigToolMultiRenameLayer()
	{
		CAcModuleResourceOverride res;
		MultiRenameSymbolRecord renameDlg(acedGetAcadFrame());
		if (!renameDlg.LoadData(MultiRenameSymbolRecord::LayerTable))
		{
			AfxMessageBox(_T("��ȡ����¼�������󣬲�����ȡ��"));
			return;
		}
		renameDlg.DoModal();
	}

	static void ConfigToolMultiRenameTextStyle()
	{
		CAcModuleResourceOverride res;
		MultiRenameSymbolRecord renameDlg(acedGetAcadFrame());
		if (!renameDlg.LoadData(MultiRenameSymbolRecord::TextStyleTable))
		{
			AfxMessageBox(_T("��ȡ������ʽ�������󣬲�����ȡ��"));
			return;
		}
		renameDlg.DoModal();
	}

	static void ConfigToolSearchSignBox()
	{
		CAcModuleResourceOverride resOverride;
		SearchSignBox *pSignBox = new SearchSignBox(acedGetAcadFrame());;
		pSignBox->Create(IDD_DIALOG_SEARCHSIGNBOX);
		pSignBox->ShowWindow(SW_SHOW);
		pSignBox->CenterWindow();
	}

	static void ConfigToolArchiveAllFonts()
	{
		ArchiveAllFonts::GetInstance()->start();
	}

	static void ConfigToolEditConfigToolSettings()
	{
		//CString path = GPath::GetFilePath(ConfigFile);
		//ShellExecute(acedGetAcadFrame()->m_hWnd, _T("open"), _T("explorer.exe"), path, NULL, SW_SHOWNORMAL);
		CAcModuleResourceOverride res;
		EditConfigToolSettings configToolSetDlg(acedGetAcadFrame());
		configToolSetDlg.DoModal();
	}

	static void ConfigToolConfigToolUserManual()
	{
		GPath::OpenUserManual(_T(""));
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CJQConfigToolApp)
//��������ת����
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, MultiTransTextToMText, MultiTransTextToMText, ACRX_CMD_MODAL, NULL)

//�޸���������
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, SetMTextXdata, SetMTextXdata, ACRX_CMD_MODAL, NULL)
//���Ҳ��޸Ķ�������
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, MultiSearchAndEditMText, MultiSearchAndEditMText, ACRX_CMD_MODAL, NULL)
//���Ŀ¼������� 
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, AddCatalogBodyAttrs, AddCatalogBodyAttrs, ACRX_CMD_MODAL, NULL)

//���ǩ����
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, AddRoleSignBox, AddRoleSignBox, ACRX_CMD_MODAL, NULL)

//�������������
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, MultiRenameBlock, MultiRenameBlock, ACRX_CMD_MODAL, NULL)
//�������������
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, MultiRenameLayer, MultiRenameLayer, ACRX_CMD_MODAL, NULL)
//����������������ʽ��
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, MultiRenameTextStyle, MultiRenameTextStyle, ACRX_CMD_MODAL, NULL)

//����ǩ����
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, ArchiveAllFonts, ArchiveAllFonts, ACRX_CMD_MODAL, NULL)

//����ǩ����
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, SearchSignBox, SearchSignBox, ACRX_CMD_MODAL, NULL)

//ѡ��
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, EditConfigToolSettings, EditConfigToolSettings, ACRX_CMD_MODAL, NULL)

//ʹ���ֲ�
ACED_ARXCOMMAND_ENTRY_AUTO(CJQConfigToolApp, ConfigTool, ConfigToolUserManual, ConfigToolUserManual , ACRX_CMD_MODAL, NULL)