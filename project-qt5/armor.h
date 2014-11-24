#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor: public Item{
public:
    Armor(int, QString, QString, QString, int);
    int getDefense();
private:
    int m_defense;
};

#endif // ARMOR_H
