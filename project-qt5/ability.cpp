#include "ability.h"

QString Ability::getName(){
    return m_name;
}

int Ability::getValue(){
    return m_dam;
}

QString Ability::getSpecial(){
    return m_special;
}

Ability::Ability(QString name, int dam, QString special)
    : m_name(name), m_dam(dam), m_special(special) {}
