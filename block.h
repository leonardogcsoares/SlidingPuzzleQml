#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>

class Block : public QObject
{
    Q_OBJECT
public:
    explicit Block(QObject *parent = 0);
    Block(int index, int value);

    int index();
    void setIndex(int index);

    int value();
    void setValue(int value);

public slots:

private:
    int mIndex;
    int mValue;
};

#endif // BLOCK_H
