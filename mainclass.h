#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QSettings>

class FileMonitoring;
class BX_Y1A;
class MyUdpServer;

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);

private:
    void openCfg();
    void initCfg();
    void initFileMonitoring(QString filePath, QString filePath2, int Lagging, int X, int Y, int Width, int Height);
    void initBX_Y1A(QString ScreenIp, int ScreenPort, int ScreenWidth, int ScreenHeight);
    void initMyUdpServer(int port);
    void setIni(QString key, QString value);
    void setIni(QString key, int value);

signals:

public slots:
    void showMsg(QString msg);
    void slotSetIni(QString key, QString value);
    void slotSetIni(QString key, int value);
    void slotUpdateIni();

private:
    FileMonitoring* m_fileMonitoring = nullptr;   // 文件监控
    BX_Y1A* m_BX_Y1A = nullptr;
    MyUdpServer* m_MyUdpServer = nullptr;
    QSettings* m_settings;
};

#endif // MAINCLASS_H
