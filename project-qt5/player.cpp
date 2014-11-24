#include <QTextStream>
#include "player.h"

Player::Player(QString name, int str, int dex, int intl, int con, int spd)
    : Entity(name, str, dex, intl, con, spd), m_MP(intl*2), m_stamina(1+(con/3)+(spd/5)),
      m_xPosition(0), m_yPosition(0), m_direction("east") {}

QString Player::toString() {
    QString output;
    QTextStream os(&output);
    os << "---Player Information---" << "\n"
       << "Name: " << Entity::getName() << "\n"
       << "Condition:" << "\n"
       << "*HP: " << Entity::getStat("hp") << "\n"
       << "*MP: " << m_MP << "\n"
       << "*ST: " << m_stamina << "\n"
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
        return m_MP;
    else if (statName == "stam")
        return m_stamina;
    else
        return Entity::getStat(statName);
}


int Player::getXPos(){
    return m_xPosition;
}

int Player::getYPos(){
    return m_yPosition;
}

QString Player::getDirection(){
    return m_direction;
}

void Player::setPos(int x, int y){
    m_xPosition = x;
    m_yPosition = y;
}

void Player::setDir(QString dir){
    m_direction = dir;
}

void Player::setStat(QString statName, int newValue){
    Entity::setStat(statName, newValue);
    if (statName == "intl")
        m_MP = newValue*2;
    else if (statName == "con" || statName == "spd")
        m_stamina = 1 + (Entity::getStat("con"))/3 + (Entity::getStat("spd"))/5;
}

void Player::statInfo(){
    qDebug() << toString();
}

void Player::movementRequest(QString dir){
    if (dir == "forward")
        sendRequest(getDirection(), getXPos(), getYPos());
    if (dir == "left"){
        if (getDirection() == "north")
            setDir("west");
        else if (getDirection() == "west")
            setDir("south");
        else if (getDirection() == "south")
            setDir("east");
        else if (getDirection() == "east")
            setDir("north");
    }
}

void Player::receiveMoveApproval(int xPos, int yPos){
    setPos(xPos,yPos);
}
