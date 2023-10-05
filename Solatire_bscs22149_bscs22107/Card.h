#pragma once
#include <SFML/Graphics.hpp>
#include<Windows.h>
#include<windows.h>
#include <iostream>
#include <stack>
#include <random>
#include"Utility.h"


using namespace sf;
using namespace std;
class Card
{
public:
    Card();
    Card(const Card&);
    Card& operator=(const Card&);
    friend bool operator==(const Card&, const Card&);
    Card_Types _type;
    cardNames name;
    Color_ color, c2;
    card_Row Row, r5;
    bool flipped;
    Texture front_side;
    Texture back_side;
    Sprite card_sprite, dummy_sprite;
    float _x, _y;
};







#define stringify( name ) #name
static string convert_suits[] =
{
        stringify(CLUBS),
        stringify(DIAMONDS),
        stringify(HEARTS),
        stringify(SPADES)
};

static string convert_names[] =
{
        stringify(ACE),
        stringify(TWO),
        stringify(THREE),
        stringify(FOUR),
        stringify(FIVE),
        stringify(SIX),
        stringify(SEVEN),
        stringify(EIGHT),
        stringify(NINE),
        stringify(TEN),
        stringify(JACK),
        stringify(QUEEN),
        stringify(KING)
};

