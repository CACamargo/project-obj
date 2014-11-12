#ifndef SCENE_H
#define SCENE_H

#include <QString>

class Scene{
public:
    QString getBckg();
    Scene(QString);
private:
    QString m_background;

};

#endif // SCENE_H
