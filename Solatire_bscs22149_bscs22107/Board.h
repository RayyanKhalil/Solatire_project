#pragma once
#include <SFML/Graphics.hpp>
#include<Windows.h>
#include<windows.h>
using namespace sf;

class Board
{
public:
    RectangleShape B;
    CircleShape C;
    Board();
    Board(int s1, int s2);

};