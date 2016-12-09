#include <QGuiApplication>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QDebug>
#include <QObject>

#include "gamemodel.h"
#include "mytable.h"
#include "jogo.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<Jogo>("GameComponents", 1, 0, "Jogo");

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    QList<QObject*> dataList;
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

//    for (int i=0; i < dataList.count(); i++) {
//        GameModel* gm = (GameModel*) dataList[i];
//        gm->setValue(dataList.count() - i-1);
//        gm->valueChanged();
//    }

//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    QQmlContext *ctxt = view.rootContext();
//    view.setSource(QUrl("qrc:/main.qml"));

    Jogo* jogo = new Jogo(QUrl("qrc:/main.qml"));






//    view.show();
    return app.exec();
}
