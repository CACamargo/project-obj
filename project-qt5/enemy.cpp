#include <QTextStream>
#include <QDebug>
#include "enemy.h"

Enemy::Enemy()
    :Entity("none",0,0,0,0,0), m_type("none"){}

Enemy::Enemy(QString name, int str, int dex, int intl, int con, int spd, QString type)
    :Entity(name, str, dex, intl, con, spd), m_type(type){}

int Enemy::getStat(QString statName) const{
    return Entity::getStat(statName);
}

QString Enemy::getType(){
    return m_type;
}

void Enemy::setStat(QString statName, int newValue){
    Entity::setStat(statName, newValue);
}

QString Enemy::toString(){
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

void Enemy::receiveEnemyType(QString enemyType){
    QString name;
    QString status = "OK";
    int lvl;
    int str;
    int dex;
    int intl;
    int con;
    int spd;
    m_type = enemyType;

    if (m_type == "none"){
        name = "none";
        lvl = 0;
        str = 0;
        dex = 0;
        intl = 0;
        con = 0;
        spd = 0;
    }

    else if (m_type == "amazon"){
        name = "Amazon";
        lvl = 1;
        str = 28;
        dex = 22;
        intl = 14;
        con = 27;
        spd = 18;
    }
    else if (m_type == "demon"){
        name = "Demon";
        lvl = 1;
        str = 25;
        dex = 18;
        intl = 30;
        con = 22;
        spd = 18;
    }
    else if (m_type == "dragon"){
        name = "Dragon";
        lvl = 1;
        str = 26;
        dex = 26;
        intl = 26;
        con = 26;
        spd = 26;
    }
    else if (m_type == "goblin"){
        name = "Goblin";
        lvl = 1;
        str = 22;
        dex = 30;
        intl = 20;
        con = 22;
        spd = 28;
    }
    else if (m_type == "horseman"){
        name = "Horseman";
        lvl = 1;
        str = 27;
        dex = 25;
        intl = 16;
        con = 24;
        spd = 29;
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

void Enemy::receivePlayerAttack(int damage){
    QString report;
    QTextStream os(&report);
    if (damage < getStat("def")){
        os << "The enemy resisted all damage!";
        sendEnemyDamageReport(QVariant(report));
    }
    else {
        int collateralDamage = damage - getStat("def");
        os << "The enemy took " << collateralDamage << " damage!\n";

        if (collateralDamage >= getStat("HP")){
            os << "The enemy has been vanquished!";
            sendEnemyDamageReport(QVariant(report));
            sendEnemyDeathReport();
        }
        else{
            setStat("HP",getStat("HP") - collateralDamage);
            sendEnemyDamageReport(QVariant(report));
        }
    }
}

void Enemy::receiveEnemyAttackOrder(){
    issueEnemyAttack(getStat("dam"));
}

void Enemy::receiveEscapeAttemptReport(QVariant fleeRoll){
    if (fleeRoll.toBool() == true){
        setName("none");
        setStatus("OK");
        setStat("lvl",1);
        setStat("str",0);
        setStat("dex",0);
        setStat("int",0);
        setStat("con",0);
        setStat("spd",0);
        setStat("HP", 0);
        sendEnemyDeathReport();
    }
}


