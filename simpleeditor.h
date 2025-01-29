#ifndef SIMPLEEDITOR_H
#define SIMPLEEDITOR_H

#include <QMainWindow>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui {
class SimpleEditor;
}
QT_END_NAMESPACE

class SimpleEditor : public QMainWindow
{
    Q_OBJECT

public:
    SimpleEditor(QWidget *parent = nullptr);
    ~SimpleEditor();

protected:
    void updateVideoViewFit();
    void resizeEvent(QResizeEvent* event);
    void updateVideo(QString fileName);

private:
    Ui::SimpleEditor *ui;
    QGraphicsVideoItem* videoItem;
    QString fileName;
    QMediaPlayer* player;

public slots:
    void selectVideoFile();
};
#endif // SIMPLEEDITOR_H
