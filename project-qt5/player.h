#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QDebug>
#include "entity.h"

class Player: public QObject, public Entity{
    Q_OBJECT
public:
    QString toString();
    int getStat(QString statName);
    void setStat(QString statName, int newValue);
    Player(QString name, int str, int dex, int intl, int con, int spd);
    //void statInfo(QString statInf);


public slots:
    void statInfo();

private:
    int m_mp;
    int m_stam;
};

#endif // PLAYER_H*/
