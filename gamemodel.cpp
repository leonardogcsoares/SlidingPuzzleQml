#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{

}

GameModel::GameModel(int value, int index) {
    this->mValue = value;
    this->mIndex = index;
}

int GameModel::value() {
    return this->mValue;
}

void GameModel::setValue(int value) {
    this->mValue = value;
}


int GameModel::index() {
    return this->mIndex;
}
