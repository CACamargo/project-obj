#include "entity.h"

Entity::~Entity() {

}

Entity::Entity(QString name, int str, int dex, int intl, int con, int spd)
    : m_abilities(),m_name(name), m_status("OK"), m_level(1), m_HP(con*3), m_strength(str), m_dexterity(dex), m_intelligence(intl), m_constitution(con), m_speed(spd) {}


QString Entity::getName(){
    return m_name;
}

QString Entity::getStatus(){
    return m_status;
}

QList<Ability> Entity::getAbilities(){
    return m_abilities;
}

int Entity::getStat(QString statName){
    if (statName == "lvl")
        return m_level;
    else if (statName == "hp")
        return m_HP;
    else if (statName == "str")
        return m_strength;
    else if (statName == "dex")
        return m_dexterity;
    else if (statName == "int")
        return m_intelligence;
    else if (statName == "con")
        return m_constitution;
    else if (statName == "spd")
        return m_speed;
    else
        return 0;
}

void Entity::setStat(QString statName, int newValue){
    if (statName == "lvl")
        m_level = newValue;
    else if (statName == "str")
        m_strength = newValue;
    else if (statName == "dex")
        m_dexterity = newValue;
    else if (statName == "int")
        m_intelligence = newValue;
    else if (statName == "con"){
        m_constitution = newValue;
        m_HP = newValue*3;
    }
    else if (statName == "spd")
        m_speed = newValue;
}

void Entity::addAbility(QString abilityName, int dam, QString special){
    Ability ab = Ability(abilityName, dam, special);
    m_abilities.append(ab);
}

void Entity::delAbility(QString abilityName){
    if (!m_abilities.isEmpty()){
        QList<Ability>::iterator it = m_abilities.begin();
        while (it != m_abilities.end()) {
          if ((*it).getName() == abilityName)
            it = m_abilities.erase(it);
          else
            ++it;
        }
    }
}
