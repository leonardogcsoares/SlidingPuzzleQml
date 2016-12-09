#ifndef JOGO_H
#define JOGO_H

#include <QObject>
#include <QList>
#include <QQuickView>
#include <QUrl>
#include "gamemodel.h"

#define TAM 4

class Jogo : public QObject
{
    Q_OBJECT
public:
    explicit Jogo(QObject *parent = 0);
    Jogo(QUrl url);
    Q_INVOKABLE void cellClicked(int value, int index);
    QList<QObject*> refreshDataList();
signals:

public slots:
    void refresh();
//    void saveClicked();
//    void loadClicked();

private:
    int currentMatrix[TAM][TAM];
    GameModel *mArray[TAM][TAM];
    QQuickView mView;
    QQmlContext *mCtxt;
    int test;
};

#endif // JOGO_H
