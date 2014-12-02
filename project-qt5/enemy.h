#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QDebug>
#include "entity.h"

class Enemy: public QObject, public Entity{
    Q_OBJECT
public:
    Enemy();
    Enemy(QString name, int str, int dex, int intl, int con, int spd, QString type);
    QString getType() ;
    int getStat(QString statName) const;
    void setStat(QString statName, int newValue);
    QString toString();

public slots:
    void receiveEnemyType(QString enemyType);
    void receivePlayerAttack(int damage);
    void receiveEnemyAttackOrder();
    void receiveEscapeAttemptReport(QVariant);

signals:
    void sendEnemyDamageReport(QVariant report);
    void sendEnemyDeathReport();
    void issueEnemyAttack(int damage);

private:
    QString m_type;
};

#endif // ENEMY_H
