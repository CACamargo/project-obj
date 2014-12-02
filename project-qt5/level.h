#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QString>
#include <QVector>

class Level: public QObject{
    Q_OBJECT
public:
    Level(int, int);
    QString getTile(int, int);
    int getSpecial(int, int);
    void setTile(QString, int, int);
    void setSpecial(int, int, int);
public slots:
    void evalRequest(QString, int, int);
    void receiveSceneSpecialReport(QString, int, int);
signals:
    void sendTileInfo(QString, int);
    void sendMoveApproval(int, int);    
private:
    QVector< QVector< QString > > m_map;
    QVector< QVector< int > > m_special;
    int m_rows;
    int m_columns;
};

#endif // LEVEL_H
