// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <afxdisp.h>       
#include <cstring>
#include <iostream>
using namespace  std;

#ifdef _UNICODE  
typedef wstring tstring;
#define _TEXT_CHAR	wchar_t
#define _TEXT_T(x)	L ## x
#else  
typedef string tstring;
#define _TEXT_CHAR	char
#define _TEXT_T(x)	x	
#endif 


// TODO: 在此处引用程序需要的其他头文件
