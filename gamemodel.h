#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>

class GameModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int index READ index)
public:
    explicit GameModel(QObject *parent = 0);
    GameModel(int value, int index);

    int value();
    void setValue(int value);

    int index();

signals:
    void valueChanged();

public slots:

private:
    int mValue;
    int mIndex;

};

#endif // GAMEMODEL_H
