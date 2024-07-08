#include "myudpserver.h"
#include <QJsonDocument>

MyUdpServer::MyUdpServer(quint16 port, QObject *parent)
    : QObject{parent}
    , m_port(port)
{
    InitSocket();
    initIniJson();
}

void MyUdpServer::InitSocket()
{
    mUdpSocket = new QUdpSocket(this);
    connect(mUdpSocket,&QUdpSocket::readyRead,this,[=]{
        ReadPendingDataframs();
    });

    mUdpSocket->bind(m_port);
}

qint64 MyUdpServer::writeDatagram(const QByteArray &datagram)
{
    return mUdpSocket->writeDatagram(datagram, m_clientAddress, m_clientPort);
}

void MyUdpServer::initIniJson()
{
    m_iniJson.insert("Screen/ScreenIp", "");
    m_iniJson.insert("Screen/ScreenPort", "");
    m_iniJson.insert("Screen/ScreenWidth", "");
    m_iniJson.insert("Screen/ScreenHeight", "");
    m_iniJson.insert("Screen/ScreenLogPath", "");
    m_iniJson.insert("FileMonitoring/FilePath01", "");
    m_iniJson.insert("FileMonitoring/FilePath02", "");
    m_iniJson.insert("UdpServer/Port", "");
    m_iniJson.insert("Image/X", "");
    m_iniJson.insert("Image/Y", "");
    m_iniJson.insert("Image/Width", "");
    m_iniJson.insert("Image/Height", "");
}

void MyUdpServer::setIni(QJsonObject& json)
{
    if(json.contains("Screen/ScreenIp") && json.value("Screen/ScreenIp").isString()){
        emit signalSetIni("Screen/ScreenIp", json.value("Screen/ScreenIp").toString());
    }
    if(json.contains("Screen/ScreenPort") && json.value("Screen/ScreenPort").isString()){
        emit signalSetIni("Screen/ScreenPort", json.value("Screen/ScreenPort").toString());
    }
    if(json.contains("Screen/ScreenWidth") && json.value("Screen/ScreenWidth").isDouble()){
        emit signalSetIni("Screen/ScreenWidth", json.value("Screen/ScreenWidth").toInt());
    }
    if(json.contains("Screen/ScreenHeight") && json.value("Screen/ScreenHeight").isDouble()){
        emit signalSetIni("Screen/ScreenHeight", json.value("Screen/ScreenHeight").toInt());
    }
    if(json.contains("FileMonitoring/FilePath01") && json.value("FileMonitoring/FilePath01").isString()){
        emit signalSetIni("FileMonitoring/FilePath01", json.value("FileMonitoring/FilePath01").toString());
    }
    if(json.contains("FileMonitoring/Lagging") && json.value("FileMonitoring/Lagging").isDouble()){
        emit signalSetIni("FileMonitoring/Lagging", json.value("FileMonitoring/Lagging").toInt());
    }
    if(json.contains("Image/X") && json.value("Image/X").isDouble()){
        emit signalSetIni("Image/X", json.value("Image/X").toInt());
    }
    if(json.contains("Image/Y") && json.value("Image/Y").isDouble()){
        emit signalSetIni("Image/Y", json.value("Image/Y").toInt());
    }
    if(json.contains("Image/Width") && json.value("Image/Width").isDouble()){
        emit signalSetIni("Image/Width", json.value("Image/Width").toInt());
    }
    if(json.contains("Image/Height") && json.value("Image/Height").isDouble()){
        emit signalSetIni("Image/Height", json.value("Image/Height").toInt());
    }
    emit signalUpdateIni();
}

void MyUdpServer::ReadPendingDataframs()
{
    QByteArray _data;
    _data.resize(mUdpSocket->pendingDatagramSize());

    QJsonObject jsonObj;

    while(mUdpSocket->hasPendingDatagrams())
    {
        mUdpSocket->readDatagram(_data.data(), _data.size(), &m_clientAddress, &m_clientPort);
        jsonObj = QJsonDocument::fromJson(_data).object();

        QJsonObject m_backJson;
        m_backJson.insert("res", "1");  // 1成功 0失败

        if(jsonObj.isEmpty()){
            m_backJson["res"] = "0";
            m_backJson["msg"] = "Invalid Json";
            mUdpSocket->writeDatagram(QJsonDocument(m_backJson).toJson(), m_clientAddress, m_clientPort);
            return;
        }

        if(jsonObj.contains("code") && jsonObj.value("code").isString()){
            QString code = jsonObj.value("code").toString();
            if(code == "1"){
                m_backJson["res"] = "1";
                m_backJson.insert("data", m_iniJson);
                m_backJson["msg"] = "successful";
                mUdpSocket->writeDatagram(QJsonDocument(m_backJson).toJson(), m_clientAddress, m_clientPort);
            }else if(code == "2"){
                /* 修改配置 */
                m_backJson["res"] = "1";
                m_backJson["msg"] = "modified";
                setIni(jsonObj);
                mUdpSocket->writeDatagram(QJsonDocument(m_backJson).toJson(), m_clientAddress, m_clientPort);
            }else{
                m_backJson["res"] = "0";
                m_backJson["msg"] = "unknown code";
                mUdpSocket->writeDatagram(QJsonDocument(m_backJson).toJson(), m_clientAddress, m_clientPort);
            }

        }else{
            m_backJson["res"] = "0";
            m_backJson["msg"] = "erro!!! no key:code or key is not a string";
            mUdpSocket->writeDatagram(QJsonDocument(m_backJson).toJson(), m_clientAddress, m_clientPort);
        }

        //mUdpSocket->writeDatagram(_data, m_clientAddress, m_clientPort);
    }
}
