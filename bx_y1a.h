#ifndef BX_Y1A_H
#define BX_Y1A_H

#include <QObject>
#include "YQNetCom.h"

class BX_Y1A : public QObject
{
    Q_OBJECT
public:
    explicit BX_Y1A(QString ScreenIp, int ScreenPort, int ScreenWidth, int ScreenHeight, QObject *parent = nullptr);

    // 发送文字
    bool sendText(_TEXT_CHAR* content);

    // 发送图片
    bool sendPic(_TEXT_CHAR* picPath);

private:
    void init();


signals:

private:
    _TEXT_CHAR* m_programName = (_TEXT_CHAR*)"节目1";
    _TEXT_CHAR* m_bgColor = (_TEXT_CHAR*)"0x00000000";
    _TEXT_CHAR* m_user = (_TEXT_CHAR*)"guest";
    _TEXT_CHAR* m_pwd = (_TEXT_CHAR*)"guest";

    QString m_ScreenIp;
    int m_ScreenPort;
    int m_ScreenWidth;
    int m_ScreenHeight;
    QString m_ScreenLogPath;
};

#endif // BX_Y1A_H
