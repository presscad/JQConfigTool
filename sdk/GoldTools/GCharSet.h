#pragma once
#include <string>
#include <map>

#ifndef  GOLD_EXPORT
#define  GOLD_EXPORT
#endif 

#ifdef UNICODE
#define gstring std::wstring
#else
#define gstring std::string
#endif

namespace GCharSet
{
    /*!
     @brief ��mfc��CStringת����stl��string
     */
    std::string GOLD_EXPORT MFC2STL(CString src);

    /*!
     @brief ת��CString������Ƕ��ֽڻ�����ת��string�������unicode����ת��wstring
     */
    gstring GOLD_EXPORT GetGString(CString src);

    /*!
     @brief �����ַ���ת����utf8
     */
    std::string GOLD_EXPORT LocalToUTF8(CString src);

    /*!
     @brief utf8ת��������
     */
    CString GOLD_EXPORT UTF8ToLocal(std::string src);

	//
	std::wstring GOLD_EXPORT Local2W(CString src);

	//
	std::string GOLD_EXPORT Local2U16BE(CString src);
	//void GOLD_EXPORT Local2U16BE(CString src, char*& dest, int& len);

	//std::string תMFC  
	//ansiת������
	CString GOLD_EXPORT A2Local(std::string src);

	//
	CString GOLD_EXPORT URLEncode(CString& src);

};
