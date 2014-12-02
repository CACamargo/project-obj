#include <QDebug>
#include <QTime>

#include "scene.h"

Scene::Scene(QString background, QString special)
    :m_backgroundID(background), m_special(special) {}

QString Scene::getBackground(){
    return m_backgroundID;
}

QString Scene::getSpecial(){
    return m_special;
}

void Scene::setBackground(QString id){
    m_backgroundID = id;
}

void Scene::setSpecial(QString special){
    m_special = special;
}

int Scene::randInt(int low, int high){
    return qrand() % ((high + 1) - low) + low;
}

void Scene::spawnEnemy(){
    m_special = "none";
    int spawnTrigger = randInt(1,5);
    if (spawnTrigger == 3){
        int typeTrigger = randInt(1,5);
        if (typeTrigger == 1){
            m_special = "amazon";

        }
        else if (typeTrigger == 2){
            m_special = "demon";

        }
        else if (typeTrigger == 3){
            m_special = "dragon";

        }
        else if (typeTrigger == 4){
            m_special = "goblin";

        }
        else if (typeTrigger == 5){
            m_special = "horseman";

        }
    }
    sendEnemyType(m_special);
    sendSceneInfo(QVariant(m_special));
}

void Scene::spawnChest(int chestType){
    m_special = "chest";
    sendChestInfo(chestType);
    sendSceneInfo(QVariant(m_special));
}

void Scene::spawnNPC(int npcType){
    if (npcType == 3){
        m_special = "old man";
    }
    sendNPCType(m_special);
    sendSceneInfo(QVariant(m_special));
}

void Scene::changeScene(QString tileInfo, int tileSpecial){
    if (getBackground() != tileInfo){
        setBackground(tileInfo);
        QVariant newID (tileInfo);
        sendImageID(newID);

        if (tileSpecial != 0){
            if (tileSpecial == 1 || tileSpecial == 2){
                spawnChest(tileSpecial);
            }
            else if (tileSpecial == 3){
                spawnNPC(tileSpecial);
            }
        }
        else {
            spawnEnemy();
        }
    }
}

void Scene::receiveUseRequest(){
    if(getSpecial() != "chest"){
        QVariant verdict("There's nothing to use here.");
        sendUseVerdict(verdict);
    }
    else{
        relayUseRequest();
    }
}

void Scene::receiveTalkRequest(){
    if(getSpecial() != "old man"){
        QVariant verdict("There's no one here to talk to.");
        sendTalkVerdict(verdict);
    }
    else{
        relayTalkRequest();
    }
}

void Scene::receiveEnemyDeathReport(){
    m_special = "none";
    sendSceneInfo(QVariant(m_special));
}

void Scene::receiveUseReport(QString report){
    m_special = "none";
    sendUseVerdict(QVariant(report));
    sendSceneInfo(QVariant(m_special));
    reportChestUse();
}

void Scene::receivePlayerPosition(int xPos, int yPos){
    reportSceneSpecial(m_special, xPos, yPos);
}

void Scene::receiveDialog(QString dialog){
    sendTalkVerdict(QVariant(dialog));
}

void Scene::receiveFleeOrder(int spd){
    int fleeRoll = randInt(1,100);
    if (fleeRoll <= spd){
        reportEscapeAttempt(QVariant(true));
    }
    else
        reportEscapeAttempt(QVariant(false));
}
