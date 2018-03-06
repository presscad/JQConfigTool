#pragma once

#ifndef GOLD_EXPORT
#ifdef GOLDTOOLS_MODULE
    #define GOLD_EXPORT
#else
    #define GOLD_EXPORT
#endif
#endif

namespace GPath
{
    /*!
     @brief ��ȡ����İ�װ·��
     */
    CString GOLD_EXPORT GetGoldAppPath();

	/*!
	@brief ��ȡ����AppData·��: ��%Appdata%/JinQuConfigTool
	*/
	CString GOLD_EXPORT GetGoldAppDataPath();


	/*!
	@brief ��ȡAutoCAD�İ�װ·��
	*/
	CString GOLD_EXPORT GetAcadAppPath();

	/*!
	@brief ��ȡϵͳfontsĿ¼
	*/
	CString GOLD_EXPORT GetSystemFontsPath();

    /*!
     @brief ��ȡ�ļ�·����Ŀ¼������\
     @param file �ļ���
     */
    CString GOLD_EXPORT GetFilePath(CString& file);

    /*!
     @brief �õ��ļ����ͣ�ͨ����׺����ȡ������.��
     */
    CString GOLD_EXPORT GetFileType(CString& file);

    /*!
     @brief �õ��ļ�����������·������
     */
    CString GOLD_EXPORT GetFileTitle(const CString& file);

    //�õ��������ļ����͵�����
    CString GOLD_EXPORT GetFileNameNoExt(const CString& file);

    //�õ��ļ�����������·�����ļ�����
    CString GOLD_EXPORT GetFileTitleNoExt(const CString& file);

    /*!
     @brief �õ���newType�滻���͵��ļ���
     */
    CString GOLD_EXPORT GetNewTypeFile(CString& file, CString newType);

    /*!
     @brief �ϲ�·��
     @param path ����·��
     @param append ��Ҫ�ϲ���·��
     */
    CString GOLD_EXPORT AppendPath(CString path, CString append);

    /*!
     @brief ��ȡ�Ϸ��ļ�����ȥ��һЩ�Ƿ��ַ�
     */
    //CString GOLD_EXPORT GetValidPath(CString& path);

    /*!
     @brief ��ȡ�Ϸ��ļ���
     */
    void GOLD_EXPORT GetValidPath(CString& path);

	/*!
	@brief ��topic��������ĵ�������ֵΪ�ĵ�·����
	*/
	CString GOLD_EXPORT OpenUserManual(CString topic);
};