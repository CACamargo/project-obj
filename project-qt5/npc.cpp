#include <QTextStream>
#include <QDebug>
#include "npc.h"

NPC::NPC()
    :Entity("none",0,0,0,0,0), m_dialog(""){}

NPC::NPC(QString name, int str, int dex, int intl, int con, int spd, QString dialog)
    :Entity(name, str, dex, intl, con, spd), m_dialog(dialog){}

int NPC::getStat(QString statName) const{
    return Entity::getStat(statName);
}

QString NPC::getDialog(){
    return m_dialog;
}

void NPC::setStat(QString statName, int newValue){
    Entity::setStat(statName, newValue);
}

void NPC::setDialog(QString dialog){
    m_dialog = dialog;
}

QString NPC::toString(){
    QString output;
    QTextStream os(&output);
    os << "Name: " << Entity::getName() << "\n"
       << "*Condition:" << "\n"
       << "HP: " << Entity::getStat("HP") << "\n"
       << "STATUS: " << Entity::getStatus() << "\n\n"
       << "*Atributes:" << "\n"
       << "Str: " << Entity::getStat("str") << "\n"
       << "Dex: " << Entity::getStat("dex") << "\n"
       << "Int: " << Entity::getStat("int") << "\n"
       << "Con: " << Entity::getStat("con") << "\n"
       << "Spd: " << Entity::getStat("spd") << "\n"
       << "Dam: " << Entity::getStat("dam") << "\n"
       << "Def: " << Entity::getStat("def") << "\n";

    return output;
}
void NPC::receiveNPCType(QString type){
    QString name;
    QString status = "OK";
    int lvl;
    int str;
    int dex;
    int intl;
    int con;
    int spd;

    if (type == "none"){
        name = "none";
        lvl = 0;
        str = 0;
        dex = 0;
        intl = 0;
        con = 0;
        spd = 0;
        m_dialog = "";
    }

    else if (type == "old man"){
        name = "old man";
        lvl = 1;
        str = 10;
        dex = 10;
        intl = 10;
        con = 10;
        spd = 10;
        m_dialog = "The old man looks at you and says:\n"
                "'This is a dangerous place, lad. You better tread carefully.'";
    }
    setName(name);
    setStatus(status);
    setStat("lvl",lvl);
    setStat("str",str);
    setStat("dex",dex);
    setStat("int",intl);
    setStat("con",con);
    setStat("spd",spd);
    setStat("HP",getStat("max HP"));
}

void NPC::receiveTalkRequest(){
    sendDialog(m_dialog);
}
