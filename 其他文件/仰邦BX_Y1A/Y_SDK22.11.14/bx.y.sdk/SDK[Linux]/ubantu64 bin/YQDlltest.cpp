
//#include "stdafx.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include "YQNetCom.h"
using namespace std;
int main()
{	
	int card_count=0;
	unsigned char cards[4094];
	unsigned short port=80;
	char *ip="192.168.3.103";

	_TEXT_CHAR* user_name="guest",*user_pwd="guest";
	/*char *ip="192.168.3.101";
	unsigned short pcport=8001,cardport=6005;
	unsigned short port=0;
	_TEXT_CHAR *pid="50C811344D45594D411000002F31EE12",*barcode="";
	int server_mode=1;
	int sss=set_screen_server(barcode, pid,"192.168.3.101 ",6005,server_mode);
        cout<<"set_screen_server=="<<sss<<endl;
	 Start_PcClient(ip,pcport);
	 while(1)
	   {
	    	sleep(2);	
	     	port=Get_Port_Pid(pid);
			cout<<"Get_Port_Pid===="<<port<<endl;
	    	if (port>0)
	    	{
			break;
		   }
	  }*/
	card_unit cardcount[10];
	int ret=SearchCards(cardcount);
	cout<<"SearchCards=="<<cardcount[0].barcode<<endl;
	//搜索
	//  int result=search_card(cards,&card_count);
	 // cout<<"card_count=="<<card_count<<endl;
	 int volumn=0;
	  ret=get_screen_volumn(ip,port,user_name,user_pwd,&volumn);
	 cout<<"volumn=="<<volumn<<endl;
	//1.设置控制器IP地址(已测)
	/*  char *newip="192.168.3.105",*dns_server="";
	 _TEXT_CHAR* barcode="C0Y3001804250075",*pid="50C811344D45594D411000002F31EE12",*submark="255.255.255.0",*gateway="192.168.3.1";
	    int min_waitTime,max_waitTime;
           int ssi=set_screen_ip(barcode,pid,newip,submark,gateway,dns_server,&min_waitTime,&max_waitTime);
          cout<<"set_screen_ip=="<<ssi<<endl;*/
        //2.自动获取IP地址(已测)
	/*  _TEXT_CHAR* barcode="C0Y3001804250075",*pid="50C811344D45594D411000002F31EE12";
	   int min_waitTime,max_waitTime;
	  int ssai=set_screen_auto_ip(barcode,pid,&min_waitTime,&max_waitTime);
	  cout<<"set_screen_auto_ip=="<<ssai<<endl;*/
	//4.设置控制器MAC地址(已测)
	 /*      char barcode[20]="C0Y3001804250075";
	      char mac[20]="02:FF:FF:BF:F8:9B";
	      char pid[35]="50C811344D45594D411000002F31EE12";
	      int min_waitTime=0,max_waitTime=0;
	      int ssm=set_screen_mac(barcode,pid,mac,&min_waitTime,&max_waitTime);
	      cout<<"set_screen_mac=="<<ssm<<endl;*/
	 //3.获取MAC地址(已测)
	  /*  char mac[20];
	    int gsm=get_screen_mac(ip, port,user_name,user_pwd,mac);
	     cout<<"get_screen_mac=="<<gsm<<endl;
	    cout<<"get_screen_mac=="<<mac<<endl;*/
	//4.设置barcode(已测)
	 /*    char barcode[20]="C0Y3001804250075";
	    int sb=set_screen_barcode(ip,port,user_name,user_pwd,barcode);
	    cout<<"screen_barcode=="<<sb<<endl;*/
	//5.获取Barcode(目前Barcode为空)(已测)
	 /*    char barcode[20];
	     int Barcode=get_barcode(ip,port,user_name,user_pwd,barcode);
	    cout<<"get_barcode=="<<Barcode<<endl;
	    cout<<"barcode=="<<barcode<<endl;*/
	 //6.设置音量（已测）
	  /*   int volumn=88;
	     int sv=set_screen_volumn(ip,port,user_name,user_pwd,volumn);
	     cout<<"screen_volumn=="<<sv<<endl;*/
	 //7.校时(已测)
	   /*   int b=check_time(ip,port,user_name,user_pwd);
              cout<<"check_time=="<<b<<endl;*/
	//8.重起app固件(已测)
	//    int ra=restart_app(ip,port,user_name,user_pwd);
	//   cout<<"restart=="<<ra<<endl;
         //9.重起系统(已测)
	 //   int r=reboot(ip,port,user_name,user_pwd);
	 //  cout<<"reboot=="<<r<<endl;
        /*******************************************************/
	// 1.设置亮度(已测)
	/*   int brightness=100;
	   int sb=set_screen_brightness(ip,port,user_name,user_pwd,brightness);
	   cout<<"screen_brightness=="<<sb<<endl;*/
	//2.自动调亮
	/*  int data_count=48;
	  int brightness[48]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,1,1,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
	  int sab=set_screen_auto_brightness(ip,port,user_name,user_pwd,brightness,data_count);
	  cout<<"screen_auto_brightness=="<<sab<<endl;*/
	//3.调亮(已测)(每次要传48个值)
	/*  int data_count=48;
	  short brightness[48]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,1,1,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
          int scb=set_screen_cus_brightness(ip,port,user_name,user_pwd,brightness,data_count);
	  cout<<"screen_cus_brightness=="<<scb<<endl;*/
	/******************目前无法测试************************/
	 //1.锁屏(已测)
	/*    int lock=0;
	    int sl=lock_screen(ip,port,user_name,user_pwd,lock);
	    if(lock==1)
	       cout<<"锁屏"<<endl;
            else
	       cout<<"开屏"<<endl;
	   cout<<"screen_lock=="<<sl<<endl;
	    //2屏的状态(screen_status)
	    int screen_onoff,brigtness,brigtness_mode,volume,screen_lockunlock,program_lockunlock;
	    char screen_time[30],screen_addr[30];
	    int ss= get_screen_status(ip,port,user_name,user_pwd,&screen_onoff,&brigtness,&brigtness_mode,&volume,&screen_lockunlock,&program_lockunlock,screen_time,screen_addr);
	    cout<<"screen_status=="<<ss<<endl;
	    cout<<"screen_lockunlock=="<<screen_lockunlock<<endl;
	    cout<<"program_lockunlock=="<<program_lockunlock<<endl;
	   cout<<"screen_time=="<<screen_time<<endl;  */                                                                                                                                                    
	 //3.固件升级
	  /* _TEXT_CHAR* src_path="/home/fantx/0704/Properties/BX-Y3_upgrade_V18062500.bxf";
	  int fu=update_firmware(ip,port,user_name,user_pwd,src_path);
	  cout<<"update_firmware=="<<fu<<endl;*/
        //4固件版本查询(已测)
	/*   char firmware_version[20],app_version[20],fpga_version[20];
	   int fv=get_firmware_version(ip,port,user_name,user_pwd,firmware_version,app_version,fpga_version);
	   cout<<"get_firmware_version=="<<fv<<endl;
	   cout<<"firmware_version=="<<firmware_version<<endl;
	   cout<<"app_version=="<<app_version<<endl;
	   cout<<"fpga_version=="<<fpga_version<<endl;*/
	 //1.设置screen_ip_flag
	 /*  int flag=1;
	   int sif=set_screen_ip_flag(ip,port,user_name,user_pwd,flag);
	  cout<<"screen_ip_flag=="<<sif<<endl;*/
	 //2.设置screen_timezone
	 /*  int timezoneflag=1,timezone_interval=60;
	  char* timezone="GMT-12",*timezone_server="time.nist.gov";
	  int st=set_screen_timezone(ip,port,user_name,user_pwd,timezoneflag,timezone,timezone_server,timezone_interval);
	   cout<<"screen_timezone=="<<st<<endl;*/
	 //1.清理素材
	 /*   int cm=clear_material(ip,port,user_name,user_pwd);
	   cout<<"clear_material=="<<cm<<endl;*/
       /*************************************************/
	//1.开关机(已测)0 关机 1开机
	/*      int turnonoff_status=0 ;
             int st=set_screen_turnonoff(ip,port,user_name,user_pwd,turnonoff_status);
             cout<<"screen_turnonoff=="<<st<<endl;
             sleep(5);
	     turnonoff_status=1;
	     st=set_screen_turnonoff(ip,port,user_name,user_pwd,turnonoff_status);
	     cout<<"screen_turnonoff=="<<st<<endl; */ 
	//2.定时开关机(已测)(turnonoff为句柄可多次添加)
	/*    unsigned long turnonoff= create_turnonoff();
	    int action1=0;
 	    char time1[20]="16:24:00";
	    int action2=1;
	    char time2[20]="16:25:00";
	    add_turnonoff(turnonoff,action1,time1);
	    add_turnonoff(turnonoff,action2,time2);
            int sct=set_screen_cus_turnonoff(ip,port,user_name,user_pwd,turnonoff);
	    cout<<"screen_cus_turnonoff=="<<sct<<endl;
	    //设置完成销毁句柄 
	 //   delete_turnonoff(turnonoff);
	
	 //3取消定时开关机(已测)
          int csct=cancel_screen_cus_turnonoff(ip,port,user_name,user_pwd);
	   cout<<"cancel_screen_cus_turnonoff=="<<csct<<endl;*/
	 //4.set_screen_led_flag
	  /*   int flag=0;
	     int ssf=set_screen_led_flag(ip,port,user_name,user_pwd,flag);
	     cout<<"set_screen_led_flag=="<<ssf<<endl;*/
	//5.设置屏幕logo(screen_logo)(已测)(必须为.bon文件)
	 /*  int  flag=1;
	    int screen_w=128, screen_h=96;
	   _TEXT_CHAR* src_path="/home/fantx/YQNetCom/Properties/logo.bon";
	   int sl=set_screen_logo(ip,port,user_name,user_pwd,flag,screen_w, screen_h,src_path);
	   cout<<"screen_logo=="<<sl<<endl;*/
	/***********************************************/
	 //3.设置输出方式(目前不支持)
	 //    int  output_type=0;
	 //    int sot=set_screen_output_type(ip,port,user_name,user_pwd,output_type);
	 //   cout<<"screen_output_type=="<<sot<<endl;
	//4.设置控制器名称
	 //  _TEXT_CHAR* controller_name="BY-Y3";
	 // int sn=set_screen_name(ip,port,user_name,user_pwd,controller_name);
	 // cout<<"screen_name=="<<sn<<endl;
        /*********************************************/
	//10.设置屏参(已测)
	/*    int screen_w=128,screen_h=96;
           int ss=set_screen_size(ip,port,user_name,user_pwd,screen_w,screen_h);
	   cout<<"screen_size=="<<ss<<endl;*/
	//11.查询通用属性
 	/*int screen_parameter= get_screen_parameters(ip,port,user_name,user_pwd,cards);
	cout<<"screen_parameters=="<<screen_parameter<<endl;*/
	//12.切换存储介质
	/*  char *storage_media="usb1";
	  int sssm=set_screen_storage_media(ip,port,user_name,user_pwd,storage_media);
	  cout<<"set_screen_storage_media=="<<sssm<<endl;*/
	/******************发送图片*******************/
       /*  int w=128,h=96 ,device_type=9048;
	 unsigned long  play_list=create_playlist(w,h,device_type);
	 _TEXT_CHAR* name="project-1";
	 unsigned long  program=create_program(name);
	unsigned long pic_area=create_pic();
	int  stay_time=0,display_effects=1,display_speed=16;
	 _TEXT_CHAR* path="/home/fantx/YQNetCom/Properties/d.jpg";
	 int apu=add_pic_unit(pic_area,stay_time,display_effects,display_speed,path);
	 cout<<"add_pic_unit=="<<apu<<endl;
	int x=0,y=0,transparency=100;
        int ap=add_pic(program,pic_area, x, y,w, h,transparency);
	cout<<"add_pic=="<<ap<<endl;
	int play_mode=1,play_week=127,play_time=1;
	_TEXT_CHAR* aging_start_time="",*aging_end_time="",*period_ontime="",*period_offtime="";
	int  pap=add_program_in_playlist(play_list,program,play_mode,play_time, aging_start_time,aging_end_time,period_ontime, period_offtime, play_week);
	cout<<"playlist_add_program=="<<pap<<endl;
	_TEXT_CHAR* tmp_path="/home/fantx/YQNetCom/Properties";
	int send_style=0;
	long long free_size,total_size;
	//cancel_send_program(play_list);
	int sp=send_program(ip,port,user_name,user_pwd,tmp_path,play_list,send_style,&free_size,&total_size);
	cout<<"send_program=="<<sp<<endl;*/
	//发送完节目销毁句柄
	//delete_playlist(play_list);
	/**************播放视频*******************/
	/* int w=128,h=96,device_type=9048;
	 // int w=1280,h=1024,device_type=9048;
	 unsigned long  play_list=create_playlist(w,h,device_type);
	 _TEXT_CHAR* name="project-1";
	 unsigned long  program=create_program(name);
         unsigned long video_area=create_video();

	 int volume=100,scale_mode=1,source=0,play_time=1800;
	 _TEXT_CHAR* path="/home/fantx/YQNetCom/Properties/dt.avi";
         int avu1=add_video_unit(video_area,volume,scale_mode,source,play_time,path);
	 cout<<"add_video_unit=="<<avu1<<endl;
	 int x=0,y=0,volume_mode=0,video_type=0;
	 int ad=add_video(program,video_area,x,y,w,h,volume_mode,video_type);

	int play_mode=1,play_week=127;
	_TEXT_CHAR* aging_start_time="",*aging_end_time="",*period_ontime="",*period_offtime="";
	int  pap=add_program_in_playlist(play_list,program,play_mode,play_time, aging_start_time,aging_end_time,period_ontime, period_offtime, play_week);
	cout<<"playlist_add_program=="<<pap<<endl;
	_TEXT_CHAR* tmp_path="/home/fantx/YQNetCom/Properties";
	int send_style=0;
	long long free_size,total_size;
	int sp=send_program(ip,port,user_name,user_pwd,tmp_path,play_list,send_style,&free_size,&total_size);
	cout<<"send_program=="<<sp<<endl;*/
	//发送完节目销毁句柄
	//delete_playlist(play_list);
	/********************************************/  
	/********************发送时间****************/
	/* int w=128,h=96,device_type=9048;
	 unsigned long  play_list=create_playlist(w,h,device_type);
	 _TEXT_CHAR* name="program_1";
	 unsigned long  program=create_program(name);*/
        /********数字**********/
	/*  int x1=8,y1=38,transparency1=100,time_mode1=0,font_size1=12;
	 int w1=113,h1=64;
	 unsigned long time_area1=create_time();
	 char *bg_color1="0x00000000",*time_equation1="0:0:00",*positive_te1="+",*content1="%H时%M分%S秒",*unit_color1="0Xffffffff",*font_name1="宋体  ",*font_attributes="bold";
	 int atu=add_time_unit(time_area1,content1,unit_color1,font_name1,font_size1,x1,y1,font_attributes);
	cout<<"add_time_unit=="<<atu<<endl;
         int at=add_time(program,time_area1,x1,y1,w1,h1,transparency1,bg_color1,time_equation1,positive_te1);
	cout<<"add_time=="<<at<<endl;*/
	/********表盘**********/
	/* int x=0,y=0,transparency=100;
	 w=96,h=96;
	char *time_equation="0:0:00",*positive_te="-",*hour_color="0xFFFFFF00",*minute_color="0xFF00FF00",*second_color="0xFFFF0000",*bg_image="/home/fantx/YQNetCom0425/Properties/clock/13.png";
	int ac=add_clock(program,x,y,w,h,transparency,time_equation,positive_te,hour_color, minute_color,second_color,bg_image);
	cout<<"add_clock=="<<ac<<endl;*/
	////////////////////////////////
        /**********计时分区**********///过去开始 未来结束
	/* int x1=2,y1=0,transparency=100,font_size=12,content_x=3, content_y=37;
	 int w1=97,h1=64;
	char*bg_color="0x00",*time_equation="",*target_type="end",*target_date="2018-07-20",*target_time="23:59:00",
	*content="dd天hh时mm分ss秒",*digital_color="0xFFFFFFFF",*font_color="0xFFFFFFFF",*font_name="simsun",*font_attributes="bold";
	int ac=add_count(program,x1,y1,w1,h1,transparency,bg_color,time_equation,target_type,target_date,target_time,content,font_color,font_name,font_size,content_x,content_y,font_attributes);
	 cout<<"add_count=="<<ac<<endl;*/
	  /////////////////////////////
	/*************农历**************************/
	/* int x=17,y=7,font_size=12,transparency=100;
	 w=91,h=70;
	unsigned long calendar_area=create_calendar();
	char* content1="heavenlystem",* color="0xFFFFFFFF", *font_name="simsun",*font_attributes="normal",*text_content="";
	int x_1=14,y_1=17;
	 int acu1=add_calendar_unit(calendar_area,content1,color,font_name,font_size,x_1,y_1,font_attributes,text_content);
	cout<<"add_calendar_unit=="<<acu1<<endl;
	char *content2="lunarcalendar";
	 int x_2=10,y_2=40;
	  int acu2=add_calendar_unit(calendar_area,content2,color,font_name,font_size,x_2,y_2,font_attributes,text_content);
	 cout<<"add_calendar_unit=="<<acu2<<endl;  
	 char *content3="solarterms";
	 int x_3=6,y_3=63;
	 int acu3=add_calendar_unit(calendar_area,content3,color,font_name,font_size,x_3,y_3,font_attributes,text_content);
	cout<<"add_calendar_unit=="<<acu3<<endl;
	char* bg_color="0x00000000",* time_equation="0:0:00",*positive_te="+";
	 int ac=add_calendar(program,calendar_area,x,y,w,h,transparency,bg_color,time_equation,positive_te);
	 cout<<"add_calendar=="<<ac<<endl;*/
        //////////////////////////////////////
	/*int play_mode=1,play_week=127,play_time=1;
	_TEXT_CHAR* aging_start_time="",*aging_end_time="",*period_ontime="",*period_offtime="";
	int  pap=add_program_in_playlist(play_list,program,play_mode,play_time, aging_start_time,aging_end_time,period_ontime, period_offtime, play_week);
	cout<<"playlist_add_program=="<<pap<<endl;
	_TEXT_CHAR* tmp_path="/home/fantx/YQNetCom/Properties";
	int send_style=0;
	//是否锁定节目
	//int flag=0;
     	//int lp=lock_program(ip,port,user_name,user_pwd,flag,name); 
     	//cout<<"lock_program=="<<lp<<endl;
	long long free_size,total_size;
	int sp=send_program(ip,port,user_name,user_pwd,tmp_path,play_list,send_style,&free_size,&total_size);
	cout<<"send_program=="<<sp<<endl;*/
	//发送完节目销毁句柄
	//delete_playlist(play_list);
     ////////////////////////////////////////////////////////////
     	 //1.锁屏(已测)
	 /*    int lock=1;
	    if(lock==1)
	       cout<<"锁屏"<<endl;
            else
	       cout<<"开屏"<<endl;
	    int sl=lock_screen(ip,port,user_name,user_pwd,lock);
	   cout<<"screen_lock=="<<sl<<endl;
	 //2屏的状态(screen_status)
	    int screen_onoff,brigtness,brigtness_mode,volume,screen_lockunlock,program_lockunlock;
	    char screen_time[30],screen_addr[30],screen_customer_onoff[20];
	    int ss= get_screen_status(ip,port,user_name,user_pwd,&screen_onoff,&brigtness,&brigtness_mode,&volume,&screen_lockunlock,&program_lockunlock,screen_time,screen_addr,screen_customer_onoff);
	    cout<<"screen_status=="<<ss<<endl;
	    cout<<"screen_lockunlock=="<<screen_lockunlock<<endl;
	    cout<<"program_lockunlock=="<<program_lockunlock<<endl;
	    cout<<"screen_time=="<<screen_time<<endl;*/
	/********************************************/
	/******************发送天气(还没写接口)*******************/
	/* int w=128,h=96,device_type=9048;
	 unsigned long  play_list=create_playlist(w,h,device_type);
	 _TEXT_CHAR* name="project-1";
	 unsigned long  program=create_program(name);
	 
	int play_mode=1,play_week=127,play_time=1;
	_TEXT_CHAR* aging_start_time="",*aging_end_time="",*period_ontime="",*period_offtime="";
	int  pap=add_program_in_playlist(play_list,program,play_mode,play_time, aging_start_time,aging_end_time,period_ontime, period_offtime, play_week);
	cout<<"playlist_add_program=="<<pap<<endl;
	_TEXT_CHAR* tmp_path="/home/fantx/YQNetCom/Properties";
	int send_style=0;
	long long free_size,total_size;
	int sp=send_program(ip,port,user_name,user_pwd,tmp_path,play_list,send_style,&free_size,&total_size);
	cout<<"send_program=="<<sp<<endl;
	//发送完节目销毁句柄
	delete_playlist(play_list);*/
	/*********************************************/
	/***********发送字幕（不能正常发送）******************/
	/*  int w=128,h=96,device_type=9048;
	 unsigned long  play_list=create_playlist(w,h,device_type);
	 _TEXT_CHAR* name="project-1";
	 unsigned long  program=create_program(name);
	 int x=0,y=0,layout=0,transparency=100,font_size=24,display_effects=2,display_speed=16,stay_time=1,content_x=15, content_y=20;
	 _TEXT_CHAR* aging_start_time="",*aging_end_time="",*period_ontime="",*period_offtime="",*font_name="simsun",*bg_color="0xFFFFFFFF",*font_attributes="bold";
	 char name_b[20]="cc",font_color[20]="0xFFFFFF00",content[60]="qawseeer";
	 int ate=add_text(program,x,y,w,h,transparency,bg_color,display_effects,display_speed,stay_time,font_color,font_name,font_size,content,content_x,content_y,font_attributes);
	 cout<<"add_text=="<<ate<<endl;
	 int play_mode=1,play_week=127,play_time=1;
	 int  pap=add_program_in_playlist( play_list,program,play_mode,play_time, aging_start_time,aging_end_time,period_ontime, period_offtime, play_week);
         cout<<"playlist_add_program=="<<pap<<endl;
	  _TEXT_CHAR* tmp_path="/home/fantx/YQNetCom/Properties";
	  int send_style=0;
	  long long free_size,total_size;
	  int sam=send_program(ip,port,user_name,user_pwd,tmp_path,play_list,send_style,&free_size,&total_size);
	  cout<<"send _program=="<<sam<<endl; */
	 //发送完节目销毁句柄
	//  delete_playlist(play_list);																
        /*********************************/
	//1.查询可用介质列表get_screen_disk_list(已测)
	 /*   char storage_media[]=""; 
	    int sdl=get_screen_disk_list(ip,port, user_name,user_pwd,storage_media);
            cout<<"screen_disk_list=="<<sdl<<endl;
	    cout<<"storage_media=="<<storage_media<<endl;*/
	//2.get_screen_cur_disk
	/* char storage_media[10]="";
	 int scd=get_screen_cur_disk(ip,port,user_name,user_pwd,storage_media);
	cout<<"get_screen_cur_disk=="<<scd<<endl;
	cout<<"storage_media=="<<storage_media<<endl;*/
	//3.查询指定介质信息get_screen_disk_list
	/*char storage_media[10]="emmc";
	long long totalsize=0,freesize=0,usedsize=0;
	int sdi=get_screen_disk_info(ip, port,user_name,user_pwd,storage_media,&totalsize,&freesize,&usedsize);
	cout<<"screen_disk_info=="<<sdi<<endl;
	cout<<"totalsize=="<<totalsize<<endl;
	cout<<"freesize=="<<freesize<<endl;
	cout<<"usedsize=="<<usedsize<<endl;*/
	//4.设置存储介质
	 /*  char *storage_media="emmc";
	  int sssm=set_screen_storage_media(ip,port,user_name,user_pwd,storage_media);
	  cout<<"set_screen_storage_media=="<<sssm<<endl;*/
	/******************************************
        //取消发送节目
	// cancel_send_program(play_list);
	
        /***********************/

	return 0;
}


