#ifndef CHEST_H
#define CHEST_H

#include <QObject>
#include <QVector>
#include <QVariant>
#include "item.h"

class Chest: public QObject {
    Q_OBJECT

public:
    Chest(int itemLimit = 5);
    Chest(QVector< Item > items);
    QVector< Item > getContents();
    int getItemLimit();
    void addContent(Item item);
    void removeContent(int position);
    void clearContent();

public slots:
    void receiveChestInfo(int chestType);
    void receiveUseRequest();

signals:
    void sendItem(Item item);
    void sendUseReport(QString report);

private:
    int m_itemLimit;
    QVector< Item > m_contents;
};

#endif // CHEST_H
