#include "scene.h"

QString Scene::getBckg(){
    return m_background;
}

Scene::Scene(QString background)
    :m_background(background) {}
