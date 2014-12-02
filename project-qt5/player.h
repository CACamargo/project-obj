#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QDebug>
#include <QVector>
#include "entity.h"
#include "item.h"

class Player: public QObject, public Entity{
    Q_OBJECT
public:
    Player(QString name, int str, int dex, int intl, int con, int spd, int equipNumber = 7, int invRows = 2, int invColumns = 10);
    QString toString();
    int getStat(QString statName);
    int getXPos();
    int getYPos();
    QString getDirection();
    Item getItem(int row, int column, int invRows = 2, int invColumns = 10);
    void setStat(QString statName, int newValue);
    void setPos(int x, int y);
    void setDir(QString dir);
    void addItem(Item item, int invRows = 2, int invColumns = 10);
    void equipItem(Item item, int equipNumber = 6);
    void useItem(int row, int column);

public slots:
    void receiveStatusRequest();
    void movementRequest(QString dir);
    void receiveMoveApproval(int xPos, int yPos);
    void receiveInventoryRequest();    
    void receiveItemInfoRequest(int row, int column);
    void receiveEquipTypeRequest(int index);
    void receiveEquipItemRequest(int row, int column);
    void receiveEquippedItemInfoRequest(int index);
    void receiveUseItemRequest(int row, int column);
    void receiveDiscardItemRequest(int row, int column);
    void receivePlayerInfoRequest();
    void receivePlayerAttackOrder();
    void receiveAbilitiesRequest();
    void receiveAbilityUseOrder(int);
    void receiveGuardOrder();
    void receiveCombatUseRequest(int row, int column);
    void receiveFleeOrder();
    void receiveEnemyAttack(int);
    void receiveItem(Item item);
    void receiveChestUseReport();
    void receiveEnemyDeathReport();
    void receiveCombatInventoryRequest();

signals:
    void sendStatusInfo(QVariant);
    void sendRequest(QString, int, int);
    void sendInventoryInfo();
    void sendItemType(QVariant, QVariant);    
    void sendItemInfo(QVariant, QVariant, QVariant, QVariant);
    void sendEquipType(QVariant, QVariant);
    void sendEquippedItemInfo(QVariant);
    void sendPlayerInfo(QVariant);
    void issuePlayerAttack(int damage);
    void sendPlayerDamageReport(QVariant);
    void sendPlayerDeathReport();
    void reportPosition(int, int);
    void reportAbilityUse();
    void reportCombatUse();
    void relayFleeOrder(int spd);
    void sendAbilityInfo(QVariant,QVariant);
    void sendCombatItemType(QVariant, QVariant);

private:
    int m_experience;
    int m_maxMP;
    int m_maxST;
    int m_MP;
    int m_ST;
    int m_xPosition;
    int m_yPosition;
    bool m_isGuarding;
    QString m_direction;
    QVector < Item > m_equippedItems;
    QVector < QVector < Item > > m_inventory;

};

#endif // PLAYER_H*/
