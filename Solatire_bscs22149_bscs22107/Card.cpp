#include "Card.h"
#include"Utility.h"
#include<algorithm>

Card::Card()
{
    flipped = false;
    front_side.loadFromFile("a.png");
    back_side.loadFromFile("a.png");
    card_sprite.setTexture(back_side);
    _x = 0;
    _y = 0;
}
Card::Card(const Card& c)
    : _type(c._type),
    name(c.name),
    color(c.color),
    Row(c.Row),
    flipped(c.flipped),
    front_side(c.front_side),
    back_side(c.back_side),
    card_sprite(c.card_sprite),
    _x(c._x),
    _y(c._y)
{

}
Card& Card::operator=(const Card& c)
{
    _type = c._type;
    name = c.name;
    color = c.color;
    Row = c.Row;
    flipped = c.flipped;
    front_side = c.front_side;
    back_side = c.back_side;
    card_sprite = c.card_sprite;
    _x = c._x;
    _y = c._y;
    return *this;
}
void swap(Card& first, Card& second)
{
    using std::swap;
    swap(first._type, second._type);
    swap(first.name, second.name);
    swap(first.color, second.color);
    swap(first.Row, second.Row);
    swap(first.flipped, second.flipped);
    swap(first.front_side, second.front_side);
    swap(first.back_side, second.back_side);
    swap(first.card_sprite, second.card_sprite);
    swap(first._x, second._x);
    swap(first._y, second._y);
}
bool operator==(const Card& lhs, const Card& rhs)
{
    return lhs.color == rhs.color && lhs.name == rhs.name && lhs._type == rhs._type;
}

