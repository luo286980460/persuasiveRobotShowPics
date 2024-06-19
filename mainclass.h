#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>

class FileMonitoring;
class BX_Y1A;

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);

private:
    void initCfg();
    void initFileMonitoring(QString filePath, QString filePath2, int Lagging);
    void initBX_Y1A(QString ScreenIp, int ScreenPort, int ScreenWidth, int ScreenHeight);

signals:

public slots:
    void showMsg(QString msg);

private:
    FileMonitoring* m_fileMonitoring;   // 文件监控
    BX_Y1A* m_BX_Y1A;
};

#endif // MAINCLASS_H
