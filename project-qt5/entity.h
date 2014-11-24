#ifndef ENTITY_H
#define ENTITY_H

#include "ability.h"
#include <QList>

class Entity {

public:        
    QString getName();
    QString getStatus();
    QList<Ability> getAbilities();
    virtual QString toString() = 0;
    virtual int getStat(QString);
    virtual void setStat(QString, int);
    void addAbility(QString, int, QString);
    void delAbility(QString);
    virtual ~Entity();

protected:
    Entity(QString, int, int, int, int, int);

private:
    QList<Ability> m_abilities;
    QString m_name;
    QString m_status;
    int m_level;
    int m_HP;
    int m_strength;
    int m_dexterity;
    int m_intelligence;
    int m_constitution;
    int m_speed;
};

#endif // ENTITY_H
