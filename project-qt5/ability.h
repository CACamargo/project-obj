#ifndef ABILITY_H
#define ABILITY_H

#include <QString>

class Ability {
public:
    QString getName();
    int getValue();
    QString getSpecial();
    Ability(QString name, int dam, QString special);

private:
    QString m_name;
    int m_dam;
    QString m_special;
};

#endif // ABILITY_H
