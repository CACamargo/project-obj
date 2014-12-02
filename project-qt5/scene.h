#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QString>
#include <QVariant>

class Scene: public QObject{
    Q_OBJECT
public:
    Scene(QString, QString);
    QString getBackground();
    QString getSpecial();
    void setBackground(QString);
    void setSpecial(QString);
    int randInt(int low, int high);
    void spawnEnemy();
    void spawnChest(int chestType);
    void spawnNPC(int npcType);

public slots:
    void changeScene(QString tileInfo, int tileSpecial);
    void receiveUseRequest();
    void receiveTalkRequest();
    void receiveEnemyDeathReport();
    void receiveUseReport(QString);
    void receivePlayerPosition(int, int);
    void receiveDialog(QString dialog);
    void receiveFleeOrder(int spd);

signals:
    void sendImageID(QVariant);
    void sendUseVerdict(QVariant);
    void sendTalkVerdict(QVariant);
    void sendEnemyType(QString);
    void sendSceneInfo(QVariant);
    void sendChestInfo(int chestType);
    void relayUseRequest();
    void reportChestUse();
    void reportSceneSpecial(QString, int, int);
    void relayTalkRequest();
    void sendNPCType(QString);
    void reportEscapeAttempt(QVariant);

private:
    QString m_backgroundID;
    QString m_special;
};

#endif // SCENE_H
