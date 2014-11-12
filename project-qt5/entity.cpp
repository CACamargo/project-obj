#include "entity.h"

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
        return m_lvl;
    else if (statName == "hp")
        return m_hp;
    else if (statName == "str")
        return m_str;
    else if (statName == "dex")
        return m_dex;
    else if (statName == "int")
        return m_int;
    else if (statName == "con")
        return m_con;
    else if (statName == "spd")
        return m_spd;
    else
        return 0;
}

void Entity::setStat(QString statName, int newValue){
    if (statName == "lvl")
        m_lvl = newValue;
    else if (statName == "str")
        m_str = newValue;
    else if (statName == "dex")
        m_dex = newValue;
    else if (statName == "int")
        m_int = newValue;
    else if (statName == "con"){
        m_con = newValue;
        m_hp = newValue*3;
    }
    else if (statName == "spd")
        m_spd = newValue;
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

Entity::~Entity() {

}

Entity::Entity(QString name, int str, int dex, int intl, int con, int spd)
    : m_abilities(),m_name(name), m_status("OK"), m_lvl(1), m_hp(con*3), m_str(str), m_dex(dex), m_int(intl), m_con(con), m_spd(spd) {}
