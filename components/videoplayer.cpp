#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);

    // Create Media Player and video item
    // then add video item to player
    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    videoItem = new QGraphicsVideoItem;
    player->setVideoOutput(videoItem);
    player->setAudioOutput(audio);

    // Create graphics scene to add to video item
    QGraphicsScene* gs = new QGraphicsScene(this);
    gs->addItem(videoItem);
    ui->graphicsView->setScene(gs);

    // Show and scale video
    ui->graphicsView->show();
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
    updateVideoViewFit();

    // Set default video
    // remove once done
    // player->setSource(QUrl("https://cdn.mikz.dev/hackutd-devday-workshop/videos/ass-class.mp4"));
    player->setSource(QUrl::fromLocalFile("/home/mikey/Downloads/ElephantsDream.mp4"));
    player->play();
    audio->setVolume(40);

    // Update video size on resize
    connect(gs, &QGraphicsScene::sceneRectChanged, this, &VideoPlayer::updateVideoViewFit);

    // Update duration display on change
    connect(player, &QMediaPlayer::positionChanged, this, &VideoPlayer::setPositionDisplay);
    connect(player, &QMediaPlayer::seekableChanged, this, &VideoPlayer::toggleActions);
}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}

void VideoPlayer::updateVideoViewFit()
{
    if (videoItem) {
        ui->graphicsView->fitInView(videoItem, Qt::KeepAspectRatio);
    }
}

void VideoPlayer::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    updateVideoViewFit();
}

void VideoPlayer::setVideoFile(QString newFileName) {
    player->setSource(QUrl::fromLocalFile(newFileName));
    player->play();
}

void VideoPlayer::setPositionDisplay(qint64 position) {
    ui->timeText->setText(QString::number(position / 1000.0));
}

void VideoPlayer::toggleActions(bool seekable) {
    // If not seekable, disable all actions
    if (!seekable) {
        ui->playPause->setDisabled(true);
        return;
    }

    if (player->isSeekable()) {
        ui->playPause->setDisabled(false);
    }
}
