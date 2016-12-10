#include "jogo.h"

#include "block.h"
#include <QList>
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>
#include <QDebug>
#include <QQuickView>
#include <QQuickItem>
#include <QUrl>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QQmlComponent>


void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

Jogo::Jogo(QObject *parent) : QObject(parent)
{

}

// Declaration of Static Variables
int Jogo::currentMatrix[TAM][TAM];
Block* Jogo::mArray[TAM][TAM];
QQuickView* Jogo::mView;
int Jogo::moves = 0;

void Jogo::initMatrix(QQuickView *view) {

    this->mView = view;

    this->newGame();
}

void Jogo::newGame() {
    // Initialize the default matrix
    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            int index = TAM*i + j;
            int val = index + 1;
            if (i == 3 && j == 3) {
                val = 0;
            }

            Block *model = new Block(index, val);
            this->mArray[i][j] = model;

            QString formattedString = QString("cell%1%2").arg(QString::number(i), QString::number(j));
            QObject* cell = this->mView->rootObject()->findChild<QObject*>(formattedString);
            if (cell) {
                cell->setProperty("text", val == 0 ? QString(" ") : QString::number(val));
            } else {
                qDebug("Cell not found");
            }
        }
    }
//    this->randomize();
}

void Jogo::randomize() {
    this->moves = 0;
    srand(time(NULL));

    int zPosx = 3, zPosy = 3;
    for (int a = 0; a < 10000; ++a) {
        int option = rand()%4;
//        std::cout << zPosx * TAM + zPosy << " Option: " << option << std::endl;
        switch (option) {
        case 0:
            if (zPosx != 0) zPosx = zPosx - 1;
            break;
        case 1:
            if (zPosx != 3) zPosx = zPosx + 1;
            break;
        case 2:
            if (zPosy != 0) zPosy = zPosy - 1;
            break;
        case 3:
            if (zPosy != 3) zPosy = zPosy + 1;
            break;
        }
        this->cellClicked(zPosx * TAM + zPosy, true);
    }

//    this->printMatrix();
}


void Jogo::refresh() {
    qDebug() << "Called refresh ";

}

void Jogo::cellClicked(int index, bool randomizing) {
//    qDebug() << "Cell clicked " << index;
    int currentX, currentY;
    bool switchFound = false;


    // Check safe to avoid bugs
    if (index > 15)
        return;

    for (int i=0; i < TAM; i++) {
        for (int j=0; j< TAM; j++) {
            int calcIndex = i*TAM+j;
            if (calcIndex == index) {
                currentX = i;
                currentY = j;
            }
        }
    }

    int switchX, switchY;

    // Check North
    if (currentX > 0) {
        switchX = currentX-1;
        switchY = currentY;
        if (this->mArray[switchX][switchY]->value() == 0) {
            switchFound = true;
        }
    }
    // Check South
    if (currentX < 3 && !switchFound) {
        switchX = currentX+1;
        switchY = currentY;
        if (this->mArray[switchX][switchY]->value() == 0) {
            switchFound = true;
        }
    }
    // Check West
    if (currentY > 0 && !switchFound) {
        switchX = currentX;
        switchY = currentY-1;
        if (this->mArray[switchX][switchY]->value() == 0) {
            switchFound = true;
        }
    }
    // Check East
    if (currentY < 3 && !switchFound) {
        switchX = currentX;
        switchY = currentY+1;
        if (this->mArray[switchX][switchY]->value() == 0) {
            switchFound = true;
        }
    }

    if (switchFound) {
//        qDebug() << "Switch pieces: " << currentX << " " << currentY << "\n" << switchX << " " << switchY;
        this->switchPieces(currentX, currentY, switchX, switchY);
        this->addMove();
        if (this->isGameWon() && !randomizing) {
            qDebug() << "Game won";
            delay();
//            // gameWon()
             randomize();
        }
    }
}

void Jogo::switchPieces(int x1, int y1, int x2, int y2) {
    int valToSwitch = this->mArray[x1][y1]->value();

    QString formattedString = QString("cell%1%2").arg(QString::number(x1), QString::number(y1));
    QObject* cell = this->mView->rootObject()->findChild<QObject*>(formattedString);
    if (cell) {
        int val = this->mArray[x2][y2]->value();
        cell->setProperty("text", val == 0 ? QString(" ") : QString::number(val));
    } else {
        qDebug() << "Cell not found  " << formattedString;
    }
    this->mArray[x1][y1]->setValue(this->mArray[x2][y2]->value());

    formattedString = QString("cell%1%2").arg(QString::number(x2), QString::number(y2));
    cell = this->mView->rootObject()->findChild<QObject*>(formattedString);
    if (cell) {
        cell->setProperty("text", valToSwitch == 0 ? QString(" ") : QString::number(valToSwitch));
    } else {
        qDebug() << "Cell not found " << formattedString;
    }

    this->mArray[x2][y2]->setValue(valToSwitch);
}

void Jogo::addMove() {
    ++this->moves;
}

int Jogo::totalMoves() {
    return this->moves;
}

bool Jogo::isGameWon() {
    for (int x=0; x < TAM; ++x) {
        for (int y=0; y < TAM; ++y) {
            if (x==3 && y==3){
               break;
            }
            if ((TAM*x + y + 1) != this->mArray[x][y]->value()) {
                return false;
            }
        }
    }
    return true;
}
