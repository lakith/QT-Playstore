#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "gamewindow.h"
#include "gamebase.h"

GameBase * game;

GameWindow::GameWindow()
{
    game = new GameBase();
    game->show();
}
