#include "stdafx.h"
#include "Send_DynamicArea.h"
#include <iostream>
#include"iostream"
#include "windows.h"
#include "time.h"
#include <tchar.h>
#include <atlstr.h> 
#include "atlenc.h"
using namespace std;
#include "base64.h"

std::string string_To_UTF8(const std::string & str) 
{ 
int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0); 

wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
ZeroMemory(pwBuf, nwLen * 2 + 2); 

::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen); 

int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL); 

char * pBuf = new char[nLen + 1]; 
ZeroMemory(pBuf, nLen + 1); 

::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL); 

std::string retStr(pBuf); 

delete []pwBuf; 
delete []pBuf; 

pwBuf = NULL; 
pBuf  = NULL; 

return retStr; 
} 
LPCWSTR stringToLPCWSTR(std::string orig)
{
size_t origsize = orig.length() + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

return wcstring;
}
void StringToWstring(std::wstring& szDst, std::string str)
{
std::string temp = str;
int len=MultiByteToWideChar(CP_ACP, 0, (LPCSTR)temp.c_str(), -1, NULL,0); 
wchar_t * wszUtf8 = new wchar_t[len+1]; 
memset(wszUtf8, 0, len * 2 + 2); 
MultiByteToWideChar(CP_ACP, 0, (LPCSTR)temp.c_str(), -1, (LPWSTR)wszUtf8, len);
szDst = wszUtf8;
std::wstring r = wszUtf8;
delete[] wszUtf8;
}

 /// 更新动态区文件
 void dynamicfile()
 {   
    char* ip = "192.168.89.166";
	unsigned short port=80;
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	 _TEXT_CHAR controller_name[128]=_TEXT_T("");
	unsigned long playlist=create_playlist(64, 32,8536);

	_TEXT_CHAR* name=_TEXT_T("program_1");
	unsigned long program=create_program(name,_TEXT_T("0xff000000")); 

	_TEXT_CHAR* font_name=_TEXT_T("SimSun"); 
	_TEXT_CHAR* font_attributes=_TEXT_T("normal");
	_TEXT_CHAR* font_alignment=_TEXT_T("0");
	_TEXT_CHAR font_color[20]=_TEXT_T("0xffff0000");
	_TEXT_CHAR bg_color[20]=_TEXT_T("0xff000000"); 
	_TEXT_CHAR* content=_TEXT_T("显示数据");
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	long long  free_size=0, total_size=0;
	int send_style=0;

    int dynamic_type = 1;
	_TEXT_CHAR* file=_TEXT_T("test.txt");
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
	if(dynamic_type==0){file=_TEXT_T("test.bmp");}
	if(dynamic_type==1){file=_TEXT_T("test.txt");}
	DWORD dynamic_area = create_dynamic();
    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, file, gif_flag, bg_color, 12, font_name, font_color, font_attributes,  _TEXT_T("0"),  _TEXT_T("0"), 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
            
    err = add_dynamic(program, dynamic_area,0, 0, 0, 64, 32, _T(""), 0, _T(""), 100);
    delete_dynamic(dynamic_area);

    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
    err = update_dynamic(ip, port, user_name, user_pwd, playlist, _T(""), 0, 0);
	//更新动态区文件素材，在显示屏上已经存在动态区时，可以使用这个接口更新素材
    //err = update_dynamic_unit(ip, port, user_name, user_pwd, playlist);
	cout<<"update_dynamic:"<<err<<endl;
	delete_playlist(playlist);
 }
 
 /// 更新动态区字符串
 void dynamicstr()
 {   
    char* ip = "192.168.89.166";
	unsigned short port=80;
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	 _TEXT_CHAR controller_name[128]=_TEXT_T("");
	unsigned long playlist=create_playlist(64, 32,8536);

	_TEXT_CHAR* name=_TEXT_T("program_1");
	unsigned long program=create_program(name,_TEXT_T("0xff000000")); 

	_TEXT_CHAR* font_name=_TEXT_T("SimSun"); 
	_TEXT_CHAR* font_attributes=_TEXT_T("normal");
	_TEXT_CHAR* font_alignment=_TEXT_T("0");
	_TEXT_CHAR font_color[20]=_TEXT_T("0xffff0000");
	_TEXT_CHAR bg_color[20]=_TEXT_T("0xff000000"); 
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	long long  free_size=0, total_size=0;
	int send_style=0;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    std::string file = string_To_UTF8("显示数据");
	std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(file.c_str()), file.length());
	std::wstring sds;
	StringToWstring(sds,encoded);
	_TEXT_CHAR*  content=(_TEXT_CHAR*)(sds.data());
	DWORD dynamic_area = create_dynamic();

    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, content, gif_flag, bg_color, 12, font_name, font_color, font_attributes,  _TEXT_T("0"),  _TEXT_T("0"), 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
            
    err = add_dynamic(program, dynamic_area,0, 0, 0, 32, 32, _T(""), 0, _T(""), 100);
    delete_dynamic(dynamic_area);

	display_effects = 53;
	DWORD dynamic_area1 = create_dynamic();

    err = add_dynamic_unit(dynamic_area1, dynamic_type, display_effects, display_speed, stay_time, content, gif_flag, bg_color, 12, font_name, font_color, font_attributes,  _TEXT_T("0"),  _TEXT_T("0"), 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
            
    err = add_dynamic(program, dynamic_area1,1, 32, 0, 32, 32, _T(""), 0, _T(""), 100);
    delete_dynamic(dynamic_area1);

    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
    err = update_dynamic_small(ip, port, user_name, user_pwd, playlist, _T(""), 0, 0);
	//更新动态区文件素材，在显示屏上已经存在动态区时，可以使用这个接口更新素材
    //err = update_dynamic_unit_small(ip, port, user_name, user_pwd, playlist);
	delete_playlist(playlist);
 }
 
 /// 更新动态区json分区
 void dynamicJSON()
 {   
    char* ip = "192.168.89.166";
	unsigned short port=80;
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	 _TEXT_CHAR controller_name[128]=_TEXT_T("");
	unsigned long playlist=create_playlist(64, 32,8536);

	_TEXT_CHAR* name=_TEXT_T("program_1");
	unsigned long program=create_program(name,_TEXT_T("0xff000000")); 

	_TEXT_CHAR* font_name=_TEXT_T("SimSun"); 
	_TEXT_CHAR* font_attributes=_TEXT_T("normal");
	_TEXT_CHAR* font_alignment=_TEXT_T("0");
	_TEXT_CHAR font_color[20]=_TEXT_T("0xffff0000");
	_TEXT_CHAR bg_color[20]=_TEXT_T("0xff000000"); 
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	long long  free_size=0, total_size=0;
	int send_style=0;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
	_TEXT_CHAR*  url=_TEXT_T("http://121.199.50.130:8180/projectDataServer/passengerServer/queryRealTimePassengerByUser?loginName=xmnpt&loginPwd=123456");
	_TEXT_CHAR*  urlstr=_TEXT_T("cmVzdWx0IlswXSJzaG9wSWQ=");
	DWORD dynamic_area = create_dynamic();

    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, url, gif_flag, bg_color, 12, font_name, font_color, font_attributes,  _TEXT_T("0"),  _TEXT_T("0"), 0, 0, 0,urlstr,_TEXT_T(""));
            
    err = add_dynamic(program, dynamic_area,0, 0, 0, 64, 32, _T(""), 0, _T(""), 100);
    delete_dynamic(dynamic_area);

    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
    err = update_dynamic_small(ip, port, user_name, user_pwd, playlist, _T(""), 0, 0);
	//更新动态区文件素材，在显示屏上已经存在动态区时，可以使用这个接口更新素材
    //err = update_dynamic_unit_small(ip, port, user_name, user_pwd, playlist);
	cout<<"update_dynamic:"<<err<<endl;
	delete_playlist(playlist);
 }