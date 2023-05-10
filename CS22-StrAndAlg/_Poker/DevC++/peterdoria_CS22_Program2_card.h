/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Sources: https://en.wikipedia.org/wiki/Standard_52-card_deck
//         https://en.wikipedia.org/wiki/Pip_(counting)



const string pips[] = {"Ace", "Two", "Three", "Four", "Five",
                       "Six", "Seven", "Eight", "Nine", "Ten",
                       "Jack", "Queen", "King"};
const string suits[] = {"Hearts", "Spades", "Clubs", "Diamonds"};

class Card
{
public:
    // Get card value
    int get();

    // Set card value
    void set(int value);

    string getPip();

    string getSuit();

    // Print card value
    void print();

private:
	string cardArt;
    int m_cardValue;
};

#endif
