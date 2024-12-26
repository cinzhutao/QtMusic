#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化
    this->MediaInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 初始化函数
void MainWindow::MediaInit() {

    this->setWindowTitle("AcFun");
    this->setWindowIcon(QPixmap(":/Icon/Icon/AcFun.png"));

    // 初始化变量
    Player = new QMediaPlayer(this);
    PlayList = new QMediaPlaylist(this);
    videoWidget = new QVideoWidget(this);
    DataList = new QListWidget(this);
    Menu = new QMenu(this);
    deleteAll = new QAction("删除全部", this);

    // 功能性设置
    DataList->setContextMenuPolicy(Qt::CustomContextMenu);  // 设置自定义右键菜单
    Menu->addAction(deleteAll);  // 添加删除菜单项
    Player->setPlaylist(PlayList);
    //Player->setVideoOutput(videoWidget);
    ui->videoSlider->setSingleStep(0);
    ui->Begin->setDisabled(true);
    ui->back->setDisabled(true);
    ui->advance->setDisabled(true);
    this->setAcceptDrops(true);

    // 设置UI布局样式
    this->DataList->setStyleSheet("QListView { font: 25 9pt Microsoft YaHei; border: 15px solid white; border-radius: 10px; }"
                                  "QListView::item { height: 60px; }"
                                  "QListView::item:hover { background-color: transparent; padding: 10px; border-left: 3px solid rgb(130, 130, 130); }"
                                  "QListView::item:selected { background-color: transparent; color: black; padding: 10px; border-left: 3px solid black; }");

    //ui->horizontalLayout->addWidget(videoWidget, 10);
    //ui->horizontalLayout->addWidget(DataList, 0);
    ui->horizontalLayout->addWidget(DataList);
    ui->Begin->setIcon(QPixmap(":/Icon/Icon/begin.png"));
    ui->Begin->setIconSize(QSize(30, 30));
    ui->back->setIcon(QPixmap(":/Icon/Icon/back.png"));
    ui->back->setIconSize(QSize(30, 30));
    ui->advance->setIcon(QPixmap(":/Icon/Icon/advance.png"));
    ui->advance->setIconSize(QSize(30, 30));
    ui->volumeData->setIcon(QPixmap(":/Icon/Icon/volumeHigh.png"));
    ui->volumeData->setIconSize(QSize(30, 30));

    // 连接信号和槽函数
    connect(DataList, &QListWidget::itemDoubleClicked, this, &MainWindow::onItemDoubleClicked);  // 双击事件
    connect(DataList, &QListWidget::customContextMenuRequested, this, &MainWindow::showListWidgetMenuSlot);  // 右键菜单事件
    connect(deleteAll, &QAction::triggered, this, &MainWindow::deleteAllData);  // 删除所有数据事件
    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::GetDuration);  // 媒体时长变化事件
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::upDateSlider);;  // 媒体播放位置变化事件
    connect(Player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(slot_PlayError(QMediaPlayer::Error)));  // 播放错误事件
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::ChangeVoice);  // 音量变化事件
    connect(ui->videoSlider, &QSlider::sliderMoved, this, &MainWindow::MoveVideo);  // 视频进度变化事件
    connect(ui->btnInsertFile, &QPushButton::clicked, this, &MainWindow::InsertMediaFile);  // 导入媒体文件事件
    connect(ui->advance, &QPushButton::clicked, this, &MainWindow::PlayNextMedia);  // 播放下一首事件
    connect(ui->back, &QPushButton::clicked, this, &MainWindow::PlayPreviousMedia);  // 播放上一首事件
}

// 拖拽进入事件
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

// 拖拽离开事件
void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

// 拖拽移动事件
void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

// 拖拽放下事件
void MainWindow::dropEvent(QDropEvent *event)
{
    QString name;
    QList<QUrl> urls;
    QList<QUrl>::Iterator i;
    urls = event->mimeData()->urls();
    for(i = urls.begin(); i != urls.end(); ++i) {
        name = i->path();
        this->DataList->addItem(name);
    }

    PlayList->addMedia(QUrl::fromLocalFile(name));
    PlayList->setCurrentIndex(PlayList->mediaCount() -1);
    int newIndex = PlayList->currentIndex(); // 计算当前播放索引
    DataList->setCurrentRow(newIndex);  // 更新列表选中项
    Player->play();
}

// 播放错误提示
void MainWindow::slot_PlayError(QMediaPlayer::Error error) {
    QString text;
    if(QMediaPlayer::NoError == error)
    {
        text = "正常解码!";
    }
    else if(QMediaPlayer::ResourceError == error)
    {
        text = "媒体资源无法解析。";
    }
    else if(QMediaPlayer::FormatError == error)
    {
        text = "不支持该媒体资源的格式，没有解码器!";
    }
    else if(QMediaPlayer::NetworkError == error)
    {
        text = "发生网络错误。";
    }
    else if(QMediaPlayer::AccessDeniedError == error)
    {
        text = "没有适当的权限来播放媒体资源。";
    }
    else if(QMediaPlayer::ServiceMissingError == error)
    {
        text = "没有找到有效的播放服务，播放无法继续。";
    }

    QMessageBox::critical(this, "播放器提示", text, QMessageBox::Ok, QMessageBox::Ok);
}

// 更新视频进度条
void MainWindow::upDateSlider(qint64 position) {

    ui->Begin->setDisabled(false);
    ui->back->setDisabled(false);
    ui->advance->setDisabled(false);

    if(ui->videoSlider->isSliderDown()) {
        return;
    }

    double num_p = position;
    double num_d = Player->duration();

    ui->videoSlider->setSliderPosition(100 * num_p / num_d);

    QTime currentTime(0, 0, 0, 0);
    currentTime = currentTime.addMSecs(position);
    currentFormatTime = currentTime.toString("mm:ss");
    ui->BeginTime->setText(currentFormatTime);
}

// 获取视频总时长
void MainWindow::GetDuration(qint64 duration) {
    QTime totalTime = QTime(0, 0, 0, 0);
    totalTime = totalTime.addMSecs(duration);
    totalFormatTime = totalTime.toString("mm:ss");
    ui->EndTime->setText(totalFormatTime);
}

// 右键菜单显示
void MainWindow::showListWidgetMenuSlot(QPoint) {
    Menu->exec(QCursor::pos());
}

// 删除所有数据
void MainWindow::deleteAllData() {
    PlayList->clear();
    DataList->clear();
    Player->stop();
    ui->Begin->setIcon(QPixmap(":/Icon/Icon/begin.png"));
    ui->Begin->setIconSize(QSize(30, 30));
}

// 导入文件
void MainWindow::InsertMediaFile()
{
    QString strCurrentPath = QDir::homePath();
    QString stdDlgTitle = "请选择视频文件";
    QString strFilter = "MP3 File(*.mp3);;MP4 File(*.mp4);;All File(*.*)";
    QString strAllFiles = QFileDialog::getOpenFileName(this, stdDlgTitle,
                                                       strCurrentPath, strFilter);

    if(strAllFiles.isEmpty()) {
        QMessageBox::information(this, "错误", "打开视频文件失败，请重新检查", QMessageBox::Yes | QMessageBox::No);
        return;
    }

    QFileInfo fileInfos(strAllFiles);
    qDebug() << "文件信息: " << fileInfos.fileName() << ", path: " << fileInfos.filePath();

    DataList->addItem(fileInfos.filePath());
    ui->Begin->setIcon(QPixmap(":/Icon/Icon/pause.png"));
    PlayList->addMedia(QUrl::fromLocalFile(strAllFiles));
    PlayList->setCurrentIndex(PlayList->mediaCount() -1);
    //Player->setVideoOutput(videoWidget);
    int newIndex = PlayList->currentIndex(); // 计算当前播放索引
    DataList->setCurrentRow(newIndex);  // 更新列表选中项
    Player->play();
}

// 双击播放视频
void MainWindow::onItemDoubleClicked(QListWidgetItem *item) {
    int index = DataList->row(item); // 获取当前选中项的索引
    PlayList->setCurrentIndex(index); // 设置播放列表的当前索引
    Player->play(); // 开始播放
    ui->Begin->setIcon(QPixmap(":/Icon/Icon/pause.png")); // 更新按钮图标
}

// 开始/暂停按钮
void MainWindow::on_Begin_clicked()
{
    if(Player->state() ==  QMediaPlayer::PlayingState) {
        ui->Begin->setIcon(QPixmap(":/Icon/Icon/begin.png"));
        Player->pause();  // 暂停播放
    } else {
        ui->Begin->setIcon(QPixmap(":/Icon/Icon/pause.png"));
        Player->play();  // 开始播放
    }
}


// 设置视频播放速度
void MainWindow::on_Speed_currentIndexChanged(const QString &arg1)
{
    Player->setPlaybackRate(arg1.toDouble());
}

// 一键静音
void MainWindow::on_volumeData_clicked()
{
    if(back_volume == 0 && ui->volumeValue->text() == "0 ") {
        ui->volumeData->setIcon(QPixmap(":/Icon/Icon/volumeCross.png"));
        return;
    }

    if(++flag_back_volume % 2 != 0) {
        back_volume = ui->volumeValue->text().toInt();
    }

    if(ui->volumeValue->text().toInt() != 0) {
        ui->volumeSlider->setValue(0);
        Player->setVolume(0);
        ui->volumeValue->setText(QString::number(0) + QString(" "));
        ui->volumeData->setIcon(QPixmap(":/Icon/Icon/volumeCross.png"));
    } else {
        ui->volumeSlider->setValue(back_volume);
        Player->setVolume(back_volume);
        if(back_volume < 10){
            ui->volumeValue->setText(QString::number(back_volume) + QString(" "));
        } else{
            ui->volumeValue->setText(QString::number(back_volume));
        }
        ui->volumeData->setIcon(QPixmap(":/Icon/Icon/volumeHigh.png"));
    }
}

// 更新音量
void MainWindow::ChangeVoice(int volumeData) {
    Player->setVolume(volumeData);
    if(volumeData == 0) {
        ui->volumeValue->setText(QString("0 "));
        ui->volumeData->setIcon(QPixmap(":/Icon/Icon/volumeCross.png"));
    } else if(volumeData < 10) {
        ui->volumeValue->setText(QString::number(volumeData) + QString(" "));
    }
    else {
        ui->volumeValue->setText(QString::number(volumeData));
        ui->volumeData->setIcon(QPixmap(":/Icon/Icon/volumeHigh.png"));
    }
}

// 更新视频进度
void MainWindow::MoveVideo(int videoData) {
    double num_d = Player->duration();
    Player->setPosition(videoData * 1000 * (num_d / 100000));
}

// 捕获键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << event->key();
    switch (event->key()) {
    case Qt::Key_Space:
        on_Begin_clicked();
        break;
    default:
        break;
    }
}

// 播放下一首
void MainWindow::PlayNextMedia() {
    if (PlayList->mediaCount() == 0) return; // 检查播放列表是否为空
    if (PlayList->currentIndex() == PlayList->mediaCount() - 1) {
        PlayList->setCurrentIndex(0); // 循环播放到第一首
    } else {
        PlayList->next(); // 播放下一首
    }
    int newIndex = PlayList->currentIndex(); // 计算当前播放索引
    DataList->setCurrentRow(newIndex);  // 更新列表选中项
    Player->play();
}

// 播放上一首
void MainWindow::PlayPreviousMedia() {
    if (PlayList->mediaCount() == 0) return; // 检查播放列表是否为空
    if (PlayList->currentIndex() == 0) {
        PlayList->setCurrentIndex(PlayList->mediaCount() - 1); // 循环播放到最后一首
    } else {
        PlayList->previous(); // 播放上一首
    }
    int newIndex = PlayList->currentIndex(); // 计算当前播放索引
    DataList->setCurrentRow(newIndex);  // 更新列表选中项
    Player->play();
}

