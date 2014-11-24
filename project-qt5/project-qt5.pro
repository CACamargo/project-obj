TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    player.cpp \
    entity.cpp \
    ability.cpp \
    scene.cpp \
    item.cpp \
    level.cpp

RESOURCES += qml.qrc \
    assets.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    entity.h \
    player.h \
    ability.h \
    scene.h \
    item.h \
    level.h \
    weapon.h \
    armor.h \
    potion.h
