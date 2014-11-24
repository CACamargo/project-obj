#include "scene.h"
#include <QDebug>

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

void Scene::changeScene(QString tileInfo){
    qDebug() << "Location: " << tileInfo;
    setBackground(tileInfo);
    QVariant newID (tileInfo);
    sendImageID(newID);

}
