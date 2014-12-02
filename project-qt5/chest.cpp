#include <QTextStream>
#include <QDebug>
#include "chest.h"

Chest::Chest(int itemLimit)
    :m_itemLimit(itemLimit) {
    m_contents.resize(itemLimit);
}

Chest::Chest(QVector< Item > items)
    :m_itemLimit(items.size()), m_contents(items) {}

QVector< Item > Chest::getContents(){
    return m_contents;
}

int Chest::getItemLimit(){
    return m_itemLimit;
}

void Chest::addContent(Item item){
    for (int i = 0; i < m_itemLimit; ++i){
        if (m_contents[i].getType() == "none"){
            m_contents[i] = item;
            break;
        }
    }
}

void Chest::removeContent(int position){
    m_contents[position] = Item();
}

void Chest::clearContent(){
    for (int i = 0; i < m_itemLimit; ++i){
        if (m_contents[i].getType() != "none"){
            m_contents[i] = Item();
        }
        else
            break;
    }
}

void Chest::receiveChestInfo(int chestType){
    clearContent();
    if (chestType == 1){
        Item item1("Mace of destruction","mace","none",12,2);
        Item item2("Small health potion","health potion","none",50,1);
        addContent(item1);
        addContent(item2);
    }
    else if (chestType == 2){
        Item item1("Savage axe","axe","none",18,4);
        Item item2("Small health potion","health potion","none",50,1);
        addContent(item1);
        addContent(item2);
    }
}

void Chest::receiveUseRequest(){
    QString output;
    QTextStream os(&output);
    os << "Obtained:\n";
    for (int i = 0; i < m_itemLimit; ++i){
        if (m_contents[i].getType() != "none"){
            sendItem(m_contents[i]);
            os << "* " << m_contents[i].getName() << "\n";
        }
        else {
            break;
        }
    }
    clearContent();
    sendUseReport(output);
}
