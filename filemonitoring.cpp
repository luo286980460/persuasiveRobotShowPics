#include "filemonitoring.h"
#include "filemonitoringworker.h"

FileMonitoring::FileMonitoring(QString filePath1, QString filePath2, int Lagging,
                               int X, int Y, int Width, int Height, int m_manuallyCutImgSwitch, QObject *parent)
    : QObject{parent}
{
    m_work = new FileMonitoringWorker(filePath1, filePath2, Lagging, X, Y, Width, Height, m_manuallyCutImgSwitch);
    m_work->moveToThread(&m_workerThread);

    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);    // 退出线程必加

    connect(m_work,SIGNAL(showMsg(QString)), this, SIGNAL(showMsg(QString)));
    connect(this, &FileMonitoring::signalInitWorker, m_work, &FileMonitoringWorker::slotInitWorker);       // 初始化工作类
    connect(m_work, &FileMonitoringWorker::signalShowPic, this, &FileMonitoring::signalShowPic);       // 初始化工作类
}

FileMonitoring::~FileMonitoring()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void FileMonitoring::start()
{
    emit signalInitWorker();
    m_workerThread.start();
}

void FileMonitoring::stop()
{
    m_workerThread.quit();
    m_workerThread.wait();
}
