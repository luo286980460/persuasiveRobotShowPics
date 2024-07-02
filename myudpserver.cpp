#include "myudpserver.h"
#include <QJsonDocument>

MyUdpServer::MyUdpServer(quint16 port, QObject *parent)
    : QObject{parent}
    , m_port(port)
{
    InitSocket();
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
}

void MyUdpServer::modifySettings(QJsonObject &jsonObj)
{

    // 修改显示屏IP
    if(jsonObj.contains("Screen/ScreenIp") && jsonObj.value("Screen/ScreenIp").isString()){

    }
    // 修改显示屏端口
    if(jsonObj.contains("Screen/ScreenPort") && jsonObj.value("Screen/ScreenPort").isDouble()){

    }
    // 修改显示屏宽度
    if(jsonObj.contains("Screen/ScreenWidth") && jsonObj.value("Screen/ScreenWidth").isDouble()){

    }
    // 修改显示屏高度
    if(jsonObj.contains("Screen/ScreenHeight") && jsonObj.value("Screen/ScreenHeight").isDouble()){

    }
    // 修改需要监控的文件夹1
    if(jsonObj.contains("FileMonitoring/FilePath01") && jsonObj.value("FileMonitoring/FilePath01").isString()){

    }
    // 修改需要监控的文件夹2
    if(jsonObj.contains("FileMonitoring/FilePath02") && jsonObj.value("FileMonitoring/FilePath02").isString()){

    }
    // 修改处理照片的延时
    if(jsonObj.contains("FileMonitoring/Lagging") && jsonObj.value("FileMonitoring/Lagging").isDouble()){

    }
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
        emit signalSetIni("FileMonitoring/v", json.value("FileMonitoring/Lagging").toInt());
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
