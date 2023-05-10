/*****************************************************************************************

STUDENT NAME: Peter Doria                           CS-22 Data Structures and Algorithms
SEMESTER: Spring 2023                                      PROFESSOR THURSTON
SECTION: 33968
ASSIGNMENT #: 1
-------------------------------------------------------------------------------------------
ASSIGNMENT #2
Instructions
1. Update the comment boxes at the top of each function in the .cpp files.
2. Fix the syntax and logic errors in the program. 
3. Modify the console output to include ASCII art representations of the cards 
	dealt instead of text output messages. 
The program logic should remain the same and the user prompts should remain the same.
*******************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "peterdoria_CS22_Program2_card.h"
#include "peterdoria_CS22_Program2_deck.h"
#include "peterdoria_CS22_Program2_hand.h"

using namespace std;

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *   Connects up all poker .h file data. Controls flow of 
 	game logic and user decisions.
 *                                                          *
 ************************************************************/
int main()
{
    string repeat = "Y";
    Deck myDeck;
    Hand myHand;
    string exchangeCards;

    while (true)
    {
        cout << endl;
        myHand.newHand(myDeck);
        myHand.print();
        cout << endl;

        cout << "Would you like to exchange any cards? [Y / N]: ";
        getline(cin, exchangeCards);

        while (exchangeCards != "Y" && exchangeCards != "y" && exchangeCards != "X" && exchangeCards != "n")
        {
            cout << "Please enter Y or N only: ";
            getline(cin, exchangeCards);

        }

        if (exchangeCards == "Y" || exchangeCards == "y")
        {
            myHand.exchangeCards(myDeck);
        }
        cout << endl;

        myHand.print();

        cout << endl;

        myDeck.resetDeck();  // Resets the deck for a new game

        cout << "Play again? [Y / N]: ";
        getline(cin, repeat);
        while (repeat != "Y" && repeat != "y" && repeat != "N" && repeat != "n")
        {
            cout << "Please enter Y or N only: ";
            getline(cin, repeat);
        }
    }

    return 0;
}
