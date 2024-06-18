// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#ifndef _STDAFX_H
#define _STDAFX_H



#ifdef _WIN32
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <WinSock2.h>
#include <windows.h>
#endif
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "boost/property_tree/ptree.hpp"


using namespace std;
using namespace boost::property_tree;
extern std::string g_sServiceIp;

#ifdef _UNICODE  
typedef boost::property_tree::wptree tptree;
typedef wstring tstring;
typedef wstringstream tstringstream;
#define _TEXT_CHAR	wchar_t
#define _TEXT_T(x)	L ## x
#define tcout	wcout
#else  
typedef boost::property_tree::ptree tptree;
typedef string tstring;
typedef stringstream tstringstream;
#define _TEXT_CHAR	char
#define _TEXT_T(x)	x	
#define tcout	cout
#define BYTE unsigned char
#endif   

#endif

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
