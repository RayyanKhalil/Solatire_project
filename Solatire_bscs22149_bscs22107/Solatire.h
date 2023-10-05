#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Card.h"
#include<Windows.h>
#include<windows.h>
#include <stack>
#include <random>
#include<queue>
#include <vector>

using namespace sf;
using namespace std;
class Solatire
{
    vector<Card> N1;
    vector<Card> N2;
    vector<Card> N3;
    vector<Card> N4;
    vector<Card> N5;
    vector<Card> N6;
    vector<Card> N7;

    stack<Card> Piles;
    stack<Card> shuffled_pile22;

    stack<Card> draw_pile;
    stack<Card> Reserve1;
    stack<Card> Reserve2;
    stack<Card> Reserve3;
    stack<Card> Reserve4;
public:
    int wasteSet = 25;

    Card* cards = new Card[52];

    Solatire();
    void setSounds();
    void setSolatirePile();
    void shuffleCards();
    void setCardFrontTexture(Card& card);
    int determineShuffleType(bool isFPileEmpty, int pile_number);
    void setCardFlippedStatus(Card& card);
    bool isLastCardInPile(const vector<Card>& pile, int index);
    void setCardBackTexture(Card& card);
    void setCardPosition(Card& card, int index);
    void setSpriteTexture();
    void setSpriteTexture(vector<Card>&);
    void setSpriteTexture(int);
    void setSpriteTexture(stack<Card>&, int, int);
    void setSpriteTexture(vector<Card>&, int, int);
    void setPileCards();
    void setCordinates(Card&);
    void displayCards(RenderWindow&);
    void displayCards(RenderWindow&, stack<Card>& s1);
    void displayCards(RenderWindow&, vector<Card>&, int);
    void checkSprite(Vector2f);
    bool checkSprite(Vector2f, FloatRect, int, stack<Card>&, vector<Card>&);









};