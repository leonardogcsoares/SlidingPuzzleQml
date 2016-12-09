#ifndef JOGO_H
#define JOGO_H

#include <QObject>
#include <QList>
#include <QQuickView>
#include <QUrl>

class Jogo : public QObject
{
    Q_OBJECT
public:
    explicit Jogo(QObject *parent = 0);
    Jogo(QUrl url);
    Q_INVOKABLE void cellClicked(int value, int index);
    static QList<QObject*> getDataList();
signals:

public slots:
//    void saveClicked();
//    void loadClicked();

private:
    static QList<QObject*> mDataList;
    QQuickView mView;
    QQmlContext *mCtxt;
};

#endif // JOGO_H
