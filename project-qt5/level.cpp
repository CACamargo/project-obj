#include "level.h"
#include <QDebug>

Level::Level(int rows, int columns)
    :m_rows(rows), m_columns(columns){

    m_map.resize(rows);
    m_special.resize(rows);

    for (int i = 0; i < rows; ++i) {
        m_map[i].resize(columns);
        m_special[i].resize(columns);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            m_map[i][j] = "none";
            m_special[i][j] = 0;
        }
    }
}

QString Level::getTile(int row, int column){
    if ((row > -1 && row <= m_rows) && (column > -1 && column <= m_columns))
        return m_map[row][column];
    else
        return "none";
}

int Level::getSpecial(int row, int column){
    if ((row > -1 && row <= m_rows) && (column > -1 && column <= m_columns))
        return m_special[row][column];
    else
        return 0;
}

void Level::setTile(QString background, int row, int column){
    if (row <= m_rows && column <= m_columns)
        m_map[row][column] = background;
}

void Level::setSpecial(int special, int row, int column){
    if (row <= m_rows && column <= m_columns)
        m_special[row][column] = special;
}

void Level::evalRequest(QString dir, int xPos, int yPos){
    if (dir == "north" && xPos > 0){
        sendTileInfo(m_map[xPos-1][yPos], m_special[xPos-1][yPos]);
        sendMoveApproval(xPos-1, yPos);
    }
    else if (dir == "east" && yPos < m_columns - 1){
        sendTileInfo(m_map[xPos][yPos+1], m_special[xPos][yPos+1]);
        sendMoveApproval(xPos, yPos+1);
    }
    else if (dir == "west" && yPos > 0){
        sendTileInfo(m_map[xPos][yPos-1], m_special[xPos][yPos-1]);
        sendMoveApproval(xPos, yPos-1);
    }
    else if (dir == "south" && xPos < m_rows - 1){
        sendTileInfo(m_map[xPos+1][yPos], m_special[xPos+1][yPos]);
        sendMoveApproval(xPos+1, yPos);
    }
    else {
        sendTileInfo(m_map[xPos][yPos], m_special[xPos][yPos]);
        qDebug() << "Cannot advance any more.";
    }
}

void Level::receiveSceneSpecialReport(QString special, int xPos, int yPos){
    if (special == "none")
        m_special[xPos][yPos] = 0;
}
