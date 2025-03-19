#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>

class Scrubber : public QWidget
{
public:
    explicit Scrubber(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setFillPercent(float percent);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    float percent;
};

#endif // RENDERAREA_H
