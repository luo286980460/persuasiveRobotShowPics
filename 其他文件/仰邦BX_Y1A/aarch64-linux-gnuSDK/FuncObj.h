#pragma once
#ifndef _FUNCOBJ_H
#define _FUNCOBJ_H
#pragma pack (push,1)

struct WifiListData
{
	int is_connect;
	int wifi_signal;
	_TEXT_CHAR ssid[64];
};

struct ControllerData
{
	int is_dhcp;
	int wifi_is_dhcp;
	int output_type;
	int port;
	int screen_w;
	int screen_h;
	int screen_volume;
	int screen_brigtness;
	int screen_brigtness_mode;
	int screen_rotation;
	int screen_file_verify_switch;
	unsigned short screen_type;
	_TEXT_CHAR storagemedia[10];
	_TEXT_CHAR barcode[17];
	_TEXT_CHAR ip[20];
	_TEXT_CHAR source_ip[20];
	_TEXT_CHAR sub_mark[20];
	_TEXT_CHAR gateway[20];
	_TEXT_CHAR mac[20];
	_TEXT_CHAR local_ip[20];
	_TEXT_CHAR pid[33];
	_TEXT_CHAR local_net[64];
	_TEXT_CHAR ap_wifi_ip[20];
	_TEXT_CHAR wifi_ip[20];
	_TEXT_CHAR wifi_sub_mark[20];
	_TEXT_CHAR wifi_gateway[20];
	_TEXT_CHAR dns_server[20];
	_TEXT_CHAR network_device[20];
	_TEXT_CHAR network_mode[20];
	_TEXT_CHAR controller_name[128];
};

struct ControllerInfo
{
	int is_dhcp;
	int wifi_is_dhcp;
	int output_type;
	int port;
	int screen_w;
	int screen_h;
	int screen_volume;
	int screen_brigtness;
	int screen_brigtness_mode;
	int fold_type;
	int fold_count;
	int logic_width;
	int logic_height;
	int screen_rotation;
	int timezone_flag;
	int screen_file_verify_switch;
	unsigned short screen_type;
	_TEXT_CHAR storagemedia[10];
	_TEXT_CHAR barcode[17];
	_TEXT_CHAR ip[20];
	_TEXT_CHAR source_ip[20];
	_TEXT_CHAR sub_mark[20];
	_TEXT_CHAR gateway[20];
	_TEXT_CHAR mac[20];
	_TEXT_CHAR local_ip[20];
	_TEXT_CHAR pid[33];
	_TEXT_CHAR local_net[64];
	_TEXT_CHAR ap_wifi_ip[20];
	_TEXT_CHAR wifi_ip[20];
	_TEXT_CHAR wifi_sub_mark[20];
	_TEXT_CHAR wifi_gateway[20];
	_TEXT_CHAR dns_server[20];
	_TEXT_CHAR network_device[20];
	_TEXT_CHAR network_mode[20];
	_TEXT_CHAR controller_name[128];
	_TEXT_CHAR fold_width[128];
	_TEXT_CHAR fold_height[128];
	_TEXT_CHAR timezone[128];
	_TEXT_CHAR timezone_server[128];
};

struct ControllerSensor
{
	float sensor_value;
	_TEXT_CHAR sensor_sequence[20];
	_TEXT_CHAR sensor_state[20];
	_TEXT_CHAR sensor_address[20];
};

struct DatabaseUnitInfo
{
	int				unit_order;
	_TEXT_CHAR*		bgImage;
	int				pageStayTime;
	int				updateEmptyData;
	_TEXT_CHAR*		dbType;
	_TEXT_CHAR*		host;
	int				port;
	_TEXT_CHAR* 	instance;
	_TEXT_CHAR* 	user;
	_TEXT_CHAR* 	password;
	_TEXT_CHAR* 	dbName;
	_TEXT_CHAR* 	queryCommand;
	_TEXT_CHAR* 	oddLinesBgColor;
	_TEXT_CHAR* 	evenLinesBgColor;
	_TEXT_CHAR* 	oddLinesFontColor;
	_TEXT_CHAR* 	evenLinesFontColor;
	_TEXT_CHAR* 	fontName;
	int				fontSize;
	_TEXT_CHAR* 	fontSizeType;
	_TEXT_CHAR* 	fontAttributes;
	_TEXT_CHAR* 	alignment_H;
	_TEXT_CHAR* 	alignment_V;
	int				autoLF;
	int				rowToColumn;
	int				displayFieldName;
	int				paintTable;
	int				tableLineWidth;
	_TEXT_CHAR* 	tableLinear;
	_TEXT_CHAR* 	tableLineColor;
	int				displayRows;
	int				displayColumns;
	_TEXT_CHAR* 	tableName;
};

struct SpecifyColumn
{
	int				column;
	int				columnWidth;
	_TEXT_CHAR* 	bgColor;
	_TEXT_CHAR* 	fontName;
	_TEXT_CHAR* 	fontColor;
	int				fontSize;
	_TEXT_CHAR* 	fontSizeType;
	_TEXT_CHAR* 	fontAttributes;
	_TEXT_CHAR* 	alignment_H;
	_TEXT_CHAR* 	alignment_V;
	int				autoLF;
};
struct SpecifyRow
{
	int				row;
	int				rowHeight;
	_TEXT_CHAR* 	bgColor;
	_TEXT_CHAR* 	fontName;
	_TEXT_CHAR* 	fontColor;
	int				fontSize;
	_TEXT_CHAR* 	fontSizeType;
	_TEXT_CHAR* 	fontAttributes;
	_TEXT_CHAR* 	alignment_H;
	_TEXT_CHAR* 	alignment_V;
	int				autoLF;
};
struct SpecifyCell
{
	int				row;
	int				column;
	_TEXT_CHAR* 	content;
	_TEXT_CHAR* 	bgColor;
	_TEXT_CHAR* 	fontName;
	_TEXT_CHAR* 	fontColor;
	int				fontSize;
	_TEXT_CHAR* 	fontSizeType;
	_TEXT_CHAR* 	fontAttributes;
	_TEXT_CHAR* 	alignment_H;
	_TEXT_CHAR* 	alignment_V;
	int				autoLF;
};
struct TLSInfo
{
	int				offset;
	int				len;
	_TEXT_CHAR*		fingerprint;
	_TEXT_CHAR*		sign;
	_TEXT_CHAR*		digest;
};

#pragma pack(pop)
#endif
