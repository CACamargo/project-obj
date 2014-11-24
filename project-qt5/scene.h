#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QString>
#include <QVariant>

class Scene: public QObject{
    Q_OBJECT
public:
    Scene(QString, QString);
    QString getBackground();
    QString getSpecial();
    void setBackground(QString);
    void setSpecial(QString);

public slots:
    void changeScene(QString);

signals:
    void sendImageID(QVariant);
private:
    QString m_backgroundID;
    QString m_special;
};

#endif // SCENE_H
