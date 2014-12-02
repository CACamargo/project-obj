#include "entity.h"

Entity::~Entity() {

}

Entity::Entity(QString name, int str, int dex, int intl, int con, int spd, int abilityLimit)
    : m_abilities(),m_name(name), m_status("OK"), m_level(1), m_maxHP(1+(con*3)+str),
      m_strength(str), m_dexterity(dex), m_intelligence(intl), m_constitution(con), m_speed(spd),
      m_damage(1+(str)+(dex/2)), m_defense((con/2)+(str/4)+(dex/6)), m_abilityLimit(abilityLimit) {

    m_HP = m_maxHP;
    m_abilities.resize(m_abilityLimit);
}

QString Entity::getName() const{
    return m_name;
}

QString Entity::getStatus() const{
    return m_status;
}

QVector<Ability> Entity::getAbilities() const{
    return m_abilities;
}

Ability Entity::getAbility(int position){
    if (position < m_abilityLimit)
        return m_abilities[position];
    else
        return Ability();
}

int Entity::getStat(QString statName) const{
    if (statName == "lvl")
        return m_level;
    else if (statName == "max HP")
        return m_maxHP;
    else if (statName == "HP")
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
    else if (statName == "dam")
        return m_damage;
    else if (statName == "def")
        return m_defense;
    else if (statName == "abilityLimit")
        return m_abilityLimit;
    else
        return 0;
}

void Entity::setName(QString name){
    m_name = name;
}

void Entity::setStatus(QString status){
    m_status = status;
}

void Entity::setStat(QString statName, int newValue){
    if (statName == "lvl")
        m_level = newValue;
    else if (statName == "HP")
        m_HP = newValue;
    else if (statName == "str"){
        m_strength = newValue;
        m_maxHP = 1+(m_constitution*3)+m_strength;
        m_damage = 1+(m_strength)+(m_dexterity/2);
        m_defense = (m_constitution/2)+(m_strength/4)+(m_dexterity/6);
    }
    else if (statName == "dex"){
        m_dexterity = newValue;
        m_damage = 1+(m_strength)+(m_dexterity/2);
        m_defense = (m_constitution/2)+(m_strength/4)+(m_dexterity/6);
    }
    else if (statName == "int")
        m_intelligence = newValue;
    else if (statName == "con"){
        m_constitution = newValue;
        m_maxHP = 1+(m_constitution*3)+m_strength;
        m_defense = (m_constitution/2)+(m_strength/4)+(m_dexterity/6);
    }
    else if (statName == "spd")
        m_speed = newValue;
    else if (statName == "dam")
        m_damage = newValue;
    else if (statName == "def")
        m_defense = newValue;    
}

void Entity::addAbility(QString abilityName, QString type, float damMultiplier, int cost, QString special, QString desc){
    Ability ability = Ability(abilityName, type, damMultiplier, cost, special, desc);
    for (int i = 0; i < m_abilityLimit; ++i){
        if (m_abilities[i].getType() == "none"){
            m_abilities[i] = ability;
            break;
        }
    }
}

void Entity::delAbility(int position){
    if (m_abilities[position].getType() != "none"){
        m_abilities[position] = Ability();
    }
}
