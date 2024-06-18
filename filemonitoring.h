#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QThread>

class FileMonitoringWorker;

class FileMonitoring : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitoring(QString filePath, QObject *parent = nullptr);
    ~FileMonitoring();

    void start();
    void stop();

signals:
    void signalInitWorker();
    void showMsg(QString msg);
    void signalShowPic(QString picPath);

private:
    QThread m_workerThread;                 // 工作线程
    FileMonitoringWorker *m_work = nullptr; // 工作类
};

#endif // FILEMONITORING_H
