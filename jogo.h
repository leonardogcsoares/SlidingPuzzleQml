#ifndef JOGO_H
#define JOGO_H

#include <QObject>
#include <QList>
#include <QQuickView>
#include <QUrl>

#include "time.h"
#include "block.h"

#define TAM 4

class Jogo : public QObject
{
    Q_OBJECT
public:
    explicit Jogo(QObject *parent = 0);
    Q_INVOKABLE void cellClicked(int index, bool randomizing=false);

    void randomize();
    void newGame();
    void initMatrix(QQuickView *view);
    bool isGameWon();
    int totalMoves();


    bool isSolvable();
    void printMatrix();
    void addMove();

    void switchPieces(int x1, int y1, int x2, int y2);

signals:

public slots:
    void refresh();
//    void saveClicked();
//    void loadClicked();

private:
    static int currentMatrix[TAM][TAM];
    static Block *mArray[TAM][TAM];
    static QQuickView* mView;
    static int moves;

    int test;
};

#endif // JOGO_H
