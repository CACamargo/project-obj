#include "item.h"

Item::Item(int weight, QString type, QString special, QString id)
    :m_weight(weight), m_type(type), m_special(special), m_imageID(id) {}

int Item::getWeight(){
    return m_weight;
}

QString Item::getType(){
    return m_type;
}

QString Item::getSpecial(){
    return m_special;
}

QString Item::getID(){
    return m_imageID;
}
