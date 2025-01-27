#ifndef SIMPLEEDITOR_H
#define SIMPLEEDITOR_H

#include <QMainWindow>

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
};
#endif // SIMPLEEDITOR_H
