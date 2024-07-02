#ifndef MYUDPSERVER_H
#define MYUDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QJsonObject>

class MyUdpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyUdpServer(quint16 port, QObject *parent = nullptr);

    void InitSocket();                  // 初始化套接字
    qint64 writeDatagram(const QByteArray &datagram);

private:
    void initIniJson();
    void modifySettings(QJsonObject& jsonObj);              //修改配置信息
    void setIni(QJsonObject& json);

signals:
    void signalSetIni(QString key, QString value);
    void signalSetIni(QString key, int value);
    void signalUpdateIni();

public slots:
    void ReadPendingDataframs();        // 读取消息

public:
    QJsonObject m_iniJson;

private:
    QUdpSocket *mUdpSocket              // UDP套接字
     = nullptr;
    quint16 m_port;                     // 本地监听端口
    QHostAddress m_clientAddress;       // 客户端ip临时保存
    quint16 m_clientPort;               // 客户端port临时保存
};

#endif // MYUDPSERVER_H
