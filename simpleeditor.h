#ifndef SIMPLEEDITOR_H
#define SIMPLEEDITOR_H

#include <QMainWindow>
#include <QGraphicsVideoItem>

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

private:
    Ui::SimpleEditor *ui;
    QGraphicsVideoItem* videoItem;
};
#endif // SIMPLEEDITOR_H
