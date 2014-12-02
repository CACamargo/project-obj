#include <QTextStream>
#include <QVariant>
#include <QDebug>
#include "player.h"

Player::Player(QString name, int str, int dex, int intl, int con, int spd, int equipNumber, int invRows, int invColumns)
    : Entity(name, str, dex, intl, con, spd), m_experience(0), m_maxMP(intl*3+con), m_maxST(1+(con/3)+(spd/5)),
      m_xPosition(0), m_yPosition(0), m_isGuarding(false), m_direction("north") {

    m_MP = m_maxMP;
    m_ST = m_maxST;

    m_equippedItems.resize(equipNumber);

    m_inventory.resize(invRows);
    for (int i = 0; i < invRows; ++i) {
        m_inventory[i].resize(invColumns);
    }    
}

QString Player::toString() {
    QString output;
    QTextStream os(&output);
    os << "Name: " << getName() << "\n\n"
       << "*Condition:" << "\n"
       << "HP: " << getStat("HP") << "/" << getStat("max HP") << "\n"
       << "MP: " << m_MP << "/" << getStat("max MP") << "\n"
       << "ST: " << m_ST << "\n"
       << "STATUS: " << getStatus() << "\n\n"
       << "*Atributes:" << "\n"
       << "Str: " << getStat("str") << "\n"
       << "Dex: " << getStat("dex") << "\n"
       << "Int: " << getStat("int") << "\n"
       << "Con: " << getStat("con") << "\n"
       << "Spd: " << getStat("spd") << "\n";

    return output;
}

int Player::getStat(QString statName){
    if (statName == "exp")
        return m_experience;
    else if (statName == "max MP")
        return m_maxMP;
    else if (statName == "max ST")
        return m_maxST;
    else if (statName == "MP")
        return m_MP;
    else if (statName == "ST")
        return m_ST;
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

Item Player::getItem(int row, int column, int invRows, int invColumns){
    if (row > -1 && row < invRows && column > -1 && column < invColumns)
        return m_inventory[row][column];
    else
        return Item();
}

void Player::setStat(QString statName, int newValue){
    Entity::setStat(statName, newValue);
    if (statName == "exp")
        m_experience = newValue;
    else if (statName == "MP")
        m_MP = newValue;
    else if (statName == "intl")
        m_MP = newValue*2;
    else if (statName == "con" || statName == "spd")
        m_ST = 1 + (Entity::getStat("con"))/3 + (Entity::getStat("spd"))/5;
}

void Player::setPos(int x, int y){
    m_xPosition = x;
    m_yPosition = y;
}

void Player::setDir(QString dir){
    m_direction = dir;
}

void Player::addItem(Item item, int invRows, int invColumns){
    int stop = 0;
    for (int i = 0; i < invRows && stop == 0; i++) {
        for (int j = 0; j < invColumns && stop == 0; j++) {
            if (getItem(i,j).getType() == "none"){
                m_inventory[i][j] = item;
                stop = 1;
            }
        }
    }
}

void Player::equipItem(Item item, int equipNumber){
    int index = -1;
    QString type = item.getType();
    QString statName;
    if (type == "helm")
        index = 0;
    else if (type == "chest piece")
        index = 1;
    else if (type == "greaves")
        index = 2;
    else if (type == "boots")
        index = 3;
    else if (type == "shield")
        index = 4;
    else if (type == "sword" || type == "axe" || type == "mace")
        index = 5;

    if (index > -1 && index < equipNumber){
        if (index < 5)
            statName = "def";
        else if (index == 5)
            statName = "dam";
        setStat(statName,getStat(statName) - m_equippedItems[index].getEffect());
        m_equippedItems[index] = item;
        setStat(statName,getStat(statName) + m_equippedItems[index].getEffect());
    }

    sendEquipType(1+index, type);
}

void Player::useItem(int row, int column){
    if (row > -1 && row < m_inventory.size()){
        if (column > -1 && column < m_inventory[row].size()){
            QString type = m_inventory[row][column].getType();

            if (type == "health potion"){
                if (getStat("HP") + m_inventory[row][column].getEffect() > getStat("max HP"))
                    setStat("HP", getStat("max HP"));
                else
                    setStat("HP", getStat("HP") + m_inventory[row][column].getEffect());
            }
            else if (type == "mana potion"){
                if (getStat("MP") + m_inventory[row][column].getEffect() > getStat("max MP"))
                    setStat("MP", getStat("max MP"));
                else
                    setStat("HP", getStat("MP") + m_inventory[row][column].getEffect());
            }
        }
    }
}

void Player::receiveStatusRequest(){
    QVariant info(toString());
    sendStatusInfo(info);
}

void Player::movementRequest(QString dir){
    if (dir == "forward")
        sendRequest(getDirection(), getXPos(), getYPos());
    else if (dir == "left"){
        if (getDirection() == "north")
            setDir("west");

        else if (getDirection() == "west")
            setDir("south");

        else if (getDirection() == "south")
            setDir("east");

        else if (getDirection() == "east")
            setDir("north");
    }
    else if (dir == "right"){
        if (getDirection() == "north")
            setDir("east");

        else if (getDirection() == "west")
            setDir("north");

        else if (getDirection() == "south")
            setDir("west");

        else if (getDirection() == "east")
            setDir("south");
    }
}

void Player::receiveMoveApproval(int xPos, int yPos){
    setPos(xPos,yPos);
}

void Player::receiveInventoryRequest(){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            sendItemType(1+j+(i*10),m_inventory[i][j].getType());
        }
    }
    sendInventoryInfo();
}

void Player::receiveCombatInventoryRequest(){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            sendCombatItemType(1+j+(i*10),m_inventory[i][j].getType());
        }
    }
}

void Player::receiveItemInfoRequest(int row, int column){
    QVariant info = "";
    if (row > -1 && row < m_inventory.size()){
        if (column > -1 && column < m_inventory[row].size()){
            QVariant type = m_inventory[row][column].getType();
            if (type != "none"){
                info = (m_inventory[row][column].toString());
            }
            sendItemInfo(info,type,QVariant(row),QVariant(column));
        }
    }
}

void Player::receiveEquipTypeRequest(int index){
    if (index > -1 && index < m_equippedItems.size()){
        sendEquipType(index+1,QVariant(m_equippedItems[index].getType()));
    }
}

void Player::receiveEquipItemRequest(int row, int column){
    int index;
    if (row > -1 && row < m_inventory.size()){
        if (column > -1 && column < m_inventory[row].size()){
            QString type = m_inventory[row][column].getType();
            if (type != "none"){
                if (type == "helm")
                    index = 0;
                else if (type == "chest piece")
                    index = 1;
                else if (type == "greaves")
                    index = 2;
                else if (type == "boots")
                    index = 3;
                else if (type == "shield")
                    index = 4;
                else if (type == "sword" || type == "axe" || type == "mace")
                    index = 5;

                Item temp(m_equippedItems[index]);
                equipItem(m_inventory[row][column]);
                m_inventory[row][column] = temp;
                sendItemType(1+row+column,m_inventory[row][column].getType());
            }
        }
    }
}

void Player::receiveEquippedItemInfoRequest(int index){
    QVariant info = "";
    if (index > -1 && index < m_equippedItems.size()){
        if (m_equippedItems[index].getName() != "none"){
            info = (m_equippedItems[index].toString());
        }
        sendEquippedItemInfo(info);
    }
}

void Player::receiveUseItemRequest(int row, int column){
    useItem(row, column);
    m_inventory[row][column] = Item();
    sendItemType(1+(row*10)+column, m_inventory[row][column].getType());
    sendItemInfo("", m_inventory[row][column].getType(), QVariant(row), QVariant(column));
}

void Player::receiveDiscardItemRequest(int row, int column){
    if (m_inventory[row][column].getType() != "none"){
        m_inventory[row][column] = Item();
        sendItemType(1+(row*10)+column, m_inventory[row][column].getType());
        sendItemInfo("", m_inventory[row][column].getType(), QVariant(row), QVariant(column));
    }
}

void Player::receivePlayerInfoRequest(){
    QString info;
    QTextStream os(&info);
    os << "HP: " << getStat("HP") << "\n"
       << "MP: " << getStat("MP") << "\n"
       << "ST: " << getStat("ST") << "\n"
       << "COND: " << getStatus();

    sendPlayerInfo(QVariant(info));
}

void Player::receivePlayerAttackOrder(){
    issuePlayerAttack(getStat("dam"));
}

void Player::receiveAbilitiesRequest(){
    QString info;
    QTextStream os(&info);
    Ability ability;
    for (int i = 0; i < 9; i++) {
        info = "";
        ability = getAbility(i);
        if (ability.getType() == "none"){
            break;
        }
        else {
            os << ability.getName() << "\n";
            if (ability.getType() == "physical")
                os << "ST: ";
            else if (ability.getType() == "magical")
                os << "MP: ";
            os << ability.getCost();
            sendAbilityInfo(QVariant(i+1),QVariant(info));
        }
    }
}

void Player::receiveAbilityUseOrder(int position){
    Ability ability = getAbility(position);
    if (ability.getType() != "none"){
        if (ability.getType() == "physical" && ability.getCost() <= m_ST) {
            m_ST -= ability.getCost();
            float multiplier = ability.getEffect();
            int totalDamage = int((multiplier*getStat("dam")+0.5));
            reportAbilityUse();
            issuePlayerAttack(totalDamage);
        }
        else if (ability.getType() == "magical" && ability.getCost() <= m_MP){
            m_MP -= ability.getCost();
            float multiplier = ability.getEffect();
            int totalDamage = int((multiplier*getStat("dam")+0.5));
            issuePlayerAttack(totalDamage);
            reportAbilityUse();
        }
    }
}

void Player::receiveGuardOrder(){
    m_isGuarding = true;
    int STregen = 1 + (getStat("con")/5) + (getStat("spd")/10);

    if (m_ST < m_maxST){
        if (m_ST + STregen < m_maxST)
            m_ST += STregen;
        else
            m_ST = m_maxST;
    }
}

void Player::receiveCombatUseRequest(int row, int column){
    QString itemType = m_inventory[row][column].getType();
    if (itemType == "health potion" || itemType == "mana potion"){
        useItem(row, column);
        m_inventory[row][column] = Item();
        sendCombatItemType(1+(row*10)+column, itemType);
        reportCombatUse();
    }
}

void Player::receiveFleeOrder(){
    relayFleeOrder(getStat("spd"));
}

void Player::receiveEnemyAttack(int damage){
    QString report;
    QTextStream os(&report);
    if (damage < getStat("def")){
        os << "The enemy attacked, but you resisted all damage!";
        sendPlayerDamageReport(QVariant(report));
    }
    else {
        int collateralDamage;

        if (m_isGuarding == true){
            collateralDamage = (damage - getStat("def"))/2;
            m_isGuarding = false;
        }
        else
            collateralDamage = damage - getStat("def");

        os << "The enemy attacked you for " << collateralDamage << " damage!\n";

        if (collateralDamage >= getStat("HP")){
            sendPlayerDeathReport();
        }
        else{
            setStat("HP",getStat("HP") - collateralDamage);
            sendPlayerDamageReport(QVariant(report));
        }
    }
    qDebug() << report;
}

void Player::receiveItem(Item item){
    addItem(item);
}

void Player::receiveChestUseReport(){
    reportPosition(m_xPosition, m_yPosition);
}

void Player::receiveEnemyDeathReport(){
    m_ST = m_maxST;
}
