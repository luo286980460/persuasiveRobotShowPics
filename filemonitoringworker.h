#ifndef FILEMONITORINGWORKER_H
#define FILEMONITORINGWORKER_H

#include <QObject>

class QFileSystemWatcher;
class QFileInfo;

class FileMonitoringWorker : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitoringWorker(QString filePath, QObject *parent = nullptr);

private:
    void initFileMonitoring();              // 打开文件监控
    void updatePath();                      // 更新文件路径
    QFileInfo getNewer(QFileInfo* file1, QFileInfo* file2);  // 比较返回相对较新的文件
    void sendPic2Led(QString base64);
    void unPackJson(QJsonObject& json);


signals:
    void showMsg(QString msg);
    void signalShowPic(QString picPath);

public slots:
    void slotInitWorker();                  // 初始化工作类

private slots:
    void dealPicFiles(QString path);

private:
    QFileSystemWatcher* m_fileMonitoring;   // 文件监控
    QString m_filePath;                     // 文件监控路径
    QString m_filePathData;                 // 文件监控带日期
};

#endif // FILEMONITORINGWORKER_H
