#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "player.h"
#include "scene.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Player p1("Player character",10,10,10,10,10);
    QString playerInfo = p1.toString();
    qDebug() << playerInfo;

    QObject *rootObject = engine.rootObjects().first();
    QObject *newButton = rootObject->findChild<QObject*>("statusButton");
    //QObject::connect(newButton, SIGNAL(clicked()), &p1, SIGNAL(statInfo(QString)));
    QObject::connect(newButton, SIGNAL(clicked()), &p1, SLOT(statInfo()));

    return app.exec();
}
