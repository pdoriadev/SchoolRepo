/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
*/

#ifndef HAND_H
#define HAND_H

#include <iostream>
#include "peterdoria_CS22_Program2_card.h"       // Include card header file here
#include "peterdoria_CS22_Program2_deck.h"       // Include deck header file here
using namespace std;

const int NUM_CARDS_ON_HAND = 5;

class Hand
{
public:
    // Put new card from deck into given location in a hand
    void newCard(Deck& deck, int location);

    // Get all new cards
    void newHand(Deck& deck);

    // Determine cards to exchange and exchange them in a hand
    void exchangeCards(Deck& deck);

    // Print the hand
    void print();

private:
    Card m_hand[NUM_CARDS_ON_HAND];  // A hand consists of 5 cards
};

#endif
