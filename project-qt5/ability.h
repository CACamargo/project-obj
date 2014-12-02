#ifndef ABILITY_H
#define ABILITY_H

#include <QString>

class Ability {
public:
    Ability();
    Ability& operator=(const Ability& other);
    Ability(QString name, QString type, float effect, int cost, QString special, QString desc);
    QString getName();
    QString getType();
    float getEffect();
    int getCost();
    QString getSpecial();
    QString getDescription();


private:
    QString m_name;
    QString m_type;
    float m_effect;
    int m_cost;
    QString m_special;
    QString m_description;
};

#endif // ABILITY_H
