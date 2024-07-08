#include "stdafx.h"
#include "Send_Program.h"

//����ͼƬ
void Send_ProgramPictures()
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
	_TEXT_CHAR* content=_TEXT_T("test.bmp");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    //ͼƬ
    DWORD pic_area = create_pic();

    //ͼԪ
    int err = add_pic_unit(pic_area, 0, 0, 16, content);
    //ͼƬ����
    err = add_pic(program, pic_area, 0, 0, 64,32, 100);
    delete_pic(pic_area);
					
	CString str1,str2,str3,str4;
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�ĿͼƬ�ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�ĿͼƬʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//������Ļ
void Program_str()
{
    char* ip = "192.168.89.183";
	unsigned short port=80;
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	 _TEXT_CHAR controller_name[128]=_TEXT_T("");
	unsigned long playlist=create_playlist(64, 32,11608);

	_TEXT_CHAR* name=_TEXT_T("program_1");
	unsigned long program=create_program(name,_TEXT_T("0xff000000")); 

	_TEXT_CHAR* font_name=_TEXT_T("SimSun"); 
	_TEXT_CHAR* font_attributes=_TEXT_T("normal");
	_TEXT_CHAR* font_alignment=_TEXT_T("0");
	_TEXT_CHAR font_color[20]=_TEXT_T("0xffff0000");
	_TEXT_CHAR bg_color[20]=_TEXT_T("0xff000000"); 
	_TEXT_CHAR* content=_TEXT_T("��ʾ����test");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    
    DWORD area_tree = create_text();

    int err = add_text_unit_text(area_tree, 10, 16, font_name, 12, font_attributes, font_alignment, font_color, bg_color, content);
    err = add_text(program, area_tree, 0, 0, 64, 32, 100, 0, 1);
    delete_text(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ��Ļ�ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ��Ļʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//������Ļ-���ı�
void Program_str_line()
{
    char* ip = "192.168.89.183";
	unsigned short port=80;
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	 _TEXT_CHAR controller_name[128]=_TEXT_T("");
	unsigned long playlist=create_playlist(64, 32,11608);

	_TEXT_CHAR* name=_TEXT_T("program_1");
	unsigned long program=create_program(name,_TEXT_T("0xff000000")); 

	_TEXT_CHAR* font_name=_TEXT_T("SimSun"); 
	_TEXT_CHAR* font_attributes=_TEXT_T("normal");
	_TEXT_CHAR* font_alignment=_TEXT_T("0");
	_TEXT_CHAR font_color[20]=_TEXT_T("0xffff0000");
	_TEXT_CHAR bg_color[20]=_TEXT_T("0xff000000"); 
	_TEXT_CHAR* content=_TEXT_T("<span foreground='blue' font='10'>test</span><span foreground='red' font='10'>����</span>");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    
    DWORD area_tree = create_rich_text();

    int err = add_rich_text_unit(area_tree, 10, 16, _TEXT_T(""), bg_color, content);
    err = add_rich_text(program, area_tree, 0, 0, 64, 32, 100, 0, 0);
    delete_rich_text(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	cout<<"add_program_in_playlist:"<<err<<endl;
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ���ı��ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ���ı�ʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//����ʱ��
void Program_time()
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
	_TEXT_CHAR* content=_TEXT_T("%Y��%m��%d��");//����%w %Hʱ%M��%S�� ��ͨ�ַ���
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
	_TEXT_CHAR* time_equation =_TEXT_T("1:0:00");
	_TEXT_CHAR* positive_te =_TEXT_T("true"); 
	_TEXT_CHAR* adjustment =_TEXT_T("+00:00:00:00");//���Ե���ʱ�֧����������ʽ����dd:hh:mm:ss��
    
    DWORD area_tree = create_time();

    int err = add_time_unit(area_tree, content, font_color, font_name, 12, 0, 16, font_attributes);
    err = add_time(program, area_tree, 0, 0, 64, 32, 100, bg_color, time_equation, positive_te,adjustment);
    delete_time(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	cout<<"add_program_in_playlist:"<<err<<endl;
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ��Ļ�ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ��Ļʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//���ͱ��� 
void Program_clock()
{
    int err = 0;
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
	_TEXT_CHAR* content=_TEXT_T(".\\clock\\1.png");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    
    DWORD area_tree = create_clock();
	_TEXT_CHAR hour_color[20]=_TEXT_T("0xFFFF0000"); 
	_TEXT_CHAR minute_color[20]=_TEXT_T("0xFFFFFF00");
	_TEXT_CHAR second_color[20]=_TEXT_T("0xFF00FF00");
    ////ʱ��
    err = add_clock_hour(area_tree, _TEXT_T(""), hour_color, 12, 2);
    //����
    err = add_clock_minute(area_tree, _TEXT_T(""), minute_color, 10, 1);
    //����
    err = add_clock_second(area_tree, _TEXT_T(""), second_color, 8, 1);
	_TEXT_CHAR* time_equation =_TEXT_T("00:00:00");//ʱ���ʽ��hh:mm:ss��
    _TEXT_CHAR*  positive_te = _TEXT_T("true");//������ʱ���true������false��
	_TEXT_CHAR* adjustment =_TEXT_T("00:00:00");//���Ե���ʱ�֧����������ʽ����dd:hh:mm:ss��
    err = add_clock(program, area_tree, 0, 0, 64, 32, 100, time_equation, positive_te,adjustment, hour_color, minute_color, second_color, content);
    delete_clock(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	cout<<"add_program_in_playlist:"<<err<<endl;
	long long  free_size=0, total_size=0;
	int send_style=0;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ���� �ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ���� ʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//������Ƶ
void Program_video()
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
	_TEXT_CHAR* content=_TEXT_T("test.mp4");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    
    DWORD area_tree = create_video();

    int err = add_video_unit(area_tree, 2, 1, 0, 1000, content, _TEXT_T(""));
    err = add_video(program, area_tree, 0, 0, 64, 32, 0, 0, 0, _TEXT_T(""), _TEXT_T(""));
    delete_video(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ��Ƶ�ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ��Ƶʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//����ũ��
void Program_calendar()
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
	_TEXT_CHAR* content=_TEXT_T("��ʾ����test");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    
    DWORD area_tree = create_calendar();
	
	_TEXT_CHAR* mode=_TEXT_T("heavenlystem"); //lunarcalendar   solarterms   text
    int err = add_calendar_unit(area_tree, mode, font_color, font_name, 10, 0, 16, font_attributes, content);
	_TEXT_CHAR* time_equation =_TEXT_T("00:00:00");//ʱ���ʽ��hh:mm:ss��
    _TEXT_CHAR*  positive_te = _TEXT_T("true");//������ʱ���true������false��
	_TEXT_CHAR* adjustment =_TEXT_T("+00:00:00:00");//���Ե���ʱ�֧����������ʽ����dd:hh:mm:ss��
    err = add_calendar(program, area_tree, 0, 0, 64, 32, 100, bg_color, time_equation, positive_te,adjustment);
    delete_calendar(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀũ���ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀũ��ʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//�����Ų���
void Send_ProgramColorStr()
{
	int err=0;
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
	_TEXT_CHAR* content=_TEXT_T("<span foreground='blue' font='10'>test</span><span foreground='red' font='10'>����</span>");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    
    DWORD area_tree = create_colortext();
	_TEXT_CHAR* colorstr=_TEXT_T("colorstr.png"); 
    add_colorful_fontunit(area_tree, colorstr, 0, 16, 5, 0, 16, 1, 50);
	_TEXT_CHAR* bgcolor=_TEXT_T("bgcolor.png"); 
    add_colorful_hollowunit(area_tree, 5, 5, 0, bgcolor);
    add_colorful_subtitle(program, area_tree, 0, 0, 64, 32);
    delete_colortext(area_tree);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ�Ų��ֳɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ�Ų���ʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}

//���ͼ�ʱ
void Program_count()
{
	int err=0;
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
	_TEXT_CHAR* content=_TEXT_T("dd��hhʱmm��ss��");
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
	_TEXT_CHAR* time_equation =_TEXT_T("00:00:00");
	_TEXT_CHAR* positive_te =_TEXT_T("end"); 
    
    int font_size = 12;
    int content_x = 0;
    int content_y = 16;
    _TEXT_CHAR* add_enable = _TEXT_T("yes");
    _TEXT_CHAR* target_date = _TEXT_T("2021-12-30");
    _TEXT_CHAR* target_time = _TEXT_T("12:00:00");

    err = add_count(program, 0, 0, 64, 32, 100, bg_color, time_equation, positive_te,target_date, target_time, content, font_color, font_name, font_size, content_x, content_y, font_attributes, add_enable);
					
	_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
	_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
	int play_time=1;
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // ɾ���ļ�����ֻ���·���ִ�
	//CString str_url = szFilePath;
	
    err = add_program_in_playlist(playlist, program, 0, 10,aging_start_time,aging_end_time, period_ontime,period_offtime,127);
	cout<<"add_program_in_playlist:"<<err<<endl;
	long long  free_size=0, total_size=0;
	int send_style=0;
    err = send_program(ip, port, user_name, user_pwd, szFilePath, playlist, send_style, &free_size, &total_size);

    if (err == 0)
    {
		cout<<"���½�Ŀ��Ļ�ɹ�"<<err<<endl;
    }
    else
    {
		cout<<"���½�Ŀ��Ļʧ�ܣ�������:"<<err<<endl;
    }
	delete_playlist(playlist);
}