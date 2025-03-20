#ifndef SCRUBBER_H
#define SCRUBBER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class Scrubber;
}
QT_END_NAMESPACE

class Scrubber : public QWidget
{
    Q_OBJECT

public:
    explicit Scrubber(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setFillPercent(float percent);

signals:
    void seeked(qreal percent);

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    float percent;
};

#endif // SCRUBBER_H
