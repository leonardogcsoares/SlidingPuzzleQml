#ifndef ABSTRACTGAMEMODEL_H
#define ABSTRACTGAMEMODEL_H

#include <QAbstractListModel>

class AbstractGame
{
public:
    AbstractGame(const int value, const int index);

    int index();
    int value();

private:
    int mValue;
    int mIndex;
};

class AbstractGameModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AbstractGameRoles {
        ValueRole = Qt::UserRole + 1,
        IndexRole
    };

    AbstractGameModel(QObject *parent = 0);

    void addGameModel(AbstractGame game);
    void replace(int index, int oldVal, int newVal);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<AbstractGame> mGames;
};

#endif // ABSTRACTGAMEMODEL_H
