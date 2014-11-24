#ifndef ABILITY_H
#define ABILITY_H

#include <QString>

class Ability {
public:
    QString getName();
    int getValue();
    QString getSpecial();
    Ability(QString, int, QString);

private:
    QString m_name;
    int m_damage;
    QString m_special;
};

#endif // ABILITY_H
