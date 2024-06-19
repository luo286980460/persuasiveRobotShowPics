#ifndef FILEMONITORINGWORKER_H
#define FILEMONITORINGWORKER_H

#include <QObject>
#include <QTimer>

class QFileSystemWatcher;
class QFileInfo;

class FileMonitoringWorker : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitoringWorker(QString filePath1, QString filePath2, int Lagging, QObject *parent = nullptr);

private:
    void initFileMonitoring();              // 打开文件监控
    void updatePath();                      // 更新文件路径
    QFileInfo getNewer(QFileInfo* file1, QFileInfo* file2);  // 比较返回相对较新的文件
    void sendPic2Led(QString base64);
    void unPackJson(QJsonObject& json);
    void initTimer();


signals:
    void showMsg(QString msg);
    void signalShowPic(QString picPath);

public slots:
    void slotInitWorker();                  // 初始化工作类

private slots:
    void dealPicFiles(QString path);

private:
    QFileSystemWatcher* m_fileMonitoring;   // 文件监控
    QString m_filePath1;                    // 文件监控路径
    QString m_filePath2;                    // 文件监控路径
    QString m_filePathData1;                // 文件监控带日期
    QString m_filePathData2;                // 文件监控带日期
    QString m_picLogPath;                   // 照片临时存储路径
    int m_lagging;                          // 照片处理延迟
    QTimer* m_timer = nullptr;
};

#endif // FILEMONITORINGWORKER_H
