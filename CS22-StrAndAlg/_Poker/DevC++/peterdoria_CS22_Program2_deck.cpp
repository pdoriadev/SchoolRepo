/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Deck member functions
*/

#include "peterdoria_CS22_Program2_deck.h"


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *      Full deck of cards generated at Deck class construction
 *                                                          *
 ************************************************************/
Deck::Deck() //--- default class constructor
{
    srand(time(0));
    for (int i=0; i < 52; i++)
    {
        Card cardInstance;
        cardInstance.set(i);	
        m_undealtDeck.push_back(cardInstance); // should it be .get here()???
    }
    readInAsciiArt();
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *      Takes all dealt cards and puts them back into the 
 	undealt deck
 *                                                          *
 ************************************************************/
void Deck::resetDeck()
{
    while (getSizeDealtDeck() != 0)
    {
        //m_undealtDeck.push_back(m_dealtDeck.pop_back());
        int last_index = getSizeDealtDeck()-1;
        m_undealtDeck.push_back(m_dealtDeck[last_index]);
        m_dealtDeck.pop_back();
    }
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *  - Private function. Should be called automatically when
        the card value is assigned. 
    use private card value variable to determine which ascii 
    art to read in, and assign each line of the ascii art 
	to a private string within an array. 
	
	13 cards per suit, 6 rows per card, each suit is ordered
		 from Ace to King going from top to bottom.                                       
 *                                                          *
 ************************************************************/
void Deck::readInAsciiArt()
{
	asciiCardArt.resize(52);
    // open file
    ifstream asciiArtFile;
    asciiArtFile.open("peterdoria_CS22_Program2_CardASCII_Art.txt");
    if (!asciiArtFile.fail())
    {
        int i = 0;
        int j = 0;
        while (getline(asciiArtFile, art))
        {
        	if (i != 0 && i % 6 == 0)
        	{
        		j++;
        		try
				{
					throw j;
				}
				catch (int e)
				{
					if (e > 51)
					{
						cout << "\n\n" << "index exceeds array size" << '\n\n';
						break; 									
					}
				} 			
			}
        
        	asciiCardArt[j] += art;
            i++;
        }
        asciiArtFile.close();
        if (asciiArtFile.is_open())
        {
        	cout << "File should not be open. closing" << endl;
		}    
    }
    else // failed to open
        cout << "Failed to open asciiArtFile" << '\n';
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *      selects a random card to deal out of the undealt deck
 	and add to the user's "hand"
 *                                                          *
 ************************************************************/
//   1. initialize random number generator
//          srand(time(0));
//   2. Create the deck of cards (52 Card objects)
//          loop 52 times
//             a. create an instance of the Card class
//             b. set the card instance to the value of the counter
//             c. add the card to the undealt deck vector

// reset() --- Reset the deck (completely undealt). We are moving all the cards in the dealt vector back to the undealt vector.
//   loop while the dealt deck is not empty
//       a. compute for the last index of the dealt deck vector and save it to a variable
//       b. get the Card from the last index in the dealt vector then,
//       c. push that Card back to the undealt vector
//       d. remove the last Card from the dealt vector

Card Deck::dealCard() // --- Deal a single card
{
    int random_index = rand() % getSizeUndealtDeck(); // gets random index in undealt deck
    Card random_card; // creates a card instance
    random_card.set(m_undealtDeck[random_index].get()); // set the random card to the correct value

    m_dealtDeck.push_back(random_card); // pushes the random card to the dealt deck
    m_undealtDeck[random_index] = m_undealtDeck.back(); // puts the back index value to the random index
    m_undealtDeck.pop_back(); // gets rid of the back value
    return random_card;

        //   1. get a random card through an random index
        //        - the random index will be rand() modulo the size of undealt deck
        //   2. using the random index, get the random card from the undealt deck and assign to a new instance of the Card
        //   3. then add a copy of the random card to the dealt deck vector
        //   4. swap the last card in the undealt deck with the random card in the undealt deck
        //   5. remove the last card in the dealt deck
        //   6. return the random card

}

string Deck::getCardArt(int index)
{
	return asciiCardArt[index];
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *    returns number of cards remaining in undealt deck.                                                      *
 *                                                          *
 ************************************************************/
const int Deck::getSizeUndealtDeck()  // --- return size of undealt deck
{
    return m_undealtDeck.size();
}
/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *    returns number of cards remaining in dealt deck.                                                      *
 *                                                          *
 ************************************************************/
const int Deck::getSizeDealtDeck()  // --- return size of dealt deck
{
    return m_dealtDeck.size();
}


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *       Calls print function for each card in undealt deck
 *                                                          *
 ************************************************************/
void Deck::printUndealtDeck() // loops through the undealt deck and prints it
{
   for (int i=0; i < getSizeUndealtDeck(); i++)
    {
        m_undealtDeck[i].print();
        cout << endl;
    }
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *       Calls print function for each card in dealt deck
 *                                                          *
 ************************************************************/
void Deck::printDealtDeck() // loops through the dealt deck
{
   for (int i=0; i < getSizeDealtDeck(); i++)
    {
        m_dealtDeck[i].print();
        cout << endl;
    }
}
