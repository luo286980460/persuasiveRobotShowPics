// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
