#include "stdafx.h"
#include <afx.h>
#include "YQNetCom.h"

#pragma comment(lib, "YQNetCom.lib")

string string_To_UTF8(const std::string & str);
LPCWSTR stringToLPCWSTR(std::string orig);
void StringToWstring(std::wstring& szDst, std::string str);
 /// ���¶�̬���ļ�
 void dynamicfile();
 /// ���¶�̬���ַ���
 void dynamicstr();
 /// ���¶�̬��json����
 void dynamicJSON();