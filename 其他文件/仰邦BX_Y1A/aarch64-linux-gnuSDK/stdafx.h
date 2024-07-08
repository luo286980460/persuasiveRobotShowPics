// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#ifndef _STDAFX_H
#define _STDAFX_H



#ifdef _WIN32
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
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

// TODO: 在此处引用程序需要的其他头文件
