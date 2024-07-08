#include <iostream>
#include"iostream"
#include "windows.h"
#include "time.h"
#include <tchar.h>

#include <atlstr.h> 
#include "atlenc.h"
using namespace std;
#include "base64.h"


#define _TEXT_CHAR	wchar_t
#define _TEXT_T(x)	L ## x

typedef struct card
{
	char ip[20];//控制器地址
	char barcode[17];//控制器条形码
}card_unit;
typedef struct _CARD_SERVER
{
	char barcode[17];//控制器条形
}server_card;


//初始化动态链接库
typedef int(__stdcall *PInitSdk)();

//释放动态链接库
typedef int(__stdcall *PReleaseSdk)();

/// <summary>
/// 创建播放列表
/// </summary>
/// <param name="w">屏幕宽度</param>
/// <param name="h">屏幕高度</param>
/// <param name="device_type">控制卡型号BX-Y04/8280 BX-Y08/8536 BX-Y2/8792 BX-Y2L/9304 BX-Y3/9048</param>
/// <returns>播放列表句柄</returns>
typedef unsigned long(__stdcall *Pcreate_playlist)(int w, int h, int device_type);

/// <summary>
/// 创建节目句柄
/// </summary>
/// <param name="name">节目名</param>
/// <returns>节目句柄</returns>
typedef unsigned long (__stdcall *Pcreate_program)(LPCWSTR name, LPCWSTR bg_color);

/// <summary>
/// 创建动态区句柄
/// </summary>
/// <returns>动态区句柄</returns>
typedef unsigned long (__stdcall *Pcreate_dynamic)();
//销毁动态区句柄
typedef void (__stdcall *Pdelete_dynamic)(unsigned long dynamic_area);
// 函数：	clear_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			LPCWSTR user_name：登录名
//			LPCWSTR user_pwd：登录密码
// 说明：	清空动态区
typedef int (__stdcall *Pclear_dynamic)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd);

/// <summary>
/// 添加动态区图文数据
/// </summary>
/// <param name="dynamic_area">动态区句柄</param>
/// <param name="dynamic_type">动态单元类型 图片 0  txt 1</param>
/// <param name="display_effects">特技类型</param>
/// <param name="display_speed">特技速度</param>
/// <param name="stay_time">特技停留时间</param>
/// <param name="file_path">元素路径：文本类的支持txt（utf-8）格式，字符串要使用Base64编码格式</param>
/// <param name="gif_flag">0非GIF；1GIF类型（暂不支持动态播放，作为普通图片播放）</param>
/// <param name="bg_color">背景颜色</param>
/// <param name="font_size">字体大小</param>
/// <param name="font_name">字体</param>
/// <param name="font_color">字体颜色</param>
/// <param name="font_attributes">包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进行组合</param>
/// <param name="align_h">水平对齐方式0居左/1居右/2居中</param>
/// <param name="align_v">垂直对齐方式0居上/1居下/2居中</param>
//以下三个为视频属性，暂不支持视频
/// <param name="volumn">音量</param>
/// <param name="scale_mode">缩放模式，窗口比例0/原始比例1</param>
/// <param name="rolation_mode">旋转角度</param>
/// <returns></returns>
typedef int (__stdcall *Padd_dynamic_unit)(unsigned long dynamic_area, int dynamic_type, int display_effects, int display_speed, int stay_time,LPCWSTR file_path, int gif_flag, LPCWSTR bg_color, int font_size, LPCWSTR font_name, LPCWSTR font_color, LPCWSTR font_attributes, LPCWSTR align_h, LPCWSTR align_v, int volumn, int scale_mode, int rolation_mode,LPCWSTR key_list, _TEXT_CHAR* proxyService);

/// <summary>
/// 把动态区添加到节目
/// </summary>
/// <param name="tree">节目句柄</param>
/// <param name="area_tree">动态区句柄</param>
/// <param name="dynamic_id">动态区编号0-31</param>
/// <param name="x">坐标起始X</param>
/// <param name="y">坐标起始Y</param>
/// <param name="w">区域宽度</param>
/// <param name="h">区域高度</param>
/// <param name="relative_program">关联的节目，即所要关联的节目序号(节目列表中的 order 字段("0","1",...))</param>
/// <param name="run_mode">动态区运行方式，0全局播放动态区/1全局动态区节目/2全局动态区节目/3绑定播放动态区，关联节目开始播放时播放动态区，直到关联节目播放完毕/4绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后本轮不再显示/5绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后静止显示该动态区的最后一个unit/6绑定播放动态区，关联节目播放完后播放动态区</param>
/// <param name="update_frequency">放空""即可 </param>
/// <param name="transparency">透明度  1-255</param>
/// <returns></returns>
typedef int (__stdcall *Padd_dynamic)(unsigned long program, unsigned long dynamic_area,int dynamic_id, int x, int y, int w, int h, LPCWSTR relative_program, int run_mode,LPCWSTR update_frequency, int transparency);

//格式化，不建议使用
typedef int (__stdcall *Preboot)(char* ip, unsigned short port,LPCWSTR user_name, LPCWSTR user_pwd);

/// <summary>
/// 把节目添加到节目单
/// </summary>
/// <param name="playlist">播放列表</param>
/// <param name="program">节目句柄</param>
/// <param name="play_mode">播放模式，0 – 定长播放，1 – 定次播放</param>
/// <param name="play_time">播放时长或者播放次数</param>
/// <param name="aging_start_time">播放时效的开始日期</param>
/// <param name="aging_end_time">播放时效结束日期</param>
/// <param name="period_ontime">播放时段开始时间</param>
/// <param name="period_offtime">放时段结束时间</param>
/// <param name="play_week">bit0 ～ bit6 依次表示星期一至星期天，0—表示该天节目不能播放，1—表示该天节目可以播放</param>
/// <returns></returns>
typedef int (__stdcall *Padd_program_in_playlist)(unsigned long playlist, unsigned long program, int play_mode, int play_time, LPCWSTR aging_start_time, LPCWSTR aging_end_time, LPCWSTR period_ontime, LPCWSTR period_offtime, int play_week);

/// <summary>
/// 更新动态区图文文件
/// </summary>
/// <param name="ip">控制卡IP</param>
/// <param name="port">端口</param>
/// <param name="user_name">登录名 "guest"</param>
/// <param name="user_pwd">登录密码 "guest"</param>
/// <param name="dynamic_playlist">播放列表</param>
/// <param name="immediately_play">指定一个关联了普通节目的动态区 ID（必须是 dynamics 参数中存在的 id）</param>
/// <param name="conver">是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目</param>
/// <param name="onlyUpdate">是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"</param>
/// <returns></returns>
typedef int (__stdcall *Pupdate_dynamic)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);

/// <summary>
/// 更新动态区字符串
/// </summary>
/// <param name="ip">控制卡IP</param>
/// <param name="port">端口</param>
/// <param name="user_name">登录名 "guest"</param>
/// <param name="user_pwd">登录密码 "guest"</param>
/// <param name="dynamic_playlist">播放列表</param>
/// <param name="immediately_play">指定一个关联了普通节目的动态区 ID（必须是 dynamics 参数中存在的 id）</param>
/// <param name="conver">是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目</param>
/// <param name="onlyUpdate">是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"</param>
/// <returns></returns>
typedef int (__stdcall *Pupdate_dynamic_small)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned long playlist, LPCWSTR immediately_play, int conver, int onlyUpdate);

/// <summary>
/// 替换素材，可用于更新已有动态区字符串
/// </summary>
/// <param name="ip">控制卡IP</param>
/// <param name="port">端口</param>
/// <param name="user_name">登录名 "guest"</param>
/// <param name="user_pwd">登录密码 "guest"</param>
/// <param name="dynamic_playlist">播放列表句柄</param>
/// <returns></returns>
typedef int (__stdcall *Pupdate_dynamic_unit_small)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned long playlist);

/// <summary>
/// 取消节目单
/// </summary>
/// <param name="playlist">播放列表句柄</param>
typedef int (__stdcall *Pcancel_send_program)(unsigned long playlist);

/// <summary>
/// 销毁播放列表
/// </summary>
/// <param name="playlist">播放列表句柄</param>
typedef int (__stdcall *Pdelete_playlist)(unsigned long playlist);

/// <summary>
/// 校正时间
/// </summary>
/// <param name="ip">控制卡IP</param>
/// <param name="port">端口</param>
/// <param name="user_name">登录名 "guest"</param>
/// <param name="user_pwd">登录密码 "guest"</param>
/// <returns></returns>
typedef int (__stdcall *Pcheck_time)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd);

/// <summary>
/// 创建图文句柄
/// </summary>
/// <returns>图文句柄</returns>
typedef int (__stdcall *Pcreate_pic)();

/// <summary>
/// 添加图文数据
/// </summary>
/// <param name="area_tree">图⽚分区句柄 </param>
/// <param name="stay_time">停留时间 </param>
/// <param name="display_effects">特技编号</param>
/// <param name="display_speed">特技运行速度</param>
/// <param name="path">图片文件全路径</param>
/// <returns></returns>
typedef int (__stdcall *Padd_pic_unit)(unsigned long pic_area, int stay_time, int display_effects, int display_speed, LPCWSTR src_path);

/// <summary>
/// 把图文区域添加到节目
/// </summary>
/// <param name="tree">节目句柄</param>
/// <param name="area_tree">图文区句柄</param>
/// <param name="x">坐标起始X</param>
/// <param name="y">坐标起始Y</param>
/// <param name="w">区域宽度</param>
/// <param name="h">区域高度</param>
/// <param name="transparency">透明度  1-255</param>
/// <returns></returns>
typedef int (__stdcall *Padd_pic)(unsigned long program, unsigned long pic_area, int x, int y, int w, int h, int transparency);

/// <summary>
/// 发送节目到显示屏
/// </summary>
/// <param name="ip">控制卡IP</param>
/// <param name="port">端口</param>
/// <param name="user_name">登录名 "guest"</param>
/// <param name="user_pwd">登录密码 "guest"</param>
/// <param name="tmp_path">播放列表路径</param>
/// <param name="playlist">播放列表</param>
/// <param name="send_style">固定值为0 不能改变</param>
/// <param name="free_size">剩余空间  目前无效</param>
/// <param name="total_size">总容量  目前无效</param>
/// <returns>返回值 0成功</returns>
typedef int (__stdcall *Psend_program)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, LPCWSTR tmp_path, unsigned long playlist, int send_style, long long  * free_size, long long * total_size);

// 函数：	update_dynamic_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			LPCWSTR user_name：登录名
//			LPCWSTR user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
// 说明：	更新动态区素材
typedef int (__stdcall *Pupdate_dynamic_unit)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned long playlist);

/// <summary>
/// 创建时间句柄
/// </summary>
/// <returns>时间句柄</returns>
typedef unsigned long (__stdcall *Pcreate_time)();
/// <summary>
/// 添加时间数据
/// </summary>
/// <param name="time_tree">时间分区句柄 </param>
/// <param name="content">显⽰内容 </param>
/// <param name="font_color">字体颜⾊ </param>
/// <param name="font_name">字体名称 </param>
/// <param name="font_size">字体⼤⼩ </param>
/// <param name="x">x坐标(相对窗⼝)</param>
/// <param name="y">y坐标(相对窗⼝)</param>
/// <param name="font_attributes">字体属性（包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进⾏组合）</param>
/// <returns></returns>
typedef int (__stdcall *Padd_time_unit)(unsigned long time_area, LPCWSTR content, LPCWSTR font_color, LPCWSTR font_name, int font_size, int x, int y, LPCWSTR font_attributes);
/// <summary>
/// 添加时间区到节目
/// </summary>
/// <param name="tree">节⽬句柄 </param>
/// <param name="area_tree">时间分区句柄 </param>
/// <param name="x">坐标起始X</param>
/// <param name="y">坐标起始Y</param>
/// <param name="w">区域宽度</param>
/// <param name="h">区域高度</param>
/// <param name="transparency">透明度 </param>
/// <param name="bg_color">背景颜色</param>
/// <param name="time_equation">时差，格式“hh:mm:ss” </param>
/// <param name="positive_te">正，负时差：”true“，”false“"</param>
/// <returns></returns>
typedef int (__stdcall *Padd_time)(unsigned long program, unsigned long time_area, int x, int y, int w, int h, int transparency, LPCWSTR bg_color, LPCWSTR time_equation, LPCWSTR positive_te, LPCWSTR adjustment);


typedef unsigned long (__stdcall *Pcreate_video)();
typedef int (__stdcall *Padd_video_unit)(unsigned long video_area, int volume, int scale_mode, int source, int play_time, LPCWSTR src_path, LPCWSTR crop_type);
typedef int (__stdcall *Padd_video)(unsigned long program, unsigned long video_area, int x, int y, int w, int h, int volume_mode, int video_type, int ratation_mode, LPCWSTR clone_str, LPCWSTR crop_type);


typedef int (__stdcall *Plock_screen)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, int lock);
typedef int (__stdcall *Pset_screen_volumn)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, int volumn);
typedef int (__stdcall *Pset_screen_brightness)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, int brightness);
typedef int (__stdcall *Pset_screen_auto_brightness)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, LPCWSTR sensor_addr);
typedef int (__stdcall *Pset_screen_cus_brightness)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned short* brightness, int data_count);

typedef int (__stdcall *Pset_screen_turnonoff)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, int turnonoff_status);
typedef unsigned long (__stdcall *Pcreate_turnonoff)();
typedef int (__stdcall *Padd_turnonoff)(unsigned long turnonoff, int action, LPCWSTR time);
typedef int (__stdcall *Pdelete_turnonoff)(unsigned long turnonoff);
typedef int (__stdcall *Pset_screen_cus_turnonoff)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned long turnonoff);
typedef int (__stdcall *Pcancel_screen_cus_turnonoff)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd);

typedef unsigned long (__stdcall *Pcreate_text)();
typedef int (__stdcall *Padd_text_unit_text)(unsigned long area_tree, int stay_time, int display_speed, LPCWSTR font_name, int font_size, LPCWSTR font_attributes, LPCWSTR font_alignment, LPCWSTR font_color, LPCWSTR bg_color, LPCWSTR content);
typedef int (__stdcall *Padd_text)(unsigned long tree, unsigned long area_tree, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);  
typedef int (__stdcall *Pget_screen_parameters)(char* ip, unsigned short port, LPCWSTR user_name, LPCWSTR user_pwd, unsigned char* cards);      

	PInitSdk init_sdk;
	PReleaseSdk release_sdk;

	Pcreate_playlist create_playlist;
	Pcreate_program create_program;
	Padd_program_in_playlist add_program_in_playlist;
	Psend_program send_program;
	Pcancel_send_program cancel_send_program;
	Pdelete_playlist delete_playlist;

	Pcreate_dynamic create_dynamic;
	Pdelete_dynamic delete_dynamic;
	Padd_dynamic_unit add_dynamic_unit;
	Padd_dynamic add_dynamic;
	Pupdate_dynamic update_dynamic;
	Pupdate_dynamic_unit update_dynamic_unit;
	Pupdate_dynamic_small update_dynamic_small;
	Pupdate_dynamic_unit_small update_dynamic_unit_small;
	Pclear_dynamic clear_dynamic;

	Pcheck_time check_time;
	Preboot reboot;

	Pcreate_pic create_pic;
	Padd_pic_unit add_pic_unit;
	Padd_pic add_pic;

	Pcreate_time create_time;
	Padd_time_unit add_time_unit;
	Padd_time add_time;

	Pcreate_video create_video;
	Padd_video_unit add_video_unit;
	Padd_video add_video;

	Plock_screen lock_screen;
	Pset_screen_volumn set_screen_volumn;
	Pset_screen_brightness set_screen_brightness;
	Pset_screen_auto_brightness set_screen_auto_brightness;
	Pset_screen_cus_brightness set_screen_cus_brightness;

	Pset_screen_turnonoff set_screen_turnonoff;
	Pcreate_turnonoff create_turnonoff;
	Padd_turnonoff add_turnonoff;
	Pdelete_turnonoff delete_turnonoff;
	Pset_screen_cus_turnonoff set_screen_cus_turnonoff;
	Pcancel_screen_cus_turnonoff cancel_screen_cus_turnonoff;

	Pcreate_text create_text;
	Padd_text_unit_text add_text_unit_text;
	Padd_text add_text;
	Pget_screen_parameters get_screen_parameters;


string string_To_UTF8(const std::string & str);
LPCWSTR stringToLPCWSTR(std::string orig);
void Program_dynamic_uint_small(char* ip,int port,LPCWSTR str);
void Program_dynamic_small(char* ip,int port,LPCWSTR str);
void Program_dynamic(char* ip,int port,LPCWSTR str);
void Program_bmp(char* ip,int port,LPCWSTR str);
void Program_dynamic_uint(char* ip,int port,LPCWSTR str);
void Program_time(char* ip,int port,LPCWSTR str);
void Program_video(char* ip,int port,LPCWSTR str);
void Program_cleardynamic(char* ip,int port,LPCWSTR str);
void Program_lock_screen(char* ip,int port,LPCWSTR str, int nlock);
void Program_set_screen_volumn(char* ip,int port,LPCWSTR str, int volumn);
void Program_set_screen_brightness(char* ip,int port,LPCWSTR str, int brightness);
void Program_set_screen_cus_brightness(char* ip,int port,LPCWSTR str);
void Program_set_screen_turnonoff(char* ip,int port,LPCWSTR str, int turnonoff);
void Program_set_screen_cus_turnonoff(char* ip,int port,LPCWSTR str);
void Program_cancel_screen_cus_turnonoff(char* ip,int port,LPCWSTR str);
void Program_str(char* ip,int port,LPCWSTR str);
void Program_str1(char* ip,int port,LPCWSTR user_name,LPCWSTR user_pwd);
void Program_dynamic1(char* ip,int port,LPCWSTR str);

int main(int argc, char* argv[])
{
	HINSTANCE hdll = LoadLibrary(L"YQNetCom.dll");
	if(hdll==NULL)
	  {
		  cout<<"NULL";
	  }
	init_sdk = (PInitSdk)GetProcAddress(hdll,"init_sdk");
	release_sdk = (PReleaseSdk)GetProcAddress(hdll,"release_sdk");

	create_playlist = (Pcreate_playlist)GetProcAddress(hdll,"create_playlist");
	create_program = (Pcreate_program)GetProcAddress(hdll,"create_program");
	add_program_in_playlist = (Padd_program_in_playlist)GetProcAddress(hdll,"add_program_in_playlist");
	cancel_send_program = (Pcancel_send_program)GetProcAddress(hdll,"cancel_send_program");
	delete_playlist = (Pdelete_playlist)GetProcAddress(hdll,"delete_playlist");
	send_program = (Psend_program)GetProcAddress(hdll,"send_program");

	create_dynamic = (Pcreate_dynamic)GetProcAddress(hdll,"create_dynamic");
	delete_dynamic = (Pdelete_dynamic)GetProcAddress(hdll,"delete_dynamic");
	add_dynamic_unit = (Padd_dynamic_unit)GetProcAddress(hdll,"add_dynamic_unit");
	add_dynamic = (Padd_dynamic)GetProcAddress(hdll,"add_dynamic");
	update_dynamic = (Pupdate_dynamic)GetProcAddress(hdll,"update_dynamic");
	update_dynamic_unit = (Pupdate_dynamic_unit)GetProcAddress(hdll,"update_dynamic_unit");
	update_dynamic_small = (Pupdate_dynamic_small)GetProcAddress(hdll,"update_dynamic_small");
	update_dynamic_unit_small = (Pupdate_dynamic_unit_small)GetProcAddress(hdll,"update_dynamic_unit_small");
	clear_dynamic = (Pclear_dynamic)GetProcAddress(hdll,"clear_dynamic");

	check_time = (Pcheck_time)GetProcAddress(hdll,"check_time");
	reboot = (Preboot)GetProcAddress(hdll,"reboot");

	create_pic = (Pcreate_pic)GetProcAddress(hdll,"create_pic");
	add_pic_unit = (Padd_pic_unit)GetProcAddress(hdll,"add_pic_unit");
	add_pic = (Padd_pic)GetProcAddress(hdll,"add_pic");

	create_time = (Pcreate_time)GetProcAddress(hdll,"create_time");
	add_time_unit = (Padd_time_unit)GetProcAddress(hdll,"add_time_unit");
	add_time = (Padd_time)GetProcAddress(hdll,"add_time");

	create_video = (Pcreate_video)GetProcAddress(hdll,"create_video");
	add_video_unit = (Padd_video_unit)GetProcAddress(hdll,"add_video_unit");
	add_video = (Padd_video)GetProcAddress(hdll,"add_video");
	
	lock_screen = (Plock_screen)GetProcAddress(hdll,"lock_screen");
	set_screen_volumn = (Pset_screen_volumn)GetProcAddress(hdll,"set_screen_volumn");
	set_screen_brightness = (Pset_screen_brightness)GetProcAddress(hdll,"set_screen_brightness");
	set_screen_auto_brightness = (Pset_screen_auto_brightness)GetProcAddress(hdll,"set_screen_auto_brightness");
	set_screen_cus_brightness = (Pset_screen_cus_brightness)GetProcAddress(hdll,"set_screen_cus_brightness");
	
	set_screen_turnonoff = (Pset_screen_turnonoff)GetProcAddress(hdll,"set_screen_turnonoff");
	create_turnonoff = (Pcreate_turnonoff)GetProcAddress(hdll,"create_turnonoff");
	add_turnonoff = (Padd_turnonoff)GetProcAddress(hdll,"add_turnonoff");
	delete_turnonoff = (Pdelete_turnonoff)GetProcAddress(hdll,"delete_turnonoff");
	set_screen_cus_turnonoff = (Pset_screen_cus_turnonoff)GetProcAddress(hdll,"set_screen_cus_turnonoff");
	cancel_screen_cus_turnonoff = (Pcancel_screen_cus_turnonoff)GetProcAddress(hdll,"cancel_screen_cus_turnonoff");
	
	create_text = (Pcreate_text)GetProcAddress(hdll,"create_text");
	add_text_unit_text = (Padd_text_unit_text)GetProcAddress(hdll,"add_text_unit_text");
	add_text = (Padd_text)GetProcAddress(hdll,"add_text");
	get_screen_parameters = (Pget_screen_parameters)GetProcAddress(hdll,"get_screen_parameters");

	int err=init_sdk();
	
    char* ip = "192.168.89.166";
    int port = 80;
    LPCWSTR str = L"guest";
	
    err = check_time(ip, port, _TEXT_T("guest"), _TEXT_T("guest"));
	cout<<"check_time:"<<err<<endl;
	//Program_cleardynamic(ip, port, str);
	Program_dynamic_small(ip, port, str);

	err=release_sdk();
    system("pause");
	return 0;
}
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

//更新动态区字符串
void Program_dynamic_small(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(64, 32, 8536);
	cout<<"create_playlist:"<<playlist<<endl;
    unsigned long program = create_program(L"program_1",_TEXT_T("0xff000000"));
	cout<<"create_program:"<<program<<endl;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    LPCWSTR bg_color = L"0xff000000";
    LPCWSTR color = _T("0xffff0000");
    LPCWSTR font_attributes = _T("normal");
    LPCWSTR font = _T("SimSun");
    LPCWSTR align_h = _T("0");
    LPCWSTR align_v = _T("0");

    std::string file = string_To_UTF8("动147态区");
	std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(file.c_str()), file.length());
	LPCWSTR wcstring = stringToLPCWSTR(encoded);
	/*
    std::string file1 = string_To_UTF8("第一个动");
	std::string encoded1 = base64_encode(reinterpret_cast<const unsigned char*>(file1.c_str()), file1.length());
	LPCWSTR wcstring1 = stringToLPCWSTR(encoded1);
	*/
    unsigned long dynamic_area = create_dynamic();
	cout<<"create_dynamic:"<<dynamic_area<<endl;
    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, wcstring, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
     //err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, wcstring1, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
	//cout<<"add_dynamic_unit:"<<err<<endl;
    err = add_dynamic(program, dynamic_area,0, 0, 0, 32, 32,_T("") , 0, _T(""), 100);
	cout<<"add_dynamic:"<<err<<endl;
    delete_dynamic(dynamic_area);

    LPCWSTR m_aging_start_time = _T("");
    LPCWSTR m_aging_stop_time = _T("");
    LPCWSTR m_period_ontime = _T("");
    LPCWSTR m_period_offtime = _T("");
    err = add_program_in_playlist(playlist, program, 1, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
	cout<<"add_program_in_playlist:"<<err<<endl;
    err = update_dynamic_small(ip, port, str, str, playlist, _T(""), 1, 0);
	cout<<"update_dynamic_small:"<<err<<endl;

    cancel_send_program(playlist);
    delete_playlist(playlist);
}
//更新动态区字符串内容
void Program_dynamic_uint_small(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(128, 96, 8536);
	cout<<"create_playlist:"<<playlist<<endl;
    unsigned long program = create_program(L"program_1",_TEXT_T("0xff000000"));
	cout<<"create_program:"<<program<<endl;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    LPCWSTR bg_color = _T("0xff000000");
    LPCWSTR color = _T("0xffff0000");
    LPCWSTR font_attributes = _T("normal");
    LPCWSTR font = _T("SimSun");
    LPCWSTR align_h = _T("0");
    LPCWSTR align_v = _T("0");

    std::string file = string_To_UTF8("动态区更新789");
	std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(file.c_str()), file.length());
	LPCWSTR File = stringToLPCWSTR(encoded);
    unsigned long dynamic_area = create_dynamic();
	cout<<"create_dynamic:"<<dynamic_area<<endl;
    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, File, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
	cout<<"add_dynamic_unit:"<<err<<endl;
    err = add_dynamic(program, dynamic_area,0, 0, 0, 32, 32, _T(""), 0, _T(""), 100);
	cout<<"add_dynamic:"<<err<<endl;
    delete_dynamic(dynamic_area);

    LPCWSTR m_aging_start_time = _T("");
    LPCWSTR m_aging_stop_time = _T("");
    LPCWSTR m_period_ontime = _T("");
    LPCWSTR m_period_offtime = _T("");
    err = add_program_in_playlist(playlist, program, 1, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
	cout<<"add_program_in_playlist:"<<err<<endl;
    err = update_dynamic_unit_small(ip, port, str, str, playlist);
	cout<<"update_dynamic_unit_small:"<<err<<endl;

    cancel_send_program(playlist);
    delete_playlist(playlist);
}

//更新动态区图文文件
void Program_dynamic(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(64, 32, 8536);
	cout<<"create_playlist:"<<playlist<<endl;
    unsigned long program = create_program(L"program_1",_TEXT_T("0xff000000"));
	cout<<"create_program:"<<program<<endl;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    LPCWSTR bg_color = L"0xff000000";
    LPCWSTR color = L"0xffff0000";
    LPCWSTR font_attributes = L"normal";
    LPCWSTR font = L"SimSun";
    LPCWSTR align_h = L"0";
    LPCWSTR align_v = L"0";

	LPCWSTR ff=L"1.txt";
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, L'\\'))[1] = 0;
	LPCWSTR f = wcscat(szFilePath,ff);
    unsigned long dynamic_area = create_dynamic();
	cout<<"create_dynamic:"<<dynamic_area<<endl;
    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, f, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
	cout<<"add_dynamic_unit:"<<err<<endl;
    err = add_dynamic(program, dynamic_area,0, 0, 0, 64, 32, _T(""), 0, L"", 100);
	cout<<"add_dynamic:"<<err<<endl;
    delete_dynamic(dynamic_area);

    LPCWSTR m_aging_start_time = _T("2018-12-01");
    LPCWSTR m_aging_stop_time = _T("2018-12-30");
    LPCWSTR m_period_ontime = _T("15:14:00");
    LPCWSTR m_period_offtime = _T("15:15:00");
    err = add_program_in_playlist(playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
	cout<<"add_program_in_playlist:"<<err<<endl;
    err = update_dynamic(ip, port, str, str, playlist, _T(""), 1, 0);
	cout<<"update_dynamic:"<<err<<endl;

    cancel_send_program(playlist);//printf("result：%d\n",result);
    delete_playlist(playlist);
}
//更新动态区图文文件内容
void Program_dynamic_uint(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(128, 96, 8536);
	cout<<"create_playlist:"<<playlist<<endl;
    unsigned long program = create_program(L"program_1",_TEXT_T("0xff000000"));
	cout<<"create_program:"<<program<<endl;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    LPCWSTR bg_color = L"0xff000000";
    LPCWSTR color = L"0xffff0000";
    LPCWSTR font_attributes = L"normal";
    LPCWSTR font = L"SimSun";
    LPCWSTR align_h = L"0";
    LPCWSTR align_v = L"0";

	LPCWSTR ff=L"2.txt";
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, L'\\'))[1] = 0;
	LPCWSTR f = wcscat(szFilePath,ff);
    unsigned long dynamic_area = create_dynamic();
	cout<<"create_dynamic:"<<dynamic_area<<endl;
    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, f, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
	cout<<"add_dynamic_unit:"<<err<<endl;
    err = add_dynamic(program, dynamic_area,0, 0, 0, 64, 32, _T(""), 0, L"", 100);
	cout<<"add_dynamic:"<<err<<endl;
    delete_dynamic(dynamic_area);

    LPCWSTR m_aging_start_time = _T("");
    LPCWSTR m_aging_stop_time = _T("");
    LPCWSTR m_period_ontime = _T("");
    LPCWSTR m_period_offtime = _T("");
    err = add_program_in_playlist(playlist, program, 1, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
	cout<<"add_program_in_playlist:"<<err<<endl;
    err = update_dynamic_unit(ip, port, str, str,playlist);
	cout<<"update_dynamic:"<<err<<endl;

    cancel_send_program(playlist);
    delete_playlist(playlist);
}

//删除所有动态区
void Program_cleardynamic(char* ip,int port,LPCWSTR str) 
{
    int err = clear_dynamic(ip, port, str, str);
}

//发送图片
void Program_bmp(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(128, 96, 8536);
	LPCWSTR name=L"program_1";
    unsigned long program = create_program(name,_TEXT_T("0xff000000"));
    //图片
	LPCWSTR ff=L"男.bmp";
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, L'\\'))[1] = 0;
	LPCWSTR file = wcscat(szFilePath,ff);

    unsigned long pic_area = create_pic();
    int err = add_pic_unit(pic_area, 1, 5, 1, file);
    err = add_pic(program, pic_area, 0, 0, 128, 96, 100);
		
    LPCWSTR m_aging_start_time = _T("2018-12-01");
    LPCWSTR m_aging_stop_time = _T("2018-12-30");
    LPCWSTR m_period_ontime = _T("15:20:00");
    LPCWSTR m_period_offtime = _T("15:21:00");
    err = add_program_in_playlist(playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
    int send_style = 0;

	LPCWSTR tmp_path=L"F:\\Temp\\";
    long long  free_size=0, total_size=0;
    err = send_program(ip, port, str, str, tmp_path, playlist, send_style, &free_size,&total_size);

    cancel_send_program(playlist);
    delete_playlist(playlist);
}

//发送时间
void Program_time(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(128, 96, 8280);
	LPCWSTR name=L"program_1";
    unsigned long program = create_program(name,_TEXT_T("0xff000000"));
	
    //时间
    unsigned long time_area = create_time();
    LPCWSTR content = L"jfshafffdjksf";
    LPCWSTR content1 = L"%Y年%m月%d日";
    LPCWSTR content2 = L"星期%w";
    LPCWSTR content3 = L"%H时%M分%S秒";
    LPCWSTR font = L"宋体";
    LPCWSTR color = L"0xffff0000";
    LPCWSTR font_attributes = L"bold";
    LPCWSTR bg_color = L"0xff00f000";
    LPCWSTR time_equation = L"1:0:00";
    LPCWSTR positive_te = L"true";
    LPCWSTR adjustment = L"+00:00:00:00";
    int err ;
	//err = add_time_unit(time_area, content, color, font, 12, 0, 16, font_attributes);
    err = add_time_unit(time_area, content1, color, font, 12, 0, 32, font_attributes);
    /*err = add_time_unit(time_area, content2, color, font, 12, 0, 48, font_attributes);
    err = add_time_unit(time_area, content3, color, font, 12, 0, 64, font_attributes);*/
    err = add_time(program, time_area, 0, 0, 128, 96, 255, bg_color, time_equation, positive_te,adjustment);
		
	LPCWSTR m_aging_start_time = L"";
	LPCWSTR m_aging_stop_time = L"";
	LPCWSTR m_period_ontime = L"";
	LPCWSTR m_period_offtime = L"";
    err = add_program_in_playlist(playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
    int send_style = 0;

	LPCWSTR tmp_path=L"F:\\Temp\\";
    long long  free_size=0, total_size=0;
    err = send_program(ip, port, str, str, tmp_path, playlist, send_style, &free_size,&total_size);

    cancel_send_program(playlist);
    delete_playlist(playlist);
}

//发送视频
void Program_video(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(128, 96, 8536);
	LPCWSTR name=L"program_1";
    unsigned long program = create_program(name,_TEXT_T("0xff000000"));
	
    //视频
	LPCWSTR ff=L"海尔1_Convert_M.mp4";
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, L'\\'))[1] = 0;
	LPCWSTR VideoFile = wcscat(szFilePath,ff);
    unsigned long video_area = create_video();
    int err = add_video_unit(video_area, 2, 1, 0, 1000, VideoFile, L"");
    err = add_video(program, video_area, 0, 0, 128, 96, 0, 0, 0, L"", L"");
		
	LPCWSTR m_aging_start_time = L"";
	LPCWSTR m_aging_stop_time = L"";
	LPCWSTR m_period_ontime = L"";
	LPCWSTR m_period_offtime = L"";
    err = add_program_in_playlist(playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
    int send_style = 0;

	LPCWSTR tmp_path=L"F:\\Temp\\";
    long long  free_size=0, total_size=0;
    err = send_program(ip, port, str, str, tmp_path, playlist, send_style, &free_size,&total_size);

    cancel_send_program(playlist);
    delete_playlist(playlist);
}

//锁定屏幕
void Program_lock_screen(char* ip,int port,LPCWSTR str, int nlock)
{
    int err = lock_screen(ip, port, str, str, nlock);
}
//设置系统⾳量
void Program_set_screen_volumn(char* ip,int port,LPCWSTR str, int volumn)
{
    int err = set_screen_volumn(ip, port, str, str, volumn);
}
//手动调亮
void Program_set_screen_brightness(char* ip,int port,LPCWSTR str, int brightness)
{
    int err = set_screen_brightness(ip,port, str, str, brightness);
}
//定时调亮
void Program_set_screen_cus_brightness(char* ip,int port,LPCWSTR str)
{
	unsigned short brightness[48]={0};
    for (int i = 0; i < 48; i++) { brightness[i] = 255; }
    int err = set_screen_cus_brightness(ip, port, str, str, brightness,48);
}
//手动设置开关机
void Program_set_screen_turnonoff(char* ip,int port,LPCWSTR str, int turnonoff)
{
    int err = set_screen_turnonoff(ip, port, str, str, turnonoff);
}
//定时开关机
void Program_set_screen_cus_turnonoff(char* ip,int port,LPCWSTR str)
{
    unsigned long trunonoff = create_turnonoff();
    add_turnonoff(trunonoff, 1, L"22:15:00");
    add_turnonoff(trunonoff, 0, L"22:16:00");
    add_turnonoff(trunonoff, 1, L"22:24:00");
    add_turnonoff(trunonoff, 0, L"22:26:00");
    int err = set_screen_cus_turnonoff(ip, port, str, str, trunonoff);
    delete_turnonoff(trunonoff);
}
//取消定时开关机,保留取消时屏幕状态
void Program_cancel_screen_cus_turnonoff(char* ip,int port,LPCWSTR str)
{
    int err = cancel_screen_cus_turnonoff(ip, port, str, str);
}

        //发送字幕
void Program_str(char* ip,int port,LPCWSTR str)
{
        int err = 0;
        
    unsigned long playlist = create_playlist(64, 32, 8536);
	LPCWSTR name=L"默认字幕显示";
    unsigned long program = create_program(name,_TEXT_T("0xff000000"));
        //图片
        unsigned long area_tree = create_text();
        err = add_text_unit_text(area_tree, 5, 5, L"SimSun", 12, L"normal", L"0", L"0xffff0000", L"0xff000000", L"111111");
        //Console.WriteLine("add_text_unit_text:" + err);
        err = add_text(program, area_tree, 0, 0, 64, 32, 100,4,1);

    LPCWSTR m_aging_start_time = _T("");
    LPCWSTR m_aging_stop_time = _T("");
    LPCWSTR m_period_ontime = _T("");
    LPCWSTR m_period_offtime = _T("");
    err = add_program_in_playlist(playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
    int send_style = 0;

	LPCWSTR tmp_path=L"F:\\Temp\\";
    long long  free_size=0, total_size=0;
    err = send_program(ip, port, str, str, tmp_path, playlist, send_style, &free_size,&total_size);

    cancel_send_program(playlist);
    delete_playlist(playlist);
}

void Program_str1(char* ip,int port,LPCWSTR user_name,LPCWSTR user_pwd)
{
	int w=256,h=120,device_type=8536;
	unsigned long  play_list=create_playlist(w,h,device_type);
	
	

	_TEXT_CHAR* name=L"project-1";
	unsigned long  program=create_program(name,_TEXT_T("0xff000000"));

	unsigned long  text_area= create_text();
	unsigned long  text_area1= create_text();
	unsigned long  text_area2= create_text();
	unsigned long  text_area3= create_text();
	unsigned long  text_area4= create_text();
	unsigned long  text_area5= create_text();
	

	int x=470,y=0,layout=0,transparency=100,font_size=10;
        int display_effects=52,display_speed=16,stay_time=0,content_x=60;     		int content_y=20,unit_type = 1;
 
        _TEXT_CHAR *font_name=L"Arial",*bg_color=L"0xFF000000";                  
        _TEXT_CHAR *font_attributes=L"normal",*font_alignment = L"10"; 			  
	 char name_b[20]="cc",font_color[20]="0xFFFFAB00";
         char content[60]="CHINESE";

	 int ate=add_text_unit_text(text_area,stay_time,display_speed,font_name,font_size,font_attributes,font_alignment,L"0xFFFFAB00",bg_color,L"CHINESE");

         add_text_unit_text(text_area1,0,16,font_name,10,L"normal",L"10",L"0xFFFF0000",bg_color,L"501C");
		 add_text_unit_text(text_area2,0,16,font_name,10,L"normal",L"10",L"0xFFFF0000",bg_color,L"AURO");
		 add_text_unit_text(text_area3,0,16,font_name,10,L"normal",L"10",L"0xFFFF0000",bg_color,L"LED");
		 add_text_unit_text(text_area4,0,16,font_name,10,L"normal",L"10",L"0xFFFF0000",bg_color,L"DISPLAY");
		 add_text_unit_text(text_area5,0,16,font_name,10,L"normal",L"10",L"0xFFFF0000",bg_color,L"BUSES");
	 cout<<"add_text_unit_text=="<<ate<<endl;

         ate = add_text(program,text_area,201,0,55,20,transparency,display_effects,unit_type);

			   add_text(program,text_area1,201,20,55,20,transparency,1,unit_type);
			   add_text(program,text_area2,160,0,40,20,transparency,1,unit_type);
			   add_text(program,text_area3,160,20,40,20,transparency,1,unit_type);
			   add_text(program,text_area4,120,0,40,20,transparency,1,unit_type);
			   add_text(program,text_area5,120,20,40,20,transparency,1,unit_type);
	cout<<"add_text=="<<ate<<endl;

        _TEXT_CHAR *aging_start_time=L"",*aging_end_time=L"";
        _TEXT_CHAR *period_ontime=L"",*period_offtime=L"";
 
        

	 int play_mode=1,play_week=127,play_time=1;
	 int  pap=add_program_in_playlist( play_list,program,play_mode,play_time, aging_start_time,aging_end_time,period_ontime, period_offtime, play_week);
         cout<<"playlist_add_program=="<<pap<<endl;
	  _TEXT_CHAR* tmp_path=L"F:\\Temp\\";
	  int send_style=0;
	  long long free_size,total_size;
	  int sam=send_program(ip,port,user_name,user_pwd,tmp_path,play_list,send_style,&free_size,&total_size);
	  cout<<"send _program=="<<sam<<endl; 

}


//更新动态区图文文件
void Program_dynamic1(char* ip,int port,LPCWSTR str)
{
    unsigned long playlist = create_playlist(64, 32,8536);
	cout<<"create_playlist:"<<playlist<<endl;
    unsigned long program = create_program(L"program_1",_TEXT_T("0xff000000"));
	cout<<"create_program:"<<program<<endl;

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    LPCWSTR bg_color = L"0xff000000";
    LPCWSTR color = L"0xffff0000";
    LPCWSTR font_attributes = L"normal";
    LPCWSTR font = L"SimSun";
    LPCWSTR align_h = L"0";
    LPCWSTR align_v = L"0";

	LPCWSTR ff=L"1.txt";
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, L'\\'))[1] = 0;
	LPCWSTR f = wcscat(szFilePath,ff);
    unsigned long dynamic_area = create_dynamic();
	cout<<"create_dynamic:"<<dynamic_area<<endl;
    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, _TEXT_T("1.txt"), gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
     err = add_dynamic_unit(dynamic_area, 0, display_effects, display_speed, stay_time,  _TEXT_T("1.bmp"), gif_flag, bg_color, 12, font, color, font_attributes,  _TEXT_T("0"),  _TEXT_T("0"), 0, 0, 0,_TEXT_T(""),_TEXT_T(""));
	cout<<"add_dynamic_unit:"<<err<<endl;
    err = add_dynamic(program, dynamic_area,0, 0, 0, 64, 32, L"", 0, L"", 100);
	cout<<"add_dynamic:"<<err<<endl;
    delete_dynamic(dynamic_area);

    LPCWSTR m_aging_start_time = _T("2018-12-01");
    LPCWSTR m_aging_stop_time = _T("2018-12-30");
    LPCWSTR m_period_ontime = _T("15:14:00");
    LPCWSTR m_period_offtime = _T("15:15:00");
    err = add_program_in_playlist(playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
	cout<<"add_program_in_playlist:"<<err<<endl;
    err = update_dynamic(ip, port, _TEXT_T("guest"), _TEXT_T("guest"), playlist, _TEXT_T(""), 1, 0);
	cout<<"update_dynamic:"<<err<<endl;

    cancel_send_program(playlist);
    delete_playlist(playlist);
}