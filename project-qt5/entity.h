#ifndef ENTITY_H
#define ENTITY_H

#include "ability.h"
#include <QVector>

class Entity {

public:        
    QString getName() const;
    QString getStatus() const;
    QVector<Ability> getAbilities() const;
    Ability getAbility(int position);
    virtual int getStat(QString const) const;
    void setName(QString name);
    void setStatus(QString status);
    virtual void setStat(QString, int);
    void addAbility(QString, QString, float, int, QString, QString);
    void delAbility(int);
    virtual ~Entity();
    virtual QString toString() = 0;

protected:
    Entity(QString, int, int, int, int, int, int abilityLimit = 9);

private:
    QVector<Ability> m_abilities;
    QString m_name;
    QString m_status;
    int m_level;
    int m_maxHP;
    int m_HP;
    int m_strength;
    int m_dexterity;
    int m_intelligence;
    int m_constitution;
    int m_speed;
    int m_damage;
    int m_defense;
    int m_abilityLimit;
};

#endif // ENTITY_H
