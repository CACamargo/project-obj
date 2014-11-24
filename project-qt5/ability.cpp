#include "ability.h"

Ability::Ability(QString name, int dam, QString special)
    : m_name(name), m_damage(dam), m_special(special) {}

QString Ability::getName(){
    return m_name;
}

int Ability::getValue(){
    return m_damage;
}

QString Ability::getSpecial(){
    return m_special;
}
