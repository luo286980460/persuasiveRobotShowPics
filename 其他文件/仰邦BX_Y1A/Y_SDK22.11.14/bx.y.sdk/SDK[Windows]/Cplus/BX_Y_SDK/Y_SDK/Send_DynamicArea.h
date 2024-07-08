#include "stdafx.h"
#include <afx.h>
#include "YQNetCom.h"

#pragma comment(lib, "YQNetCom.lib")

string string_To_UTF8(const std::string & str);
LPCWSTR stringToLPCWSTR(std::string orig);
void StringToWstring(std::wstring& szDst, std::string str);
 /// 更新动态区文件
 void dynamicfile();
 /// 更新动态区字符串
 void dynamicstr();
 /// 更新动态区json分区
 void dynamicJSON();