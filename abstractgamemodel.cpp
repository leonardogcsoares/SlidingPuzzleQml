#include "abstractgamemodel.h"


AbstractGame::AbstractGame(const int value, const int index) {
    this->mValue = value;
    this->mIndex = index;
}

int AbstractGame::index() {
    return this->mIndex;
}

int AbstractGame::value() {
    return this->mValue;
}

AbstractGameModel::AbstractGameModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

void AbstractGameModel::addGameModel(AbstractGame game) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    this->mGames << game;
    endInsertRows();
}

int AbstractGameModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return mGames.count();
}

QVariant AbstractGameModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= mGames.count())
        return QVariant();

    AbstractGame game = mGames[index.row()];
    if (role == IndexRole)
        return game.index();
    else if (role == ValueRole)
        return game.value();
    return QVariant();
}

QHash<int, QByteArray> AbstractGameModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IndexRole] = "index";
    roles[ValueRole] = "value";
    return roles;
}
