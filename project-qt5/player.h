#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QDebug>
#include "entity.h"

class Player: public QObject, public Entity{
    Q_OBJECT
public:
    Player(QString, int, int, int, int, int);
    QString toString();
    int getStat(QString);    
    int getXPos();
    int getYPos();
    QString getDirection();
    void setStat(QString, int);
    void setPos(int, int);
    void setDir(QString);

    //void statInfo(QString statInf);

public slots:
    void statInfo();
    void movementRequest(QString);
    void receiveMoveApproval(int, int);

signals:
    void sendRequest(QString, int, int);

private:
    int m_MP;
    int m_stamina;
    int m_xPosition;
    int m_yPosition;
    QString m_direction;
};

#endif // PLAYER_H*/
