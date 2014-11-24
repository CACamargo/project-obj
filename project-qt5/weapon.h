#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon: public Item{
public:
    Weapon(int, QString, QString, QString, int);
    int getDamage();
private:
    int m_damage;
};

#endif // WEAPON_H
