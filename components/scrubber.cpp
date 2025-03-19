#include "scrubber.h"

Scrubber::Scrubber(QWidget *parent)
{
    percent = 0.0f;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize Scrubber::sizeHint() const
{
    return QSize(1000, 20);
}

QSize Scrubber::minimumSizeHint() const
{
    return QSize(400, 20);
}

void Scrubber::setFillPercent(float percent)
{
    this->percent = percent;
    update();
}

void Scrubber::paintEvent(QPaintEvent *event)
{
    int end = this->width() * percent;
    QRect rect(0, 0, end, 20);

    QPainter painter(this);
    painter.fillRect(rect, QColor(0, 0, 0));
}
