#include "mytable.h"
#include <QDebug>
#include <QQuickItem>
#include <QObject>

MyTable::MyTable(QObject *parent) : QObject(parent)
{

}

void MyTable::cppSlot(const QString &v)  {
    qDebug() << "Called the C++ slot with value:" << v;
}
