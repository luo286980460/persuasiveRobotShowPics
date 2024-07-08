/************************************************************************
 * file:	YQNetCom.h
 * brief:	Header file of Network communication library in network part
 * author:	Judy
 * date:	2020-01-15
 ***********************************************************************/
#ifndef _YQNETCOM_H
#define _YQNETCOM_H
#ifdef _WIN32
#ifdef YQNETCOM_EXPORTS
#define LEDNETSDK_API extern "C" __declspec(dllexport)
#else
#define LEDNETSDK_API extern "C" __declspec(dllimport)
#endif
#define _TEXT_CHAR	wchar_t
//#define _JAVA
// #ifdef _JAVA
// #define _CALL_STD __cdecl
// #else
#define _CALL_STD __stdcall
//#endif
#else
#define LEDNETSDK_API extern "C"
#define _TEXT_CHAR	char
#define _CALL_STD  
#endif

typedef struct card
{
	char ip[20];//控制器地址
	char barcode[17];//控制器条形码
}card_unit;
typedef struct _CARD_SERVER
{
	char barcode[17];//控制器条形
}server_card;


#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
LEDNETSDK_API int _CALL_STD init_sdk();

LEDNETSDK_API int _CALL_STD release_sdk();
#endif

LEDNETSDK_API int _CALL_STD search_card(unsigned char* cards, int* card_count);

LEDNETSDK_API unsigned long _CALL_STD create_radio();
LEDNETSDK_API int _CALL_STD search_cardSend(unsigned long radio);
LEDNETSDK_API int _CALL_STD search_cardRecv(unsigned long radio,unsigned char* cards, int* card_count);
LEDNETSDK_API void _CALL_STD destroy_radio(unsigned long radio);

LEDNETSDK_API int _CALL_STD get_udp_stamp(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* out_stamp, int is_comm = 0);
LEDNETSDK_API void _CALL_STD set_udp_stamp(_TEXT_CHAR* out_stamp, _TEXT_CHAR* out_sign);
// 函数：	set_screen_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* ip：控制器ip
//			char* submark：网关
//			char* gateway：子网掩码
//			char* dns_server: 域名服务器地址
// 说明：	设置控制器IP地址
LEDNETSDK_API int _CALL_STD set_screen_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);
/*
//函数：	set_screen_ip_dwhand
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器ip
//			char* submark：网关
//			char* gateway：子网掩码
//			char* dns_server: 域名服务器地址
// 说明：	TCP设置控制器IP地址
*/
LEDNETSDK_API int _CALL_STD set_screen_ip_dwhand(unsigned long dwhand, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD set_screen_shadow_net_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark);

LEDNETSDK_API int _CALL_STD restart_app_udp(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_wifi_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* ip：控制器ip
//			char* submark：网关
//			char* gateway：子网掩码
//			char* dns_server: 域名服务器地址
// 说明：	设置控制器IP地址
LEDNETSDK_API int _CALL_STD set_screen_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_auto_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
// 说明：	设置控制器自动获取IP地址
LEDNETSDK_API int _CALL_STD set_screen_auto_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_auto_wifi_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
// 说明：	设置控制器自动获取IP地址
LEDNETSDK_API int _CALL_STD set_screen_auto_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_mac
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* mac：控制器mac
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD set_screen_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_server
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			int server_mode：server(1)：普通服务器模式；cloud(2) ：云平台服务器模式；jtcproxy(3): 交通诱导；off(0)：关闭服务器模式；
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD set_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* server_ip, unsigned short port, int server_mode);
LEDNETSDK_API int _CALL_STD set_screen_server_dwhand(unsigned long dwhand, char* server_ip, unsigned short port, int server_mode);

// 函数：	enable_screen_server
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			int server_mode：server(1)：普通服务器模式；cloud(2) ：云平台服务器模式；off(0)：关闭服务器模式；
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD enable_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int server_mode);
LEDNETSDK_API int _CALL_STD enable_screen_server_dwhand(unsigned long dwhand, int server_mode);

// 函数：	set_screen_server_info
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dwhand：通讯句柄
//			_TEXT_CHAR* server_ip：设置的服务器IP
//			_TEXT_CHAR* server_port：设置的服务器端口
// 说明：	设置控制器服务器地址等相关信息
LEDNETSDK_API int _CALL_STD set_screen_server_info_dwhand(unsigned long dwhand, _TEXT_CHAR* server_ip, _TEXT_CHAR* server_port);
// 函数：	get_screen_server_info
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dwhand：通讯句柄
//			_TEXT_CHAR* server_ip：设置的服务器IP
//			_TEXT_CHAR* server_port：设置的服务器端口
// 说明：	获取设置的控制器服务器地址等相关信息
LEDNETSDK_API int _CALL_STD get_screen_server_info_dwhand(unsigned long dwhand, _TEXT_CHAR* server_ip, _TEXT_CHAR* server_port);

// 函数：	set_screen_install_address
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			_TEXT_CHAR* install_address：控制器安装地址
// 说明：	设置控制器IP地址
LEDNETSDK_API int _CALL_STD set_screen_install_address(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* install_address);

// 函数：	set_bx_param
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dwhand：通讯句柄
//			_TEXT_CHAR* param：设置的参数
// 说明：	设置需要保存的以便之后回读的相关信息
LEDNETSDK_API int _CALL_STD set_bx_param(unsigned long dwhand, _TEXT_CHAR* param);
LEDNETSDK_API int _CALL_STD get_bx_param(unsigned long dwhand, _TEXT_CHAR* param);

LEDNETSDK_API int _CALL_STD set_web_user_id(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* user_id);

LEDNETSDK_API int _CALL_STD send_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* tmp_path, unsigned long playlist, int send_style, long long  * free_size, long long * total_size, int is_make = 0, int is_save = 1);
LEDNETSDK_API int _CALL_STD send_program_dwhand(unsigned long dwhand, char* ip, _TEXT_CHAR* tmp_path, unsigned long playlist, int send_style, long long  * free_size, long long * total_size, int is_make = 0, int is_save = 1);
LEDNETSDK_API void _CALL_STD make_program(unsigned long playlist, _TEXT_CHAR* tmp_path);
LEDNETSDK_API void _CALL_STD query_rate(unsigned long playlist, long long * total,long long * cur,int* rate,int* remainsec,int* taskcount,int* completecount);

LEDNETSDK_API void _CALL_STD cancel_send_program(unsigned long playlist);

LEDNETSDK_API void _CALL_STD add_video_md5(unsigned long playlist, _TEXT_CHAR* md5, _TEXT_CHAR* file_path);

LEDNETSDK_API void _CALL_STD add_tls_md5(unsigned long playlist, _TEXT_CHAR* md5, struct TLSInfo* tls_infos);

// 函数：	clear_material
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登陆密码
// 说明：	清理无用素材
LEDNETSDK_API int _CALL_STD clear_material(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_material_dwhand(unsigned long dwhand);
// 函数：	only_clear_material_dwhand
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登陆密码
// 说明：	清理无用素材（不停播，只是发送清理无用素材命令）
LEDNETSDK_API int _CALL_STD only_clear_material_dwhand(unsigned long dwhand);

// 函数：	clear_all_program
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登陆密码
// 说明：	清空所有节目
LEDNETSDK_API int _CALL_STD clear_all_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_all_program_dwhand(unsigned long dwhand);

// 函数：	enable_uploaddownload
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登陆密码
//			int enable_state：开启还是关闭
//			int upload_download：上传还是下载
// 说明：	开启/关闭文件上传/下载
LEDNETSDK_API int _CALL_STD enable_uploaddownload(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int enable_state, int upload_download);
LEDNETSDK_API int _CALL_STD enable_uploaddownload_dwhand(unsigned long dwhand, int enable_state, int upload_download);

#pragma region insert list
LEDNETSDK_API void _CALL_STD add_insert_list(unsigned long playlist, int insert_list_count, int insert_list_duration);
#pragma endregion insert list

#pragma region program
LEDNETSDK_API unsigned long _CALL_STD create_playlist(int w, int h, int device_type);

LEDNETSDK_API void _CALL_STD delete_playlist(unsigned long playlist);

LEDNETSDK_API unsigned long _CALL_STD create_program(_TEXT_CHAR* name, _TEXT_CHAR* bg_color);
LEDNETSDK_API void _CALL_STD delete_program(unsigned long program_area);

LEDNETSDK_API unsigned long _CALL_STD create_video();
LEDNETSDK_API void _CALL_STD delete_video(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_pic();
LEDNETSDK_API void _CALL_STD delete_pic(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_weather();
LEDNETSDK_API void _CALL_STD delete_weather(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_text();
LEDNETSDK_API void _CALL_STD delete_text(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_rich_text();
LEDNETSDK_API void _CALL_STD delete_rich_text(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_colortext();
LEDNETSDK_API void _CALL_STD delete_colortext(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_time();
LEDNETSDK_API void _CALL_STD delete_time(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_calendar();
LEDNETSDK_API void _CALL_STD delete_calendar(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_sensor();
LEDNETSDK_API void _CALL_STD delete_sensor(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_db();
LEDNETSDK_API void _CALL_STD delete_db(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_db_unit();
LEDNETSDK_API void _CALL_STD delete_db_unit(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_audio();
LEDNETSDK_API void _CALL_STD delete_audio(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_broder();
LEDNETSDK_API void _CALL_STD delete_broder(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_dynamic();

LEDNETSDK_API void _CALL_STD delete_dynamic(unsigned long dynamic_area);

LEDNETSDK_API unsigned long _CALL_STD create_clock();
LEDNETSDK_API void _CALL_STD delete_clock(unsigned long area_tree);

LEDNETSDK_API unsigned long _CALL_STD create_nvr();
LEDNETSDK_API void _CALL_STD delete_nvr(unsigned long area_tree);

// 函数：	add_video
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long pic_area：分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			int volume_mode：是否静音（0非静音/1静音）
//			int video_type：视频类型（0本地视频，1外部视频源）
//			int ratation_mode：逆时针角度
//			_TEXT_CHAR* clone_str：克隆信息：（x :y :w:h ,x1：y1：w1：h1...）
//			_TEXT_CHAR* crop_type： 外部视频显示区域位置及大小（w + "x" + h + "+" + x + "+" + y）
// 说明：	添加视频分区
LEDNETSDK_API int _CALL_STD add_video(unsigned long program, unsigned long video_area, int x, int y, int w, int h, int volume_mode, int video_type, int ratation_mode, _TEXT_CHAR* clone_str, _TEXT_CHAR* crop_type);

// 函数：	add_pic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long pic_area：图片分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
// 说明：	添加图片分区
LEDNETSDK_API int _CALL_STD add_pic(unsigned long program, unsigned long pic_area, int x, int y, int w, int h, int transparency);

// 函数：	add_weather
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long weather_area：天气分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			int display_effects   分区特技类型索引 建议只使用0,2,50~57这几种特技类型
//      	string weatherURIHead     天气信息和空气质量的URI头信息
//			string cityID 	城市ID
//			string language  	语言类型
//			int display_speed    特技速度等级，1~16,1为最快
//			int stay_time    图片停留时间，以秒为单位
//			string fontFamily  字体类型 如，宋体,“Sans”
//			string foreGround   字体颜色RGB,如，”#00FF00”
//			string fontSize     左半部分字体大小，如40
//			int smallFontSize  右半部分字体大小，为左边的1/2；
//			int modifyCityName   修改城市名
//			int displayMode    	0- 一般样式;  1- 精美样式1; 2-精美样式2;  3- 预报三天
//			int displayLines    	0-Single line; 1-Multi-line
//			int iconGrade		0- 16*16；1- 24*24；2- 32*32；3- 48*48；4-64*64
//			int tempUnit 	 	0-摄氏度；1-华氏度
//			int isDisplayCity	 	1/true-显示；0/false-不显示
//			int isDisplayIcon		1/true-显示；0/false-不显示
//			int isDisplayWeath		1/true-显示；0/false-不显示
//			int isDisplayTemp		1/true-显示；0/false-不显示
//			int isDisplayWind		1/true-显示；0/false-不显示
//			int isDisplayAirIndex	1/true-显示；0/false-不显示
//			int isDisplayPM	  		1/true-显示；0/false-不显示
//			int alignPosition		0/居左；1/居中；2/居右
// 说明：	添加天气分区
LEDNETSDK_API int _CALL_STD add_weather(unsigned long program, unsigned long weather_area, int x, int y, int w, int h, int transparency, 
	int stay_time, int display_effects, int display_speed, _TEXT_CHAR* weatherURIHead, _TEXT_CHAR* cityID, _TEXT_CHAR* language, _TEXT_CHAR* fontFamily,
	_TEXT_CHAR* foreGround, int fontSize, int smallFontSize, _TEXT_CHAR* modifyCityName, int display_mode, int displayLines, int iconGrade, int temp_unit,
	int isDisplayCity, int isDisplayIcon, int isDisplayWeath, int isDisplayTemp, int isDisplayWind, int isDisplayAirIndex, int isDisplayPM, int alignPosition);

// 函数：	add_broder
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long broder_area：边框区分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			_TEXT_CHAR* areaXYWH:十字屏边框的四个角的坐标位置字段
// 说明：	添加边框分区
LEDNETSDK_API int _CALL_STD add_broder(unsigned long program, unsigned long broder_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* areaXYWH = _TEXT_T(""));

// 函数：	add_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long dynamic_area：动态区分区句柄
//			int dynamic_id：动态区编号
//			int x/y/w/h:动态区区域坐标和宽高
//			_TEXT_CHAR* relative_program:关联的节目，即所要关联的节目序号(节目列表中的 order 字段("0","1",...))，可为空
//			int run_mode:动态区运行方式，0全局播放动态区/1全局动态区节目/2全局动态区节目/3绑定播放动态区，关联节目开始播放时播放动态区，直到关联节目播放完毕/4绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后本轮不再显示/5绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后静止显示该动态区的最后一个unit/6绑定播放动态区，关联节目播放完后播放动态区
//			_TEXT_CHAR* update_frequency：放空""即可  URLPicture或URLText类型资源下载更新频率，单位秒。小于5s均按5s处理。为空或0则只下载一次
//			int transparency: 分区透明度
// 说明：	添加动态区
LEDNETSDK_API int _CALL_STD add_dynamic(unsigned long program, unsigned long dynamic_area, int dynamic_id, int x, int y, int w, int h, _TEXT_CHAR* relative_program, int run_mode, _TEXT_CHAR* update_frequency, int transparency);

// 函数：	add_colorful_subtitle
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long colorful_subtitle_area：炫彩字区分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
// 说明：	添加炫彩字分区
LEDNETSDK_API int _CALL_STD add_colorful_subtitle(unsigned long program, unsigned long colorful_subtitle_area, int x, int y, int w, int h);

// 函数：	add_db
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long db_area：数据库分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
// 说明：	添加数据库分区
LEDNETSDK_API int _CALL_STD add_db(unsigned long program, unsigned long db_area, int x, int y, int w, int h, int transparency);

// 函数：	add_text
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long text_area：字幕区分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			int display_effects：显示特技
//			int unit_type：0 - 渲染好的文本图片，上位机渲染 ； 1 - 未渲染的文字，控制卡自渲染
// 说明：	添加字幕分区
LEDNETSDK_API int _CALL_STD add_text(unsigned long program, unsigned long text_area, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);

// 函数：	add_rich_text
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long text_area：富文本区分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度(0~100)：100 为完全不透明，默认100
//			int display_effects：显示特技;建议只使用0，50，51这三种特技类型      
//			int alignment_h: 居左0，居中2，居右1
// 说明：	添加富文本区
LEDNETSDK_API int _CALL_STD add_rich_text(unsigned long program, unsigned long rich_text_area, int x, int y, int w, int h, int transparency, int display_effects, int alignment_h);

// 函数：	add_clock
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long clock_area：表盘区分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			_TEXT_CHAR* time_equation：调整时间，格式‘hh:mm:ss’  
//			_TEXT_CHAR* positive_te：调整时间方向（true为加/false为减）
//			_TEXT_CHAR* adjustment：用以调整时差；支持天数，格式“±dd:hh:mm:ss”
//			_TEXT_CHAR* hour_color：时针颜色
//			_TEXT_CHAR* minute_color：分针颜色
//			_TEXT_CHAR* second_color：秒针颜色
//			_TEXT_CHAR* bg_image：背景图片
// 说明：	添加表盘分区
LEDNETSDK_API int _CALL_STD add_clock(unsigned long program, unsigned long clock_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* adjustment, _TEXT_CHAR* hour_color, _TEXT_CHAR* minute_color, _TEXT_CHAR* second_color, _TEXT_CHAR* bg_image);

// 函数：	add_clock_hour
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long clock_area：表盘分区句柄
//			_TEXT_CHAR* src_path：秒针图片 
//			_TEXT_CHAR* h_color：秒针颜色
//			int h_length：时针的长度（暂设置无效）
//			int h_width：时针的宽度
// 说明：	添加表盘分区时针
LEDNETSDK_API int _CALL_STD add_clock_hour(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* h_color, int h_length, int h_width);

// 函数：	add_clock_minute
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long clock_area：表盘分区句柄
//			_TEXT_CHAR* src_path：秒针图片 
//			_TEXT_CHAR* m_color：秒针颜色
//			int m_length：分针的长度（暂设置无效）
//			int m_width：分针的宽度
// 说明：	添加表盘分区分针
LEDNETSDK_API int _CALL_STD add_clock_minute(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* m_color, int m_length, int m_width);

// 函数：	add_clock_second
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long clock_area：表盘分区句柄
//			_TEXT_CHAR* src_path：秒针图片 
//			_TEXT_CHAR* s_color：秒针颜色
//			int s_length：秒针的长度（暂设置无效）
//			int s_width：秒针的宽度
// 说明：	添加表盘分区秒针
LEDNETSDK_API int _CALL_STD add_clock_second(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* s_color, int s_length, int s_width);

// 函数：	add_count
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long calendar_area：计时区分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			_TEXT_CHAR* bg_color：背景色 
//			_TEXT_CHAR* time_equation：调整时间，格式‘hh:mm:ss’  
//			_TEXT_CHAR* positive_te：计时类型（‘end’ - 倒计时，start’ - 正计时）
//			_TEXT_CHAR* target_date：目标日期‘yyyy-MM-dd’
//			_TEXT_CHAR* target_time：目标时间‘hh:mm:ss’
//			_TEXT_CHAR* content：计时区显示内容（如：‘距离目标：dd 天 hh 时 mm 分 ss 秒’）
//			_TEXT_CHAR* font_color：字体颜色
//			_TEXT_CHAR* font_name：字体名
//			int font_size：字体大小
//			int content_x：文字x坐标
//			int content_y：文字y坐标
//			_TEXT_CHAR* font_attributes：文字属性（粗体/斜体/下划线等）
//			_TEXT_CHAR* add_enable：单位换算(计时累加)：‘no’ - 否；‘yes’ - 是
// 说明：	添加计时分区
LEDNETSDK_API int _CALL_STD add_count(unsigned long program, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* target_date, _TEXT_CHAR* target_time, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int content_x, int content_y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* add_enable);

// 函数：	add_calendar
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long calendar_area：农历分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			_TEXT_CHAR* bg_color：背景色 
//			_TEXT_CHAR* time_equation：调整时间，格式‘hh:mm:ss’
//			_TEXT_CHAR* positive_te：调整时间方向（true为加/false为减）
//			_TEXT_CHAR* adjustment：用以调整时差；支持天数，格式“±dd:hh:mm:ss”
// 说明：	添加农历分区
LEDNETSDK_API int _CALL_STD add_time(unsigned long program, unsigned long time_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* adjustment);

// 函数：	add_calendar
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long calendar_area：农历分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			_TEXT_CHAR* bg_color：背景色 
//			_TEXT_CHAR* time_equation：调整时间，格式‘hh:mm:ss’
//			_TEXT_CHAR* positive_te：调整时间方向（true为加/false为减）
//			_TEXT_CHAR* adjustment：用以调整时差；支持天数，格式“±dd:hh:mm:ss”
// 说明：	添加农历分区
LEDNETSDK_API int _CALL_STD add_calendar(unsigned long program, unsigned long calendar_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* adjustment);

// 函数：	add_sensor
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			_TEXT_CHAR* font_name：字体名
//			int font_size：字体大小
//			_TEXT_CHAR* font_attributes：文字属性（粗体/斜体/下划线等）
//			_TEXT_CHAR* font_color：字体颜色
//			_TEXT_CHAR* thresh_fontcolor：超阈值时的字体颜色
//			_TEXT_CHAR* bg_color：背景色
//			_TEXT_CHAR* content_sensor：传感器分区显示内容
//			int content_x：文字显示x坐标
//			int content_y：文字显示y坐标 
//			int unit_type：传感器单位标识
//			int significant_digits：需要显示的小数位数
//			float unit_coefficient：单位转换系数
//			float correction：修正值
//			_TEXT_CHAR* thresh_mode：阈值模式（0小于，1大于）
//			int thresh：阈值
//			_TEXT_CHAR* sensor_addr：传感器地址
//			_TEXT_CHAR* fun_seq：功能序号
//			int update_time：更新间隔
// 说明：	添加传感器分区
LEDNETSDK_API int _CALL_STD add_sensor(unsigned long program, int x, int y, int w, int h, int transparency, 
	_TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_color, _TEXT_CHAR* thresh_fontcolor, _TEXT_CHAR* bg_color, 
	_TEXT_CHAR* content_sensor, int content_x, int content_y, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int update_time);

// 函数：	add_animation
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			int display_effects：动画类型
//			int display_density：密度等级 
//			int display_size：动画纹理尺寸
//			_TEXT_CHAR* direction：动画方向
//			int display_speed：动画速度
//			_TEXT_CHAR* animation_color：动画纹理颜色 
//			int taper：锥度
//			_TEXT_CHAR* file_path：动画纹理路径
//			_TEXT_CHAR* file_type：动画纹理类型
// 说明：	添加炫彩背景分区
LEDNETSDK_API int _CALL_STD add_animation(unsigned long program, int x, int y, int w, int h, int transparency, int display_effects, int display_density, int display_size, _TEXT_CHAR* direction, int display_speed, _TEXT_CHAR* animation_color, int taper, _TEXT_CHAR* file_path, _TEXT_CHAR* file_type);

// 函数：	add_audio
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long audio_area：背景音乐分区句柄
// 说明：	添加背景音乐分区
LEDNETSDK_API int _CALL_STD add_audio(unsigned long program, unsigned long audio_area);

// 函数：	add_nvr
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long program：节目句柄
//			unsigned long nvr_area：分区句柄
//			int x：分区x坐标
//			int y：分区y坐标
//			int w：分区宽度 
//			int h：分区高度
//			int transparency：分区透明度
//			int volume_mode：是否静音（0非静音/1静音）
//			int ratation_mode：逆时针角度
// 说明：	添加nvr分区
LEDNETSDK_API int _CALL_STD add_nvr(unsigned long program, unsigned long nvr_area, int x, int y, int w, int h, int volume_mode, int ratation_mode);


// 函数：	add_video_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long video_area：视频分区句柄
//			int volume：音量
//			int scale_mode：缩放模式
//			int source：外部视频源类型 
//			_TEXT_CHAR* src_path：视频路径
//			_TEXT_CHAR* crop_type：外部视频源显示位置
// 说明：	添加视频分区项
LEDNETSDK_API int _CALL_STD add_video_unit(unsigned long video_area, int volume, int scale_mode, int source, int play_time, _TEXT_CHAR* src_path, _TEXT_CHAR* crop_type);

// 函数：	add_broder_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long broder_area：边框分区句柄
//			int duration：播放时长（单位：秒）
//			int broder_w：边框宽度
//			int texture_w：纹理片段宽度（即边框高度）
//			int stunt_type：显示特技
//			int display_speed：特技速度
//			int flicker_grade：闪烁速度 
//			_TEXT_CHAR* src_path：边框纹理路径
//			_TEXT_CHAR* flicker_path：辅纹理片段图片文件路径（可放空）
// 说明：	添加边框分区项
LEDNETSDK_API int _CALL_STD add_broder_unit(unsigned long broder_area, int duration, int broder_w, int texture_w, int stunt_type, int stunt_speed, int flicker_grade, _TEXT_CHAR* src_path, _TEXT_CHAR* flicker_path);

// 函数：	add_pic_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long pic_area：图片分区句柄
//			int stay_time：特技停留时间 
//			int display_effects：显示特技
//			int display_speed：特技速度
//			_TEXT_CHAR* src_path：图片路径
// 说明：	添加图文分区项
LEDNETSDK_API int _CALL_STD add_pic_unit(unsigned long pic_area, int stay_time, int display_effects, int display_speed, _TEXT_CHAR* src_path);

// 函数：	add_text_unit_img
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long text_area：字幕分区句柄
//			int stay_time：特技停留时间 
//			int display_speed：特技速度
//			int last_move_width：最后一张图片移动的宽度
//			_TEXT_CHAR* src_path：文本图片路径
// 说明：	添加字幕分区项为图片时的分区项
LEDNETSDK_API int _CALL_STD add_text_unit_img(unsigned long text_area, int stay_time, int display_speed, int last_move_width, _TEXT_CHAR* src_path);

// 函数：	add_text_unit_text
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long text_area：字幕分区句柄
//			int stay_time：特技停留时间 
//			int display_speed：特技速度
//			_TEXT_CHAR* font_name：字体名
//			int font_size：字体大小
//			_TEXT_CHAR* font_attributes：文字属性（粗体/斜体/下划线等）
//			_TEXT_CHAR* font_alignment：（协议待定）
//			_TEXT_CHAR* font_color：字体颜色
//			_TEXT_CHAR* bg_color：背景色
//			_TEXT_CHAR* content：文本内容
// 说明：	添加字幕分区项为文本时的分区项
LEDNETSDK_API int _CALL_STD add_text_unit_text(unsigned long text_area, int stay_time, int display_speed, _TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_alignment, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);

// 函数：	add_rich_text_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long rich_text_area：富文本分区句柄
//			int stay_time：特技停留时间，以秒为单位
//			int display_speed：特技速度等级，1~16,1为最快
//			_TEXT_CHAR* bg_image_path：背景图片文件路径，上位机需要将背景图片和节目文件一起下发，该目录为控制卡存储背景图片的目录。
//			_TEXT_CHAR* bg_color：背景色；
//			_TEXT_CHAR* content：文本内容；需要显示的内容和文字属性，如字体类型、颜色、大小、行间距，如：<span foregroud=’white’ font=’12’>上海仰邦</span>
//			格式参考链接：https://developer.gnome.org/pango/stable/pango-Markup.html
// 说明：	添加富文本分区项
LEDNETSDK_API int _CALL_STD add_rich_text_unit(unsigned long rich_text_area, int stay_time, int display_speed, _TEXT_CHAR* bg_image_path, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);

// 函数：	add_colorful_hollowunit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long colorful_subtitle_area：炫彩字分区句柄
//			int display_effects：字芯特技
//			int display_speed：特技速度
//			int stay_time：特技停留时间 
//			_TEXT_CHAR* file：字芯图片路径
// 说明：	添加炫彩字分区字芯项
LEDNETSDK_API int _CALL_STD add_colorful_hollowunit(unsigned long colorful_subtitle_area, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* hollow_file);

// 函数：	add_colorful_fontunit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long colorful_subtitle_area：炫彩字分区句柄
//			_TEXT_CHAR* file：文字图片路径
//			int display_effects：显示特技
//			int display_speed：特技速度
//			int stay_time：特技停留时间 
//			int wave_effects：波动特技
//			int wave_count：波峰个数
//			int wave_speed：波动速度
//			int wave_amplitude：波峰幅度
// 说明：	添加炫彩字分区项
LEDNETSDK_API int _CALL_STD add_colorful_fontunit(unsigned long colorful_subtitle_area, _TEXT_CHAR* file, int display_effects, int display_speed, int stay_time, int wave_effects, int wave_count, int wave_speed, int wave_amplitude);

// 函数：	add_time_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long time_area：时间分区句柄
//			_TEXT_CHAR* content：文字内容
//			_TEXT_CHAR* font_color：字体颜色
//			_TEXT_CHAR* font_name：字体名
//			int font_size：字体大小
//			int x：文字渲染区左下角相对分区左上角的水平偏移
//			int y：文字渲染区左下角相对分区左上角的垂直偏移
//			_TEXT_CHAR* font_attributes：文字属性（粗体/斜体/下划线等）
// 说明：	添加时间分区项
LEDNETSDK_API int _CALL_STD add_time_unit(unsigned long time_area, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes);

// 函数：	add_calendar_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long calendar_area：农历分区句柄
//			_TEXT_CHAR* mode：农历形式（‘heavenlystem’: 为 干支纪年，‘甲子’ - ‘癸亥’‘lunarcalendar’: 为阴历，如‘正月 初六’‘solarterms’ : 为节气或距离下个节气的天数，如‘立夏’、 ‘距小满 10 天’等）
//			_TEXT_CHAR* font_color：字体颜色
//			_TEXT_CHAR* font_name：字体名
//			int font_size：字体大小
//			int x：文字渲染区左下角相对分区左上角的水平偏移
//			int y：文字渲染区左下角相对分区左上角的垂直偏移
//			_TEXT_CHAR* font_attributes：文字属性（粗体/斜体/下划线等）
//			_TEXT_CHAR* text_content：文字内容
// 说明：	添加农历分区项
LEDNETSDK_API int _CALL_STD add_calendar_unit(unsigned long calendar_area, _TEXT_CHAR* mode, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* text_content);

//LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, _TEXT_CHAR* db_type, _TEXT_CHAR* db_ip,  unsigned short db_port,  _TEXT_CHAR* user_name,  _TEXT_CHAR* user_pwd,  _TEXT_CHAR* db_name, int update_time, int stay_time, int display_effects, int display_speed,  _TEXT_CHAR* bg_odd_color,  _TEXT_CHAR* bg_even_color, _TEXT_CHAR* text_odd_color, _TEXT_CHAR* text_even_color,  _TEXT_CHAR* font_name, int font_size, int font_bold, int font_italic, int font_underline, int font_strikeout, int font_noAntialias, _TEXT_CHAR* align_h_type, _TEXT_CHAR* align_v_type, _TEXT_CHAR* auto_lf , _TEXT_CHAR* headtype, _TEXT_CHAR* row_to_column, int linear, int line_w, int paint_table, _TEXT_CHAR* line_color, int row_count, int column_count, int row_h, int column_w, _TEXT_CHAR* cmd_data, _TEXT_CHAR* cmd_fieldname , _TEXT_CHAR* bg_img);

// 函数：	add_db_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long db_area：数据库分区句柄
//			unsigned long dbUnit：数据库项句柄
//			struct DatabaseUnitInfo* dbUnitInfo：数据库项结构体
// 说明：	添加数据库分区项
LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, unsigned long dbUnit, struct DatabaseUnitInfo* dbUnitInfo);

// 函数：	add_db_unit_specifyrow
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dbUnit：数据库项句柄
//			struct SpecifyRow* specifyRow：行结构体
// 说明：	添加数据库特殊行
LEDNETSDK_API int _CALL_STD add_db_unit_specifyrow(unsigned long dbUnit, struct SpecifyRow* specifyRow);

// 函数：	add_db_unit_specifycolumn
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dbUnit：数据库项句柄
//			struct SpecifyColumn* specifyColumn：列结构体
// 说明：	添加数据库特殊列
LEDNETSDK_API int _CALL_STD add_db_unit_specifycolumn(unsigned long dbUnit, struct SpecifyColumn* specifyColumn);

// 函数：	add_db_unit_specifycell
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dbUnit：数据库项句柄
//			struct SpecifyCell* specifyCell：单元格结构体
// 说明：	添加数据库特殊单元格
LEDNETSDK_API int _CALL_STD add_db_unit_specifycell(unsigned long dbUnit, struct SpecifyCell* specifyCell);

// 函数：	add_audio_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long audio_area：背景音乐分区句柄
//			int volume：音量
//			_TEXT_CHAR* src_path：音乐文件路径
// 说明：	添加背景音乐项
LEDNETSDK_API int _CALL_STD add_audio_unit(unsigned long audio_area, int volume, _TEXT_CHAR* src_path);

// 函数：	add_dynamic_unit
// 返回值：	
// 参数：	
//			dynamic_area：动态区区域句柄
//			int dynamic_type:动态单元类型
//			int display_effects:特技类型
//			int display_speed：特技速度
//			int stay_time:特技停留时间
//			file_path:元素路径：文本类的支持txt格式
//			gif_flag:0非GIF；1GIF类型（暂不支持动态播放，作为普通图片播放）
//			bg_color：背景颜色
//			font_size：字体大小
//			font_color:字体颜色
//			font_attributes：包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进行组合
//			font_name：字体
//			align_h:水平对齐方式0居左/1居右/2居中
//			align_v:垂直对齐方式0居上/1居下/2居中
//			以下三个为视频属性，暂不支持视频
//			1. volumn：音量
//			2. scale_mode：缩放模式，窗口比例0/原始比例1
//			3. rolation_mode：旋转角度
//			_TEXT_CHAR* key_list 类型为"URLText"，且获取网络资源为json格式数据时有效。获取数据的字段
//			_TEXT_CHAR* proxyService 动态区"URLText"类型，网络资源为代理服务时，该参数有效，且该参数是代理服务的标识参数（存在且非空）。 
// 说明：	添加动态区项
LEDNETSDK_API int _CALL_STD add_dynamic_unit(unsigned long dynamic_area, int dynamic_type, int display_effects, int display_speed, int stay_time,_TEXT_CHAR* file_path, int gif_flag, _TEXT_CHAR* bg_color, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* font_attributes, _TEXT_CHAR* align_h, _TEXT_CHAR* align_v, int volumn, int scale_mode, int rolation_mode, _TEXT_CHAR* key_list, _TEXT_CHAR* proxyService);

// 函数：	add_nvr_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long nvr_area：分区句柄
//			_TEXT_CHAR* nvrid: nvr设备ID号
//			_TEXT_CHAR* username: "admin" nvr登录用户名
//			_TEXT_CHAR* upwd:"admin" nvr登录密码
//			_TEXT_CHAR* nvraddr: http:\\192.168.0.199"NVR设备网络地址
//			int playTime: 播放时长以秒为单位; 0表示在节目时效内一直播放或由文件时长决定
//			int volume：音量
//			_TEXT_CHAR* valid：有效区域是否打开 on or off
//			int x：视频页的横坐标(如果valid="off"，值放0即可)
//			int y：视频页的纵坐标(如果valid="off"，值放0即可)
//			int w：要显示的视频页的宽度(如果valid="off"，值放0即可)
//			int h：要显示的视频页的高度(如果valid="off"，值放0即可)
// 说明：	添加nvr分区项
LEDNETSDK_API int _CALL_STD add_nvr_unit(unsigned long nvr_area, _TEXT_CHAR* nvrid, _TEXT_CHAR* username, _TEXT_CHAR* upwd, _TEXT_CHAR* nvraddr, int playTime, int volume, _TEXT_CHAR* valid, int x,int y, int w, int h);


// 函数：	add_program_in_playlist
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long playlist：播放列表句柄
//			unsigned long program：节目句柄
//			int play_mode：播放模式（0定长/1定次）
//			int play_time：播放时长（play_mode定长时为时长，定次时为次数）
//			_TEXT_CHAR* aging_start_time：播放时效开始日期‘yyyy-MM-dd’
//			_TEXT_CHAR* aging_end_time：播放时效结束日期
//			_TEXT_CHAR* period_ontime：播放开始时间‘hh:mm:ss’ 
//			_TEXT_CHAR* period_offtime：播放结束时间
//			int play_week：星期有效标识
// 说明：	添加节目到播放列表
LEDNETSDK_API int _CALL_STD add_program_in_playlist(unsigned long playlist, unsigned long program, int play_mode, int play_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, int play_week);

// 函数：	set_playlist_style
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long playlist：创建的播放列表句柄
//			int sync_display：是否为同步播放（1为同步播放）
//			int startH：起始时
//			int startM：起始分
//			int startS：起始秒
//			int endH：结束时
//			int endM：结束分
//			int endS：结束秒
// 说明：	设置是否同步播放（用于灯杆屏需要同步播放场景）
LEDNETSDK_API int _CALL_STD set_playlist_style(unsigned long playlist, int sync_display, int startH, int startM, int startS, int endH, int endM, int endS);
#pragma endregion program

#pragma region bulletin
// 函数：	play_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long bulletin_list：create_bulletin接口创建的公告句柄
// 说明：	播放指定公告
LEDNETSDK_API int _CALL_STD play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long bulletin_list);
LEDNETSDK_API int _CALL_STD play_bulletin_dwhand(unsigned long dwhand,char* ip, unsigned short port, unsigned long bulletin_list);

// 函数：	create_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int x：x坐标
//			int y：y坐标
//			int w：显示宽度
//			int h：显示高度
//			_TEXT_CHAR* name: 公告名
//			int layout:  显示位置
//			int transparency： 透明度
//			int font_size： 字体大小
//			_TEXT_CHAR* font_name: 字体名
//			_TEXT_CHAR* font_color: 字体颜色
//			_TEXT_CHAR* bg_color: 背景色
//			int display_effects: 特技号
//			int display_speed: 特技运行速度
//			int stay_time: 特技停留时间 
//			_TEXT_CHAR* aging_start_time: 开始日期（年月日）
//			_TEXT_CHAR* aging_end_time: 结束日期
//			_TEXT_CHAR* period_ontime: 开始时间（时分秒）
//			_TEXT_CHAR* period_offtime:  结束时间
//			_TEXT_CHAR* content: 公告内容
//			_TEXT_CHAR* font_align: 字体属性（粗体/斜体/下划线等）
// 说明：	创建播放公告
LEDNETSDK_API int _CALL_STD create_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
LEDNETSDK_API int _CALL_STD create_bulletin_dwhand(unsigned long dwhand, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);

// 函数：	delete_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* names：指定删除的公告名称，多个使用分号隔开
// 说明：	删除指定公告
LEDNETSDK_API int _CALL_STD delete_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd,  _TEXT_CHAR* names);
LEDNETSDK_API int _CALL_STD delete_bulletin_dwhand(unsigned long dwhand,  _TEXT_CHAR* names);

// 函数：	stop_play_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	停止播放公告
LEDNETSDK_API int _CALL_STD stop_play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD stop_play_bulletin_dwhand(unsigned long dwhand);

// 函数：	add_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	添加公告并且生存xml文件，并且记录到play_list类中；方便在上传文件的时候使用文件md5及路径
LEDNETSDK_API int _CALL_STD add_bulletin(_TEXT_CHAR* tmp_path, unsigned long playlist, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
#pragma endregion bulletin

// 函数：	change_password
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* pwd：新密码
//			int style：密码算法（2为sha256/其他为sha1）sha256主要为Y3X型号使用，配合华为项目增加的
// 说明：	修改密码
LEDNETSDK_API int _CALL_STD change_password(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pwd, int style = 1);
LEDNETSDK_API int _CALL_STD change_password_dwhand(unsigned long dwhand, _TEXT_CHAR* pwd, int style = 1);

// 函数：	reset_password
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	重置密码
LEDNETSDK_API int _CALL_STD reset_password(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD reset_password_dwhand(unsigned long dwhand, _TEXT_CHAR* user_name);

// 函数：	check_screen_info
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* path：播放节目路径
// 说明：	检查指定控制器信息（主要判断控制器型号和PID是否匹配）
LEDNETSDK_API int _CALL_STD check_screen_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pid, unsigned short device_type);
LEDNETSDK_API int _CALL_STD check_screen_info_dwhand(unsigned long dwhand, _TEXT_CHAR* pid, unsigned short device_type);

// 函数：	play_program
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* path：播放节目路径
// 说明：	播放指定节目
LEDNETSDK_API int _CALL_STD play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, int is_save = 1);
LEDNETSDK_API int _CALL_STD play_program_dwhand(unsigned long dwhand, _TEXT_CHAR* src_path, int is_save = 1);

// 函数：	stop_play_program
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	停止播放节目
LEDNETSDK_API int _CALL_STD stop_play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD stop_play_program_dwhand(unsigned long dwhand);

// 函数：	lock_program
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int flag：锁定1/解锁0
//			_TEXT_CHAR* program_name：需锁定/解锁的节目名称（节目文件中的name属性值）
// 说明：	锁定/解锁节目
LEDNETSDK_API int _CALL_STD lock_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, _TEXT_CHAR* program_name);
LEDNETSDK_API int _CALL_STD lock_program_dwhand(unsigned long dwhand, int flag, _TEXT_CHAR* program_name);

// 函数：	get_screen_parameters
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned char* cards：ControllerInfo结构体
// 说明：	获取屏幕参数
LEDNETSDK_API int _CALL_STD get_screen_parameters(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned char* cards);
LEDNETSDK_API int _CALL_STD get_screen_parameters_dwhand(unsigned long dwhand, unsigned char* cards);

// 函数：	restart_boot
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	系统重启
LEDNETSDK_API int _CALL_STD restart_boot(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD restart_boot_dwhand(unsigned long dwhand);

// 函数：	restart_app
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	app（应用）重启
LEDNETSDK_API int _CALL_STD restart_app(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD restart_app_dwhand(unsigned long dwhand);

// 函数：	check_time
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	校时
LEDNETSDK_API int _CALL_STD check_time(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD check_time_dwhand(unsigned long dwhand);

// 函数：	check_time_str
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* time_str:时间（格式："yyyy-MM-dd hh:mm:ss"）
//			int is_utc:是否以UTC时间校正控制器时间(1是UTC时间/0本地时间)
// 说明：	校时
LEDNETSDK_API int _CALL_STD check_time_str(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* time_str, int is_utc);

// 函数：	lock_screen
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int lock：锁屏1/解锁0
// 说明：	锁屏/解锁
LEDNETSDK_API int _CALL_STD lock_screen(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int lock);
LEDNETSDK_API int _CALL_STD lock_screen_dwhand(unsigned long dwhand, int lock);

// 函数：	set_screen_brightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int brightness：亮度值
// 说明：	设置即时亮度
LEDNETSDK_API int _CALL_STD set_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int brightness);
LEDNETSDK_API int _CALL_STD set_screen_brightness_dwhand(unsigned long dwhand, int brightness);

// 函数：	set_screen_auto_brightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned short* brightness：亮度值集合
//			int data_count：亮度值个数
//			unsigned short* sensor_brightness：传感器亮度值集合
//			int sensor_data_count：传感器亮度值个数
//			_TEXT_CHAR* sensor_addr：传感器地址
// 说明：	设置自动调亮
LEDNETSDK_API int _CALL_STD set_screen_auto_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);
LEDNETSDK_API int _CALL_STD set_screen_auto_brightness_dwhand(unsigned long dwhand, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);

// 函数：	set_screen_cus_brightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned short* brightness：亮度值集合
//			int data_count：亮度值个数
// 说明：	设置定时调亮
LEDNETSDK_API int _CALL_STD set_screen_cus_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count);
LEDNETSDK_API int _CALL_STD set_screen_cus_brightness_dwhand(unsigned long dwhand, unsigned short* brightness, int data_count);

// 函数：	set_screen_volumn
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int volumn：音量
// 说明：	设置音量
LEDNETSDK_API int _CALL_STD set_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int volumn);
LEDNETSDK_API int _CALL_STD set_screen_volumn_dwhand(unsigned long dwhand, int volumn);

// 函数：	set_screen_turnonoff
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int turnonoff_status：开机1/关机0
// 说明：	开关机
LEDNETSDK_API int _CALL_STD set_screen_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int turnonoff_status);
LEDNETSDK_API int _CALL_STD set_screen_turnonoff_dwhand(unsigned long dwhand, int turnonoff_status);

// 函数：	screen_cus_turnonoff
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			struct CustomerTurnOnOffScreenData* turnonoff：定时开关机结构体
//			int data_count：定时开关机结构体个数，如果传入为0时，表示取消定时开关机；否则表示设置定时开关机
// 说明：	定时开关机
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long turnonoff);
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff_dwhand(unsigned long dwhand, unsigned long turnonoff);

// 函数：	cancel_screen_cus_turnonoff
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	取消定时开关机
LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff_dwhand(unsigned long dwhand);

#pragma region customer turn onoff
LEDNETSDK_API unsigned long _CALL_STD create_turnonoff();

LEDNETSDK_API void _CALL_STD add_turnonoff(unsigned long turnonoff, int action, _TEXT_CHAR* time);

LEDNETSDK_API void _CALL_STD delete_turnonoff(unsigned long turnonoff);
#pragma endregion customer turn onoff

// 函数：	set_apn
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* ppp_apn：
//			_TEXT_CHAR* ppp_number：
//			_TEXT_CHAR* ppp_username：
//			_TEXT_CHAR* ppp_password：
// 说明：	设置APN
LEDNETSDK_API int _CALL_STD set_apn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);
LEDNETSDK_API int _CALL_STD set_apn_dwhand(unsigned long dwhand, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);

// 函数：	set_screen_logo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int flag：打开/关闭logo
//			_TEXT_CHAR* logo_layout：显示位置
//			int screen_w：显示宽度
//			int screen_h：显示高度
//			_TEXT_CHAR* src_path：logo文件路径
// 说明：	设置logo
LEDNETSDK_API int _CALL_STD set_screen_logo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, _TEXT_CHAR* logo_layout, int screen_w, int screen_h, _TEXT_CHAR* src_path);
LEDNETSDK_API int _CALL_STD set_screen_logo_dwhand(unsigned long dwhand,char* ip, unsigned short port, int flag, _TEXT_CHAR* logo_layout, int screen_w, int screen_h, _TEXT_CHAR* src_path);

// 函数：	set_screen_size
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int screen_w：显示宽度
//			int screen_h：显示高度
//			int screenrotation：旋转角度
// 说明：	设置屏幕参数（宽/高/旋转角度）
LEDNETSDK_API int _CALL_STD set_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int screenrotation);
LEDNETSDK_API int _CALL_STD set_screen_size_dwhand(unsigned long dwhand, int screen_w, int screen_h, int screenrotation);

// 函数：	set_fold_screen_size
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int screen_w：显示宽度
//			int screen_h：显示高度
//			int fold_type：折数
//			int fold_count, int* fold_h, int h_len, int* fold_w, int w_len
// 说明：	设置折屏
LEDNETSDK_API int _CALL_STD set_fold_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);
LEDNETSDK_API int _CALL_STD set_fold_screen_size_dwhand(unsigned long dwhand, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);

// 函数：	set_screen_barcode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 _TEXT_CHAR* barcode：要设置的条形码
// 说明：	设置条形码
LEDNETSDK_API int _CALL_STD set_screen_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD set_screen_barcode_dwhand(unsigned long dwhand, _TEXT_CHAR* barcode);

// 函数：	set_screen_ip_flag
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 int flag：是否显示IP提示信息
// 说明：	设置是否显示IP提示信息
LEDNETSDK_API int _CALL_STD set_screen_ip_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);
LEDNETSDK_API int _CALL_STD set_screen_ip_flag_dwhand(unsigned long dwhand, int flag);

// 函数：	set_screen_led_flag
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 int flag：是否显示LED标志
// 说明：	设置是否显示LED标志
LEDNETSDK_API int _CALL_STD set_screen_led_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);
LEDNETSDK_API int _CALL_STD set_screen_led_flag_dwhand(unsigned long dwhand, int flag);

// 函数：	set_screen_output_type
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 int output_type：输出模式（0 LCD，1 DVI）
// 说明：	设置输出方式
LEDNETSDK_API int _CALL_STD set_screen_output_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int output_type);
LEDNETSDK_API int _CALL_STD set_screen_output_type_dwhand(unsigned long dwhand, int output_type);

// 函数：	set_screen_player_type
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 int player_type：播放模式（"normal/0":异步模式，"sync/1":同步模式）
// 说明：	切换播放模式
LEDNETSDK_API int _CALL_STD set_screen_player_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int player_type);
LEDNETSDK_API int _CALL_STD set_screen_player_type_dwhand(unsigned long dwhand, int player_type);

// 函数：	set_screen_name
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* controller_name：控制器名称
// 说明：	设置控制器名称
LEDNETSDK_API int _CALL_STD set_screen_name(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_name);
LEDNETSDK_API int _CALL_STD set_screen_name_dwhand(unsigned long dwhand, _TEXT_CHAR* controller_name);

// 函数：	set_screen_timezone
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int timezoneflag: 是否打开自动授时
//			_TEXT_CHAR* timezone：时区（标准时区格式）
//			_TEXT_CHAR* timezone_server：时区服务器地址
//			int timezone_interval：时区授时间隔时间
// 说明：	设置自动授时
LEDNETSDK_API int _CALL_STD set_screen_timezone(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);
LEDNETSDK_API int _CALL_STD set_screen_timezone_dwhand(unsigned long dwhand, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);

// 函数：	set_screen_language
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* controller_language：控制器显示语言
// 说明：	设置控制器显示语言
LEDNETSDK_API int _CALL_STD set_screen_language(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_language);
LEDNETSDK_API int _CALL_STD set_screen_language_dwhand(unsigned long dwhand, _TEXT_CHAR* controller_language);

// 函数：	set_serial
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* serial_mode：串口模式（off 关闭，s1，s2）
//			_TEXT_CHAR* baudrate：波特率
//			int timeout：通讯超时时间（单位：毫秒）
//			_TEXT_CHAR* device_num：从设备号
// 说明：	设置串口
LEDNETSDK_API int _CALL_STD set_serial(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* serial_mode, _TEXT_CHAR* baudrate, int timeout, _TEXT_CHAR* device_num);
LEDNETSDK_API int _CALL_STD set_serial_dwhand(unsigned long dwhand, _TEXT_CHAR* serial_mode, _TEXT_CHAR* baudrate, int timeout, _TEXT_CHAR* device_num);

// 函数：	get_screen_disk_list
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* storage_media：返回的存储介质列表(多个使用逗号","隔开)
// 说明：	查询存储介质列表
LEDNETSDK_API int _CALL_STD get_screen_disk_list(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD get_screen_disk_list_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

// 函数：	get_screen_cur_disk
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* storage_media：返回的当前存储介质
// 说明：	查询当前存储介质
LEDNETSDK_API int _CALL_STD get_screen_cur_disk(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD get_screen_cur_disk_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

// 函数：	get_screen_disk_info
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* storage_media：要查询的存储介质
//			long long *totalsize：总容量
//			long long *freesize：剩余容量
//			long long *usedsize：已使用容量
// 说明：	查询指定存储介质的容量信息
LEDNETSDK_API int _CALL_STD get_screen_disk_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);
LEDNETSDK_API int _CALL_STD get_screen_disk_info_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);

// 函数：	set_screen_storage_media
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* storage_media：要设置的存储介质
// 说明：	设置存储介质
LEDNETSDK_API int _CALL_STD set_screen_storage_media(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD set_screen_storage_media_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

// 函数：	get_screen_status
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int* screen_onoff：开关机状态
//			int* brigtness：亮度
//			int* brigtness_mode：亮度模式
//			int* volume：音量
//			int* screen_lockunlock：屏幕锁定状态
//			int* program_lockunlock：节目锁定状态
//			int* screen_output_type：输出模式
//			int* screen_player_mode：播放模式
//			_TEXT_CHAR* screen_time：控制器时间
//			_TEXT_CHAR* screen_addr：控制器名称
//			_TEXT_CHAR* screen_customer_onoff：定时开关机
//			_TEXT_CHAR* screen_language：控制器语言
//			_TEXT_CHAR* screen_gps：gps信息
// 说明：	查询控制器状态
LEDNETSDK_API int _CALL_STD get_screen_status(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, int* screen_output_type, int* screen_player_mode, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff, _TEXT_CHAR* screen_language, _TEXT_CHAR* screen_gps);
LEDNETSDK_API int _CALL_STD get_screen_status_dwhand(unsigned long dwhand, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, int* screen_output_type, int* screen_player_mode, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff, _TEXT_CHAR* screen_language, _TEXT_CHAR* screen_gps);

// 函数：	get_ap_wifi_status
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int* apwifi_onoff：AP WiFi状态(属性 apmute)
// 说明：	查询AP WiFi 状态
LEDNETSDK_API int _CALL_STD get_ap_wifi_status(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* apwifi_onoff);
LEDNETSDK_API int _CALL_STD get_ap_wifi_status_dwhand(unsigned long dwhand, int* apwifi_onoff);

// 函数：	get_screen_send_program_info
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int* screen_w：屏幕宽度
//			int* screen_h：屏幕高度
//			int* fold_type：折屏标志
//			unsigned short* screen_type：折屏信息
// 说明：	查询控制器折屏信息
LEDNETSDK_API int _CALL_STD get_screen_send_program_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);
LEDNETSDK_API int _CALL_STD get_screen_send_program_info_dwhand(unsigned long dwhand, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);

// 函数：	get_firmware_version
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* firmware_version：控制器版本号
//			_TEXT_CHAR* app_version：控制器版本号
//			_TEXT_CHAR* fpga_version：FPGA版本号
// 说明：	查询控制器版本
LEDNETSDK_API int _CALL_STD get_firmware_version(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);
LEDNETSDK_API int _CALL_STD get_firmware_version_dwhand(unsigned long dwhand, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);

// 函数：	update_firmware
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* src_path：升级包路径
//			struct TLSInfo* tls_infos：是否有素材认证的结构体，在没有素材认证的时候，结构体可以给空
// 说明：	查询控制器版本
LEDNETSDK_API int _CALL_STD update_firmware(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, struct TLSInfo* tls_infos);
LEDNETSDK_API int _CALL_STD update_firmware_dwhand(unsigned long dwhand,char* ip, unsigned short port, _TEXT_CHAR* src_path, struct TLSInfo* tls_infos);

LEDNETSDK_API unsigned int _CALL_STD net_getcode(char* ip, unsigned short port);

LEDNETSDK_API unsigned long _CALL_STD net_login(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int login_style = 0);
LEDNETSDK_API int _CALL_STD net_logout(unsigned long post);

// 函数：	set_xser_cmd
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long post：登录后的句柄
//			int cmd：命令号
//			_TEXT_CHAR* content：命令数据
//			int len：数据长度
//			_TEXT_CHAR* recv_data：接收的回包数据
//			int* recv_cmd：回复命令
//			int* recv_status：回复状态
//			int* recv_len：接收数据长度
// 说明：	透传命令，设置xser信息
LEDNETSDK_API int _CALL_STD set_xser_cmd(unsigned long post,int cmd,_TEXT_CHAR* content, int len, _TEXT_CHAR* recv_data, int* recv_cmd, int* recv_status, int* recv_len);

// 函数：	get_barcode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* barcode：查询到的条形码
// 说明：	查询条形码
LEDNETSDK_API int _CALL_STD get_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD get_barcode_dwhand(unsigned long dwhand, _TEXT_CHAR* barcode);

// 函数：	get_screen_mac
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* mac：查询到的MAC
// 说明：	查询MAC
LEDNETSDK_API int _CALL_STD get_screen_mac(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* mac);
LEDNETSDK_API int _CALL_STD get_screen_mac_dwhand(unsigned long dwhand, _TEXT_CHAR* mac);

// 函数：	get_screen_capture
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* file_path：截屏后保存文件路径
//			int captureW：截屏宽度
//			int captureH：截屏高度
// 说明：	屏幕监控
LEDNETSDK_API int _CALL_STD get_screen_capture(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* file_path, int captureW, int captureH);
LEDNETSDK_API int _CALL_STD get_screen_capture_dwhand(unsigned long dwhand, _TEXT_CHAR* file_path, int captureW, int captureH);
LEDNETSDK_API int _CALL_STD get_screen_capture_dwhand1(unsigned long dwhand, _TEXT_CHAR* file_path, int captureW, int captureH, int* min_waitTime, int* max_waitTime, _TEXT_CHAR* download_path);

// 函数：	copy_file
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* file_path：截屏后保存文件路径
//			int captureW：截屏宽度
//			int captureH：截屏高度
// 说明：	复制文件（从控制器指定路径复制到控制器指定路径）
LEDNETSDK_API int _CALL_STD copy_file_dwhand1(unsigned long dwhand, _TEXT_CHAR* file_path, _TEXT_CHAR* download_path);

// 函数：	get_screen_log
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* file_path：RPCLog文件路径
//			_TEXT_CHAR* file_path1：RPCLog.1文件路径
// 说明：	查询控制器日志
LEDNETSDK_API int _CALL_STD get_screen_log(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* file_path, _TEXT_CHAR* file_path1);
LEDNETSDK_API int _CALL_STD get_screen_log_dwhand(unsigned long dwhand, _TEXT_CHAR* file_path, _TEXT_CHAR* file_path1);

// 函数：	get_screen_folder_files
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* folder_path：文件夹路径(eg: /share)
//			_TEXT_CHAR* files：返回的文件内容（base64）
// 说明：	查询控制器指定目录下的所有文件列表
LEDNETSDK_API int _CALL_STD get_screen_folder_files(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* folder_path, _TEXT_CHAR* files);
LEDNETSDK_API int _CALL_STD get_screen_folder_files_dwhand(unsigned long dwhand, _TEXT_CHAR* folder_path, _TEXT_CHAR* files);
LEDNETSDK_API int _CALL_STD get_screen_folder_files_dwhand1(unsigned long dwhand, _TEXT_CHAR* file_path);

// 函数：	get_screen_output_type
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int* screen_output_type：查询到的控制器输出模式
// 说明：	查询控制器输出模式
LEDNETSDK_API int _CALL_STD get_screen_output_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_output_type);
LEDNETSDK_API int _CALL_STD get_screen_output_type_dwhand(unsigned long dwhand, int* screen_output_type);

// 函数：	get_screen_player_mode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int* screen_player_mode：查询到的控制器播放模式
// 说明：	查询控制器播放模式
LEDNETSDK_API int _CALL_STD get_screen_player_mode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_player_mode);
LEDNETSDK_API int _CALL_STD get_screen_player_mode_dwhand(unsigned long dwhand, int* screen_player_mode);

// 函数：	download_file
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* src_path：需要下载的文件路径
//			_TEXT_CHAR* dest_path：保存的文件路径
// 说明：	下载指定文件到指定位置
LEDNETSDK_API int _CALL_STD download_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);
LEDNETSDK_API int _CALL_STD download_file_dwhand(unsigned long dwhand, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);

// 函数：	upload_file
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* src_path：需要上传的文件路径
//			_TEXT_CHAR* dest_file_name：上传后的文件名，不包括后缀
//			struct TLSInfo* tls_infos：素材认证时结构体句柄
// 说明：	上传指定文件到指定位置
LEDNETSDK_API int _CALL_STD upload_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_file_name, struct TLSInfo* tls_infos);
LEDNETSDK_API int _CALL_STD upload_file_dwhand(unsigned long dwhand,char* ip, unsigned short port, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_file_name, struct TLSInfo* tls_infos);

// 函数：	delete_file
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* delete_files：需要删除的文件，使用“;”隔开
// 说明：	删除指定位置的指定文件
LEDNETSDK_API int _CALL_STD delete_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* delete_files);
LEDNETSDK_API int _CALL_STD delete_file_dwhand(unsigned long dwhand, _TEXT_CHAR* delete_files);

// 函数：	get_screen_player_file
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* program_list：播放列表文件
//			_TEXT_CHAR* program_name：当前播放的节目文件名
// 说明：	获取播放列表文件
LEDNETSDK_API int _CALL_STD get_screen_player_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* program_list, _TEXT_CHAR* program_name);
LEDNETSDK_API int _CALL_STD get_screen_player_file_dwhand(unsigned long dwhand, _TEXT_CHAR* program_list, _TEXT_CHAR* program_name);

// 函数：	set_screen_prompt_flag
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* prompt_flag：“on”：打开提示信息（默认） “off”：关闭提示信息（设置后需要断电重启）
// 说明：	设置屏幕提示信息标志
LEDNETSDK_API int _CALL_STD set_screen_prompt_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* prompt_flag);
LEDNETSDK_API int _CALL_STD set_screen_prompt_flag_dwhand(unsigned long dwhand, _TEXT_CHAR* prompt_flag);
#pragma region UDP WIFI
LEDNETSDK_API int _CALL_STD  get_ssid_list(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* values);

LEDNETSDK_API int _CALL_STD  set_ap_property(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_name, _TEXT_CHAR* wifi_pwd, char* wifi_ip);

LEDNETSDK_API int _CALL_STD  connect_wifi(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_name, _TEXT_CHAR* wifi_pwd, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD  disconnect_wifi(_TEXT_CHAR* barcode, _TEXT_CHAR* pid);

LEDNETSDK_API int _CALL_STD  query_wifi_status(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_status);
#pragma endregion UDP WIFI

#pragma region Font
// 函数：	query_font
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* fontfile：字库文件路径
//			_TEXT_CHAR* fontname：字库文件名
// 说明：	查询字库
LEDNETSDK_API int _CALL_STD query_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);
LEDNETSDK_API int _CALL_STD query_font_dwhand(unsigned long dwhand, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);

// 函数：	install_font
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long font：字库文件路径和文件名
// 说明：	安装字库
LEDNETSDK_API int _CALL_STD install_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font, unsigned long tls_font, int* min_waitTime, int* max_waitTime);
LEDNETSDK_API int _CALL_STD install_font_dwhand(unsigned long dwhand, unsigned long font, unsigned long tls_font, int* min_waitTime, int* max_waitTime);

// 函数：	delete_font
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* fontname：字库文件名
// 说明：	卸载字库
LEDNETSDK_API int _CALL_STD delete_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font);
LEDNETSDK_API int _CALL_STD delete_font_dwhand(unsigned long dwhand, unsigned long font);

#pragma region customer font
LEDNETSDK_API unsigned long _CALL_STD create_font();
LEDNETSDK_API unsigned long _CALL_STD create_font_tls();

LEDNETSDK_API void _CALL_STD add_font(unsigned long font, unsigned long tls_font, _TEXT_CHAR* system_font, _TEXT_CHAR* custom_font, struct TLSInfo* tls_infos);

LEDNETSDK_API void _CALL_STD delete_add_font(unsigned long font, _TEXT_CHAR* font_name);

LEDNETSDK_API void _CALL_STD delete_create_font(unsigned long font);
#pragma endregion customer font
#pragma endregion Font

#pragma region sensor manage
LEDNETSDK_API unsigned long _CALL_STD create_manage_sensor();

LEDNETSDK_API void _CALL_STD add_manage_sensor(unsigned long sensor, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int relay_type, int relay_switch);

LEDNETSDK_API void _CALL_STD delete_add_sensor(unsigned long sensor, int sensor_index);

LEDNETSDK_API void _CALL_STD delete_create_sensor(unsigned long sensor);

// 函数：	get_sensor_bus
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 _TEXT_CHAR* sensor_bus：返回搜索到的传感器总线列表
// 说明：	获取总线列表
LEDNETSDK_API int _CALL_STD get_sensor_bus(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus);
LEDNETSDK_API int _CALL_STD get_sensor_bus_dwhand(unsigned long dwhand, _TEXT_CHAR* sensor_bus);

// 函数：	query_seeksensor
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			 _TEXT_CHAR* sensor_bus：需要搜索的传感器总线列表（可为*）
//			int* min_waitTime：搜索最小等待时间
//			int* max_waitTime：搜索最大等待时间
// 说明：	搜索传感器
LEDNETSDK_API int _CALL_STD query_seeksensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);
LEDNETSDK_API int _CALL_STD query_seeksensor_dwhand(unsigned long dwhand, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);

// 函数：	get_sensor
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned char* sensors：传感器列表
//			int* sensors_count：传感器个数
// 说明：	获取传感器列表
LEDNETSDK_API int _CALL_STD get_sensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned char* sensors, int* sensors_count);
LEDNETSDK_API int _CALL_STD get_sensor_dwhand(unsigned long dwhand, unsigned char* sensors, int* sensors_count);

// 函数：	set_relay_switch
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			int setOrCancel：绑定还是取消
//			int update_time：传感器检测周期
//			unsigned long sensors：继电器传感器句柄
// 说明：	设置继电器开关机（绑定继电器/取消绑定继电器）
LEDNETSDK_API int _CALL_STD set_relay_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int setOrCancel, int update_time, unsigned long sensors);
LEDNETSDK_API int _CALL_STD set_relay_switch_dwhand(unsigned long dwhand, int setOrCancel, int update_time, unsigned long sensors);

// 函数：	set_screenonoff_switch
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* relay_addr：继电器地址
//			int relay_type：继电器类型
//			int relay_switch：继电器开关
// 说明：	设置继电器开关机（开关屏绑定继电器）
LEDNETSDK_API int _CALL_STD set_screenonoff_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
LEDNETSDK_API int _CALL_STD set_screenonoff_switch_dwhand(unsigned long dwhand, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
#pragma endregion sensor

#pragma region dynamic
// 函数：	update_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
//			_TEXT_CHAR* immediately_play：可以指定一个关联了普通节目的动态区ID（必须是dynamics参数中存在的id），让该动态区尝试立即播放
//			int conver：是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目
//			int onlyUpdate：是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"
// 说明：	更新动态区
LEDNETSDK_API int _CALL_STD update_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);
LEDNETSDK_API int _CALL_STD update_dynamic_dwhand(unsigned long dwhand, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);

// 函数：	update_dynamic_small
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
//			_TEXT_CHAR* immediately_play：可以指定一个关联了普通节目的动态区ID（必须是dynamics参数中存在的id），让该动态区尝试立即播放
//			int conver：是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目
//			int onlyUpdate：是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"
// 说明：	更新动态区内容少的
LEDNETSDK_API int _CALL_STD update_dynamic_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);
LEDNETSDK_API int _CALL_STD update_dynamic_small_dwhand(unsigned long dwhand, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);

// 函数：	update_dynamic_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
// 说明：	更新动态区素材
LEDNETSDK_API int _CALL_STD update_dynamic_unit(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
LEDNETSDK_API int _CALL_STD update_dynamic_unit_dwhand(unsigned long dwhand, unsigned long playlist);

// 函数：	update_dynamic_unit_small
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
// 说明：	更新动态区素材，素材较小的时候使用
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small_dwhand(unsigned long dwhand, unsigned long playlist);

// 函数：	save_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
// 说明：	保存动态区，掉电保存，需要传入的是需要保存的动态区ID号；自动记录在playlist cpp中
LEDNETSDK_API int _CALL_STD save_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
// 函数：	save_dynamic_forid
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR*：动态区ID号，多个用“；”隔开
// 说明：	保存动态区，掉电保存，需要传入的是需要保存的动态区ID号
LEDNETSDK_API int _CALL_STD save_dynamic_forid(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* ids);
LEDNETSDK_API int _CALL_STD save_dynamic_dwhand(unsigned long dwhand, unsigned long playlist);

// 函数：	clear_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	清空所有动态区
LEDNETSDK_API int _CALL_STD clear_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_dynamic_dwhand(unsigned long dwhand);

// 函数：	delete_input_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	删除指定动态区动态区
LEDNETSDK_API int _CALL_STD delete_input_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* id_list);
LEDNETSDK_API int _CALL_STD delete_input_dynamic_dwhand(unsigned long dwhand, _TEXT_CHAR* id_list);

LEDNETSDK_API int _CALL_STD delete_save_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD delete_save_dynamic_dwhand(unsigned long dwhand);
#pragma endregion dynamic

#pragma region TTS
// 函数：	active_tts
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	激活语音
LEDNETSDK_API int _CALL_STD active_tts(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD active_tts_dwhand(unsigned long dwhand);

// 函数：	add_tts_voice
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* voice_text：语音内容
//			int loop：循环次数
//			int gender：男生/女生
//			int effect：播音特效
//			int volume：音量
//			int tone：语调
//			int speed：播音速度
//			int one：数字读法
//			int stay_time：播放后静默时间
// 说明：	添加语音
LEDNETSDK_API int _CALL_STD add_tts_voice(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* voice_text, int loop, int gender, int effect, int volume, int tone, int speed, int one, int stay_time);
LEDNETSDK_API int _CALL_STD add_tts_voice_dwhand(unsigned long dwhand, _TEXT_CHAR* voice_text, int loop, int gender, int effect, int volume, int tone, int speed, int one, int stay_time);
#pragma endregion TTS

#pragma region JTC
// 函数：	set_jtc_mode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			int jtc_mode：JT网络模式（server1/client0）
//			_TEXT_CHAR* jtc_protocol：JT协议类型
//			_TEXT_CHAR* jtc_device_addr：JT地址
//			_TEXT_CHAR* jtc_server_addr: 服务器地址
//			unsigned short jtc_server_port：服务器端口
//			_TEXT_CHAR* porter_rate：波特率
//			int package_size：数据包长度
//			jtcproperty
// 说明：	设置JT型号的属性
LEDNETSDK_API int _CALL_STD set_jtc_mode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int jtc_mode, _TEXT_CHAR* jtc_protocol, _TEXT_CHAR* jtc_device_addr, _TEXT_CHAR* jtc_server_addr, unsigned short jtc_server_port, _TEXT_CHAR* porter_rate, int package_size);
LEDNETSDK_API int _CALL_STD set_jtc_mode_dwhand(unsigned long dwhand, int jtc_mode, _TEXT_CHAR* jtc_protocol, _TEXT_CHAR* jtc_device_addr, _TEXT_CHAR* jtc_server_addr, unsigned short jtc_server_port, _TEXT_CHAR* porter_rate, int package_size);
#pragma endregion

#pragma region IO
// 函数：	set_gp_mode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			int gp_mode：0/off - 关闭；1/discrete - 单一控制；2/combined - 组合控制(自然码)；3/gray - 组合控制(格雷码)
// 说明：	IO模式切换
LEDNETSDK_API int _CALL_STD set_gp_mode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int gp_mode);
LEDNETSDK_API int _CALL_STD set_gp_mode_dwhand(unsigned long dwhand, int gp_mode);
#pragma endregion

#pragma region TLS
// 函数：	set_tls
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			_TEXT_CHAR* src_file：证书文件路径
//			struct TLSInfo* tls_infos：证书签名的结构体（包含签名内容/证书指纹，使用哪个证书做文件认证签名的相关信息）
//			_TEXT_CHAR* fingerprint：待安装证书的指纹
//			_TEXT_CHAR* tls_certificate：对ADDCERTIFICATE的签名内容，（待安装的证书的签名）
//			_TEXT_CHAR* add_certificate_type：安装的证书类型（0通讯加密证书/1素材签名认证证书）
// 说明：	安装证书
LEDNETSDK_API int _CALL_STD set_tls(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_file, struct TLSInfo* tls_infos, _TEXT_CHAR* fingerprint, _TEXT_CHAR* tls_certificate, _TEXT_CHAR* add_certificate_type);
LEDNETSDK_API int _CALL_STD set_tls_dwhand(unsigned long dwhand, char* ip, unsigned short port, _TEXT_CHAR* src_file, struct TLSInfo* tls_infos, _TEXT_CHAR* fingerprint, _TEXT_CHAR* tls_certificate, _TEXT_CHAR* add_certificate_type);

// 函数：	get_tls_param_dwhand
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long dwhand：登录成功后返回的通讯句柄
//			_TEXT_CHAR* param：文件认证开关（authenticationswitch）
// 说明：	获取当前控制器是否处于素材签名认证状态
LEDNETSDK_API int _CALL_STD get_tls_param_dwhand(unsigned long dwhand, _TEXT_CHAR* param);

// 函数：	delete_tls
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			_TEXT_CHAR* tls_content：签名内容（对DELETECERTIFICATE的签名）
//			_TEXT_CHAR* fingerprint：证书指纹
//			_TEXT_CHAR* add_certificate_type：安装的证书类型（0通讯加密证书/1素材签名认证证书）
// 说明：	删除安装的证书
LEDNETSDK_API int _CALL_STD delete_tls(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint, _TEXT_CHAR* add_certificate_type);
LEDNETSDK_API int _CALL_STD delete_tls_dwhand(unsigned long dwhand, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint, _TEXT_CHAR* add_certificate_type);

// 函数：	verify_switch
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			int flag：打开/关闭签名认证
//			_TEXT_CHAR* tls_content：签名后的内容
//			_TEXT_CHAR* fingerprint：证书指纹
// 说明：	打开素材签名认证
LEDNETSDK_API int _CALL_STD verify_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd ,int flag, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint);
LEDNETSDK_API int _CALL_STD verify_switch_dwhand(unsigned long dwhand, int flag, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint);
#pragma endregion

#pragma region audio
// 函数：	create_manage_audio
// 返回值：	返回创建的音频句柄
// 参数：	
// 说明：	创建音频管理句柄
LEDNETSDK_API unsigned long _CALL_STD create_manage_audio();

// 函数：	add_manage_audio
// 返回值：	
// 参数：	unsigned long audio：创建的音频管理的句柄
//			_TEXT_CHAR* audio_name：音频名字
//			_TEXT_CHAR* audio_path：音频文件路径
// 说明：	添加音频文件
LEDNETSDK_API void _CALL_STD add_manage_audio(unsigned long audio, _TEXT_CHAR* audio_name, _TEXT_CHAR* audio_path);

// 函数：	delete_add_audio
// 返回值：	
// 参数：	unsigned long audio：创建的音频管理的句柄
//			_TEXT_CHAR* audio_name：音频名字
// 说明：	删除音频文件
LEDNETSDK_API void _CALL_STD delete_add_audio(unsigned long audio, _TEXT_CHAR* audio_name);

// 函数：	delete_create_audio
// 返回值：	
// 参数：	unsigned long audio：创建的音频管理的句柄
// 说明：	删除创建的音频句柄（和create_manage_audio对应一起使用）
LEDNETSDK_API void _CALL_STD delete_create_audio(unsigned long audio);

// 函数：	upload_audio_file
// 返回值：	成功返回0；失败返回对应的错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录的用户名
//			_TEXT_CHAR* user_pwd：登录的用户密码
//			unsigned long audio：创建的音频管理的句柄
// 说明：	上传音频文件
LEDNETSDK_API int _CALL_STD upload_audio_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long audio);

// 函数：	play_audio
// 返回值：	成功返回0；失败返回对应的错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录的用户名
//			_TEXT_CHAR* user_pwd：登录的用户密码
//			unsigned long audio：创建的音频管理的句柄
//			int loop_mode：音频列表循环模式（播放次数。播放顺序依照添加的音频列表。为"0"时循环播放。大于"0"时代表实际播放次数）
// 说明：	播放音频
LEDNETSDK_API int _CALL_STD play_audio(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long audio, int loop_mode);

//// 函数：	stop_play_audio
// 返回值：	成功返回0；失败返回对应的错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登录的用户名
//			_TEXT_CHAR* user_pwd：登录的用户密码
// 说明：	停止播放音频
LEDNETSDK_API int _CALL_STD stop_play_audio(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
#pragma endregion audio

#pragma region serial
//// 函数：	serial_screenonoff
// 返回值：	成功返回0；失败返回对应的错误号
// 参数：	
//			int screen_onoff：1开机 0关机
//			_TEXT_CHAR* json_data：返回的通讯数据
// 说明：	使用串口设置开关机
LEDNETSDK_API int _CALL_STD serial_screenonoff(int screen_onoff, _TEXT_CHAR* json_data);
#pragma endregion serial

#pragma region cmd proxy
// 函数：	set_proxy
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器IP
//			unsigned short port：控制器端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			_TEXT_CHAR* proxy_text：各代理模式相关参数均以字符串形式，按"，"分隔，顺序写入"proxyproperty"
// 说明：	设置液位报警（此命令以后会有很多模式设置，所以叫setproxy）
LEDNETSDK_API int _CALL_STD set_proxy(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd , _TEXT_CHAR* proxy_text);
LEDNETSDK_API int _CALL_STD set_proxy_dwhand(unsigned long dwhand, _TEXT_CHAR* proxy_text);
#pragma endregion proxy

#pragma region proxy
// 函数：	Get_Port_Barcode
// 返回值：	成功返回通讯端口；失败返回-1
// 参数：	
//			_TEXT_CHAR* pid：查询的控制器条形码
// 说明：	根据指定的条形码获取通讯端口
LEDNETSDK_API int _CALL_STD Get_Port_Barcode(_TEXT_CHAR* pid);

// 函数：	Get_Port_Pid
// 返回值：	成功返回通讯端口；失败返回-1
// 参数：	
//			_TEXT_CHAR* pid：查询的控制器PID
// 说明：	根据指定的PID获取通讯端口
LEDNETSDK_API int _CALL_STD Get_Port_Pid(_TEXT_CHAR* pid);

// 函数：	Start_Native_Server
// 返回值：	成功返回监听后的句柄；失败返回-1
// 参数：	
//			int port：启动监听的端口
// 说明：	启动服务器监听
LEDNETSDK_API unsigned long _CALL_STD Start_Native_Server(int port);
// 函数：	Start_Ssl_Server
// 返回值：	成功返回监听后的句柄；失败返回-1
// 参数：	
//			int port：查询的控制器IP
//			_TEXT_CHAR* certpath：证书路径
//			_TEXT_CHAR* keypath：私钥路径
// 说明：	启动服务器监听（加密通讯的）
LEDNETSDK_API unsigned long _CALL_STD Start_Ssl_Server(int port, _TEXT_CHAR* certpath, _TEXT_CHAR* keypath);

// 函数：	Start_Proxy
// 返回值：	成功返回0；失败返回错误号
// 参数：	无
// 说明：	
LEDNETSDK_API int _CALL_STD Start_Proxy();

// 函数：	Stop_Server
// 返回值：	无
// 参数：	
//			unsigned long iServer：启动的服务器句柄
// 说明：	停止服务器监听
LEDNETSDK_API void _CALL_STD Stop_Server(unsigned long iServer);
#pragma endregion proxy
LEDNETSDK_API int _CALL_STD SearchCards(card_unit *cards);

// 函数：	get_screeninfo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			int *screen_w：查询到的音量
//			int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type
// 说明：	获取控制器参数（宽/高/类型）
LEDNETSDK_API int _CALL_STD get_screeninfo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type);

// 函数：	get_screen_volumn
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			int *volumn：查询到的音量
// 说明：	获取音量
LEDNETSDK_API int _CALL_STD get_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int *volumn);

// 函数：	get_screen_brightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			short* brightness：查询到的亮度值数组
// 说明：	获取亮度值
LEDNETSDK_API int _CALL_STD get_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, short* brightness);

// 函数：	get_screen_onoff
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：查询的控制器IP
//			unsigned short port：查询的控制器唯端口
//			_TEXT_CHAR* user_name：控制器登录名
//			_TEXT_CHAR* user_pwd：控制器登录密码
//			int* screen_onoff：查询到的开关机状态值
// 说明：	获取屏幕开关机状态
LEDNETSDK_API int _CALL_STD get_screen_onoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff);

//多余的接口，可以直接使用set_screen_ip即可
LEDNETSDK_API int _CALL_STD set_static_ip(_TEXT_CHAR* barcode,char* ip,char *submark,char *gateway);
//多余的接口，可以直接使用set_screen_auto_ip即可
LEDNETSDK_API int _CALL_STD set_auto_ip(_TEXT_CHAR* barcode);
//没用到
LEDNETSDK_API int _CALL_STD get_netinfo(char *ip,_TEXT_CHAR* barcode,char* mask,char* gate,int *ipmode);
 #ifdef __cplusplus
}
#endif
#endif
