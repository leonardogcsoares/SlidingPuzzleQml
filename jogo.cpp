#include "jogo.h"
#include "gamemodel.h"
#include <QList>
#include <QDebug>
#include <QQuickView>
#include <QUrl>
#include <QQmlContext>


Jogo::Jogo(QObject *parent) : QObject(parent)
{

}

Jogo::Jogo(QUrl url) {
    QList<QObject*> dataList;
    dataList.append(new GameModel(0, 0));
    dataList.append(new GameModel(1, 1));
    dataList.append(new GameModel(2, 2));
    dataList.append(new GameModel(3, 3));
    dataList.append(new GameModel(4, 4));
    dataList.append(new GameModel(5, 5));
    dataList.append(new GameModel(6, 6));
    dataList.append(new GameModel(7, 7));
    dataList.append(new GameModel(8, 8));
    dataList.append(new GameModel(9, 9));
    dataList.append(new GameModel(10, 10));
    dataList.append(new GameModel(11, 11));
    dataList.append(new GameModel(12, 12));
    dataList.append(new GameModel(13, 13));
    dataList.append(new GameModel(14, 14));
    dataList.append(new GameModel(15, 15));

    for (int i=0; i < dataList.count(); i++) {
        getDataList().append(dataList.at(i));
    }

//    this->mDataList = dataList;
    qDebug() << "Data list size:" << getDataList().count();


    this->mView.setResizeMode(QQuickView::SizeRootObjectToView);
    this->mCtxt = this->mView.rootContext();
    this->mView.setSource(url);
    this->mCtxt->setContextProperty("gameModel", QVariant::fromValue(dataList));
}

void Jogo::cellClicked(int value, int index) {

//    this->mDataList.replace(index, new GameModel(90, index));

//    GameModel* gm = (GameModel*) this->mDataList[index];
    qDebug() << "Value: " << value << " Index: " << index << " DataList length: " << getDataList().count();
//    gm->setValue(90);
//    gm->valueChanged();
}

static QList<QObject*> Jogo::getDataList() {
    return mDataList;
}
