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
#include <QPixmap>
#include <QLabel>

#include "filemonitoringworker.h"

FileMonitoringWorker::FileMonitoringWorker(QString filePath1, QString filePath2, int Lagging,
                                           int X, int Y, int Width, int Height, int m_manuallyCutImgSwitch, QObject *parent)
    : QObject{parent}
    , m_filePath1(filePath1)
    , m_filePath2(filePath2)
    , m_lagging(Lagging)
    , m_imgX(X)
    , m_imgY(Y)
    , m_imgWidth(Width)
    , m_imgHeight(Height)
    , m_manuallyCutImgSwitch(m_manuallyCutImgSwitch)
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

    // QDir dir(m_filePathData1);
    // if(!dir.exists()){
    //     dir.mkpath(m_filePathData1);
    //     system(QString("chmod -R a+rwx %1").arg(m_filePathData1).toLocal8Bit());
    // }

    // m_fileMonitoring->addPath(m_filePathData1);

    QDir dir1(m_filePath1);
    if(!dir1.exists()){
        dir1.mkpath(m_filePath1);
        system(QString("chmod -R a+rwx %1").arg(m_filePath1).toLocal8Bit());
    }

    QDir dir2(m_filePath2);
    if(!dir2.exists()){
        dir2.mkpath(m_filePath2);
        system(QString("chmod -R a+rwx %1").arg(m_filePath2).toLocal8Bit());
    }

    m_fileMonitoring->addPath(m_filePath1);
    m_fileMonitoring->addPath(m_filePath2);


    qDebug() << "更新监控路径：" << m_filePath1;
    qDebug() << "更新监控路径：" << m_filePath2;
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
    // m_filePathData1.replace("%1", currTime.toString("yyyyMMdd"));
    // m_filePathData1.replace("%2", currTime.toString("yyyy"));
    // m_filePathData1.replace("%3", currTime.toString("MM"));
    // m_filePathData1.replace("%4", currTime.toString("dd"));



    m_filePath1.replace("%1", currTime.toString("yyyy-MM-dd"));
    m_filePath2.replace("%1", currTime.toString("yyyy-MM-dd"));

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
    image.load(filePath);

    //image1 = image.scaledToHeight(310);
    image = image.copy(m_imgX, m_imgY, m_imgWidth, m_imgHeight);
    if(!image.isNull())
        image = image.scaledToHeight(image.height()/2);
    image.save(savePath);

//    qDebug() << "------------------------------------------filePath: " << filePath;
//    qDebug() << "------------------------------------------savePath: " << savePath;
    return savePath;
}

QString FileMonitoringWorker::cutPicFromJson(QString filePath, QString illgCode)
{
    if(filePath.isEmpty()) return "";

    QString savePath = m_picLogPath + filePath.split("/").last().replace(".json", ".jpg");
    QJsonDocument jsonDoc;                  // 源文件 json
    QJsonObject jsonObj;
    QByteArray imgData;                     // 原图的字节数组
    QImage image;                           // 原图
    QStringList cutValeList;                // 裁切图片的所需参数列表
    int cutX, cutY, cutWidth, cutHeight;    // 裁切图片的所需参数整型
    QString illegalCode;

    QFile file(filePath);
    if(file.exists() && file.open(QIODevice::ReadWrite)){
        QByteArray by = file.readAll();
        jsonDoc = QJsonDocument::fromJson( by);
        jsonObj = jsonDoc.object();
        //qDebug() << "by: " << by;
    }else{
        return "";
    }

    imgData = QByteArray::fromBase64(jsonObj.value("zpstr1").toString().split(",",QString::SkipEmptyParts).last().toLocal8Bit());
    image.loadFromData(imgData, "JPG");

    //cutValeList = jsonObj.value("clwz").toString().split(",",QString::SkipEmptyParts);
    //image1 = image.scaledToHeight(310);
    if(jsonObj.value("clwz").isString() && cutValeList.size() == 4  && !m_manuallyCutImgSwitch){
        cutX = cutValeList.at(0).toInt();
        cutY = cutValeList.at(1).toInt();
        cutWidth = cutValeList.at(2).toInt();
        cutHeight = cutValeList.at(3).toInt();
        image = image.copy(cutX, cutY, cutWidth, cutHeight);
    }else{
        image = image.copy(m_imgX, m_imgY, m_imgWidth, m_imgHeight);
        image = image.scaledToHeight(image.height()/2);
    }

    if(!image.isNull()){
        image = image.scaledToHeight(image.height()/2);
    }

    image.save(savePath);
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
    QString illgCode;   // 违法代码
    // 读取json源文件
    QDir dir(fileName);

    //提取文件信息链表
    QFileInfoList inforList = dir.entryInfoList(QDir::Files);
    QFileInfo pic;    // 待显示的照片

    // 文件名 _ 分割 第一个是违法行为
    /**
        01 不戴头盔
        02 违法载人
        03 加载车棚
        04 违法超员
        05 危险驾驶
        06 逆向行驶
    **/

    int i = 0;
    //遍历文件信息链表,并进行相关操作
    foreach (QFileInfo info, inforList) {
        //qDebug() << "info.fileName():  "<< info.fileName();
        QString fileName = info.fileName();
        QString filePath = info.filePath();
        // 违法行为代码
        QString illgCode = fileName.split("_", QString::SkipEmptyParts).at(1);
        if(illgCode != "01" && illgCode != "02" && illgCode != "03"
            && illgCode != "04" && illgCode != "05" && illgCode != "06"){

            QFile _file(filePath);
            _file.remove();
            continue;
        }

        QThread::msleep(m_lagging);
        if(!i){
            pic = info;
            ++i;
        }
        else{
            pic = getNewer(&pic, &info);
        }
    }

    QString oldName = pic.filePath();
    QString newName;
    //qDebug() << "oldName: " << oldName;

    /* 图片截取并保存 json源文件 */
    newName = cutPicFromJson(oldName, illgCode);

    emit signalShowPic(newName);

    /* 删除原图 */
    if(!oldName.isEmpty()) {
        QFile::remove(oldName);
    }



    // {   // 读取图片源文件
    //     //打开目录
    //     QDir dir(fileName);

    //     //提取文件信息链表
    //     QFileInfoList inforList = dir.entryInfoList(QDir::Files);
    //     QFileInfo pic;    // 待显示的照片

    //     int i = 0;
    //     //遍历文件信息链表,并进行相关操作
    //     foreach (QFileInfo info, inforList) {
    //         //qDebug() << "info.fileName():  "<< info.fileName();
    //         QString filePath = info.filePath();
    //         if(filePath.contains("_scale") || filePath.contains("_510_")){
    //             QFile _file(filePath);
    //             _file.remove();
    //             continue;
    //         }
    //         QThread::msleep(m_lagging);
    //         if(!i){
    //             pic = info;
    //             ++i;
    //         }
    //         else{
    //             pic = getNewer(&pic, &info);
    //         }
    //     }

    //     QString oldName = pic.filePath();
    //     QString newName;
    //     //qDebug() << "oldName: " << oldName;

    //     /* 图片截取并保存 */
    //     newName = cutPic(oldName);
    //     emit signalShowPic(newName);

    //     /* 删除原图 */
    //     if(!oldName.isEmpty()) QFile::remove(oldName);
    // }

}
