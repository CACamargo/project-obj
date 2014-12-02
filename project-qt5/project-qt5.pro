TEMPLATE = app

QT += qml quick multimedia

SOURCES += main.cpp \
    player.cpp \
    entity.cpp \
    ability.cpp \
    scene.cpp \
    item.cpp \
    level.cpp \
    enemy.cpp \
    chest.cpp \
    npc.cpp

RESOURCES += qml.qrc \
    backgrounds.qrc \
    models.qrc \
    music1.qrc \
    music2.qrc \
    ui.qrc \
    effect1.qrc

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
    enemy.h \
    chest.h \
    npc.h
