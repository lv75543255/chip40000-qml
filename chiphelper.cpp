#include "chiphelper.h"
#include "chip.h"
#include <QImage>
#include <QGraphicsScene>
ChipHelper::ChipHelper()
{


}

void ChipHelper::addChips(QObject *object)
{
    QGraphicsScene *scene = qobject_cast<decltype (scene)>(object);
    if(scene != nullptr) {
        QImage image(":/qt4logo.png");

        int xx = 0;
        int nitems = 0;
        constexpr int CHIP_COL = 200;
        constexpr int CHIP_ROW = 200;

        constexpr int CHIP_WIDTH = 110;
        constexpr int CHIP_HEIGHT = 70;
        constexpr int TOTAL_WIDTH = CHIP_WIDTH * CHIP_COL / 2;
        constexpr int TOTAL_HEIGHT = CHIP_HEIGHT * CHIP_ROW / 2;

        for (int i = - TOTAL_WIDTH; i < TOTAL_WIDTH; i += 110) {
            ++xx;
            int yy = 0;
            for (int j = -TOTAL_HEIGHT; j < TOTAL_HEIGHT; j += 70) {
                ++yy;
                qreal x = (i + TOTAL_WIDTH) / (TOTAL_WIDTH*2.0);
                qreal y = (j + TOTAL_HEIGHT) / (TOTAL_HEIGHT*2.0);

                QColor color(image.pixel(int(image.width() * x), int(image.height() * y)));
                QGraphicsItem *item = new Chip(color, xx, yy);
                item->setPos(QPointF(i, j));
                scene->addItem(item);

                ++nitems;
            }
        }

        qDebug("chips = %d row, count= %d",xx,nitems);
    }
    else {
        qDebug("Invalid parameter");
    }
}
