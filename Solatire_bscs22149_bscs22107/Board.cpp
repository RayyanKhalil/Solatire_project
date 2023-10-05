#include "Board.h"

#include "Game.h"

Board::Board()
{
    int y = 100;
    int x = 100;
    int ypos = 0; int xpos = 0;
    B.setSize(Vector2f(y + 12, x + 58));
    B.setPosition(Vector2f(ypos, xpos));
    B.setFillColor(Color::Transparent);

    int _col = 255;
    B.setOutlineColor(Color(_col, _col, _col, _col - 128));

    int s = 1;
    B.setOutlineThickness(1);
}
Board::Board(int startXPosition, int startYPosition)
{
    int y = 100;
    int x = 100;
    B.setSize(Vector2f(y + 12, x + 58));
    B.setPosition(Vector2f(startXPosition, startYPosition));
    B.setFillColor(Color::Transparent);
    int _col = 255;
    B.setOutlineColor(Color(_col, _col, _col, _col - 128));
    int s = 1;
    B.setOutlineThickness(1);
}