#include <QTextStream>
#include "item.h"

Item::Item()
    :m_name("none"), m_type("none"), m_special("none"), m_effect(0), m_weight(0) {}

Item::Item(QString name, QString type, QString special, int effectValue, int weight)
    :m_name(name), m_type(type), m_special(special), m_effect(effectValue), m_weight(weight) {}

Item::Item(const Item& other)
    :m_name(other.m_name), m_type(other.m_type), m_special(other.m_special), m_effect(other.m_effect), m_weight(other.m_weight) {}

Item& Item::operator=(const Item& other){
    if (this != &other){
        m_name = other.m_name;
        m_type = other.m_type;
        m_special = other.m_special;
        m_effect = other.m_effect;
        m_weight = other.m_weight;
    }
    return *this;
}

QString Item::getName(){
    return m_name;
}

QString Item::getType(){
    return m_type;
}

QString Item::getSpecial(){
    return m_special;
}

int Item::getEffect(){
    return m_effect;
}

int Item::getWeight(){
    return m_weight;
}

QString Item::toString(){
    QString output;
    QString type = getType();
    QString effectType;
    QTextStream os(&output);

    if (type == "sword" || type == "axe" || type == "mace")
        effectType = "Damage: ";

    else if (type == "helm" || type == "chest piece" || type == "greaves" || type == "boots" || type == "shield")
        effectType = "Defense: ";

    else if (type == "health potion" || type == "mana potion")
        effectType = "HP restored: ";

    else if (type == "mana potion")
        effectType = "MP restored: ";

    os << getName() << "\n"
       << "Type: " << type << "\n"
       << effectType << getEffect() << "\n"
       << "Special: " << getSpecial() << "\n"
       << "Weight: " << getWeight() << "\n";

    return output;
}
