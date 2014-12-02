#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item{
public:
    Item();
    Item(QString name, QString type, QString special, int effectValue, int weight);
    Item(const Item& other);
    Item& operator=(const Item& other);
    QString getName();
    QString getType();
    QString getSpecial();
    QString toString();
    int getEffect();
    int getWeight();    

private:
    QString m_name;
    QString m_type;
    QString m_special;
    int m_effect;
    int m_weight;
};

#endif // ITEM_H
