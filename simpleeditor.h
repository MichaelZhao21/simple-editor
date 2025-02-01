#ifndef SIMPLEEDITOR_H
#define SIMPLEEDITOR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "components/videoplayer.h"

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

private:
    Ui::SimpleEditor *ui;
    VideoPlayer *player;

public slots:
    void selectVideoFile();

signals:
    void videoFileChanged(QString fileName);
};
#endif // SIMPLEEDITOR_H
