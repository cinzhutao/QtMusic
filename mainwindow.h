#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QSlider>
#include <QMouseEvent>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);  // 构造函数
    void MediaInit();  // 媒体初始化函数
    void dragEnterEvent(QDragEnterEvent *event);  // 拖拽进入事件
    void dragLeaveEvent(QDragLeaveEvent *event);  // 拖拽离开事件
    void dragMoveEvent(QDragMoveEvent *event);  // 拖拽移动事件
    void dropEvent(QDropEvent *event);  // 拖拽放下事件
    ~MainWindow();  // 析构函数

private slots:
    void InsertMediaFile();  // 导入媒体文件操作槽函数
    void on_Begin_clicked();  // 播放/暂停按钮点击事件
    void onItemDoubleClicked(QListWidgetItem * item);  // 列表项双击事件
    void showListWidgetMenuSlot(QPoint);  // 显示右键菜单槽函数
    void deleteAllData();  // 删除所有数据槽函数
    void GetDuration(qint64);  // 获取视频时长
    void upDateSlider(qint64);  // 更新进度条
    void slot_PlayError(QMediaPlayer::Error);  // 播放错误提示
    void ChangeVoice(int);  // 调整音量
    void MoveVideo(int);  // 调整视频进度
    void on_volumeData_clicked();  // 音量图标点击事件
    void keyPressEvent(QKeyEvent *event);  // 键盘按键事件
    void on_Speed_currentIndexChanged(const QString &arg1);  // 播放速度改变事件
    void PlayNextMedia();  // 播放下一首
    void PlayPreviousMedia();  // 播放上一首

private:
    Ui::MainWindow *ui;  // UI对象
    QMediaPlayer *Player;  // 媒体播放器对象
    QMediaPlaylist *PlayList;  // 媒体播放器列表
    QVideoWidget *videoWidget;  // 视频显示控件
    QListWidget *DataList;  // 数据列表
    QMenu *Menu;  // 右键菜单
    QAction *deleteAll;  // 删除所有数据的菜单项
    QString totalFormatTime;  // 视频总时长
    QString currentFormatTime;  // 当前播放时间
    int back_volume = 0;  // 上次音量值
    int flag_back_volume = 0;  // 音量状态标识

};

#endif // MAINWINDOW_H
