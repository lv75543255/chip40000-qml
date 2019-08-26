#ifndef CHIPHELPER_H
#define CHIPHELPER_H

#include <QObject>
class ChipHelper:public QObject
{
    Q_OBJECT
public:
    ChipHelper();

    Q_INVOKABLE void addChips(QObject *object);
};

#endif // CHIPHELPER_H
