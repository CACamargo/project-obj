#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "player.h"
#include "level.h"
#include "scene.h"


typedef std::vector<std::string> StringVector;
typedef std::vector<StringVector> StringVector2D;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //Begin initialization

    Player p1("Player character",10,10,10,10,10);
    Level map(10,10);
    map.setTile("corridor",0,0);
    map.setTile("cave",0,1);
    Scene scene(map.getTile(p1.getXPos(),p1.getYPos()), "none");

    //End initialization

    //Begin connections

    QObject *rootObject = engine.rootObjects().first();
    QObject *newButton = rootObject->findChild<QObject*>("statusButton");
    QObject *mainWindow = rootObject->findChild<QObject*>("mainWindow");
    //QObject::connect(newButton, SIGNAL(clicked()), &p1, SIGNAL(statInfo(QString)));
    QObject::connect(newButton, SIGNAL(clicked()), &p1, SLOT(statInfo()));
    QObject::connect(mainWindow, SIGNAL(move(QString)), &p1, SLOT(movementRequest(QString)));
    QObject::connect(&p1, SIGNAL(sendRequest(QString,int,int)), &map, SLOT(evalRequest(QString,int,int)));
    QObject::connect(&map, SIGNAL(sendTileInfo(QString)), &scene, SLOT(changeScene(QString)));
    QObject::connect(&map, SIGNAL(sendMoveApproval(int,int)), &p1, SLOT(receiveMoveApproval(int,int)));
    QObject::connect(&scene, SIGNAL(sendImageID(QVariant)), mainWindow, SLOT(updateImage(QVariant)));

    //End of connections

    QString playerInfo = p1.toString();
    qDebug() << playerInfo;
    qDebug() << scene.getBackground();
    qDebug() << map.getTile(0,1);

    return app.exec();
}
