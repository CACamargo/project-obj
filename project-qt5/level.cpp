
#include "level.h"
#include <QDebug>

Level::Level(int rows, int columns)
    :m_rows(rows), m_columns(columns){

    m_map.resize(rows);
        for (int i = 0; i < rows; ++i) {
            m_map[i].resize(columns);
        }
}

QString Level::getTile(int row, int column){
    if ((row > -1 && row <= m_rows) && (column > -1 && column <= m_columns))
        return m_map[row][column];
    else
        return "none";
}

void Level::setTile(QString background, int row, int column){
    if (row <= m_rows && column <= m_columns)
        m_map[row][column] = background;
}

void Level::evalRequest(QString dir, int xPos, int yPos){
    qDebug() << "Facing " << dir;
    if (dir == "north" && xPos > 0){
        sendTileInfo(m_map[xPos-1][yPos]);
        sendMoveApproval(xPos-1, yPos);
    }
    else if (dir == "east" && yPos < m_columns - 1){
        sendTileInfo(m_map[xPos][yPos+1]);
        sendMoveApproval(xPos, yPos+1);
    }
    else if (dir == "west" && yPos > 0){
        sendTileInfo(m_map[xPos][yPos-1]);
        sendMoveApproval(xPos, yPos-1);
    }
    else if (dir == "south" && xPos > m_rows - 1){
        sendTileInfo(m_map[xPos+1][yPos]);
        sendMoveApproval(xPos+1, yPos);
    }
}
