#ifndef FILEMONITORINGWORKER_H
#define FILEMONITORINGWORKER_H

#include <QObject>
#include <QTimer>
#include <QSize>

class QFileSystemWatcher;
class QFileInfo;

class FileMonitoringWorker : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitoringWorker(QString filePath1, QString filePath2, int Lagging,
                                  int X, int Y, int Width, int Height, QObject *parent = nullptr);

private:
    void initFileMonitoring();              // 打开文件监控
    void updatePath();                      // 更新文件路径
    QFileInfo getNewer(QFileInfo* file1, QFileInfo* file2);  // 比较返回相对较新的文件
//    void sendPic2Led(QString base64);
    void initTimer();
    QString cutPic(QString filePath);
    QString cutPicFromJson(QString filePath, QString illgCode);

    void deleteBackUp();    // 清理备份文件


signals:
    void showMsg(QString msg);
    void signalShowPic(QString picPath);

public slots:
    void slotInitWorker();                  // 初始化工作类

private slots:
    void dealPicFiles(QString fileName);

private:
    QFileSystemWatcher* m_fileMonitoring    // 文件监控
        = nullptr;
    QString m_filePath1;                    // 文件监控路径
    QString m_filePath2;                    // 文件监控路径
    QString m_filePathData1;                // 文件监控带日期
    //QString m_filePathData2;              // 文件监控带日期
    QString m_picLogPath;                   // 照片临时存储路径
    int m_lagging;                          // 照片处理延迟
    QTimer* m_timer = nullptr;
    int m_imgX                              // 照片截图左上角x坐标
        ;
    int m_imgY                              // 照片截图左上角y坐标
        ;
    int m_imgWidth                          // 照片截图宽度
        ;
    int m_imgHeight                         // 照片截图高度
        ;
    int m_backSaveDays = 3;                 // 备份文件保存时间
};
#endif // FILEMONITORINGWORKER_H
