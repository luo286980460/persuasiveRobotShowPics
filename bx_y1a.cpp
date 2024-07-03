#include "bx_y1a.h"

#include <QThread>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>

BX_Y1A::BX_Y1A(QString ScreenIp, int ScreenPort, int ScreenWidth, int ScreenHeight, QObject *parent)
    : QObject{parent}
    , m_ScreenIp(ScreenIp)
    , m_ScreenPort(ScreenPort)
    , m_ScreenWidth(ScreenWidth)
    , m_ScreenHeight(ScreenHeight)
{
    init();
    //sendPic((_TEXT_CHAR*)((QCoreApplication::applicationDirPath() + "/pics/1.jpg").toLocal8Bit().data()));

    sendTextAndPic((_TEXT_CHAR*)m_tipText.toLocal8Bit().data(), (_TEXT_CHAR*)((QCoreApplication::applicationDirPath() + "/1.jpg").toLocal8Bit().data()));
//    QThread::msleep(3000)    sendPic((_TEXT_CHAR*)"/home/ls/22/pics/2.png");
//    QThread::msleep(3000);
//    sendText((_TEXT_CHAR*)"雨天路滑 减速慢");
//    QThread::msleep(3000);
//    sendText((_TEXT_CHAR*)"行人路过 请小心");
}

void BX_Y1A::init()
{
    //init_sdk();
    m_ScreenLogPath = QCoreApplication::applicationDirPath() + "/screenLogs/";
    QDir dir(m_ScreenLogPath);
    if(!dir.exists()){
        dir.mkpath(m_ScreenLogPath);
        system(QString("chmod -R a+rwx %1").arg(m_ScreenLogPath).toLocal8Bit());
    }

    initSendTimer();
}

void BX_Y1A::initSendTimer()
{
    m_sendTimer = new QTimer(this);
    connect(m_sendTimer, &QTimer::timeout, this, [=]{
        m_canSend = true;
        m_sendTimer->stop();
    });
    m_sendTimer->setInterval(m_screenDelay);

}

bool BX_Y1A::sendText(_TEXT_CHAR* content)
{
    int res = -100;
    // 创建节目单
    unsigned long playlist = create_playlist(m_ScreenWidth, m_ScreenHeight, 11608);
    qDebug() << "playlist: " << playlist;

    // 创建节目
    unsigned long program = create_program(m_programName, m_bgColor);
    qDebug() << "program: " << program;

    // 创建文本分区
    unsigned long textArea = create_text();
    qDebug() << "textArea: " << textArea;

    // 添加字幕区文件
    res = add_text_unit_text(textArea, 1, 8, (_TEXT_CHAR*)"宋体", 12, (_TEXT_CHAR*)"normal", (_TEXT_CHAR*)""
                       , (_TEXT_CHAR*)"0xFFFF0000", (_TEXT_CHAR*)"0x00000000", content);
    //qDebug() << "add_text_unit_text: " << res;

    // 字幕分区添加到节目
    res = add_text(program, textArea, 0, 0, m_ScreenWidth, 100, 100, 2, 1);
    qDebug() << "add_text: " << res;

    // 删除文本分区
    delete_text(textArea);

    // 节目添加到节目单
    res =add_program_in_playlist(playlist, program, 0, 10, (_TEXT_CHAR*)"2012-06-20"
                            , (_TEXT_CHAR*)"3012-06-20", (_TEXT_CHAR*)"00:00:00"
                            , (_TEXT_CHAR*)"23:59:59", 0xFE);
    qDebug() << "add_program_in_playlist: " << res;

    // 发送节目单
    res = send_program(m_ScreenIp.toLocal8Bit().data(), (unsigned short)m_ScreenPort
                       , m_user, m_pwd, (_TEXT_CHAR*)m_ScreenLogPath.toLocal8Bit().data()
                       , playlist, 0, nullptr, nullptr);
    qDebug() << "send_program: " << res;

    // 销毁节目单
    delete_playlist(playlist);

    if(res == 0) return true;
    else return false;
}

bool BX_Y1A::sendPic(_TEXT_CHAR *picPath)
{
    //picPath = (_TEXT_CHAR *)((m_ScreenLogPath + "1.jpg").toLocal8Bit().data());
    //picPath = (_TEXT_CHAR*)((QCoreApplication::applicationDirPath() + "/picLog/1.jpg").toLocal8Bit().data());

    // 创建节目单
    unsigned long playlist = create_playlist(m_ScreenWidth, m_ScreenHeight, 11608);
    //qDebug() << "playlist: " << playlist;

    // 创建节目
    unsigned long program = create_program(m_programName, m_bgColor);
    //qDebug() << "program: " << program;

    //创建图文分区
    unsigned long picArea = create_pic();
    //qDebug() << "picArea: " << picArea;

    // 图文分区添加图片
    int res = add_pic_unit(picArea, 0, 2, 8, picPath);
    //qDebug() << "add_pic_unit: " << res;

    // 添加图文分区到节目
    res = add_pic(program, picArea, 0, 100, m_ScreenWidth, m_ScreenHeight-100, 100);
    //qDebug() << "add_pic: " << res;

    // 删除图文分区
    delete_pic(picArea);

   // 节目添加到节目单
   add_program_in_playlist(playlist, program, 0, 10, (_TEXT_CHAR*)"2012-06-20"
                           , (_TEXT_CHAR*)"3012-06-20", (_TEXT_CHAR*)"00:00:00"
                           , (_TEXT_CHAR*)"23:59:59", 0xFE);

   // 发送节目单
   res = send_program(m_ScreenIp.toLocal8Bit().data(), (unsigned short)m_ScreenPort
                      , m_user, m_pwd, (_TEXT_CHAR*)m_ScreenLogPath.toLocal8Bit().data()
                      , playlist, 0, nullptr, nullptr);
   qDebug() << "*******send_program:  " << res;
   if(res != 0){
        // 发送节目单
        res = send_program(m_ScreenIp.toLocal8Bit().data(), (unsigned short)m_ScreenPort
                           , m_user, m_pwd, (_TEXT_CHAR*)m_ScreenLogPath.toLocal8Bit().data()
                           , playlist, 0, nullptr, nullptr);
   }
   // 销毁节目单
   delete_playlist(playlist);

   //QFile file((char*)picPath);
   //QString _picPath = QString((char*)picPath);
   //qDebug() << "*********** _picPath: " << _picPath;
   //if(!_picPath.contains("1.jpeg")) QFile::remove(_picPath);
   //file.remove();
//   qDebug() << "*******picPath:  " << (char*)picPath;
//   if(file.open(QIODevice::ReadWrite)){
//        qDebug() << "***********************************文件打开成功";
//        if(file.remove()){
//            qDebug() << "***********************************文件删除成功";
//        }
//        else {
//            qDebug() << "***********************************文件删除失败";
//        }
//   }

   if(res == 0) return true;
   else return false;

   return true;
}

bool BX_Y1A::sendTextAndPic(_TEXT_CHAR *content, _TEXT_CHAR *picPath)
{
   int res = -100;
   // 创建节目单
   unsigned long playlist = create_playlist(m_ScreenWidth, m_ScreenHeight, 11608);
   //qDebug() << "playlist: " << playlist;

   // 创建节目
   unsigned long program = create_program(m_programName, m_bgColor);
   //qDebug() << "program: " << program;

   // 创建文本分区
   unsigned long textArea = create_text();
   //qDebug() << "textArea: " << textArea;

   // 添加字幕区文件
   res = add_text_unit_text(textArea, 1, 8, (_TEXT_CHAR*)"宋体", 35, (_TEXT_CHAR*)"normal", (_TEXT_CHAR*)""
                                                                                                   , (_TEXT_CHAR*)"0xFFFF0000", (_TEXT_CHAR*)"0x00000000", content);
    //qDebug() << "add_text_unit_text: " << res;

    // 字幕分区添加到节目
    res = add_text(program, textArea, 0, 0, m_ScreenWidth, m_TextAreaHeight, 100, 2, 1);
    //qDebug() << "add_text: " << res;

    // 删除文本分区
    delete_text(textArea);


    //创建图文分区
    unsigned long picArea = create_pic();
    //qDebug() << "picArea: " << picArea;

    // 图文分区添加图片
    res = add_pic_unit(picArea, 0, 2, 8, picPath);
    //qDebug() << "add_pic_unit: " << res;

    // 添加图文分区到节目
    res = add_pic(program, picArea, 0, m_TextAreaHeight, m_ScreenWidth, m_ScreenHeight-m_TextAreaHeight, 100);
    //qDebug() << "add_pic: " << res;

    // 删除图文分区
    delete_pic(picArea);



    // 节目添加到节目单
    res =add_program_in_playlist(playlist, program, 0, 10, (_TEXT_CHAR*)"2012-06-20"
                                  , (_TEXT_CHAR*)"3012-06-20", (_TEXT_CHAR*)"00:00:00"
                                  , (_TEXT_CHAR*)"23:59:59", 0xFE);
    //qDebug() << "add_program_in_playlist: " << res;

    // 发送节目单
    if(m_canSend){
        res = send_program(m_ScreenIp.toLocal8Bit().data(), (unsigned short)m_ScreenPort
                           , m_user, m_pwd, (_TEXT_CHAR*)m_ScreenLogPath.toLocal8Bit().data()
                           , playlist, 0, nullptr, nullptr);
    }

    if(res == 0){
        m_canSend = false;
        m_sendTimer->start();
    }

    //qDebug() << "send_program: " << res;

    // 销毁节目单
    delete_playlist(playlist);

    if(res == 0) return true;
    else return false;
}
