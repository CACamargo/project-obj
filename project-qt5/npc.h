#ifndef NPC_H
#define NPC_H

#include <QObject>
#include "entity.h"

class NPC : public QObject, public Entity{
    Q_OBJECT
public:
    NPC();
    NPC(QString name, int str, int dex, int intl, int con, int spd, QString type);
    QString getDialog() ;
    int getStat(QString statName) const;
    void setDialog(QString dialog);
    void setStat(QString statName, int newValue);
    QString toString();

public slots:
    void receiveNPCType(QString type);
    void receiveTalkRequest();

signals:
    void sendDialog(QString dialog);

private:
    QString m_dialog;

};

#endif // NPC_H
