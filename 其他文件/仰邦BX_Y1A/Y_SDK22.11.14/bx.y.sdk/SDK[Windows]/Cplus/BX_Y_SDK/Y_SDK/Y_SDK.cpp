// Y_SDK.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��ĿͼƬ
	//Send_ProgramPictures();

	//��Ŀ��Ļ
	//Program_str();

	//��Ŀ���ı�
	Program_str_line();

	//��Ŀʱ��
	//Program_time();

	//��Ŀ����
	//Program_clock();

	//��Ŀ��Ƶ
	//Program_video();

	//��Ŀũ��
	//Program_calendar();
	
	//�����Ų���
	//Send_ProgramColorStr();

	//���ͼ�ʱ
	//Program_count();
	
	/// ���¶�̬���ļ�
	//dynamicfile();
	/// ���¶�̬���ַ���
	//dynamicstr();
	/// ���¶�̬��json����
	///dynamicJSON();

	release_sdk();
	return 0;
}

