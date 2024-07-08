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
	char ip[20];//��������ַ
	char barcode[17];//������������
}card_unit;
typedef struct _CARD_SERVER
{
	char barcode[17];//����������
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
// ������	set_screen_ip
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
//			char* ip��������ip
//			char* submark������
//			char* gateway����������
//			char* dns_server: ������������ַ
// ˵����	���ÿ�����IP��ַ
LEDNETSDK_API int _CALL_STD set_screen_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);
/*
//������	set_screen_ip_dwhand
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip��������ip
//			char* submark������
//			char* gateway����������
//			char* dns_server: ������������ַ
// ˵����	TCP���ÿ�����IP��ַ
*/
LEDNETSDK_API int _CALL_STD set_screen_ip_dwhand(unsigned long dwhand, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD set_screen_shadow_net_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark);

LEDNETSDK_API int _CALL_STD restart_app_udp(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// ������	set_screen_wifi_ip
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
//			char* ip��������ip
//			char* submark������
//			char* gateway����������
//			char* dns_server: ������������ַ
// ˵����	���ÿ�����IP��ַ
LEDNETSDK_API int _CALL_STD set_screen_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

// ������	set_screen_auto_ip
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
// ˵����	���ÿ������Զ���ȡIP��ַ
LEDNETSDK_API int _CALL_STD set_screen_auto_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// ������	set_screen_auto_wifi_ip
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
// ˵����	���ÿ������Զ���ȡIP��ַ
LEDNETSDK_API int _CALL_STD set_screen_auto_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// ������	set_screen_mac
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
//			char* mac��������mac
// ˵����	���ÿ�����MAC��ַ
LEDNETSDK_API int _CALL_STD set_screen_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac, int* min_waitTime, int* max_waitTime);

// ������	set_screen_server
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
//			int server_mode��server(1)����ͨ������ģʽ��cloud(2) ����ƽ̨������ģʽ��jtcproxy(3): ��ͨ�յ���off(0)���رշ�����ģʽ��
// ˵����	���ÿ�����MAC��ַ
LEDNETSDK_API int _CALL_STD set_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* server_ip, unsigned short port, int server_mode);
LEDNETSDK_API int _CALL_STD set_screen_server_dwhand(unsigned long dwhand, char* server_ip, unsigned short port, int server_mode);

// ������	enable_screen_server
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
//			int server_mode��server(1)����ͨ������ģʽ��cloud(2) ����ƽ̨������ģʽ��off(0)���رշ�����ģʽ��
// ˵����	���ÿ�����MAC��ַ
LEDNETSDK_API int _CALL_STD enable_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int server_mode);
LEDNETSDK_API int _CALL_STD enable_screen_server_dwhand(unsigned long dwhand, int server_mode);

// ������	set_screen_server_info
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dwhand��ͨѶ���
//			_TEXT_CHAR* server_ip�����õķ�����IP
//			_TEXT_CHAR* server_port�����õķ������˿�
// ˵����	���ÿ�������������ַ�������Ϣ
LEDNETSDK_API int _CALL_STD set_screen_server_info_dwhand(unsigned long dwhand, _TEXT_CHAR* server_ip, _TEXT_CHAR* server_port);
// ������	get_screen_server_info
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dwhand��ͨѶ���
//			_TEXT_CHAR* server_ip�����õķ�����IP
//			_TEXT_CHAR* server_port�����õķ������˿�
// ˵����	��ȡ���õĿ�������������ַ�������Ϣ
LEDNETSDK_API int _CALL_STD get_screen_server_info_dwhand(unsigned long dwhand, _TEXT_CHAR* server_ip, _TEXT_CHAR* server_port);

// ������	set_screen_install_address
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* pid��������Ψһ��
//			_TEXT_CHAR* barcode��������Ψһ��
//			_TEXT_CHAR* install_address����������װ��ַ
// ˵����	���ÿ�����IP��ַ
LEDNETSDK_API int _CALL_STD set_screen_install_address(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* install_address);

// ������	set_bx_param
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dwhand��ͨѶ���
//			_TEXT_CHAR* param�����õĲ���
// ˵����	������Ҫ������Ա�֮��ض��������Ϣ
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

// ������	clear_material
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����½����
// ˵����	���������ز�
LEDNETSDK_API int _CALL_STD clear_material(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_material_dwhand(unsigned long dwhand);
// ������	only_clear_material_dwhand
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����½����
// ˵����	���������زģ���ͣ����ֻ�Ƿ������������ز����
LEDNETSDK_API int _CALL_STD only_clear_material_dwhand(unsigned long dwhand);

// ������	clear_all_program
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����½����
// ˵����	������н�Ŀ
LEDNETSDK_API int _CALL_STD clear_all_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_all_program_dwhand(unsigned long dwhand);

// ������	enable_uploaddownload
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����½����
//			int enable_state���������ǹر�
//			int upload_download���ϴ���������
// ˵����	����/�ر��ļ��ϴ�/����
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

// ������	add_video
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long pic_area���������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			int volume_mode���Ƿ�����0�Ǿ���/1������
//			int video_type����Ƶ���ͣ�0������Ƶ��1�ⲿ��ƵԴ��
//			int ratation_mode����ʱ��Ƕ�
//			_TEXT_CHAR* clone_str����¡��Ϣ����x :y :w:h ,x1��y1��w1��h1...��
//			_TEXT_CHAR* crop_type�� �ⲿ��Ƶ��ʾ����λ�ü���С��w + "x" + h + "+" + x + "+" + y��
// ˵����	�����Ƶ����
LEDNETSDK_API int _CALL_STD add_video(unsigned long program, unsigned long video_area, int x, int y, int w, int h, int volume_mode, int video_type, int ratation_mode, _TEXT_CHAR* clone_str, _TEXT_CHAR* crop_type);

// ������	add_pic
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long pic_area��ͼƬ�������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
// ˵����	���ͼƬ����
LEDNETSDK_API int _CALL_STD add_pic(unsigned long program, unsigned long pic_area, int x, int y, int w, int h, int transparency);

// ������	add_weather
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long weather_area�������������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			int display_effects   �����ؼ��������� ����ֻʹ��0,2,50~57�⼸���ؼ�����
//      	string weatherURIHead     ������Ϣ�Ϳ���������URIͷ��Ϣ
//			string cityID 	����ID
//			string language  	��������
//			int display_speed    �ؼ��ٶȵȼ���1~16,1Ϊ���
//			int stay_time    ͼƬͣ��ʱ�䣬����Ϊ��λ
//			string fontFamily  �������� �磬����,��Sans��
//			string foreGround   ������ɫRGB,�磬��#00FF00��
//			string fontSize     ��벿�������С����40
//			int smallFontSize  �Ұ벿�������С��Ϊ��ߵ�1/2��
//			int modifyCityName   �޸ĳ�����
//			int displayMode    	0- һ����ʽ;  1- ������ʽ1; 2-������ʽ2;  3- Ԥ������
//			int displayLines    	0-Single line; 1-Multi-line
//			int iconGrade		0- 16*16��1- 24*24��2- 32*32��3- 48*48��4-64*64
//			int tempUnit 	 	0-���϶ȣ�1-���϶�
//			int isDisplayCity	 	1/true-��ʾ��0/false-����ʾ
//			int isDisplayIcon		1/true-��ʾ��0/false-����ʾ
//			int isDisplayWeath		1/true-��ʾ��0/false-����ʾ
//			int isDisplayTemp		1/true-��ʾ��0/false-����ʾ
//			int isDisplayWind		1/true-��ʾ��0/false-����ʾ
//			int isDisplayAirIndex	1/true-��ʾ��0/false-����ʾ
//			int isDisplayPM	  		1/true-��ʾ��0/false-����ʾ
//			int alignPosition		0/����1/���У�2/����
// ˵����	�����������
LEDNETSDK_API int _CALL_STD add_weather(unsigned long program, unsigned long weather_area, int x, int y, int w, int h, int transparency, 
	int stay_time, int display_effects, int display_speed, _TEXT_CHAR* weatherURIHead, _TEXT_CHAR* cityID, _TEXT_CHAR* language, _TEXT_CHAR* fontFamily,
	_TEXT_CHAR* foreGround, int fontSize, int smallFontSize, _TEXT_CHAR* modifyCityName, int display_mode, int displayLines, int iconGrade, int temp_unit,
	int isDisplayCity, int isDisplayIcon, int isDisplayWeath, int isDisplayTemp, int isDisplayWind, int isDisplayAirIndex, int isDisplayPM, int alignPosition);

// ������	add_broder
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long broder_area���߿����������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			_TEXT_CHAR* areaXYWH:ʮ�����߿���ĸ��ǵ�����λ���ֶ�
// ˵����	��ӱ߿����
LEDNETSDK_API int _CALL_STD add_broder(unsigned long program, unsigned long broder_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* areaXYWH = _TEXT_T(""));

// ������	add_dynamic
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long dynamic_area����̬���������
//			int dynamic_id����̬�����
//			int x/y/w/h:��̬����������Ϳ��
//			_TEXT_CHAR* relative_program:�����Ľ�Ŀ������Ҫ�����Ľ�Ŀ���(��Ŀ�б��е� order �ֶ�("0","1",...))����Ϊ��
//			int run_mode:��̬�����з�ʽ��0ȫ�ֲ��Ŷ�̬��/1ȫ�ֶ�̬����Ŀ/2ȫ�ֶ�̬����Ŀ/3�󶨲��Ŷ�̬����������Ŀ��ʼ����ʱ���Ŷ�̬����ֱ��������Ŀ�������/4�󶨲��Ŷ�̬����������Ŀ��ʼ����ʱ���Ŷ�̬������ʾ��һ����ֲ�����ʾ/5�󶨲��Ŷ�̬����������Ŀ��ʼ����ʱ���Ŷ�̬������ʾ��һ���ֹ��ʾ�ö�̬�������һ��unit/6�󶨲��Ŷ�̬����������Ŀ������󲥷Ŷ�̬��
//			_TEXT_CHAR* update_frequency���ſ�""����  URLPicture��URLText������Դ���ظ���Ƶ�ʣ���λ�롣С��5s����5s����Ϊ�ջ�0��ֻ����һ��
//			int transparency: ����͸����
// ˵����	��Ӷ�̬��
LEDNETSDK_API int _CALL_STD add_dynamic(unsigned long program, unsigned long dynamic_area, int dynamic_id, int x, int y, int w, int h, _TEXT_CHAR* relative_program, int run_mode, _TEXT_CHAR* update_frequency, int transparency);

// ������	add_colorful_subtitle
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long colorful_subtitle_area���Ų������������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
// ˵����	����Ų��ַ���
LEDNETSDK_API int _CALL_STD add_colorful_subtitle(unsigned long program, unsigned long colorful_subtitle_area, int x, int y, int w, int h);

// ������	add_db
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long db_area�����ݿ�������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
// ˵����	������ݿ����
LEDNETSDK_API int _CALL_STD add_db(unsigned long program, unsigned long db_area, int x, int y, int w, int h, int transparency);

// ������	add_text
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long text_area����Ļ���������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			int display_effects����ʾ�ؼ�
//			int unit_type��0 - ��Ⱦ�õ��ı�ͼƬ����λ����Ⱦ �� 1 - δ��Ⱦ�����֣����ƿ�����Ⱦ
// ˵����	�����Ļ����
LEDNETSDK_API int _CALL_STD add_text(unsigned long program, unsigned long text_area, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);

// ������	add_rich_text
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long text_area�����ı����������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����(0~100)��100 Ϊ��ȫ��͸����Ĭ��100
//			int display_effects����ʾ�ؼ�;����ֻʹ��0��50��51�������ؼ�����      
//			int alignment_h: ����0������2������1
// ˵����	��Ӹ��ı���
LEDNETSDK_API int _CALL_STD add_rich_text(unsigned long program, unsigned long rich_text_area, int x, int y, int w, int h, int transparency, int display_effects, int alignment_h);

// ������	add_clock
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long clock_area���������������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			_TEXT_CHAR* time_equation������ʱ�䣬��ʽ��hh:mm:ss��  
//			_TEXT_CHAR* positive_te������ʱ�䷽��trueΪ��/falseΪ����
//			_TEXT_CHAR* adjustment�����Ե���ʱ�֧����������ʽ����dd:hh:mm:ss��
//			_TEXT_CHAR* hour_color��ʱ����ɫ
//			_TEXT_CHAR* minute_color��������ɫ
//			_TEXT_CHAR* second_color��������ɫ
//			_TEXT_CHAR* bg_image������ͼƬ
// ˵����	��ӱ��̷���
LEDNETSDK_API int _CALL_STD add_clock(unsigned long program, unsigned long clock_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* adjustment, _TEXT_CHAR* hour_color, _TEXT_CHAR* minute_color, _TEXT_CHAR* second_color, _TEXT_CHAR* bg_image);

// ������	add_clock_hour
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long clock_area�����̷������
//			_TEXT_CHAR* src_path������ͼƬ 
//			_TEXT_CHAR* h_color��������ɫ
//			int h_length��ʱ��ĳ��ȣ���������Ч��
//			int h_width��ʱ��Ŀ��
// ˵����	��ӱ��̷���ʱ��
LEDNETSDK_API int _CALL_STD add_clock_hour(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* h_color, int h_length, int h_width);

// ������	add_clock_minute
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long clock_area�����̷������
//			_TEXT_CHAR* src_path������ͼƬ 
//			_TEXT_CHAR* m_color��������ɫ
//			int m_length������ĳ��ȣ���������Ч��
//			int m_width������Ŀ��
// ˵����	��ӱ��̷�������
LEDNETSDK_API int _CALL_STD add_clock_minute(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* m_color, int m_length, int m_width);

// ������	add_clock_second
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long clock_area�����̷������
//			_TEXT_CHAR* src_path������ͼƬ 
//			_TEXT_CHAR* s_color��������ɫ
//			int s_length������ĳ��ȣ���������Ч��
//			int s_width������Ŀ��
// ˵����	��ӱ��̷�������
LEDNETSDK_API int _CALL_STD add_clock_second(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* s_color, int s_length, int s_width);

// ������	add_count
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long calendar_area����ʱ���������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			_TEXT_CHAR* bg_color������ɫ 
//			_TEXT_CHAR* time_equation������ʱ�䣬��ʽ��hh:mm:ss��  
//			_TEXT_CHAR* positive_te����ʱ���ͣ���end�� - ����ʱ��start�� - ����ʱ��
//			_TEXT_CHAR* target_date��Ŀ�����ڡ�yyyy-MM-dd��
//			_TEXT_CHAR* target_time��Ŀ��ʱ�䡮hh:mm:ss��
//			_TEXT_CHAR* content����ʱ����ʾ���ݣ��磺������Ŀ�꣺dd �� hh ʱ mm �� ss �롯��
//			_TEXT_CHAR* font_color��������ɫ
//			_TEXT_CHAR* font_name��������
//			int font_size�������С
//			int content_x������x����
//			int content_y������y����
//			_TEXT_CHAR* font_attributes���������ԣ�����/б��/�»��ߵȣ�
//			_TEXT_CHAR* add_enable����λ����(��ʱ�ۼ�)����no�� - �񣻡�yes�� - ��
// ˵����	��Ӽ�ʱ����
LEDNETSDK_API int _CALL_STD add_count(unsigned long program, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* target_date, _TEXT_CHAR* target_time, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int content_x, int content_y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* add_enable);

// ������	add_calendar
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long calendar_area��ũ���������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			_TEXT_CHAR* bg_color������ɫ 
//			_TEXT_CHAR* time_equation������ʱ�䣬��ʽ��hh:mm:ss��
//			_TEXT_CHAR* positive_te������ʱ�䷽��trueΪ��/falseΪ����
//			_TEXT_CHAR* adjustment�����Ե���ʱ�֧����������ʽ����dd:hh:mm:ss��
// ˵����	���ũ������
LEDNETSDK_API int _CALL_STD add_time(unsigned long program, unsigned long time_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* adjustment);

// ������	add_calendar
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long calendar_area��ũ���������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			_TEXT_CHAR* bg_color������ɫ 
//			_TEXT_CHAR* time_equation������ʱ�䣬��ʽ��hh:mm:ss��
//			_TEXT_CHAR* positive_te������ʱ�䷽��trueΪ��/falseΪ����
//			_TEXT_CHAR* adjustment�����Ե���ʱ�֧����������ʽ����dd:hh:mm:ss��
// ˵����	���ũ������
LEDNETSDK_API int _CALL_STD add_calendar(unsigned long program, unsigned long calendar_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* adjustment);

// ������	add_sensor
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			_TEXT_CHAR* font_name��������
//			int font_size�������С
//			_TEXT_CHAR* font_attributes���������ԣ�����/б��/�»��ߵȣ�
//			_TEXT_CHAR* font_color��������ɫ
//			_TEXT_CHAR* thresh_fontcolor������ֵʱ��������ɫ
//			_TEXT_CHAR* bg_color������ɫ
//			_TEXT_CHAR* content_sensor��������������ʾ����
//			int content_x��������ʾx����
//			int content_y��������ʾy���� 
//			int unit_type����������λ��ʶ
//			int significant_digits����Ҫ��ʾ��С��λ��
//			float unit_coefficient����λת��ϵ��
//			float correction������ֵ
//			_TEXT_CHAR* thresh_mode����ֵģʽ��0С�ڣ�1���ڣ�
//			int thresh����ֵ
//			_TEXT_CHAR* sensor_addr����������ַ
//			_TEXT_CHAR* fun_seq���������
//			int update_time�����¼��
// ˵����	��Ӵ���������
LEDNETSDK_API int _CALL_STD add_sensor(unsigned long program, int x, int y, int w, int h, int transparency, 
	_TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_color, _TEXT_CHAR* thresh_fontcolor, _TEXT_CHAR* bg_color, 
	_TEXT_CHAR* content_sensor, int content_x, int content_y, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int update_time);

// ������	add_animation
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			int display_effects����������
//			int display_density���ܶȵȼ� 
//			int display_size����������ߴ�
//			_TEXT_CHAR* direction����������
//			int display_speed�������ٶ�
//			_TEXT_CHAR* animation_color������������ɫ 
//			int taper��׶��
//			_TEXT_CHAR* file_path����������·��
//			_TEXT_CHAR* file_type��������������
// ˵����	����Ųʱ�������
LEDNETSDK_API int _CALL_STD add_animation(unsigned long program, int x, int y, int w, int h, int transparency, int display_effects, int display_density, int display_size, _TEXT_CHAR* direction, int display_speed, _TEXT_CHAR* animation_color, int taper, _TEXT_CHAR* file_path, _TEXT_CHAR* file_type);

// ������	add_audio
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long audio_area���������ַ������
// ˵����	��ӱ������ַ���
LEDNETSDK_API int _CALL_STD add_audio(unsigned long program, unsigned long audio_area);

// ������	add_nvr
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long program����Ŀ���
//			unsigned long nvr_area���������
//			int x������x����
//			int y������y����
//			int w��������� 
//			int h�������߶�
//			int transparency������͸����
//			int volume_mode���Ƿ�����0�Ǿ���/1������
//			int ratation_mode����ʱ��Ƕ�
// ˵����	���nvr����
LEDNETSDK_API int _CALL_STD add_nvr(unsigned long program, unsigned long nvr_area, int x, int y, int w, int h, int volume_mode, int ratation_mode);


// ������	add_video_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long video_area����Ƶ�������
//			int volume������
//			int scale_mode������ģʽ
//			int source���ⲿ��ƵԴ���� 
//			_TEXT_CHAR* src_path����Ƶ·��
//			_TEXT_CHAR* crop_type���ⲿ��ƵԴ��ʾλ��
// ˵����	�����Ƶ������
LEDNETSDK_API int _CALL_STD add_video_unit(unsigned long video_area, int volume, int scale_mode, int source, int play_time, _TEXT_CHAR* src_path, _TEXT_CHAR* crop_type);

// ������	add_broder_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long broder_area���߿�������
//			int duration������ʱ������λ���룩
//			int broder_w���߿���
//			int texture_w������Ƭ�ο�ȣ����߿�߶ȣ�
//			int stunt_type����ʾ�ؼ�
//			int display_speed���ؼ��ٶ�
//			int flicker_grade����˸�ٶ� 
//			_TEXT_CHAR* src_path���߿�����·��
//			_TEXT_CHAR* flicker_path��������Ƭ��ͼƬ�ļ�·�����ɷſգ�
// ˵����	��ӱ߿������
LEDNETSDK_API int _CALL_STD add_broder_unit(unsigned long broder_area, int duration, int broder_w, int texture_w, int stunt_type, int stunt_speed, int flicker_grade, _TEXT_CHAR* src_path, _TEXT_CHAR* flicker_path);

// ������	add_pic_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long pic_area��ͼƬ�������
//			int stay_time���ؼ�ͣ��ʱ�� 
//			int display_effects����ʾ�ؼ�
//			int display_speed���ؼ��ٶ�
//			_TEXT_CHAR* src_path��ͼƬ·��
// ˵����	���ͼ�ķ�����
LEDNETSDK_API int _CALL_STD add_pic_unit(unsigned long pic_area, int stay_time, int display_effects, int display_speed, _TEXT_CHAR* src_path);

// ������	add_text_unit_img
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long text_area����Ļ�������
//			int stay_time���ؼ�ͣ��ʱ�� 
//			int display_speed���ؼ��ٶ�
//			int last_move_width�����һ��ͼƬ�ƶ��Ŀ��
//			_TEXT_CHAR* src_path���ı�ͼƬ·��
// ˵����	�����Ļ������ΪͼƬʱ�ķ�����
LEDNETSDK_API int _CALL_STD add_text_unit_img(unsigned long text_area, int stay_time, int display_speed, int last_move_width, _TEXT_CHAR* src_path);

// ������	add_text_unit_text
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long text_area����Ļ�������
//			int stay_time���ؼ�ͣ��ʱ�� 
//			int display_speed���ؼ��ٶ�
//			_TEXT_CHAR* font_name��������
//			int font_size�������С
//			_TEXT_CHAR* font_attributes���������ԣ�����/б��/�»��ߵȣ�
//			_TEXT_CHAR* font_alignment����Э�������
//			_TEXT_CHAR* font_color��������ɫ
//			_TEXT_CHAR* bg_color������ɫ
//			_TEXT_CHAR* content���ı�����
// ˵����	�����Ļ������Ϊ�ı�ʱ�ķ�����
LEDNETSDK_API int _CALL_STD add_text_unit_text(unsigned long text_area, int stay_time, int display_speed, _TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_alignment, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);

// ������	add_rich_text_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long rich_text_area�����ı��������
//			int stay_time���ؼ�ͣ��ʱ�䣬����Ϊ��λ
//			int display_speed���ؼ��ٶȵȼ���1~16,1Ϊ���
//			_TEXT_CHAR* bg_image_path������ͼƬ�ļ�·������λ����Ҫ������ͼƬ�ͽ�Ŀ�ļ�һ���·�����Ŀ¼Ϊ���ƿ��洢����ͼƬ��Ŀ¼��
//			_TEXT_CHAR* bg_color������ɫ��
//			_TEXT_CHAR* content���ı����ݣ���Ҫ��ʾ�����ݺ��������ԣ����������͡���ɫ����С���м�࣬�磺<span foregroud=��white�� font=��12��>�Ϻ�����</span>
//			��ʽ�ο����ӣ�https://developer.gnome.org/pango/stable/pango-Markup.html
// ˵����	��Ӹ��ı�������
LEDNETSDK_API int _CALL_STD add_rich_text_unit(unsigned long rich_text_area, int stay_time, int display_speed, _TEXT_CHAR* bg_image_path, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);

// ������	add_colorful_hollowunit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long colorful_subtitle_area���Ų��ַ������
//			int display_effects����о�ؼ�
//			int display_speed���ؼ��ٶ�
//			int stay_time���ؼ�ͣ��ʱ�� 
//			_TEXT_CHAR* file����оͼƬ·��
// ˵����	����Ų��ַ�����о��
LEDNETSDK_API int _CALL_STD add_colorful_hollowunit(unsigned long colorful_subtitle_area, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* hollow_file);

// ������	add_colorful_fontunit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long colorful_subtitle_area���Ų��ַ������
//			_TEXT_CHAR* file������ͼƬ·��
//			int display_effects����ʾ�ؼ�
//			int display_speed���ؼ��ٶ�
//			int stay_time���ؼ�ͣ��ʱ�� 
//			int wave_effects�������ؼ�
//			int wave_count���������
//			int wave_speed�������ٶ�
//			int wave_amplitude���������
// ˵����	����Ų��ַ�����
LEDNETSDK_API int _CALL_STD add_colorful_fontunit(unsigned long colorful_subtitle_area, _TEXT_CHAR* file, int display_effects, int display_speed, int stay_time, int wave_effects, int wave_count, int wave_speed, int wave_amplitude);

// ������	add_time_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long time_area��ʱ��������
//			_TEXT_CHAR* content����������
//			_TEXT_CHAR* font_color��������ɫ
//			_TEXT_CHAR* font_name��������
//			int font_size�������С
//			int x��������Ⱦ�����½���Է������Ͻǵ�ˮƽƫ��
//			int y��������Ⱦ�����½���Է������ϽǵĴ�ֱƫ��
//			_TEXT_CHAR* font_attributes���������ԣ�����/б��/�»��ߵȣ�
// ˵����	���ʱ�������
LEDNETSDK_API int _CALL_STD add_time_unit(unsigned long time_area, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes);

// ������	add_calendar_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long calendar_area��ũ���������
//			_TEXT_CHAR* mode��ũ����ʽ����heavenlystem��: Ϊ ��֧���꣬�����ӡ� - ���ﺥ����lunarcalendar��: Ϊ�������确���� ��������solarterms�� : Ϊ����������¸��������������确���ġ��� ����С�� 10 �졯�ȣ�
//			_TEXT_CHAR* font_color��������ɫ
//			_TEXT_CHAR* font_name��������
//			int font_size�������С
//			int x��������Ⱦ�����½���Է������Ͻǵ�ˮƽƫ��
//			int y��������Ⱦ�����½���Է������ϽǵĴ�ֱƫ��
//			_TEXT_CHAR* font_attributes���������ԣ�����/б��/�»��ߵȣ�
//			_TEXT_CHAR* text_content����������
// ˵����	���ũ��������
LEDNETSDK_API int _CALL_STD add_calendar_unit(unsigned long calendar_area, _TEXT_CHAR* mode, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* text_content);

//LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, _TEXT_CHAR* db_type, _TEXT_CHAR* db_ip,  unsigned short db_port,  _TEXT_CHAR* user_name,  _TEXT_CHAR* user_pwd,  _TEXT_CHAR* db_name, int update_time, int stay_time, int display_effects, int display_speed,  _TEXT_CHAR* bg_odd_color,  _TEXT_CHAR* bg_even_color, _TEXT_CHAR* text_odd_color, _TEXT_CHAR* text_even_color,  _TEXT_CHAR* font_name, int font_size, int font_bold, int font_italic, int font_underline, int font_strikeout, int font_noAntialias, _TEXT_CHAR* align_h_type, _TEXT_CHAR* align_v_type, _TEXT_CHAR* auto_lf , _TEXT_CHAR* headtype, _TEXT_CHAR* row_to_column, int linear, int line_w, int paint_table, _TEXT_CHAR* line_color, int row_count, int column_count, int row_h, int column_w, _TEXT_CHAR* cmd_data, _TEXT_CHAR* cmd_fieldname , _TEXT_CHAR* bg_img);

// ������	add_db_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long db_area�����ݿ�������
//			unsigned long dbUnit�����ݿ�����
//			struct DatabaseUnitInfo* dbUnitInfo�����ݿ���ṹ��
// ˵����	������ݿ������
LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, unsigned long dbUnit, struct DatabaseUnitInfo* dbUnitInfo);

// ������	add_db_unit_specifyrow
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dbUnit�����ݿ�����
//			struct SpecifyRow* specifyRow���нṹ��
// ˵����	������ݿ�������
LEDNETSDK_API int _CALL_STD add_db_unit_specifyrow(unsigned long dbUnit, struct SpecifyRow* specifyRow);

// ������	add_db_unit_specifycolumn
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dbUnit�����ݿ�����
//			struct SpecifyColumn* specifyColumn���нṹ��
// ˵����	������ݿ�������
LEDNETSDK_API int _CALL_STD add_db_unit_specifycolumn(unsigned long dbUnit, struct SpecifyColumn* specifyColumn);

// ������	add_db_unit_specifycell
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dbUnit�����ݿ�����
//			struct SpecifyCell* specifyCell����Ԫ��ṹ��
// ˵����	������ݿ����ⵥԪ��
LEDNETSDK_API int _CALL_STD add_db_unit_specifycell(unsigned long dbUnit, struct SpecifyCell* specifyCell);

// ������	add_audio_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long audio_area���������ַ������
//			int volume������
//			_TEXT_CHAR* src_path�������ļ�·��
// ˵����	��ӱ���������
LEDNETSDK_API int _CALL_STD add_audio_unit(unsigned long audio_area, int volume, _TEXT_CHAR* src_path);

// ������	add_dynamic_unit
// ����ֵ��	
// ������	
//			dynamic_area����̬��������
//			int dynamic_type:��̬��Ԫ����
//			int display_effects:�ؼ�����
//			int display_speed���ؼ��ٶ�
//			int stay_time:�ؼ�ͣ��ʱ��
//			file_path:Ԫ��·�����ı����֧��txt��ʽ
//			gif_flag:0��GIF��1GIF���ͣ��ݲ�֧�ֶ�̬���ţ���Ϊ��ͨͼƬ���ţ�
//			bg_color��������ɫ
//			font_size�������С
//			font_color:������ɫ
//			font_attributes��������bold������italic������normal�������С�bold���͡�italic������ͨ����&���������
//			font_name������
//			align_h:ˮƽ���뷽ʽ0����/1����/2����
//			align_v:��ֱ���뷽ʽ0����/1����/2����
//			��������Ϊ��Ƶ���ԣ��ݲ�֧����Ƶ
//			1. volumn������
//			2. scale_mode������ģʽ�����ڱ���0/ԭʼ����1
//			3. rolation_mode����ת�Ƕ�
//			_TEXT_CHAR* key_list ����Ϊ"URLText"���һ�ȡ������ԴΪjson��ʽ����ʱ��Ч����ȡ���ݵ��ֶ�
//			_TEXT_CHAR* proxyService ��̬��"URLText"���ͣ�������ԴΪ�������ʱ���ò�����Ч���Ҹò����Ǵ������ı�ʶ�����������ҷǿգ��� 
// ˵����	��Ӷ�̬����
LEDNETSDK_API int _CALL_STD add_dynamic_unit(unsigned long dynamic_area, int dynamic_type, int display_effects, int display_speed, int stay_time,_TEXT_CHAR* file_path, int gif_flag, _TEXT_CHAR* bg_color, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* font_attributes, _TEXT_CHAR* align_h, _TEXT_CHAR* align_v, int volumn, int scale_mode, int rolation_mode, _TEXT_CHAR* key_list, _TEXT_CHAR* proxyService);

// ������	add_nvr_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long nvr_area���������
//			_TEXT_CHAR* nvrid: nvr�豸ID��
//			_TEXT_CHAR* username: "admin" nvr��¼�û���
//			_TEXT_CHAR* upwd:"admin" nvr��¼����
//			_TEXT_CHAR* nvraddr: http:\\192.168.0.199"NVR�豸�����ַ
//			int playTime: ����ʱ������Ϊ��λ; 0��ʾ�ڽ�ĿʱЧ��һֱ���Ż����ļ�ʱ������
//			int volume������
//			_TEXT_CHAR* valid����Ч�����Ƿ�� on or off
//			int x����Ƶҳ�ĺ�����(���valid="off"��ֵ��0����)
//			int y����Ƶҳ��������(���valid="off"��ֵ��0����)
//			int w��Ҫ��ʾ����Ƶҳ�Ŀ��(���valid="off"��ֵ��0����)
//			int h��Ҫ��ʾ����Ƶҳ�ĸ߶�(���valid="off"��ֵ��0����)
// ˵����	���nvr������
LEDNETSDK_API int _CALL_STD add_nvr_unit(unsigned long nvr_area, _TEXT_CHAR* nvrid, _TEXT_CHAR* username, _TEXT_CHAR* upwd, _TEXT_CHAR* nvraddr, int playTime, int volume, _TEXT_CHAR* valid, int x,int y, int w, int h);


// ������	add_program_in_playlist
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long playlist�������б���
//			unsigned long program����Ŀ���
//			int play_mode������ģʽ��0����/1���Σ�
//			int play_time������ʱ����play_mode����ʱΪʱ��������ʱΪ������
//			_TEXT_CHAR* aging_start_time������ʱЧ��ʼ���ڡ�yyyy-MM-dd��
//			_TEXT_CHAR* aging_end_time������ʱЧ��������
//			_TEXT_CHAR* period_ontime�����ſ�ʼʱ�䡮hh:mm:ss�� 
//			_TEXT_CHAR* period_offtime�����Ž���ʱ��
//			int play_week��������Ч��ʶ
// ˵����	��ӽ�Ŀ�������б�
LEDNETSDK_API int _CALL_STD add_program_in_playlist(unsigned long playlist, unsigned long program, int play_mode, int play_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, int play_week);

// ������	set_playlist_style
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long playlist�������Ĳ����б���
//			int sync_display���Ƿ�Ϊͬ�����ţ�1Ϊͬ�����ţ�
//			int startH����ʼʱ
//			int startM����ʼ��
//			int startS����ʼ��
//			int endH������ʱ
//			int endM��������
//			int endS��������
// ˵����	�����Ƿ�ͬ�����ţ����ڵƸ�����Ҫͬ�����ų�����
LEDNETSDK_API int _CALL_STD set_playlist_style(unsigned long playlist, int sync_display, int startH, int startM, int startS, int endH, int endM, int endS);
#pragma endregion program

#pragma region bulletin
// ������	play_bulletin
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned long bulletin_list��create_bulletin�ӿڴ����Ĺ�����
// ˵����	����ָ������
LEDNETSDK_API int _CALL_STD play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long bulletin_list);
LEDNETSDK_API int _CALL_STD play_bulletin_dwhand(unsigned long dwhand,char* ip, unsigned short port, unsigned long bulletin_list);

// ������	create_bulletin
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int x��x����
//			int y��y����
//			int w����ʾ���
//			int h����ʾ�߶�
//			_TEXT_CHAR* name: ������
//			int layout:  ��ʾλ��
//			int transparency�� ͸����
//			int font_size�� �����С
//			_TEXT_CHAR* font_name: ������
//			_TEXT_CHAR* font_color: ������ɫ
//			_TEXT_CHAR* bg_color: ����ɫ
//			int display_effects: �ؼ���
//			int display_speed: �ؼ������ٶ�
//			int stay_time: �ؼ�ͣ��ʱ�� 
//			_TEXT_CHAR* aging_start_time: ��ʼ���ڣ������գ�
//			_TEXT_CHAR* aging_end_time: ��������
//			_TEXT_CHAR* period_ontime: ��ʼʱ�䣨ʱ���룩
//			_TEXT_CHAR* period_offtime:  ����ʱ��
//			_TEXT_CHAR* content: ��������
//			_TEXT_CHAR* font_align: �������ԣ�����/б��/�»��ߵȣ�
// ˵����	�������Ź���
LEDNETSDK_API int _CALL_STD create_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
LEDNETSDK_API int _CALL_STD create_bulletin_dwhand(unsigned long dwhand, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);

// ������	delete_bulletin
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* names��ָ��ɾ���Ĺ������ƣ����ʹ�÷ֺŸ���
// ˵����	ɾ��ָ������
LEDNETSDK_API int _CALL_STD delete_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd,  _TEXT_CHAR* names);
LEDNETSDK_API int _CALL_STD delete_bulletin_dwhand(unsigned long dwhand,  _TEXT_CHAR* names);

// ������	stop_play_bulletin
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	ֹͣ���Ź���
LEDNETSDK_API int _CALL_STD stop_play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD stop_play_bulletin_dwhand(unsigned long dwhand);

// ������	add_bulletin
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	��ӹ��沢������xml�ļ������Ҽ�¼��play_list���У��������ϴ��ļ���ʱ��ʹ���ļ�md5��·��
LEDNETSDK_API int _CALL_STD add_bulletin(_TEXT_CHAR* tmp_path, unsigned long playlist, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
#pragma endregion bulletin

// ������	change_password
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* pwd��������
//			int style�������㷨��2Ϊsha256/����Ϊsha1��sha256��ҪΪY3X�ͺ�ʹ�ã���ϻ�Ϊ��Ŀ���ӵ�
// ˵����	�޸�����
LEDNETSDK_API int _CALL_STD change_password(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pwd, int style = 1);
LEDNETSDK_API int _CALL_STD change_password_dwhand(unsigned long dwhand, _TEXT_CHAR* pwd, int style = 1);

// ������	reset_password
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	��������
LEDNETSDK_API int _CALL_STD reset_password(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD reset_password_dwhand(unsigned long dwhand, _TEXT_CHAR* user_name);

// ������	check_screen_info
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* path�����Ž�Ŀ·��
// ˵����	���ָ����������Ϣ����Ҫ�жϿ������ͺź�PID�Ƿ�ƥ�䣩
LEDNETSDK_API int _CALL_STD check_screen_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pid, unsigned short device_type);
LEDNETSDK_API int _CALL_STD check_screen_info_dwhand(unsigned long dwhand, _TEXT_CHAR* pid, unsigned short device_type);

// ������	play_program
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* path�����Ž�Ŀ·��
// ˵����	����ָ����Ŀ
LEDNETSDK_API int _CALL_STD play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, int is_save = 1);
LEDNETSDK_API int _CALL_STD play_program_dwhand(unsigned long dwhand, _TEXT_CHAR* src_path, int is_save = 1);

// ������	stop_play_program
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	ֹͣ���Ž�Ŀ
LEDNETSDK_API int _CALL_STD stop_play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD stop_play_program_dwhand(unsigned long dwhand);

// ������	lock_program
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int flag������1/����0
//			_TEXT_CHAR* program_name��������/�����Ľ�Ŀ���ƣ���Ŀ�ļ��е�name����ֵ��
// ˵����	����/������Ŀ
LEDNETSDK_API int _CALL_STD lock_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, _TEXT_CHAR* program_name);
LEDNETSDK_API int _CALL_STD lock_program_dwhand(unsigned long dwhand, int flag, _TEXT_CHAR* program_name);

// ������	get_screen_parameters
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned char* cards��ControllerInfo�ṹ��
// ˵����	��ȡ��Ļ����
LEDNETSDK_API int _CALL_STD get_screen_parameters(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned char* cards);
LEDNETSDK_API int _CALL_STD get_screen_parameters_dwhand(unsigned long dwhand, unsigned char* cards);

// ������	restart_boot
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	ϵͳ����
LEDNETSDK_API int _CALL_STD restart_boot(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD restart_boot_dwhand(unsigned long dwhand);

// ������	restart_app
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	app��Ӧ�ã�����
LEDNETSDK_API int _CALL_STD restart_app(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD restart_app_dwhand(unsigned long dwhand);

// ������	check_time
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	Уʱ
LEDNETSDK_API int _CALL_STD check_time(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD check_time_dwhand(unsigned long dwhand);

// ������	check_time_str
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* time_str:ʱ�䣨��ʽ��"yyyy-MM-dd hh:mm:ss"��
//			int is_utc:�Ƿ���UTCʱ��У��������ʱ��(1��UTCʱ��/0����ʱ��)
// ˵����	Уʱ
LEDNETSDK_API int _CALL_STD check_time_str(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* time_str, int is_utc);

// ������	lock_screen
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int lock������1/����0
// ˵����	����/����
LEDNETSDK_API int _CALL_STD lock_screen(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int lock);
LEDNETSDK_API int _CALL_STD lock_screen_dwhand(unsigned long dwhand, int lock);

// ������	set_screen_brightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int brightness������ֵ
// ˵����	���ü�ʱ����
LEDNETSDK_API int _CALL_STD set_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int brightness);
LEDNETSDK_API int _CALL_STD set_screen_brightness_dwhand(unsigned long dwhand, int brightness);

// ������	set_screen_auto_brightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned short* brightness������ֵ����
//			int data_count������ֵ����
//			unsigned short* sensor_brightness������������ֵ����
//			int sensor_data_count������������ֵ����
//			_TEXT_CHAR* sensor_addr����������ַ
// ˵����	�����Զ�����
LEDNETSDK_API int _CALL_STD set_screen_auto_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);
LEDNETSDK_API int _CALL_STD set_screen_auto_brightness_dwhand(unsigned long dwhand, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);

// ������	set_screen_cus_brightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned short* brightness������ֵ����
//			int data_count������ֵ����
// ˵����	���ö�ʱ����
LEDNETSDK_API int _CALL_STD set_screen_cus_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count);
LEDNETSDK_API int _CALL_STD set_screen_cus_brightness_dwhand(unsigned long dwhand, unsigned short* brightness, int data_count);

// ������	set_screen_volumn
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int volumn������
// ˵����	��������
LEDNETSDK_API int _CALL_STD set_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int volumn);
LEDNETSDK_API int _CALL_STD set_screen_volumn_dwhand(unsigned long dwhand, int volumn);

// ������	set_screen_turnonoff
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int turnonoff_status������1/�ػ�0
// ˵����	���ػ�
LEDNETSDK_API int _CALL_STD set_screen_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int turnonoff_status);
LEDNETSDK_API int _CALL_STD set_screen_turnonoff_dwhand(unsigned long dwhand, int turnonoff_status);

// ������	screen_cus_turnonoff
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			struct CustomerTurnOnOffScreenData* turnonoff����ʱ���ػ��ṹ��
//			int data_count����ʱ���ػ��ṹ��������������Ϊ0ʱ����ʾȡ����ʱ���ػ��������ʾ���ö�ʱ���ػ�
// ˵����	��ʱ���ػ�
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long turnonoff);
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff_dwhand(unsigned long dwhand, unsigned long turnonoff);

// ������	cancel_screen_cus_turnonoff
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	ȡ����ʱ���ػ�
LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff_dwhand(unsigned long dwhand);

#pragma region customer turn onoff
LEDNETSDK_API unsigned long _CALL_STD create_turnonoff();

LEDNETSDK_API void _CALL_STD add_turnonoff(unsigned long turnonoff, int action, _TEXT_CHAR* time);

LEDNETSDK_API void _CALL_STD delete_turnonoff(unsigned long turnonoff);
#pragma endregion customer turn onoff

// ������	set_apn
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* ppp_apn��
//			_TEXT_CHAR* ppp_number��
//			_TEXT_CHAR* ppp_username��
//			_TEXT_CHAR* ppp_password��
// ˵����	����APN
LEDNETSDK_API int _CALL_STD set_apn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);
LEDNETSDK_API int _CALL_STD set_apn_dwhand(unsigned long dwhand, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);

// ������	set_screen_logo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int flag����/�ر�logo
//			_TEXT_CHAR* logo_layout����ʾλ��
//			int screen_w����ʾ���
//			int screen_h����ʾ�߶�
//			_TEXT_CHAR* src_path��logo�ļ�·��
// ˵����	����logo
LEDNETSDK_API int _CALL_STD set_screen_logo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, _TEXT_CHAR* logo_layout, int screen_w, int screen_h, _TEXT_CHAR* src_path);
LEDNETSDK_API int _CALL_STD set_screen_logo_dwhand(unsigned long dwhand,char* ip, unsigned short port, int flag, _TEXT_CHAR* logo_layout, int screen_w, int screen_h, _TEXT_CHAR* src_path);

// ������	set_screen_size
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int screen_w����ʾ���
//			int screen_h����ʾ�߶�
//			int screenrotation����ת�Ƕ�
// ˵����	������Ļ��������/��/��ת�Ƕȣ�
LEDNETSDK_API int _CALL_STD set_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int screenrotation);
LEDNETSDK_API int _CALL_STD set_screen_size_dwhand(unsigned long dwhand, int screen_w, int screen_h, int screenrotation);

// ������	set_fold_screen_size
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int screen_w����ʾ���
//			int screen_h����ʾ�߶�
//			int fold_type������
//			int fold_count, int* fold_h, int h_len, int* fold_w, int w_len
// ˵����	��������
LEDNETSDK_API int _CALL_STD set_fold_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);
LEDNETSDK_API int _CALL_STD set_fold_screen_size_dwhand(unsigned long dwhand, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);

// ������	set_screen_barcode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 _TEXT_CHAR* barcode��Ҫ���õ�������
// ˵����	����������
LEDNETSDK_API int _CALL_STD set_screen_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD set_screen_barcode_dwhand(unsigned long dwhand, _TEXT_CHAR* barcode);

// ������	set_screen_ip_flag
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 int flag���Ƿ���ʾIP��ʾ��Ϣ
// ˵����	�����Ƿ���ʾIP��ʾ��Ϣ
LEDNETSDK_API int _CALL_STD set_screen_ip_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);
LEDNETSDK_API int _CALL_STD set_screen_ip_flag_dwhand(unsigned long dwhand, int flag);

// ������	set_screen_led_flag
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 int flag���Ƿ���ʾLED��־
// ˵����	�����Ƿ���ʾLED��־
LEDNETSDK_API int _CALL_STD set_screen_led_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);
LEDNETSDK_API int _CALL_STD set_screen_led_flag_dwhand(unsigned long dwhand, int flag);

// ������	set_screen_output_type
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 int output_type�����ģʽ��0 LCD��1 DVI��
// ˵����	���������ʽ
LEDNETSDK_API int _CALL_STD set_screen_output_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int output_type);
LEDNETSDK_API int _CALL_STD set_screen_output_type_dwhand(unsigned long dwhand, int output_type);

// ������	set_screen_player_type
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 int player_type������ģʽ��"normal/0":�첽ģʽ��"sync/1":ͬ��ģʽ��
// ˵����	�л�����ģʽ
LEDNETSDK_API int _CALL_STD set_screen_player_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int player_type);
LEDNETSDK_API int _CALL_STD set_screen_player_type_dwhand(unsigned long dwhand, int player_type);

// ������	set_screen_name
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* controller_name������������
// ˵����	���ÿ���������
LEDNETSDK_API int _CALL_STD set_screen_name(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_name);
LEDNETSDK_API int _CALL_STD set_screen_name_dwhand(unsigned long dwhand, _TEXT_CHAR* controller_name);

// ������	set_screen_timezone
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int timezoneflag: �Ƿ���Զ���ʱ
//			_TEXT_CHAR* timezone��ʱ������׼ʱ����ʽ��
//			_TEXT_CHAR* timezone_server��ʱ����������ַ
//			int timezone_interval��ʱ����ʱ���ʱ��
// ˵����	�����Զ���ʱ
LEDNETSDK_API int _CALL_STD set_screen_timezone(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);
LEDNETSDK_API int _CALL_STD set_screen_timezone_dwhand(unsigned long dwhand, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);

// ������	set_screen_language
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* controller_language����������ʾ����
// ˵����	���ÿ�������ʾ����
LEDNETSDK_API int _CALL_STD set_screen_language(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_language);
LEDNETSDK_API int _CALL_STD set_screen_language_dwhand(unsigned long dwhand, _TEXT_CHAR* controller_language);

// ������	set_serial
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* serial_mode������ģʽ��off �رգ�s1��s2��
//			_TEXT_CHAR* baudrate��������
//			int timeout��ͨѶ��ʱʱ�䣨��λ�����룩
//			_TEXT_CHAR* device_num�����豸��
// ˵����	���ô���
LEDNETSDK_API int _CALL_STD set_serial(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* serial_mode, _TEXT_CHAR* baudrate, int timeout, _TEXT_CHAR* device_num);
LEDNETSDK_API int _CALL_STD set_serial_dwhand(unsigned long dwhand, _TEXT_CHAR* serial_mode, _TEXT_CHAR* baudrate, int timeout, _TEXT_CHAR* device_num);

// ������	get_screen_disk_list
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* storage_media�����صĴ洢�����б�(���ʹ�ö���","����)
// ˵����	��ѯ�洢�����б�
LEDNETSDK_API int _CALL_STD get_screen_disk_list(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD get_screen_disk_list_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

// ������	get_screen_cur_disk
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* storage_media�����صĵ�ǰ�洢����
// ˵����	��ѯ��ǰ�洢����
LEDNETSDK_API int _CALL_STD get_screen_cur_disk(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD get_screen_cur_disk_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

// ������	get_screen_disk_info
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* storage_media��Ҫ��ѯ�Ĵ洢����
//			long long *totalsize��������
//			long long *freesize��ʣ������
//			long long *usedsize����ʹ������
// ˵����	��ѯָ���洢���ʵ�������Ϣ
LEDNETSDK_API int _CALL_STD get_screen_disk_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);
LEDNETSDK_API int _CALL_STD get_screen_disk_info_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);

// ������	set_screen_storage_media
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* storage_media��Ҫ���õĴ洢����
// ˵����	���ô洢����
LEDNETSDK_API int _CALL_STD set_screen_storage_media(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD set_screen_storage_media_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

// ������	get_screen_status
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int* screen_onoff�����ػ�״̬
//			int* brigtness������
//			int* brigtness_mode������ģʽ
//			int* volume������
//			int* screen_lockunlock����Ļ����״̬
//			int* program_lockunlock����Ŀ����״̬
//			int* screen_output_type�����ģʽ
//			int* screen_player_mode������ģʽ
//			_TEXT_CHAR* screen_time��������ʱ��
//			_TEXT_CHAR* screen_addr������������
//			_TEXT_CHAR* screen_customer_onoff����ʱ���ػ�
//			_TEXT_CHAR* screen_language������������
//			_TEXT_CHAR* screen_gps��gps��Ϣ
// ˵����	��ѯ������״̬
LEDNETSDK_API int _CALL_STD get_screen_status(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, int* screen_output_type, int* screen_player_mode, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff, _TEXT_CHAR* screen_language, _TEXT_CHAR* screen_gps);
LEDNETSDK_API int _CALL_STD get_screen_status_dwhand(unsigned long dwhand, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, int* screen_output_type, int* screen_player_mode, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff, _TEXT_CHAR* screen_language, _TEXT_CHAR* screen_gps);

// ������	get_ap_wifi_status
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int* apwifi_onoff��AP WiFi״̬(���� apmute)
// ˵����	��ѯAP WiFi ״̬
LEDNETSDK_API int _CALL_STD get_ap_wifi_status(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* apwifi_onoff);
LEDNETSDK_API int _CALL_STD get_ap_wifi_status_dwhand(unsigned long dwhand, int* apwifi_onoff);

// ������	get_screen_send_program_info
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int* screen_w����Ļ���
//			int* screen_h����Ļ�߶�
//			int* fold_type��������־
//			unsigned short* screen_type��������Ϣ
// ˵����	��ѯ������������Ϣ
LEDNETSDK_API int _CALL_STD get_screen_send_program_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);
LEDNETSDK_API int _CALL_STD get_screen_send_program_info_dwhand(unsigned long dwhand, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);

// ������	get_firmware_version
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* firmware_version���������汾��
//			_TEXT_CHAR* app_version���������汾��
//			_TEXT_CHAR* fpga_version��FPGA�汾��
// ˵����	��ѯ�������汾
LEDNETSDK_API int _CALL_STD get_firmware_version(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);
LEDNETSDK_API int _CALL_STD get_firmware_version_dwhand(unsigned long dwhand, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);

// ������	update_firmware
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* src_path��������·��
//			struct TLSInfo* tls_infos���Ƿ����ز���֤�Ľṹ�壬��û���ز���֤��ʱ�򣬽ṹ����Ը���
// ˵����	��ѯ�������汾
LEDNETSDK_API int _CALL_STD update_firmware(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, struct TLSInfo* tls_infos);
LEDNETSDK_API int _CALL_STD update_firmware_dwhand(unsigned long dwhand,char* ip, unsigned short port, _TEXT_CHAR* src_path, struct TLSInfo* tls_infos);

LEDNETSDK_API unsigned int _CALL_STD net_getcode(char* ip, unsigned short port);

LEDNETSDK_API unsigned long _CALL_STD net_login(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int login_style = 0);
LEDNETSDK_API int _CALL_STD net_logout(unsigned long post);

// ������	set_xser_cmd
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long post����¼��ľ��
//			int cmd�������
//			_TEXT_CHAR* content����������
//			int len�����ݳ���
//			_TEXT_CHAR* recv_data�����յĻذ�����
//			int* recv_cmd���ظ�����
//			int* recv_status���ظ�״̬
//			int* recv_len���������ݳ���
// ˵����	͸���������xser��Ϣ
LEDNETSDK_API int _CALL_STD set_xser_cmd(unsigned long post,int cmd,_TEXT_CHAR* content, int len, _TEXT_CHAR* recv_data, int* recv_cmd, int* recv_status, int* recv_len);

// ������	get_barcode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* barcode����ѯ����������
// ˵����	��ѯ������
LEDNETSDK_API int _CALL_STD get_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD get_barcode_dwhand(unsigned long dwhand, _TEXT_CHAR* barcode);

// ������	get_screen_mac
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* mac����ѯ����MAC
// ˵����	��ѯMAC
LEDNETSDK_API int _CALL_STD get_screen_mac(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* mac);
LEDNETSDK_API int _CALL_STD get_screen_mac_dwhand(unsigned long dwhand, _TEXT_CHAR* mac);

// ������	get_screen_capture
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* file_path�������󱣴��ļ�·��
//			int captureW���������
//			int captureH�������߶�
// ˵����	��Ļ���
LEDNETSDK_API int _CALL_STD get_screen_capture(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* file_path, int captureW, int captureH);
LEDNETSDK_API int _CALL_STD get_screen_capture_dwhand(unsigned long dwhand, _TEXT_CHAR* file_path, int captureW, int captureH);
LEDNETSDK_API int _CALL_STD get_screen_capture_dwhand1(unsigned long dwhand, _TEXT_CHAR* file_path, int captureW, int captureH, int* min_waitTime, int* max_waitTime, _TEXT_CHAR* download_path);

// ������	copy_file
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* file_path�������󱣴��ļ�·��
//			int captureW���������
//			int captureH�������߶�
// ˵����	�����ļ����ӿ�����ָ��·�����Ƶ�������ָ��·����
LEDNETSDK_API int _CALL_STD copy_file_dwhand1(unsigned long dwhand, _TEXT_CHAR* file_path, _TEXT_CHAR* download_path);

// ������	get_screen_log
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* file_path��RPCLog�ļ�·��
//			_TEXT_CHAR* file_path1��RPCLog.1�ļ�·��
// ˵����	��ѯ��������־
LEDNETSDK_API int _CALL_STD get_screen_log(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* file_path, _TEXT_CHAR* file_path1);
LEDNETSDK_API int _CALL_STD get_screen_log_dwhand(unsigned long dwhand, _TEXT_CHAR* file_path, _TEXT_CHAR* file_path1);

// ������	get_screen_folder_files
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* folder_path���ļ���·��(eg: /share)
//			_TEXT_CHAR* files�����ص��ļ����ݣ�base64��
// ˵����	��ѯ������ָ��Ŀ¼�µ������ļ��б�
LEDNETSDK_API int _CALL_STD get_screen_folder_files(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* folder_path, _TEXT_CHAR* files);
LEDNETSDK_API int _CALL_STD get_screen_folder_files_dwhand(unsigned long dwhand, _TEXT_CHAR* folder_path, _TEXT_CHAR* files);
LEDNETSDK_API int _CALL_STD get_screen_folder_files_dwhand1(unsigned long dwhand, _TEXT_CHAR* file_path);

// ������	get_screen_output_type
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int* screen_output_type����ѯ���Ŀ��������ģʽ
// ˵����	��ѯ���������ģʽ
LEDNETSDK_API int _CALL_STD get_screen_output_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_output_type);
LEDNETSDK_API int _CALL_STD get_screen_output_type_dwhand(unsigned long dwhand, int* screen_output_type);

// ������	get_screen_player_mode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int* screen_player_mode����ѯ���Ŀ���������ģʽ
// ˵����	��ѯ����������ģʽ
LEDNETSDK_API int _CALL_STD get_screen_player_mode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_player_mode);
LEDNETSDK_API int _CALL_STD get_screen_player_mode_dwhand(unsigned long dwhand, int* screen_player_mode);

// ������	download_file
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* src_path����Ҫ���ص��ļ�·��
//			_TEXT_CHAR* dest_path��������ļ�·��
// ˵����	����ָ���ļ���ָ��λ��
LEDNETSDK_API int _CALL_STD download_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);
LEDNETSDK_API int _CALL_STD download_file_dwhand(unsigned long dwhand, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);

// ������	upload_file
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* src_path����Ҫ�ϴ����ļ�·��
//			_TEXT_CHAR* dest_file_name���ϴ�����ļ�������������׺
//			struct TLSInfo* tls_infos���ز���֤ʱ�ṹ����
// ˵����	�ϴ�ָ���ļ���ָ��λ��
LEDNETSDK_API int _CALL_STD upload_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_file_name, struct TLSInfo* tls_infos);
LEDNETSDK_API int _CALL_STD upload_file_dwhand(unsigned long dwhand,char* ip, unsigned short port, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_file_name, struct TLSInfo* tls_infos);

// ������	delete_file
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* delete_files����Ҫɾ�����ļ���ʹ�á�;������
// ˵����	ɾ��ָ��λ�õ�ָ���ļ�
LEDNETSDK_API int _CALL_STD delete_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* delete_files);
LEDNETSDK_API int _CALL_STD delete_file_dwhand(unsigned long dwhand, _TEXT_CHAR* delete_files);

// ������	get_screen_player_file
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* program_list�������б��ļ�
//			_TEXT_CHAR* program_name����ǰ���ŵĽ�Ŀ�ļ���
// ˵����	��ȡ�����б��ļ�
LEDNETSDK_API int _CALL_STD get_screen_player_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* program_list, _TEXT_CHAR* program_name);
LEDNETSDK_API int _CALL_STD get_screen_player_file_dwhand(unsigned long dwhand, _TEXT_CHAR* program_list, _TEXT_CHAR* program_name);

// ������	set_screen_prompt_flag
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* prompt_flag����on��������ʾ��Ϣ��Ĭ�ϣ� ��off�����ر���ʾ��Ϣ�����ú���Ҫ�ϵ�������
// ˵����	������Ļ��ʾ��Ϣ��־
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
// ������	query_font
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* fontfile���ֿ��ļ�·��
//			_TEXT_CHAR* fontname���ֿ��ļ���
// ˵����	��ѯ�ֿ�
LEDNETSDK_API int _CALL_STD query_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);
LEDNETSDK_API int _CALL_STD query_font_dwhand(unsigned long dwhand, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);

// ������	install_font
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long font���ֿ��ļ�·�����ļ���
// ˵����	��װ�ֿ�
LEDNETSDK_API int _CALL_STD install_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font, unsigned long tls_font, int* min_waitTime, int* max_waitTime);
LEDNETSDK_API int _CALL_STD install_font_dwhand(unsigned long dwhand, unsigned long font, unsigned long tls_font, int* min_waitTime, int* max_waitTime);

// ������	delete_font
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			_TEXT_CHAR* fontname���ֿ��ļ���
// ˵����	ж���ֿ�
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

// ������	get_sensor_bus
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 _TEXT_CHAR* sensor_bus�������������Ĵ����������б�
// ˵����	��ȡ�����б�
LEDNETSDK_API int _CALL_STD get_sensor_bus(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus);
LEDNETSDK_API int _CALL_STD get_sensor_bus_dwhand(unsigned long dwhand, _TEXT_CHAR* sensor_bus);

// ������	query_seeksensor
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			 _TEXT_CHAR* sensor_bus����Ҫ�����Ĵ����������б���Ϊ*��
//			int* min_waitTime��������С�ȴ�ʱ��
//			int* max_waitTime���������ȴ�ʱ��
// ˵����	����������
LEDNETSDK_API int _CALL_STD query_seeksensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);
LEDNETSDK_API int _CALL_STD query_seeksensor_dwhand(unsigned long dwhand, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);

// ������	get_sensor
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned char* sensors���������б�
//			int* sensors_count������������
// ˵����	��ȡ�������б�
LEDNETSDK_API int _CALL_STD get_sensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned char* sensors, int* sensors_count);
LEDNETSDK_API int _CALL_STD get_sensor_dwhand(unsigned long dwhand, unsigned char* sensors, int* sensors_count);

// ������	set_relay_switch
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			int setOrCancel���󶨻���ȡ��
//			int update_time���������������
//			unsigned long sensors���̵������������
// ˵����	���ü̵������ػ����󶨼̵���/ȡ���󶨼̵�����
LEDNETSDK_API int _CALL_STD set_relay_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int setOrCancel, int update_time, unsigned long sensors);
LEDNETSDK_API int _CALL_STD set_relay_switch_dwhand(unsigned long dwhand, int setOrCancel, int update_time, unsigned long sensors);

// ������	set_screenonoff_switch
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* relay_addr���̵�����ַ
//			int relay_type���̵�������
//			int relay_switch���̵�������
// ˵����	���ü̵������ػ����������󶨼̵�����
LEDNETSDK_API int _CALL_STD set_screenonoff_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
LEDNETSDK_API int _CALL_STD set_screenonoff_switch_dwhand(unsigned long dwhand, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
#pragma endregion sensor

#pragma region dynamic
// ������	update_dynamic
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned long playlist����̬����Ŀ���
//			_TEXT_CHAR* immediately_play������ָ��һ����������ͨ��Ŀ�Ķ�̬��ID��������dynamics�����д��ڵ�id�����øö�̬��������������
//			int conver���Ƿ񸲸���ͨ��Ŀ�����Ƿ�ֻ���Ŷ�̬����"0"����̬������ͨ��Ŀ���沥�ţ�"1"��ֹͣ������ͨ��Ŀ��ֻ���Ŷ�̬����Ŀ
//			int onlyUpdate���Ƿ�ֻ���¶�̬����ֻ���¶�̬��"0"�����ԭ���Ķ�̬�����ٸ��¶�̬��"1"
// ˵����	���¶�̬��
LEDNETSDK_API int _CALL_STD update_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);
LEDNETSDK_API int _CALL_STD update_dynamic_dwhand(unsigned long dwhand, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);

// ������	update_dynamic_small
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned long playlist����̬����Ŀ���
//			_TEXT_CHAR* immediately_play������ָ��һ����������ͨ��Ŀ�Ķ�̬��ID��������dynamics�����д��ڵ�id�����øö�̬��������������
//			int conver���Ƿ񸲸���ͨ��Ŀ�����Ƿ�ֻ���Ŷ�̬����"0"����̬������ͨ��Ŀ���沥�ţ�"1"��ֹͣ������ͨ��Ŀ��ֻ���Ŷ�̬����Ŀ
//			int onlyUpdate���Ƿ�ֻ���¶�̬����ֻ���¶�̬��"0"�����ԭ���Ķ�̬�����ٸ��¶�̬��"1"
// ˵����	���¶�̬�������ٵ�
LEDNETSDK_API int _CALL_STD update_dynamic_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);
LEDNETSDK_API int _CALL_STD update_dynamic_small_dwhand(unsigned long dwhand, unsigned long playlist, _TEXT_CHAR* immediately_play, int conver, int onlyUpdate);

// ������	update_dynamic_unit
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned long playlist����̬����Ŀ���
// ˵����	���¶�̬���ز�
LEDNETSDK_API int _CALL_STD update_dynamic_unit(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
LEDNETSDK_API int _CALL_STD update_dynamic_unit_dwhand(unsigned long dwhand, unsigned long playlist);

// ������	update_dynamic_unit_small
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned long playlist����̬����Ŀ���
// ˵����	���¶�̬���زģ��زĽ�С��ʱ��ʹ��
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small_dwhand(unsigned long dwhand, unsigned long playlist);

// ������	save_dynamic
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			unsigned long playlist����̬����Ŀ���
// ˵����	���涯̬�������籣�棬��Ҫ���������Ҫ����Ķ�̬��ID�ţ��Զ���¼��playlist cpp��
LEDNETSDK_API int _CALL_STD save_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
// ������	save_dynamic_forid
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR*����̬��ID�ţ�����á���������
// ˵����	���涯̬�������籣�棬��Ҫ���������Ҫ����Ķ�̬��ID��
LEDNETSDK_API int _CALL_STD save_dynamic_forid(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* ids);
LEDNETSDK_API int _CALL_STD save_dynamic_dwhand(unsigned long dwhand, unsigned long playlist);

// ������	clear_dynamic
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	������ж�̬��
LEDNETSDK_API int _CALL_STD clear_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_dynamic_dwhand(unsigned long dwhand);

// ������	delete_input_dynamic
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	ɾ��ָ����̬����̬��
LEDNETSDK_API int _CALL_STD delete_input_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* id_list);
LEDNETSDK_API int _CALL_STD delete_input_dynamic_dwhand(unsigned long dwhand, _TEXT_CHAR* id_list);

LEDNETSDK_API int _CALL_STD delete_save_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD delete_save_dynamic_dwhand(unsigned long dwhand);
#pragma endregion dynamic

#pragma region TTS
// ������	active_tts
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
// ˵����	��������
LEDNETSDK_API int _CALL_STD active_tts(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD active_tts_dwhand(unsigned long dwhand);

// ������	add_tts_voice
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned short port���˿�
//			_TEXT_CHAR* user_name����¼��
//			_TEXT_CHAR* user_pwd����¼����
//			_TEXT_CHAR* voice_text����������
//			int loop��ѭ������
//			int gender������/Ů��
//			int effect��������Ч
//			int volume������
//			int tone�����
//			int speed�������ٶ�
//			int one�����ֶ���
//			int stay_time�����ź�Ĭʱ��
// ˵����	�������
LEDNETSDK_API int _CALL_STD add_tts_voice(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* voice_text, int loop, int gender, int effect, int volume, int tone, int speed, int one, int stay_time);
LEDNETSDK_API int _CALL_STD add_tts_voice_dwhand(unsigned long dwhand, _TEXT_CHAR* voice_text, int loop, int gender, int effect, int volume, int tone, int speed, int one, int stay_time);
#pragma endregion TTS

#pragma region JTC
// ������	set_jtc_mode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			int jtc_mode��JT����ģʽ��server1/client0��
//			_TEXT_CHAR* jtc_protocol��JTЭ������
//			_TEXT_CHAR* jtc_device_addr��JT��ַ
//			_TEXT_CHAR* jtc_server_addr: ��������ַ
//			unsigned short jtc_server_port���������˿�
//			_TEXT_CHAR* porter_rate��������
//			int package_size�����ݰ�����
//			jtcproperty
// ˵����	����JT�ͺŵ�����
LEDNETSDK_API int _CALL_STD set_jtc_mode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int jtc_mode, _TEXT_CHAR* jtc_protocol, _TEXT_CHAR* jtc_device_addr, _TEXT_CHAR* jtc_server_addr, unsigned short jtc_server_port, _TEXT_CHAR* porter_rate, int package_size);
LEDNETSDK_API int _CALL_STD set_jtc_mode_dwhand(unsigned long dwhand, int jtc_mode, _TEXT_CHAR* jtc_protocol, _TEXT_CHAR* jtc_device_addr, _TEXT_CHAR* jtc_server_addr, unsigned short jtc_server_port, _TEXT_CHAR* porter_rate, int package_size);
#pragma endregion

#pragma region IO
// ������	set_gp_mode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			int gp_mode��0/off - �رգ�1/discrete - ��һ���ƣ�2/combined - ��Ͽ���(��Ȼ��)��3/gray - ��Ͽ���(������)
// ˵����	IOģʽ�л�
LEDNETSDK_API int _CALL_STD set_gp_mode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int gp_mode);
LEDNETSDK_API int _CALL_STD set_gp_mode_dwhand(unsigned long dwhand, int gp_mode);
#pragma endregion

#pragma region TLS
// ������	set_tls
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			_TEXT_CHAR* src_file��֤���ļ�·��
//			struct TLSInfo* tls_infos��֤��ǩ���Ľṹ�壨����ǩ������/֤��ָ�ƣ�ʹ���ĸ�֤�����ļ���֤ǩ���������Ϣ��
//			_TEXT_CHAR* fingerprint������װ֤���ָ��
//			_TEXT_CHAR* tls_certificate����ADDCERTIFICATE��ǩ�����ݣ�������װ��֤���ǩ����
//			_TEXT_CHAR* add_certificate_type����װ��֤�����ͣ�0ͨѶ����֤��/1�ز�ǩ����֤֤�飩
// ˵����	��װ֤��
LEDNETSDK_API int _CALL_STD set_tls(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_file, struct TLSInfo* tls_infos, _TEXT_CHAR* fingerprint, _TEXT_CHAR* tls_certificate, _TEXT_CHAR* add_certificate_type);
LEDNETSDK_API int _CALL_STD set_tls_dwhand(unsigned long dwhand, char* ip, unsigned short port, _TEXT_CHAR* src_file, struct TLSInfo* tls_infos, _TEXT_CHAR* fingerprint, _TEXT_CHAR* tls_certificate, _TEXT_CHAR* add_certificate_type);

// ������	get_tls_param_dwhand
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned long dwhand����¼�ɹ��󷵻ص�ͨѶ���
//			_TEXT_CHAR* param���ļ���֤���أ�authenticationswitch��
// ˵����	��ȡ��ǰ�������Ƿ����ز�ǩ����֤״̬
LEDNETSDK_API int _CALL_STD get_tls_param_dwhand(unsigned long dwhand, _TEXT_CHAR* param);

// ������	delete_tls
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			_TEXT_CHAR* tls_content��ǩ�����ݣ���DELETECERTIFICATE��ǩ����
//			_TEXT_CHAR* fingerprint��֤��ָ��
//			_TEXT_CHAR* add_certificate_type����װ��֤�����ͣ�0ͨѶ����֤��/1�ز�ǩ����֤֤�飩
// ˵����	ɾ����װ��֤��
LEDNETSDK_API int _CALL_STD delete_tls(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint, _TEXT_CHAR* add_certificate_type);
LEDNETSDK_API int _CALL_STD delete_tls_dwhand(unsigned long dwhand, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint, _TEXT_CHAR* add_certificate_type);

// ������	verify_switch
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			int flag����/�ر�ǩ����֤
//			_TEXT_CHAR* tls_content��ǩ���������
//			_TEXT_CHAR* fingerprint��֤��ָ��
// ˵����	���ز�ǩ����֤
LEDNETSDK_API int _CALL_STD verify_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd ,int flag, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint);
LEDNETSDK_API int _CALL_STD verify_switch_dwhand(unsigned long dwhand, int flag, _TEXT_CHAR* tls_content, _TEXT_CHAR* fingerprint);
#pragma endregion

#pragma region audio
// ������	create_manage_audio
// ����ֵ��	���ش�������Ƶ���
// ������	
// ˵����	������Ƶ������
LEDNETSDK_API unsigned long _CALL_STD create_manage_audio();

// ������	add_manage_audio
// ����ֵ��	
// ������	unsigned long audio����������Ƶ����ľ��
//			_TEXT_CHAR* audio_name����Ƶ����
//			_TEXT_CHAR* audio_path����Ƶ�ļ�·��
// ˵����	�����Ƶ�ļ�
LEDNETSDK_API void _CALL_STD add_manage_audio(unsigned long audio, _TEXT_CHAR* audio_name, _TEXT_CHAR* audio_path);

// ������	delete_add_audio
// ����ֵ��	
// ������	unsigned long audio����������Ƶ����ľ��
//			_TEXT_CHAR* audio_name����Ƶ����
// ˵����	ɾ����Ƶ�ļ�
LEDNETSDK_API void _CALL_STD delete_add_audio(unsigned long audio, _TEXT_CHAR* audio_name);

// ������	delete_create_audio
// ����ֵ��	
// ������	unsigned long audio����������Ƶ����ľ��
// ˵����	ɾ����������Ƶ�������create_manage_audio��Ӧһ��ʹ�ã�
LEDNETSDK_API void _CALL_STD delete_create_audio(unsigned long audio);

// ������	upload_audio_file
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ض�Ӧ�Ĵ����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼���û���
//			_TEXT_CHAR* user_pwd����¼���û�����
//			unsigned long audio����������Ƶ����ľ��
// ˵����	�ϴ���Ƶ�ļ�
LEDNETSDK_API int _CALL_STD upload_audio_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long audio);

// ������	play_audio
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ض�Ӧ�Ĵ����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼���û���
//			_TEXT_CHAR* user_pwd����¼���û�����
//			unsigned long audio����������Ƶ����ľ��
//			int loop_mode����Ƶ�б�ѭ��ģʽ�����Ŵ���������˳��������ӵ���Ƶ�б�Ϊ"0"ʱѭ�����š�����"0"ʱ����ʵ�ʲ��Ŵ�����
// ˵����	������Ƶ
LEDNETSDK_API int _CALL_STD play_audio(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long audio, int loop_mode);

//// ������	stop_play_audio
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ض�Ӧ�Ĵ����
// ������	
//			char* ip��ͨѶIP
//			unsigned short port��ͨѶ�˿�
//			_TEXT_CHAR* user_name����¼���û���
//			_TEXT_CHAR* user_pwd����¼���û�����
// ˵����	ֹͣ������Ƶ
LEDNETSDK_API int _CALL_STD stop_play_audio(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
#pragma endregion audio

#pragma region serial
//// ������	serial_screenonoff
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ض�Ӧ�Ĵ����
// ������	
//			int screen_onoff��1���� 0�ػ�
//			_TEXT_CHAR* json_data�����ص�ͨѶ����
// ˵����	ʹ�ô������ÿ��ػ�
LEDNETSDK_API int _CALL_STD serial_screenonoff(int screen_onoff, _TEXT_CHAR* json_data);
#pragma endregion serial

#pragma region cmd proxy
// ������	set_proxy
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip��������IP
//			unsigned short port���������˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			_TEXT_CHAR* proxy_text��������ģʽ��ز��������ַ�����ʽ����"��"�ָ���˳��д��"proxyproperty"
// ˵����	����Һλ�������������Ժ���кܶ�ģʽ���ã����Խ�setproxy��
LEDNETSDK_API int _CALL_STD set_proxy(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd , _TEXT_CHAR* proxy_text);
LEDNETSDK_API int _CALL_STD set_proxy_dwhand(unsigned long dwhand, _TEXT_CHAR* proxy_text);
#pragma endregion proxy

#pragma region proxy
// ������	Get_Port_Barcode
// ����ֵ��	�ɹ�����ͨѶ�˿ڣ�ʧ�ܷ���-1
// ������	
//			_TEXT_CHAR* pid����ѯ�Ŀ�����������
// ˵����	����ָ�����������ȡͨѶ�˿�
LEDNETSDK_API int _CALL_STD Get_Port_Barcode(_TEXT_CHAR* pid);

// ������	Get_Port_Pid
// ����ֵ��	�ɹ�����ͨѶ�˿ڣ�ʧ�ܷ���-1
// ������	
//			_TEXT_CHAR* pid����ѯ�Ŀ�����PID
// ˵����	����ָ����PID��ȡͨѶ�˿�
LEDNETSDK_API int _CALL_STD Get_Port_Pid(_TEXT_CHAR* pid);

// ������	Start_Native_Server
// ����ֵ��	�ɹ����ؼ�����ľ����ʧ�ܷ���-1
// ������	
//			int port�����������Ķ˿�
// ˵����	��������������
LEDNETSDK_API unsigned long _CALL_STD Start_Native_Server(int port);
// ������	Start_Ssl_Server
// ����ֵ��	�ɹ����ؼ�����ľ����ʧ�ܷ���-1
// ������	
//			int port����ѯ�Ŀ�����IP
//			_TEXT_CHAR* certpath��֤��·��
//			_TEXT_CHAR* keypath��˽Կ·��
// ˵����	��������������������ͨѶ�ģ�
LEDNETSDK_API unsigned long _CALL_STD Start_Ssl_Server(int port, _TEXT_CHAR* certpath, _TEXT_CHAR* keypath);

// ������	Start_Proxy
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	��
// ˵����	
LEDNETSDK_API int _CALL_STD Start_Proxy();

// ������	Stop_Server
// ����ֵ��	��
// ������	
//			unsigned long iServer�������ķ��������
// ˵����	ֹͣ����������
LEDNETSDK_API void _CALL_STD Stop_Server(unsigned long iServer);
#pragma endregion proxy
LEDNETSDK_API int _CALL_STD SearchCards(card_unit *cards);

// ������	get_screeninfo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			int *screen_w����ѯ��������
//			int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type
// ˵����	��ȡ��������������/��/���ͣ�
LEDNETSDK_API int _CALL_STD get_screeninfo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type);

// ������	get_screen_volumn
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			int *volumn����ѯ��������
// ˵����	��ȡ����
LEDNETSDK_API int _CALL_STD get_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int *volumn);

// ������	get_screen_brightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			short* brightness����ѯ��������ֵ����
// ˵����	��ȡ����ֵ
LEDNETSDK_API int _CALL_STD get_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, short* brightness);

// ������	get_screen_onoff
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����ѯ�Ŀ�����IP
//			unsigned short port����ѯ�Ŀ�����Ψ�˿�
//			_TEXT_CHAR* user_name����������¼��
//			_TEXT_CHAR* user_pwd����������¼����
//			int* screen_onoff����ѯ���Ŀ��ػ�״ֵ̬
// ˵����	��ȡ��Ļ���ػ�״̬
LEDNETSDK_API int _CALL_STD get_screen_onoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff);

//����Ľӿڣ�����ֱ��ʹ��set_screen_ip����
LEDNETSDK_API int _CALL_STD set_static_ip(_TEXT_CHAR* barcode,char* ip,char *submark,char *gateway);
//����Ľӿڣ�����ֱ��ʹ��set_screen_auto_ip����
LEDNETSDK_API int _CALL_STD set_auto_ip(_TEXT_CHAR* barcode);
//û�õ�
LEDNETSDK_API int _CALL_STD get_netinfo(char *ip,_TEXT_CHAR* barcode,char* mask,char* gate,int *ipmode);
 #ifdef __cplusplus
}
#endif
#endif
