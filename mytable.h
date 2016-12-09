#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QVariant>

class MyTable : public QObject
{
    Q_OBJECT
public:
    explicit MyTable(QObject *parent = 0);

public slots:
    void cppSlot(const QString &v);
};

#endif // MYTABLE_H
