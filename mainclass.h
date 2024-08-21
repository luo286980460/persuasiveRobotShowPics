#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QSettings>

/*

    编译环境安装以下：
        qtbase5-dev
        qtchooser
        qt5-qmake
        qtbase5-dev-tools
        g++
        make

    换源
        清华源
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal main restricted
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-updates main restricted
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal universe
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-updates universe
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal multiverse
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-updates multiverse
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-backports main restricted universe multiverse
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-security main restricted
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-security universe
        deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ focal-security multiverse

*/

class FileMonitoring;
class BX_Y1A;
class MyUdpServer;
class NovaController;

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);

private:
    void openCfg();
    void initCfg();
    void initFileMonitoring(QString filePath, QString filePath2,    //  初始化文件监控
                            int Lagging, int X, int Y, int Width,
                            int Height, int m_manuallyCutImgSwitch);
//    void initBX_Y1A(QString ScreenIp, int ScreenPort,               //  初始化仰邦控制器
//                    int ScreenWidth, int ScreenHeight);
    void initMyUdpServer(int port);
    void initNovaController(QString ScreenIp, int Back2DefaultProgram);                                      //  初始化诺瓦控制器
    void setIni(QString key, QString value);
    void setIni(QString key, int value);

signals:

public slots:
    void showMsg(QString msg);
    void slotSetIni(QString key, QString value);
    void slotSetIni(QString key, int value);
    void slotUpdateIni();

private:
    FileMonitoring* m_fileMonitoring = nullptr;     // 文件监控
//    BX_Y1A* m_BX_Y1A = nullptr;                     // 仰邦控制器
    MyUdpServer* m_MyUdpServer = nullptr;           // udp服务
    QSettings* m_settings = nullptr;
    NovaController* m_NovaController = nullptr;     // 诺瓦控制器
    int m_ScreenType;                               // 屏幕类型
};

#endif // MAINCLASS_H
