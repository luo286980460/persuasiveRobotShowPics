#include <QFileSystemWatcher>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QImage>
#include <QThread>

#include "filemonitoringworker.h"
#define  DATAPATH "/home/ls/22/fileTest/%1"

FileMonitoringWorker::FileMonitoringWorker(QString filePath, QObject *parent)
    : QObject{parent}
    , m_filePath(filePath)
{

}

void FileMonitoringWorker::initFileMonitoring()
{
    // 获取屏幕配置文件
    m_fileMonitoring = new QFileSystemWatcher(this);
    connect(m_fileMonitoring, SIGNAL(directoryChanged(QString)), this, SLOT(dealPicFiles(QString)));

    QDir dir(m_filePathData);
    if(!dir.exists()){
        dir.mkpath(m_filePathData);
    }
    m_fileMonitoring->addPath(m_filePathData);
    //qDebug() << "更新监控路径：" << m_filePath;
}

void FileMonitoringWorker::updatePath()
{
    m_filePathData = QString(m_filePath).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
}

QFileInfo FileMonitoringWorker::getNewer(QFileInfo *file1, QFileInfo *file2)
{
    QFile fJson1 = QFile(file1->filePath());
    QFile fJson2 = QFile(file2->filePath());

    if(!fJson1.open(QIODevice::ReadOnly)){
        return *file2;
    }
    else if(!fJson2.open(QIODevice::ReadOnly)){
        return *file1;
    }

    QJsonDocument jsonDoc1 = QJsonDocument::fromJson(fJson1.readAll());
    QJsonDocument jsonDoc2 = QJsonDocument::fromJson(fJson2.readAll());
    QJsonObject jsonObj1 = jsonDoc1.object();
    QJsonObject jsonObj2 = jsonDoc2.object();

    QDateTime dateTime1 = QDateTime::fromString(jsonObj1["gcsj"].toString(), "yyyy-MM-dd hh:mm:ss");
    QDateTime dateTime2 = QDateTime::fromString(jsonObj2["gcsj"].toString(), "yyyy-MM-dd hh:mm:ss");

    if(dateTime1 > dateTime2){
        fJson2.remove();
        qDebug() << "删除文件： " << file2->filePath();
        return *file1;
    }
    else{
        fJson1.remove();
        qDebug() << "删除文件： " << file1->filePath();
        return *file2;
    }
}

void FileMonitoringWorker::sendPic2Led(QString base64)
{
    QImage img;
    QByteArray arr_base64 = base64.toLatin1();
    img.loadFromData(QByteArray::fromBase64(arr_base64.mid(base64.indexOf(",")+1)));
    //img.loadFromData(QByteArray::fromBase64(arr_base64));
    if(img.save("/home/ls/22/picTest/1.jpeg")){
        emit signalShowPic("/home/ls/22/picTest/1.jpeg");
    }
}

void FileMonitoringWorker::unPackJson(QJsonObject &json)
{

}

void FileMonitoringWorker::slotInitWorker()
{
    updatePath();
    initFileMonitoring();
}

void FileMonitoringWorker::dealPicFiles(QString path)
{
    QThread::msleep(200);
    //打开目录
    QDir dir(path);

    //提取文件信息链表
    QFileInfoList inforList = dir.entryInfoList(QDir::Files);
    QFileInfo pic;    // 待显示的照片

    int i = 0;
    //遍历文件信息链表,并进行相关操作
    foreach (QFileInfo info, inforList) {
        if(!i++){
            pic = info;
        }
        else{
            pic = getNewer(&pic, &info);
        }
    }

    QFile file = QFile(pic.filePath());
    QJsonDocument jsonDoc;
    QJsonObject jsonObj;
    if(file.open(QIODevice::ReadOnly)){
        jsonDoc = QJsonDocument::fromJson(file.readAll());
        jsonObj = jsonDoc.object();
    }
    //qDebug() << jsonObj["clwz"].toString();
    sendPic2Led(jsonObj["zpstr1"].toString());
    file.remove();
}
