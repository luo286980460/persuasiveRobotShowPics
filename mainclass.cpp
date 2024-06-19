#include "mainclass.h"
#include "filemonitoring.h"
#include "bx_y1a.h"

#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDebug>

#define INI_PATH_NAME "/cfg.ini"

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    initCfg();
}

void MainClass::initCfg()
{
    QString ScreenIp;
    int ScreenPort;
    int ScreenWidth;
    int ScreenHeight;
    QString ScreenLogPath;
    QString FilePath1;
    QString FilePath2;
    int Lagging;
    bool screen = true;
    bool fileMo = true;
    QString cfgPath = QCoreApplication::applicationDirPath() + INI_PATH_NAME;
    QSettings settings(cfgPath, QSettings::IniFormat, this);
    settings.setIniCodec("utf-8");
    if(!QFile::exists(cfgPath)){
        qDebug() << "配置文件丢失。[" << INI_PATH_NAME << "]";
        QCoreApplication::exit();
        return;
    }

    // 屏幕
    ScreenIp = settings.value("Screen/ScreenIp", "-1").toString();
    if(ScreenIp == "-1") {showMsg("ini有误，Screen/ScreenIp");screen = false;}
    ScreenPort = settings.value("Screen/ScreenPort", -1).toInt();
    if(ScreenPort == -1) {showMsg("ini有误，Screen/ScreenPort");screen = false;}
    ScreenWidth = settings.value("Screen/ScreenWidth", -1).toInt();
    if(ScreenWidth == -1) {showMsg("ini有误，Screen/ScreenWidth");screen = false;}
    ScreenHeight = settings.value("Screen/ScreenHeight", -1).toInt();
    if(ScreenHeight == -1) {showMsg("ini有误，Screen/ScreenHeight");screen = false;}
    ScreenLogPath = settings.value("Screen/ScreenLogPath", -1).toString();
    if(screen) initBX_Y1A(ScreenIp, ScreenPort, ScreenWidth, ScreenHeight);

    // 文件监控
    FilePath1 = settings.value("FileMonitoring/FilePath01", -1).toString();
    if(FilePath1 == "-1") {showMsg("ini有误，FileMonitoring/FilePath01");fileMo = false;}
    FilePath2 = settings.value("FileMonitoring/FilePath02", -1).toString();
    if(FilePath2 == "-1") {showMsg("ini有误，FileMonitoring/FilePath02");fileMo = false;}
    Lagging = settings.value("FileMonitoring/Lagging", -1).toInt();
    if(Lagging == -1) {showMsg("ini有误，FileMonitoring/Lagging");fileMo = false;}
    if(fileMo) initFileMonitoring(FilePath1, FilePath2, Lagging);
}

void MainClass::initFileMonitoring(QString filePath1, QString filePath2, int Lagging)
{
    m_fileMonitoring = new FileMonitoring(filePath1, filePath2, Lagging);
    connect(m_fileMonitoring, &FileMonitoring::signalShowPic, this, [=](QString picPath){
        if(m_BX_Y1A){

            qDebug() << picPath;
            m_BX_Y1A->sendPic((_TEXT_CHAR*)picPath.toLocal8Bit().data());
        }
    });
    m_fileMonitoring->start();
}

void MainClass::initBX_Y1A(QString ScreenIp, int ScreenPort, int ScreenWidth, int ScreenHeight)
{
    m_BX_Y1A = new BX_Y1A(ScreenIp, ScreenPort, ScreenWidth, ScreenHeight);
}

void MainClass::showMsg(QString msg)
{
    qDebug() << msg;
}
