#include <QApplication>
#include <QDebug>
#include <QThread>
#include <QTextCodec>

#include "novacontrollerworker.h"
#include "src/NovaTraffic.h"
#include "NovaHeader.h"

#define DEFAULT_PROGRAME_PICNAME "1.jpg"

NovaControllerWorker::NovaControllerWorker(QString ip, int Back2DefaultProgram, QString startTime, QString stopTime, QObject *parent)
    : QObject{parent}
    , m_ip(ip)
    , m_port(5000)
    , m_Back2DefaultProgramTime(Back2DefaultProgram)
    , m_Back2DefaultProgramTimeFlag(Back2DefaultProgram)
    , m_startTime(QTime::fromString("08:00:00", "hh:mm:ss"))
    , m_stopTime(QTime::fromString("20:00:00", "hh:mm:ss"))
{
    QTime startTimeTmp = QTime::fromString(startTime, "hh:mm:ss");
    QTime stopTimeTmp = QTime::fromString(stopTime, "hh:mm:ss");
    if(startTimeTmp.isValid() && stopTimeTmp.isValid() && startTimeTmp < stopTimeTmp){
        m_startTime = startTimeTmp;
        m_stopTime = stopTimeTmp;
        showMsg(QString("工作时间【%1】~【%2】").arg(startTime).arg(stopTime));
    }else{
        m_startTime = QTime::fromString("08:00:00", "hh:mm:ss");
        m_stopTime = QTime::fromString("20:00:00", "hh:mm:ss");
        showMsg("时间格式错误，启用默认时间");
    }
}

void NovaControllerWorker::playProgram(int id)
{

    qDebug() << "playProgram";
    if(m_traffic && m_timer){

        //emit showMsg(QString("播放节目 %1 ").arg(id));

        switch (id) {
        case 1:
            playProgram1();
            break;
        case 2:
            playProgram2();
            break;
        case 3:
            playProgram3();
            break;
        default:
            break;
        }
        if(id != 1){
            m_Back2DefaultProgramTimeFlag = 0;
        }
        m_playFlag = 0;
    }
}

void NovaControllerWorker::playProgram1()
{
    // 下发文件
    int res = m_traffic->sendFile((QApplication::applicationDirPath() + "/Pics/" + PROGRAM1_ITEM1_PIC).toLocal8Bit(),
                                  QString(PROGRAM1_ITEM1_PIC).toLocal8Bit());

    //emit showMsg(QString("playProgram1() sendFile res = %1").arg(res));

    // 发送节目
    char program[] = PROGRAM1;
    res = m_traffic->sendPlayList(1, program);

    //emit showMsg(QString("playProgram1() sendPlayList res = %1").arg(res));
}

void NovaControllerWorker::playProgram2()
{
    // 下发文件
    int res = m_traffic->sendFile((QApplication::applicationDirPath() + "/Pics/" + PROGRAM2_ITEM1_PIC).toLocal8Bit(),
                                  QString(PROGRAM2_ITEM1_PIC).toLocal8Bit());

    //emit showMsg(QString("playProgram2() sendFile res = %1").arg(res));

    // 发送节目
    char program[] = PROGRAM2;
    m_traffic->sendPlayList(2, program);

    //emit showMsg(QString("playProgram1() sendPlayList res = %1").arg(res));
}

void NovaControllerWorker::playProgram3()
{
    // 下发文件 1
    int res = m_traffic->sendFile((QApplication::applicationDirPath() + "/Pics/" + PROGRAM3_ITEM1_PIC).toLocal8Bit(),
                                  QString(PROGRAM3_ITEM1_PIC).toLocal8Bit());

    //emit showMsg(QString("playProgram3() sendFile1 res = %1").arg(res));

    // 下发文件 2
    res = m_traffic->sendFile((QApplication::applicationDirPath() + "/Pics/" + PROGRAM3_ITEM2_PIC).toLocal8Bit(),
                              QString(PROGRAM3_ITEM2_PIC).toLocal8Bit());

    //emit showMsg(QString("playProgram3() sendFile2 res = %1").arg(res));

    // 发送节目
    char program[] = PROGRAM3;
    m_traffic->sendPlayList(3, program);

    //emit showMsg(QString("playProgram1() sendPlayList res = %1").arg(res));
}

void NovaControllerWorker::playProgramDefault(QString picPathName, QString picName, QString text)
{
    // 下发文件
    int res = m_traffic->sendFile(picPathName.toLocal8Bit(), picName.toLocal8Bit());
    //qDebug() << QString("下发文件 res ： %1").arg(res);
    //showMsg(QString("下发文件 res ： %1").arg(res));
    // 发送节目
    QString cmd = PROGRAM1;
    cmd = cmd.arg(text).arg(picName);
    res = m_traffic->sendPlayList(1, cmd.toLocal8Bit().data());
    //showMsg(QString("下发节目 res ： %1").arg(res));
}

bool NovaControllerWorker::getScreenWoringState()
{
    QTime curTime = QTime::currentTime();
    if(curTime >= m_startTime && curTime <= m_stopTime){
        return true;
    }
    return false;
}

void NovaControllerWorker::slotInit()
{
    m_traffic = new NovaTraffic(m_ip.toLocal8Bit(), m_port);

    // 播放节目1 默认节目
    slotShowPic(QApplication::applicationDirPath() + "/" + DEFAULT_PROGRAME_PICNAME);
    m_Back2DefaultProgramTimeFlag = m_Back2DefaultProgramTime+1;

    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, [=](){

        //qDebug() << "m_Back2DefaultProgramTimeFlag: " << m_Back2DefaultProgramTimeFlag;

        if(m_playFlag < m_ProgramInterval){         // 不能发送节目
            m_playFlag++;
            if(m_Back2DefaultProgramTimeFlag < m_Back2DefaultProgramTime){    // 等待发送节目
                m_Back2DefaultProgramTimeFlag++;
            }

        }else if(m_playFlag == m_ProgramInterval){  // 可发送节目
            if(m_Back2DefaultProgramTimeFlag == m_Back2DefaultProgramTime){
                // 播放节目1 默认节目
                slotShowPic(QApplication::applicationDirPath() + "/" + DEFAULT_PROGRAME_PICNAME);
                m_Back2DefaultProgramTimeFlag = m_Back2DefaultProgramTime+1;
                m_playFlag = 0;
            }else if(m_Back2DefaultProgramTimeFlag < m_Back2DefaultProgramTime){    // 等待发送节目
                m_Back2DefaultProgramTimeFlag++;
            }
        }
    });
    m_timer->start();
}

void NovaControllerWorker::slotIllegalAct()
{
    //qDebug() << QString("大屏违法:%1").arg(m_ip);
    if(m_traffic){
        // 播放节目2        临时
        playProgram(2);
    }
}

void NovaControllerWorker::slotShowPic(QString picPathName, QString picName, QString text)
{
    if(getScreenWoringState()){
        playProgramDefault(QApplication::applicationDirPath() + "/" + DEFAULT_PROGRAME_PICNAME, picName, text);
    }else{
        slotShowPic(picPathName, picName, text);
    }
    m_Back2DefaultProgramTimeFlag = 0;
}
