#ifndef BX_Y1A_H
#define BX_Y1A_H

#include <QObject>
#include <QTimer>
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


    bool sendTextAndPic(_TEXT_CHAR* content, _TEXT_CHAR* picPath);
    void showDefaultProgram();

private:
    void init();
    void updatePaths();
    void initSendTimer();


signals:

private:
    _TEXT_CHAR* m_programName = (_TEXT_CHAR*)"节目1";
    _TEXT_CHAR* m_bgColor = (_TEXT_CHAR*)"0x00000000";
    _TEXT_CHAR* m_user = (_TEXT_CHAR*)"guest";
    _TEXT_CHAR* m_pwd = (_TEXT_CHAR*)"guest";

    QString m_ScreenIp;
    QString m_tipText = "请安全驾驶";
    int m_ScreenPort;
    int m_ScreenWidth;
    int m_ScreenHeight;
    int m_TextAreaHeight = 60;
    QString m_ScreenLogPath;
    QTimer* m_sendTimer;
    bool m_canSend = true;
    int m_screenDelay = 1000;      // 屏幕下次发送的延迟 ms
    QTimer m_toDefProTimer;
};

#endif // BX_Y1A_H
