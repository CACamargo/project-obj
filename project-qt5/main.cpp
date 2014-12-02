#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTime>
#include <QDebug>
#include <QMetaObject>
#include <QMetaMethod>

#include "player.h"
#include "enemy.h"
#include "npc.h"
#include "chest.h"
#include "level.h"
#include "scene.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //Begin initialization

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    Player playerChar("Player character",16,16,10,16,14);
    Enemy enemyChar;
    NPC npcChar;
    Chest chestObj;

    //Map Initialization
    Level map(3,3);
    //Entrance
    map.setTile("entrance",0,0);

    //Cave
    map.setTile("cave",0,2);
    map.setSpecial(1,0,2);

    //Center
    map.setTile("center",1,1);
    map.setSpecial(3,1,1);

    //Hall
    map.setTile("hall",2,0);    

    //Cellar
    map.setTile("cellar",2,2);
    map.setSpecial(2,2,2);

    //Corridors
    map.setTile("corridor",0,1);
    map.setTile("corridor",1,0);
    map.setTile("corridor",1,2);
    map.setTile("corridor",2,1);

    Scene scene(map.getTile(playerChar.getXPos(),playerChar.getYPos()), "none");    

    Item item1("Sword of kings","sword","none",5,2);
    Item item2("Iron helm","helm","none",2,3);
    Item item3("Iron chest","chest piece","none",5,20);
    Item item4("Iron greaves","greaves","none",3,15);
    Item item5("Iron boots","boots","none",2,5);
    Item item6("Iron shield","shield","none",4,4);
    Item item7("Small health potion","health potion","none",50,1);
    Item item8("Small mana potion","mana potion","none",30,1);

    QObject *rootObject = engine.rootObjects().first();
    QObject *mainWindow = rootObject->findChild<QObject*>("mainWindow");

    //End initialization

    //Begin connections    

    //UI related
    QObject::connect(mainWindow, SIGNAL(relayUseRequest()), &scene, SLOT(receiveUseRequest()));
    QObject::connect(&scene, SIGNAL(sendUseVerdict(QVariant)), mainWindow, SLOT(receiveUseVerdict(QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayTalkRequest()), &scene, SLOT(receiveTalkRequest()));
    QObject::connect(&scene, SIGNAL(sendTalkVerdict(QVariant)), mainWindow, SLOT(receiveTalkVerdict(QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayStatusRequest()), &playerChar, SLOT(receiveStatusRequest()));
    QObject::connect(&playerChar, SIGNAL(sendStatusInfo(QVariant)), mainWindow, SLOT(receivePlayerStatus(QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayInventoryRequest()), &playerChar, SLOT(receiveInventoryRequest()));
    QObject::connect(&playerChar, SIGNAL(sendInventoryInfo()), mainWindow, SLOT(receiveInventoryInfo()));
    QObject::connect(&playerChar, SIGNAL(sendItemType(QVariant, QVariant)), mainWindow, SLOT(receiveItemType(QVariant, QVariant)));
    QObject::connect(mainWindow, SIGNAL(requestItemInfo(int, int)), &playerChar, SLOT(receiveItemInfoRequest(int,int)));
    QObject::connect(&playerChar, SIGNAL(sendItemInfo(QVariant, QVariant, QVariant, QVariant)), mainWindow, SLOT(receiveItemInfo(QVariant, QVariant, QVariant, QVariant)));
    QObject::connect(mainWindow, SIGNAL(requestEquipType(int)), &playerChar, SLOT(receiveEquipTypeRequest(int)));
    QObject::connect(&playerChar, SIGNAL(sendEquipType(QVariant, QVariant)), mainWindow, SLOT(receiveEquipType(QVariant, QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayEquipItemRequest(int,int)), &playerChar, SLOT(receiveEquipItemRequest(int,int)));
    QObject::connect(mainWindow, SIGNAL(relayRequestEquippedItemInfo(int)), &playerChar, SLOT(receiveEquippedItemInfoRequest(int)));
    QObject::connect(&playerChar, SIGNAL(sendEquippedItemInfo(QVariant)), mainWindow, SLOT(receiveEquippedItemInfo(QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayUseItemRequest(int, int)), &playerChar, SLOT(receiveUseItemRequest(int, int)));
    QObject::connect(mainWindow, SIGNAL(relayDiscardItemRequest(int, int)), &playerChar, SLOT(receiveDiscardItemRequest(int, int)));
    QObject::connect(mainWindow, SIGNAL(relayPlayerInfoRequest()), &playerChar, SLOT(receivePlayerInfoRequest()));
    QObject::connect(&playerChar, SIGNAL(sendPlayerInfo(QVariant)), mainWindow, SLOT(receivePlayerInfo(QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayPlayerAttackOrder()), &playerChar, SLOT(receivePlayerAttackOrder()));
    QObject::connect(mainWindow, SIGNAL(relayEnemyAttackOrder()), &enemyChar, SLOT(receiveEnemyAttackOrder()));
    QObject::connect(mainWindow, SIGNAL(relayGuardOrder()), &playerChar, SLOT(receiveGuardOrder()));
    QObject::connect(mainWindow, SIGNAL(relayFleeOrder()), &playerChar, SLOT(receiveFleeOrder()));

    //Movement related
    QObject::connect(mainWindow, SIGNAL(move(QString)), &playerChar, SLOT(movementRequest(QString)));
    QObject::connect(&playerChar, SIGNAL(sendRequest(QString,int,int)), &map, SLOT(evalRequest(QString,int,int)));
    QObject::connect(&map, SIGNAL(sendTileInfo(QString, int)), &scene, SLOT(changeScene(QString, int)));
    QObject::connect(&map, SIGNAL(sendMoveApproval(int,int)), &playerChar, SLOT(receiveMoveApproval(int,int)));
    QObject::connect(&scene, SIGNAL(sendImageID(QVariant)), mainWindow, SLOT(updateImage(QVariant)));

    //Combat related
    QObject::connect(&playerChar, SIGNAL(issuePlayerAttack(int)), &enemyChar, SLOT(receivePlayerAttack(int)));
    QObject::connect(&enemyChar, SIGNAL(issueEnemyAttack(int)), &playerChar, SLOT(receiveEnemyAttack(int)));

    QObject::connect(mainWindow, SIGNAL(relayAbilitiesRequest()), &playerChar, SLOT(receiveAbilitiesRequest()));
    QObject::connect(&playerChar, SIGNAL(sendAbilityInfo(QVariant,QVariant)), mainWindow, SLOT(receiveAbilityInfo(QVariant, QVariant)));
    QObject::connect(mainWindow, SIGNAL(relayAbilityUseOrder(int)), &playerChar, SLOT(receiveAbilityUseOrder(int)));
    QObject::connect(&playerChar, SIGNAL(reportAbilityUse()), mainWindow, SLOT(receiveAbilityUseReport()));

    QObject::connect(&scene, SIGNAL(sendEnemyType(QString)), &enemyChar, SLOT(receiveEnemyType(QString)));
    QObject::connect(&scene, SIGNAL(sendSceneInfo(QVariant)), mainWindow, SLOT(receiveSceneInfo(QVariant)));
    QObject::connect(&enemyChar, SIGNAL(sendEnemyDamageReport(QVariant)), mainWindow, SLOT(receiveEnemyDamageReport(QVariant)));
    QObject::connect(&enemyChar, SIGNAL(sendEnemyDeathReport()), &scene, SLOT(receiveEnemyDeathReport()));
    QObject::connect(&enemyChar, SIGNAL(sendEnemyDeathReport()), &playerChar, SLOT(receiveEnemyDeathReport()));
    QObject::connect(&playerChar, SIGNAL(sendPlayerDamageReport(QVariant)), mainWindow, SLOT(receivePlayerDamageReport(QVariant)));
    QObject::connect(&playerChar, SIGNAL(sendPlayerDeathReport()), mainWindow, SLOT(receivePlayerDeathReport()));

    QObject::connect(mainWindow, SIGNAL(relayCombatUseRequest(int, int)), &playerChar, SLOT(receiveCombatUseRequest(int,int)));
    QObject::connect(mainWindow, SIGNAL(relayCombatUseRequest(int, int)), &playerChar, SLOT(receivePlayerInfoRequest()));
    QObject::connect(&playerChar, SIGNAL(reportCombatUse()), mainWindow, SLOT(receiveCombatUseReport()));

    QObject::connect(&playerChar, SIGNAL(relayFleeOrder(int)), &scene, SLOT(receiveFleeOrder(int)));
    QObject::connect(&scene, SIGNAL(reportEscapeAttempt(QVariant)), &enemyChar, SLOT(receiveEscapeAttemptReport(QVariant)));
    QObject::connect(&scene, SIGNAL(reportEscapeAttempt(QVariant)), mainWindow, SLOT(receiveEscapeAttemptReport(QVariant)));

    //Chest related
    QObject::connect(&scene, SIGNAL(sendChestInfo(int)), &chestObj, SLOT(receiveChestInfo(int)));
    QObject::connect(&scene, SIGNAL(relayUseRequest()), &chestObj, SLOT(receiveUseRequest()));
    QObject::connect(&chestObj, SIGNAL(sendItem(Item)), &playerChar, SLOT(receiveItem(Item)));
    QObject::connect(&chestObj, SIGNAL(sendUseReport(QString)), &scene, SLOT(receiveUseReport(QString)));
    QObject::connect(&scene, SIGNAL(reportChestUse()), &playerChar, SLOT(receiveChestUseReport()));
    QObject::connect(&playerChar, SIGNAL(reportPosition(int,int)), &scene, SLOT(receivePlayerPosition(int,int)));
    QObject::connect(&scene, SIGNAL(reportSceneSpecial(QString, int, int)), &map, SLOT(receiveSceneSpecialReport(QString,int,int)));

    //NPC related
    QObject::connect(&scene, SIGNAL(sendNPCType(QString)), &npcChar, SLOT(receiveNPCType(QString)));
    QObject::connect(&scene, SIGNAL(relayTalkRequest()), &npcChar, SLOT(receiveTalkRequest()));
    QObject::connect(&npcChar, SIGNAL(sendDialog(QString)), &scene, SLOT(receiveDialog(QString)));
    //End of connections    

    QObject::connect(mainWindow, SIGNAL(relayCombatInventoryRequest()), &playerChar, SLOT(receiveCombatInventoryRequest()));
    QObject::connect(&playerChar, SIGNAL(sendCombatItemType(QVariant,QVariant)), mainWindow, SLOT(receiveCombatItemType(QVariant,QVariant)));

    scene.sendImageID(map.getTile(playerChar.getXPos(),playerChar.getYPos()));
    playerChar.equipItem(item1);
    playerChar.equipItem(item2);
    playerChar.equipItem(item3);
    playerChar.equipItem(item4);
    playerChar.equipItem(item5);
    playerChar.equipItem(item6);
    playerChar.addItem(item7);
    playerChar.addItem(item7);
    playerChar.addItem(item7);
    playerChar.addItem(item8);
    playerChar.addItem(item8);
    playerChar.addAbility("Punishing strike","physical", 1.25, 2,"none","Strike at an enemy with fury.");
    playerChar.addAbility("Whirlwind slash","physical", 1.6, 4,"none","Swing at an enemy with a flurry of blows.");

    QString playerInfo = playerChar.toString();
    qDebug() << playerInfo;
    qDebug() << "Damage: " << playerChar.getStat("dam");
    qDebug() << "Defense: " << playerChar.getStat("def");

    return app.exec();
}
