/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Hand member functions
*/

#include "peterdoria_CS22_Program2_hand.h"

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *     Put new card from deck into given location in the hand
 *                                                          *
 ************************************************************/
// newCard() --- Put new card from deck into given location in the hand
// 1. deal a card from the deck
// 2. assign the card to the location in the hand array
void Hand::newCard(Deck& deck, int location)
{
    Card new_card = deck.dealCard();
    m_hand[location] = new_card;
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *    The hand receives all new cards from the deck.
 *                                                          *
 ************************************************************/
// newHand() --- Get all new cards
// 1. loop for zero to the number of cards on hand (NUM_CARDS_ON_HAND)
// a. get a new card by calling another member function using the loop counter as the location
void Hand::newHand(Deck& deck)
{
    for (int i=0; i < NUM_CARDS_ON_HAND; i++)
    {
        Hand::newCard(deck, i);
    }
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *       Gives user ability to exchange a user-defined number of cards
 	from their and hand. For each exchanged card, they receive a new
	 card from the deck. 
 *                                                          *
 ************************************************************/
// exchangeCards() --- Determine cards to exchange and exchange them
// 1. declare an integer variable to store number of exchanges
// 2. Prompt and ask the user for how many cards to exchange between [1 to 5] (make sure to validate user input)
// 3. loop based on the number of exchanges to make
// declare integer position
// if user wants all card replaced, then
// position = loop counter
// otherwise,
// Prompt and ask the user for the position of the card on hand to exchange (make sure to validate user input)
// get a new card and replace the card at the identified position
void Hand::exchangeCards(Deck& deck)
{
    int num_of_exchanges;
    cout << "How many cards would you like to exchange (1-5): "; // gets number of cards to be exchanged
    cin >> num_of_exchanges;

    while (num_of_exchanges > 5 || num_of_exchanges < 1) // validates input
    {
        cout << "Please enter a number (1-5): ";
        cin >> num_of_exchanges;
    }
    
	int exchangedCards[num_of_exchanges] = {0,0,0};
    for (int i=0; i < num_of_exchanges; i++) // looping through number of exchanges
    {
    	int position = i; // positioned to be changed is i -- only relevant when discarding whole hand
        if (num_of_exchanges != NUM_CARDS_ON_HAND) // if number of exchanges is less than total hand count
        {
        	position = -1;
            cout << "Enter a position in hand of card to exchange. ";

            while (position > 5 || position < 1) // validates input
            {
                cout << "Please enter a number (1-5): ";
                cin >> position;
            	for (int j = 0; j <= i; j++) // check if user has already exchanged card at position.
                {
                	if (exchangedCards[j] == position)
                	{
                		position = -1;	
                		cout << "You cannot exchange cards you just got. ):" << '\n';
                		break;
					}
				}	
            }
            exchangedCards[i] = position;
            position--;	// position in hand adjusted for array indexing
        }
		Hand::newCard(deck, position); // replaces card at position
    }

}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *  Calls the print() function for every card in the hand
 *                                                          *
 ************************************************************/
// print() --- print the hand
// 1. loop for zero to the number of cards on hand
// a. print out location of the card on hand followed by
// b. print card pip value and card suit value

void Hand::print()
{

    for (int i=0; i < NUM_CARDS_ON_HAND; i++)
    {
    	cout << "Card " << i+1 << " is the ";
        m_hand[i].print();
    }
    cout << endl;
}
