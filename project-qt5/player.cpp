#include <QTextStream>
#include "player.h"

QString Player::toString() {
    QString output;
    QTextStream os(&output);
    os << "---Player Information---" << "\n"
       << "Name: " << Entity::getName() << "\n"
       << "Condition:" << "\n"
       << "*HP: " << Entity::getStat("hp") << "\n"
       << "*MP: " << m_mp << "\n"
       << "*ST: " << m_stam << "\n"
       << "*STATUS: " << Entity::getStatus() << "\n"
       << "Atributes:" << "\n"
       << "*Str: " << Entity::getStat("str") << "\n"
       << "*Dex: " << Entity::getStat("dex") << "\n"
       << "*Int: " << Entity::getStat("int") << "\n"
       << "*Con: " << Entity::getStat("con") << "\n"
       << "*Spd: " << Entity::getStat("spd") << "\n";

    return output;
}

int Player::getStat(QString statName){
    if (statName == "mp")
        return m_mp;
    else if (statName == "stam")
        return m_stam;
    else
        return Entity::getStat(statName);
}

void Player::setStat(QString statName, int newValue){
    Entity::setStat(statName, newValue);
    if (statName == "intl")
        m_mp = newValue*2;
    else if (statName == "con" || statName == "spd")
        m_stam = 1 + (Entity::getStat("con"))/3 + (Entity::getStat("spd"))/5;
}

void Player::statInfo(){
    qDebug() << toString();
}

Player::Player(QString name, int str, int dex, int intl, int con, int spd)
    : Entity(name, str, dex, intl, con, spd), m_mp(intl*2), m_stam(1+(con/3)+(spd/5)) {}
