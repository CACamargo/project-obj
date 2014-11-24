#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item{
public:
    int getWeight();
    QString getType();
    QString getSpecial();
    QString getID();
protected:
    Item(int, QString, QString, QString);
private:
    int m_weight;
    QString m_type;
    QString m_special;
    QString m_imageID;    
};

#endif // ITEM_H
