#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class VideoPlayer;
}
QT_END_NAMESPACE

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();

protected:
    void updateVideoViewFit();
    void resizeEvent(QResizeEvent* event);
    void updateVideo(QString fileName);
    void setPositionDisplay(qint64 position);
    void toggleActions(bool seekable);

private:
    Ui::VideoPlayer *ui;
    QMediaPlayer *player;
    QAudioOutput *audio;
    QGraphicsVideoItem *videoItem;
    QString fileName;

public slots:
    void setVideoFile(QString fileName);
};

#endif // VIDEOPLAYER_H
