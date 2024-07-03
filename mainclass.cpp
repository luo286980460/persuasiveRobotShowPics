#include "mainclass.h"
#include "filemonitoring.h"
#include "bx_y1a.h"
#include "myudpserver.h"

#include <QCoreApplication>
#include <QFile>
#include <QDebug>

#define INI_PATH_NAME "/cfg.ini"

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    openCfg();
    initCfg();
}

void MainClass::openCfg()
{
    QString cfgPath = QCoreApplication::applicationDirPath() + INI_PATH_NAME;
    m_settings = new QSettings(cfgPath, QSettings::IniFormat, this);
    m_settings->setIniCodec("utf-8");
    if(!QFile::exists(cfgPath)){
        qDebug() << "配置文件丢失。[" << INI_PATH_NAME << "]";
            QCoreApplication::exit();
        return;
    }
}

void MainClass::initCfg()
{
    QString ScreenIp;
    int ScreenPort;
    int ScreenWidth;
    int ScreenHeight;

    QString FilePath0;
    QString FilePath1;
    int Lagging;

    int X;
    int Y;
    int Width;
    int Height;

    int Port;

    bool screen = true;
    bool fileMo = true;
    bool udpServer = true;

    // udpServer
    Port = m_settings->value("UdpServer/Port", -1).toInt();
    if(Port == -1) {
        showMsg("ini有误，UdpServer/Port");
        udpServer = false;
    }
    if(udpServer){
        initMyUdpServer(Port);
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["UdpServer/Port"] = Port;
    }

    // 屏幕
    ScreenIp = m_settings->value("Screen/ScreenIp", "-1").toString();
    if(ScreenIp == "-1") {
        showMsg("ini有误，Screen/ScreenIp");
        screen = false;
    } else {
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["Screen/ScreenIp"] = ScreenIp;
    }

    ScreenPort = m_settings->value("Screen/ScreenPort", -1).toInt();
    if(ScreenPort == -1) {
        showMsg("ini有误，Screen/ScreenPort");
        screen = false;
    }else{
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["Screen/ScreenPort"] = ScreenPort;
    }

    ScreenWidth = m_settings->value("Screen/ScreenWidth", -1).toInt();
    if(ScreenWidth == -1) {
        showMsg("ini有误，Screen/ScreenWidth");
        screen = false;
    }else{
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["Screen/ScreenWidth"] = ScreenWidth;
    }

    ScreenHeight = m_settings->value("Screen/ScreenHeight", -1).toInt();
    if(ScreenHeight == -1) {
        showMsg("ini有误，Screen/ScreenHeight");
        screen = false;
    }else{
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["Screen/ScreenHeight"] = ScreenHeight;
    }
    if(screen) initBX_Y1A(ScreenIp, ScreenPort, ScreenWidth, ScreenHeight);

    // 文件监控
    FilePath0 = m_settings->value("FileMonitoring/FilePath00", "-1").toString();
    if(FilePath0 == "-1") {
        showMsg("ini有误，FileMonitoring/FilePath00");
        fileMo = false;
    }else{
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["FileMonitoring/FilePath00"] = FilePath0;
    }
    FilePath1 = m_settings->value("FileMonitoring/FilePath01", "-1").toString();
    if(FilePath1 == "-1") {
        showMsg("ini有误，FileMonitoring/FilePath01");
        fileMo = false;
    }else{
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["FileMonitoring/FilePath01"] = FilePath1;
    }
    Lagging = m_settings->value("FileMonitoring/Lagging", -1).toInt();
    if(Lagging == -1) {
        showMsg("ini有误，FileMonitoring/Lagging");
        fileMo = false;
    }else{
        if(m_MyUdpServer) m_MyUdpServer->m_iniJson["FileMonitoring/Lagging"] = Lagging;
    }

    X = m_settings->value("Image/X", -1).toInt();
    Y = m_settings->value("Image/Y", -1).toInt();
    Width = m_settings->value("Image/Width", -1).toInt();
    Height = m_settings->value("Image/Height", -1).toInt();
    if(X == -1 || Y == -1 || Width == -1 || Height == -1){
        showMsg("ini有误，Image/（X/Y/Width/Height）");
        X = 1000;
        Y = 0;
        Width = 1600;
        Height = 1800;
    }else{
        if(m_MyUdpServer) {
            m_MyUdpServer->m_iniJson["Image/X"] = X;
            m_MyUdpServer->m_iniJson["Image/Y"] = Y;
            m_MyUdpServer->m_iniJson["Image/Width"] = Width;
            m_MyUdpServer->m_iniJson["Image/Height"] = Height;
        }
    }

    if(fileMo) initFileMonitoring(FilePath0, FilePath1, Lagging, X, Y, Width, Height);
}

void MainClass::initFileMonitoring(QString filePath1, QString filePath2, int Lagging, int X, int Y, int Width, int Height)
{
    m_fileMonitoring = new FileMonitoring(filePath1, filePath2, Lagging, X, Y, Width, Height);
    connect(m_fileMonitoring, &FileMonitoring::signalShowPic, this, [=](QString picPath){
        if(m_BX_Y1A){

            if(m_BX_Y1A && !picPath.isEmpty()){
                if(picPath.contains("未")){
                    m_BX_Y1A->sendTextAndPic((_TEXT_CHAR*)"小呆逼一个", (_TEXT_CHAR*)(picPath.toLocal8Bit().data()));
                }else{
                    m_BX_Y1A->sendTextAndPic((_TEXT_CHAR*)"请安全驾驶", (_TEXT_CHAR*)(picPath.toLocal8Bit().data()));
                }
            }
        }
    });
    m_fileMonitoring->start();
}

void MainClass::initBX_Y1A(QString ScreenIp, int ScreenPort, int ScreenWidth, int ScreenHeight)
{
    m_BX_Y1A = new BX_Y1A(ScreenIp, ScreenPort, ScreenWidth, ScreenHeight);
}

void MainClass::initMyUdpServer(int port)
{
    m_MyUdpServer = new MyUdpServer(port, this);
    //connect(m_MyUdpServer, &MyUdpServer::signalSetIni, this, &MainClass::slotSetIni);
    connect(m_MyUdpServer, SIGNAL(signalSetIni(QString,QString)), this, SLOT(slotSetIni(QString,QString)));
    connect(m_MyUdpServer, SIGNAL(signalSetIni(QString,int)), this, SLOT(slotSetIni(QString,int)));
    connect(m_MyUdpServer, &MyUdpServer::signalUpdateIni, this, &MainClass::slotUpdateIni);
}

void MainClass::setIni(QString key, QString value)
{
    //qDebug() << "*******设置配置文件： " << key << "   -   " << value;
    m_settings->setValue(key, value);
}

void MainClass::setIni(QString key, int value)
{
    //qDebug() << "*******设置配置文件： " << key << "   -   " << value;
    m_settings->setValue(key, value);
}

void MainClass::showMsg(QString msg)
{
    qDebug() << msg;
}

void MainClass::slotSetIni(QString key, QString value)
{
    setIni(key, value);
}

void MainClass::slotSetIni(QString key, int value)
{
    setIni(key, value);
}

void MainClass::slotUpdateIni()
{
    if(m_fileMonitoring) {
        m_fileMonitoring->deleteLater();
        m_fileMonitoring= nullptr;
    }
    if(m_BX_Y1A) {
        m_BX_Y1A->deleteLater();
        m_BX_Y1A= nullptr;
    }
    initCfg();
}
