#include <QFileSystemWatcher>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QImage>
#include <QThread>
#include <QCoreApplication>

#include "filemonitoringworker.h"

FileMonitoringWorker::FileMonitoringWorker(QString filePath1, QString filePath2, int Lagging,
                                           int X, int Y, int Width, int Height, QObject *parent)
    : QObject{parent}
    , m_filePath1(filePath1)
    , m_filePath2(filePath2)
    , m_lagging(Lagging)
    , m_imgX(X)
    , m_imgY(Y)
    , m_imgWidth(Width)
    , m_imgHeight(Height)
{
    qDebug() << "照片处理延时：" << m_lagging << " 毫秒";

    QDir dir(m_picLogPath);
    if(!dir.exists()){
        dir.mkpath(m_picLogPath);
        system(QString("chmod -R a+rwx %1").arg(m_picLogPath).toLocal8Bit());
    }
}

void FileMonitoringWorker::initFileMonitoring()
{
    // 初始化文件监控
    m_fileMonitoring = new QFileSystemWatcher(this);
    connect(m_fileMonitoring, SIGNAL(directoryChanged(QString)), this, SLOT(dealPicFiles(QString)));

    QDir dir(m_filePathData1);
    if(!dir.exists()){
        dir.mkpath(m_filePathData1);
        system(QString("chmod -R a+rwx %1").arg(m_filePathData1).toLocal8Bit());
    }

    m_fileMonitoring->addPath(m_filePathData1);
    qDebug() << "更新监控路径：" << m_filePathData1;
}

void FileMonitoringWorker::updatePath()
{
    if(m_fileMonitoring){
        m_fileMonitoring->deleteLater();
        m_fileMonitoring = nullptr;
    }

    m_filePathData1 = m_filePath1;
    m_picLogPath = QCoreApplication::applicationDirPath() + "/picLog/" + QDateTime::currentDateTime().toString("yyyyMMdd/");
    QDir dir(m_picLogPath);
    if(!dir.exists()){
        dir.mkpath(m_picLogPath);
    }

    //qDebug() << "m_picLogPath:  " << m_picLogPath;
    QDateTime currTime = QDateTime::currentDateTime();
    m_filePathData1.replace("%1", currTime.toString("yyyyMMdd"));
    m_filePathData1.replace("%2", currTime.toString("yyyy"));
    m_filePathData1.replace("%3", currTime.toString("MM"));
    m_filePathData1.replace("%4", currTime.toString("dd"));
    initFileMonitoring();
}

QFileInfo FileMonitoringWorker::getNewer(QFileInfo *file1, QFileInfo *file2)
{
    return *file1;
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

//void FileMonitoringWorker::sendPic2Led(QString base64)
//{
//    QImage img;
//    QByteArray arr_base64 = base64.toLatin1();
//    img.loadFromData(QByteArray::fromBase64(arr_base64.mid(base64.indexOf(",")+1)));
//    //img.loadFromData(QByteArray::fromBase64(arr_base64));
//    if(img.save(m_picLogPath + "1.jpeg")){
//        emit signalShowPic(m_picLogPath + "1.jpeg");
//    }
//}

void FileMonitoringWorker::initTimer()
{
    m_timer = new QTimer;
    connect(m_timer, &QTimer::timeout, this, [=](){
        if(QTime::currentTime().toString("ss:mm:ss") == "00:00:00"){
            updatePath();
            deleteBackUp();
        }

    });
    m_timer->setInterval(1000);
    m_timer->start();
}

QString FileMonitoringWorker::cutPic(QString filePath)
{
    if(filePath.isEmpty()) return "";

    QString savePath = m_picLogPath + filePath.split("/").last();
    QImage image;
    QImage image1;
    image.load(filePath);

    //image1 = image.scaledToHeight(310);
    image = image.copy(m_imgX, m_imgY, m_imgWidth, m_imgHeight);
    image = image.scaledToHeight(image.height()/2);
    image.save(savePath);

//    qDebug() << "------------------------------------------filePath: " << filePath;
//    qDebug() << "------------------------------------------savePath: " << savePath;
    return savePath;
}

void FileMonitoringWorker::deleteBackUp()
{
    QString path = QCoreApplication::applicationDirPath() + "/picLog/";
    qDebug() << "path:  " << path;

    //打开目录
    QDir dir(path);

    //提取文件信息链表
    QFileInfoList inforList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    //遍历文件信息链表,并进行相关操作
    foreach (QFileInfo info, inforList) {
        QDateTime dirTime = QDateTime::fromString(info.fileName(), "yyyyMMdd");
        QDateTime curTime = QDateTime::currentDateTime();
        if(dirTime.daysTo(curTime) > m_backSaveDays){
            QDir _dir;
            _dir.setPath(info.filePath());
            _dir.removeRecursively();
        }
    }

}

void FileMonitoringWorker::slotInitWorker()
{
    updatePath();

    system("chmod -R a+rwx /home");
    deleteBackUp();
}

void FileMonitoringWorker::dealPicFiles(QString fileName)
{
    //打开目录
    QDir dir(fileName);

    //提取文件信息链表
    QFileInfoList inforList = dir.entryInfoList(QDir::Files);
    QFileInfo pic;    // 待显示的照片

    int i = 0;
    //遍历文件信息链表,并进行相关操作
    foreach (QFileInfo info, inforList) {
        //qDebug() << "info.fileName():  "<< info.fileName();
        QString filePath = info.filePath();
        if(filePath.contains("_scale")){
            QFile _file(filePath);
            _file.remove();
            continue;
        }
        QThread::msleep(m_lagging);
        if(!i++){
            pic = info;
        }
        else{
            pic = getNewer(&pic, &info);
        }
    }

    QString oldName = pic.filePath();
    QString newName;

    /* 图片截取并保存 */
    newName = cutPic(oldName);
    emit signalShowPic(newName);

    /* 删除原图 */
    if(!oldName.isEmpty()) QFile::remove(oldName);

}
