#include <QGuiApplication>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QDebug>
#include <QObject>


#include "mytable.h"
#include "jogo.h"
#include "block.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Jogo* jogo = new Jogo();
//    Jogo* jogo = new Jogo(QUrl("qrc:/main.qml"));
    qmlRegisterType<Jogo>("GameComponents", 1, 0, "Jogo");

    QQuickView *view = new QQuickView;
    view->setSource(QUrl("qrc:/main.qml"));
    view->show();
//    this->mCtxt = this->mView->rootContext();
    jogo->initMatrix(view);



//    view.show();
    return app.exec();
}
