#include "ability.h"

Ability::Ability()
    : m_name("none"), m_type("none"), m_effect(0.0), m_cost(0), m_special("none"), m_description("") {}

Ability::Ability(QString name, QString type, float effect, int cost, QString special, QString desc)
    : m_name(name), m_type(type), m_effect(effect), m_cost(cost), m_special(special), m_description(desc) {}

Ability& Ability::operator=(const Ability& other){
    if (this != &other){
        m_name = other.m_name;
        m_type = other.m_type;
        m_effect = other.m_effect;
        m_cost = other.m_cost;
        m_special = other.m_special;
        m_description = other.m_description;
    }
    return *this;
}
QString Ability::getName(){
    return m_name;
}

QString Ability::getType(){
    return m_type;
}

float Ability::getEffect(){
    return m_effect;
}

int Ability::getCost(){
    return m_cost;
}

QString Ability::getSpecial(){
    return m_special;
}

QString Ability::getDescription(){
    return m_description;
}
