/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Card member functions
*/
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
    setAsciiArt();
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
void Card::setAsciiArt()
{
    // open file
    ifstream asciiArtFile;
    asciiArtFile.open("peterdoria_CS22_Program2_CardASCII_Art.txt");
    if (!asciiArtFile.fail())
    {
        int i = 0;
        int j = 0;
        int cardArtStartPos = m_cardValue * 6;
        int cardArtEndPos = cardArtStartPos + 6;
        string art = "";
        while (getline(asciiArtFile, art))
        {
        	//cout << i << " loop through file" << endl;
            if (i >= cardArtStartPos && i < cardArtEndPos)
            {
            	asciiArt[j] = art;
                j++;

                if (j == 6 )
				{
					asciiArtFile.close();
					break;
				}                    
            }
            i++;
        }
        
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
    for (int i = 0; i < 6; i++)
    {
        cout << asciiArt[i] << '\n';
        
    }
    cout << '\n';
}
