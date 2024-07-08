// Y_SDK.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afx.h>
#include "YQNetCom.h"
#include "Send_Program.h"
#include "Send_DynamicArea.h"


#pragma comment(lib, "YQNetCom.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	int err=init_sdk();
	//节目图片
	//Send_ProgramPictures();

	//节目字幕
	//Program_str();

	//节目富文本
	Program_str_line();

	//节目时间
	//Program_time();

	//节目表盘
	//Program_clock();

	//节目视频
	//Program_video();

	//节目农历
	//Program_calendar();
	
	//发送炫彩字
	//Send_ProgramColorStr();

	//发送计时
	//Program_count();
	
	/// 更新动态区文件
	//dynamicfile();
	/// 更新动态区字符串
	//dynamicstr();
	/// 更新动态区json分区
	///dynamicJSON();

	release_sdk();
	return 0;
}

