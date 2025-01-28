#include "simpleeditor.h"
#include "./ui_simpleeditor.h"
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QPainter>
#include <QPalette>

SimpleEditor::SimpleEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleEditor)
{
    ui->setupUi(this);

    // ui->widget_grid
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);
    ui->widget_grid->setPalette(pal);
    ui->widget_grid->setAutoFillBackground(true);

    // Video player
    QMediaPlayer* player = new QMediaPlayer(this);
    videoItem = new QGraphicsVideoItem;
    player->setVideoOutput(videoItem);
    QGraphicsScene* gs = new QGraphicsScene(this);
    gs->addItem(videoItem);
    ui->videoView->setScene(gs);
    ui->videoView->show();
    ui->videoView->setRenderHint(QPainter::SmoothPixmapTransform);
    updateVideoViewFit();

    connect(gs, &QGraphicsScene::sceneRectChanged, this, &SimpleEditor::updateVideoViewFit);

    player->setSource(QUrl("https://cdn.mikz.dev/hackutd-devday-workshop/videos/ass-class.mp4"));
    player->play();
}

SimpleEditor::~SimpleEditor()
{
    delete ui;
}

void SimpleEditor::updateVideoViewFit()
{
    if (videoItem) {
        ui->videoView->fitInView(videoItem, Qt::KeepAspectRatio);
    }
}

void SimpleEditor::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    updateVideoViewFit();
}
