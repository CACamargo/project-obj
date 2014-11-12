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
    virtual int getStat(QString statName);
    virtual void setStat(QString statName, int newValue);
    void addAbility(QString abilityName, int dam, QString special);
    void delAbility(QString abilityName);
    virtual ~Entity();

protected:
    Entity(QString name, int str, int dex, int intl, int con, int spd);

private:
    QList<Ability> m_abilities;
    QString m_name;
    QString m_status;
    int m_lvl;
    int m_hp;
    int m_str;
    int m_dex;
    int m_int;
    int m_con;
    int m_spd;
};

#endif // ENTITY_H
