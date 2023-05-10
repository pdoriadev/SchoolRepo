/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Card member functions
*/
#include "peterdoria_CS22_Program2_deck.h"
#include "peterdoria_CS22_Program2_card.h"

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *  Returns value of card between 0 and 51 (inclusive).
 *                                                          *
 ************************************************************/
// get() --- Get card value
// - return the value from the member variable
int Card::get()
{
    return m_cardValue;
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *   Sets value of card between value of 0 and 51 (inclusive).
 	 Calls additional methods that set data that depends on 
	  card's unique value.
 *                                                          *
 ************************************************************/
// set() --- Set card value
// - set the value of the member variable
void Card::set(int newCardVal)
{
    m_cardValue = newCardVal;
}
    
void Card::setArt(Deck& deck)
{
	cardArt = deck.getCardArt(m_cardValue - 1);
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *     Returns value of card translated into its real-world
 	card value between 1 and 13 (inclusive).
 *                                                          *
 ************************************************************/
string Card::getPip()
{
    return pips[m_cardValue % 13];
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 * 		Returns suit of card based on card value between 
 	0 and 51 (inclusive)
 *                                                          *
 ************************************************************/
string Card::getSuit()
{
    return suits[m_cardValue / 13];
}


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *    Prints the real-world card number, suit, and ascii art
 	to the console. 
 *                                                          *
 ************************************************************/
// print() --- Print card value
// - print the card's value
// - Example display if member variable m_cardValue is 0
// - it should print "Ace of Hearts"
void Card::print()
{	
    int suit_number = m_cardValue / 13;
    int pip_number = m_cardValue % 13;
    cout << pips[pip_number] << " of " << suits[suit_number] << '\n';
	cout << cardArt;
    cout << '\n';
}
