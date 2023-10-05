#include "Solatire.h"
Solatire::Solatire()
{
    setSolatirePile();
    shuffleCards();
    setPileCards();
    setSpriteTexture();
    setSounds();
}

void Solatire::setSounds()
{

}

void Solatire::setSolatirePile()
{
    int index = 0;
    for (int suit = (int)Card_Types::CLUBS; suit <= (int)Card_Types::SPADES; ++suit)
    {
        for (int name = (int)cardNames::ACE; name <= (int)cardNames::KING; ++name)
        {
            Card card;
            if (suit == (int)Card_Types::CLUBS || suit == (int)Card_Types::SPADES)
            {
                card.color = Color_::BLACK;
            }
            else
            {
                card.color = Color_::RED;
            }
            card.name = (cardNames)name;
            card._type = (Card_Types)suit;
            card.flipped = false;
            card.front_side.loadFromFile(convert_suits[suit - 1] + " - " + convert_names[name - 1] + ".png");
            cards[index] = card;
            ++index;
        }
    }
}

void Solatire::shuffleCards()
{
    srand(time(nullptr));
    for (int i = 51; i > 0; i--)
    {
        int j = rand() % (i + 1);


        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}


void Solatire::setCordinates(Card& c)
{
    switch (c.Row)
    {
    case(card_Row::Waste_pile):
        c._x = 285;
        c._y = 118;
        break;

        break;
    case(card_Row::DRAW_PILE):
        c._x = 0;
        c._y = 118;
        break;
    case(card_Row::N_1):
        c._x = 285;
        c._y = 368;
        break;
    case(card_Row::N_2):
        c._x = 435;
        c._y = 368;
        break;
    case(card_Row::N_3):
        c._x = 585;
        c._y = 368;
        break;
    case(card_Row::N_4):
        c._x = 735;
        c._y = 368;
        break;
    case(card_Row::N_5):
        c._x = 885;
        c._y = 368;
        break;
    case(card_Row::N_6):
        c._x = 1035;
        c._y = 368;
        break;
    case(card_Row::N_7):
        c._x = 1185;
        c._y = 368;
        break;
    }
}

void Solatire::setPileCards()
{
    for (int i = 0; i < 52; i++)
    {
        if (i == 0)
        {
            cards[i].Row = card_Row::N_1;
            setCordinates(cards[i]);
            N1.push_back(cards[i]);
        }
        else if (i >= 1 && i <= 2)
        {
            cards[i].Row = card_Row::N_2;
            setCordinates(cards[i]);
            N2.push_back(cards[i]);
        }
        else if (i >= 3 && i <= 5)
        {
            cards[i].Row = card_Row::N_3;
            setCordinates(cards[i]);
            N3.push_back(cards[i]);
        }
        else if (i >= 6 && i <= 9)
        {
            cards[i].Row = card_Row::N_4;
            setCordinates(cards[i]);
            N4.push_back(cards[i]);
        }
        else if (i >= 10 && i <= 14)
        {
            cards[i].Row = card_Row::N_5;
            setCordinates(cards[i]);
            N5.push_back(cards[i]);
        }
        else if (i >= 15 && i <= 20)
        {
            cards[i].Row = card_Row::N_6;
            setCordinates(cards[i]);
            N6.push_back(cards[i]);
        }
        else if (i >= 21 && i <= 27)
        {
            cards[i].Row = card_Row::N_7;
            setCordinates(cards[i]);
            N7.push_back(cards[i]);
        }
        else //if(i >= 31 && i <= 75)//ye hai easy level
        {
            cards[i].Row = card_Row::Waste_pile;
            setCordinates(cards[i]);
            Piles.push(cards[i]);
            setSpriteTexture(1);



        }
    }
}

void Solatire::setSpriteTexture()
{
    setSpriteTexture(N1);
    setSpriteTexture(N2);
    setSpriteTexture(N3);
    setSpriteTexture(N4);
    setSpriteTexture(N5);
    setSpriteTexture(N6);
    setSpriteTexture(N7);
}









void Solatire::setSpriteTexture(vector<Card>& pile)
{
    for (int i = 0; i < pile.size(); ++i)
    {
        setCardBackTexture(pile[i]);
        setCardPosition(pile[i], i);

        if (isLastCardInPile(pile, i))
        {
            setCardFrontTexture(pile[i]);
            setCardFlippedStatus(pile[i]);
        }
    }
}

void Solatire::setCardBackTexture(Card& card)
{
    card.card_sprite.setTexture(card.back_side);
}

void Solatire::setCardPosition(Card& card, int index)
{
    card.card_sprite.setPosition(card._x, card._y + (index * wasteSet));
}

void Solatire::setCardFrontTexture(Card& card)
{
    card.card_sprite.setTexture(card.front_side);
}

void Solatire::setCardFlippedStatus(Card& card)
{
    card.flipped = true;
}

bool Solatire::isLastCardInPile(const vector<Card>& pile, int index)
{
    return index == pile.size() - 1;
}


void Solatire::setSpriteTexture(int pile_number)
{
    int xOffset = 100;
    int yOffset = 100;

    switch (pile_number)
    {
    case 1:
        Piles.top().card_sprite.setTexture(Piles.top().back_side);
        Piles.top().card_sprite.setPosition(Piles.top()._x, Piles.top()._y);
        Piles.top().flipped = false;
        break;
    case 2:
        draw_pile.top().card_sprite.setTexture(draw_pile.top().front_side);
        xOffset = 180;
        draw_pile.top().card_sprite.setPosition(draw_pile.top()._x + xOffset, draw_pile.top()._y);
        draw_pile.top().flipped = true;
        break;
    case 3:
        setSpriteTexture(Reserve1, 635 + xOffset, 17 + yOffset);
        break;
    case 4:
        setSpriteTexture(Reserve2, 785 + xOffset, 17 + yOffset);
        break;
    case 5:
        setSpriteTexture(Reserve3, 935 + xOffset, 17 + yOffset);
        break;
    case 6:
        setSpriteTexture(Reserve4, 1085 + xOffset, 17 + yOffset);
        break;
    case 7:
        setSpriteTexture(N1, 185 + xOffset, 268 + yOffset);
        break;
    case 8:
        setSpriteTexture(N2, 335 + xOffset, 268 + yOffset);
        break;
    case 9:
        setSpriteTexture(N3, 485 + xOffset, 268 + yOffset);
        break;
    case 10:
        setSpriteTexture(N4, 635 + xOffset, 268 + yOffset);
        break;
    case 11:
        setSpriteTexture(N5, 785 + xOffset, 268 + yOffset);
        break;
    case 12:
        setSpriteTexture(N6, 935 + xOffset, 268 + yOffset);
        break;
    case 13:
        setSpriteTexture(N7, 1085 + xOffset, 268 + yOffset);
        break;
    }
}








void Solatire::setSpriteTexture(stack<Card>& pile, int x_pos, int y_pos)
{
    pile.top().card_sprite.setTexture(pile.top().front_side);
    pile.top()._x = x_pos;
    pile.top()._y = y_pos;
    pile.top().card_sprite.setPosition(pile.top()._x, pile.top()._y);
}

void Solatire::setSpriteTexture(vector<Card>& pile, int x_pos, int y_pos) {
    for (int i = 0; i < pile.size(); ++i)
    {
        pile[i]._x = x_pos;
        pile[i]._y = y_pos;
        if (pile[i].flipped == true)
        {
            pile[i].card_sprite.setTexture(pile[i].front_side);
            pile[i].card_sprite.setPosition(pile[i]._x, pile[i]._y + (wasteSet * i));
        }
        else
        {
            pile[i].card_sprite.setTexture(pile[i].back_side);
            pile[i].card_sprite.setPosition(pile[i]._x, pile[i]._y + (wasteSet * i));
        }
    }
}

void Solatire::displayCards(RenderWindow& window)
{
    displayCards(window, Piles);
    displayCards(window, shuffled_pile22);

    displayCards(window, draw_pile);
    displayCards(window, Reserve1);
    displayCards(window, Reserve2);
    displayCards(window, Reserve3);
    displayCards(window, Reserve4);
    displayCards(window, N1, 7);
    displayCards(window, N2, 8);
    displayCards(window, N3, 9);
    displayCards(window, N4, 10);
    displayCards(window, N5, 11);
    displayCards(window, N6, 12);
    displayCards(window, N7, 13);
}

void Solatire::displayCards(RenderWindow& window, stack<Card>& stack)
{
    int s = stack.size();
    for (int i = 0; i < s; i++) // Draw pile
        window.draw(stack.top().card_sprite);
}

void Solatire::displayCards(RenderWindow& window, vector<Card>& pile, int pile_number)
{
    int s = pile.size();
    for (int i = 0; i < s; i++)
    {
        setSpriteTexture(pile_number);
        window.draw(pile[i].card_sprite);
    }
}
#include "Solatire.h"
Solatire::Solatire()
{
    setSolatirePile();
    shuffleCards();
    setPileCards();
    setSpriteTexture();
    setSounds();
}

void Solatire::setSounds()
{

}

void Solatire::setSolatirePile()
{
    int index = 0;
    for (int suit = (int)Card_Types::CLUBS; suit <= (int)Card_Types::SPADES; ++suit)
    {
        for (int name = (int)cardNames::ACE; name <= (int)cardNames::KING; ++name)
        {
            Card card;
            if (suit == (int)Card_Types::CLUBS || suit == (int)Card_Types::SPADES)
            {
                card.color = Color_::BLACK;
            }
            else
            {
                card.color = Color_::RED;
            }
            card.name = (cardNames)name;
            card._type = (Card_Types)suit;
            card.flipped = false;
            card.front_side.loadFromFile(convert_suits[suit - 1] + " - " + convert_names[name - 1] + ".png");
            cards[index] = card;
            ++index;
        }
    }
}

void Solatire::shuffleCards()
{
    srand(time(nullptr));
    for (int i = 51; i > 0; i--)
    {
        int j = rand() % (i + 1);


        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}


void Solatire::setCordinates(Card& c)
{
    switch (c.Row)
    {
    case(card_Row::Waste_pile):
        c._x = 285;
        c._y = 118;
        break;

        break;
    case(card_Row::DRAW_PILE):
        c._x = 0;
        c._y = 118;
        break;
    case(card_Row::N_1):
        c._x = 285;
        c._y = 368;
        break;
    case(card_Row::N_2):
        c._x = 435;
        c._y = 368;
        break;
    case(card_Row::N_3):
        c._x = 585;
        c._y = 368;
        break;
    case(card_Row::N_4):
        c._x = 735;
        c._y = 368;
        break;
    case(card_Row::N_5):
        c._x = 885;
        c._y = 368;
        break;
    case(card_Row::N_6):
        c._x = 1035;
        c._y = 368;
        break;
    case(card_Row::N_7):
        c._x = 1185;
        c._y = 368;
        break;
    }
}

void Solatire::setPileCards()
{
    for (int i = 0; i < 52; i++)
    {
        if (i == 0)
        {
            cards[i].Row = card_Row::N_1;
            setCordinates(cards[i]);
            N1.push_back(cards[i]);
        }
        else if (i >= 1 && i <= 2)
        {
            cards[i].Row = card_Row::N_2;
            setCordinates(cards[i]);
            N2.push_back(cards[i]);
        }
        else if (i >= 3 && i <= 5)
        {
            cards[i].Row = card_Row::N_3;
            setCordinates(cards[i]);
            N3.push_back(cards[i]);
        }
        else if (i >= 6 && i <= 9)
        {
            cards[i].Row = card_Row::N_4;
            setCordinates(cards[i]);
            N4.push_back(cards[i]);
        }
        else if (i >= 10 && i <= 14)
        {
            cards[i].Row = card_Row::N_5;
            setCordinates(cards[i]);
            N5.push_back(cards[i]);
        }
        else if (i >= 15 && i <= 20)
        {
            cards[i].Row = card_Row::N_6;
            setCordinates(cards[i]);
            N6.push_back(cards[i]);
        }
        else if (i >= 21 && i <= 27)
        {
            cards[i].Row = card_Row::N_7;
            setCordinates(cards[i]);
            N7.push_back(cards[i]);
        }
        else //if(i >= 31 && i <= 75)//ye hai easy level
        {
            cards[i].Row = card_Row::Waste_pile;
            setCordinates(cards[i]);
            Piles.push(cards[i]);
            setSpriteTexture(1);



        }
    }
}

void Solatire::setSpriteTexture()
{
    setSpriteTexture(N1);
    setSpriteTexture(N2);
    setSpriteTexture(N3);
    setSpriteTexture(N4);
    setSpriteTexture(N5);
    setSpriteTexture(N6);
    setSpriteTexture(N7);
}









void Solatire::setSpriteTexture(vector<Card>& pile)
{
    for (int i = 0; i < pile.size(); ++i)
    {
        setCardBackTexture(pile[i]);
        setCardPosition(pile[i], i);

        if (isLastCardInPile(pile, i))
        {
            setCardFrontTexture(pile[i]);
            setCardFlippedStatus(pile[i]);
        }
    }
}

void Solatire::setCardBackTexture(Card& card)
{
    card.card_sprite.setTexture(card.back_side);
}

void Solatire::setCardPosition(Card& card, int index)
{
    card.card_sprite.setPosition(card._x, card._y + (index * wasteSet));
}

void Solatire::setCardFrontTexture(Card& card)
{
    card.card_sprite.setTexture(card.front_side);
}

void Solatire::setCardFlippedStatus(Card& card)
{
    card.flipped = true;
}

bool Solatire::isLastCardInPile(const vector<Card>& pile, int index)
{
    return index == pile.size() - 1;
}


void Solatire::setSpriteTexture(int pile_number)
{
    int xOffset = 100;
    int yOffset = 100;

    switch (pile_number)
    {
    case 1:
        Piles.top().card_sprite.setTexture(Piles.top().back_side);
        Piles.top().card_sprite.setPosition(Piles.top()._x, Piles.top()._y);
        Piles.top().flipped = false;
        break;
    case 2:
        draw_pile.top().card_sprite.setTexture(draw_pile.top().front_side);
        xOffset = 180;
        draw_pile.top().card_sprite.setPosition(draw_pile.top()._x + xOffset, draw_pile.top()._y);
        draw_pile.top().flipped = true;
        break;
    case 3:
        setSpriteTexture(Reserve1, 635 + xOffset, 17 + yOffset);
        break;
    case 4:
        setSpriteTexture(Reserve2, 785 + xOffset, 17 + yOffset);
        break;
    case 5:
        setSpriteTexture(Reserve3, 935 + xOffset, 17 + yOffset);
        break;
    case 6:
        setSpriteTexture(Reserve4, 1085 + xOffset, 17 + yOffset);
        break;
    case 7:
        setSpriteTexture(N1, 185 + xOffset, 268 + yOffset);
        break;
    case 8:
        setSpriteTexture(N2, 335 + xOffset, 268 + yOffset);
        break;
    case 9:
        setSpriteTexture(N3, 485 + xOffset, 268 + yOffset);
        break;
    case 10:
        setSpriteTexture(N4, 635 + xOffset, 268 + yOffset);
        break;
    case 11:
        setSpriteTexture(N5, 785 + xOffset, 268 + yOffset);
        break;
    case 12:
        setSpriteTexture(N6, 935 + xOffset, 268 + yOffset);
        break;
    case 13:
        setSpriteTexture(N7, 1085 + xOffset, 268 + yOffset);
        break;
    }
}








void Solatire::setSpriteTexture(stack<Card>& pile, int x_pos, int y_pos)
{
    pile.top().card_sprite.setTexture(pile.top().front_side);
    pile.top()._x = x_pos;
    pile.top()._y = y_pos;
    pile.top().card_sprite.setPosition(pile.top()._x, pile.top()._y);
}

void Solatire::setSpriteTexture(vector<Card>& pile, int x_pos, int y_pos) {
    for (int i = 0; i < pile.size(); ++i)
    {
        pile[i]._x = x_pos;
        pile[i]._y = y_pos;
        if (pile[i].flipped == true)
        {
            pile[i].card_sprite.setTexture(pile[i].front_side);
            pile[i].card_sprite.setPosition(pile[i]._x, pile[i]._y + (wasteSet * i));
        }
        else
        {
            pile[i].card_sprite.setTexture(pile[i].back_side);
            pile[i].card_sprite.setPosition(pile[i]._x, pile[i]._y + (wasteSet * i));
        }
    }
}

void Solatire::displayCards(RenderWindow& window)
{
    displayCards(window, Piles);
    displayCards(window, shuffled_pile22);

    displayCards(window, draw_pile);
    displayCards(window, Reserve1);
    displayCards(window, Reserve2);
    displayCards(window, Reserve3);
    displayCards(window, Reserve4);
    displayCards(window, N1, 7);
    displayCards(window, N2, 8);
    displayCards(window, N3, 9);
    displayCards(window, N4, 10);
    displayCards(window, N5, 11);
    displayCards(window, N6, 12);
    displayCards(window, N7, 13);
}

void Solatire::displayCards(RenderWindow& window, stack<Card>& stack)
{
    int s = stack.size();
    for (int i = 0; i < s; i++) // Draw pile
        window.draw(stack.top().card_sprite);
}

void Solatire::displayCards(RenderWindow& window, vector<Card>& pile, int pile_number)
{
    int s = pile.size();
    for (int i = 0; i < s; i++)
    {
        setSpriteTexture(pile_number);
        window.draw(pile[i].card_sprite);
    }
}
