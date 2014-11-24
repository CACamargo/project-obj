#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item{
public:
    Potion(int, QString, QString, QString, int, int);
    int getHPRestore();
    int getMPRestore();
private:
    int m_hpRestore;
    int m_mpRestore;
};

#endif // POTION_H
