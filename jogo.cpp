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
    QList<GameModel*> dataList;
//    dataList.append(new GameModel(0, 0));
//    dataList.append(new GameModel(1, 1));
//    dataList.append(new GameModel(2, 2));
//    dataList.append(new GameModel(3, 3));
//    dataList.append(new GameModel(4, 4));
//    dataList.append(new GameModel(5, 5));
//    dataList.append(new GameModel(6, 6));
//    dataList.append(new GameModel(7, 7));
//    dataList.append(new GameModel(8, 8));
//    dataList.append(new GameModel(9, 9));
//    dataList.append(new GameModel(10, 10));
//    dataList.append(new GameModel(11, 11));
//    dataList.append(new GameModel(12, 12));
//    dataList.append(new GameModel(13, 13));
//    dataList.append(new GameModel(14, 14));
//    dataList.append(new GameModel(15, 15));

    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            int val = TAM*i + j;
            GameModel *model = new GameModel(val, val);
            dataList.append(model);
            this->mArray[i][j] = model;
        }
    }

    this->mView.setResizeMode(QQuickView::SizeRootObjectToView);
    this->mCtxt = this->mView.rootContext();
    this->mView.setSource(url);
    this->mCtxt->setContextProperty("gameModel", &dataList);
    this->mCtxt->setContextProperty("jogoBase", this);
}

void Jogo::refresh() {
    qDebug() << "Called refresh ";

    this->refreshDataList();
}

QList<QObject*> Jogo::refreshDataList() {
    QList<QObject*> dataList;
    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            dataList.append(this->mArray[i][j]);
        }
    }
    this->mCtxt->setContextProperty("gameModel", &dataList);
}

void Jogo::cellClicked(int value, int index) {

    qDebug() << "Value: " << value << " Index: " << index << " DataList length: " ;
    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            int val = TAM*i + j;
            if (val == index) {
                this->mArray[i][j]->mValue = 90;
            }
        }
    }
//    this->refreshDataList();
//    gm->setValue(90);
//    gm->valueChanged();
}
