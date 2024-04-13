
# Peter Doria, 3/27/24,  CS31 - 33880,  Code Practice Lab 4

import random

EASY_LIMIT = 10
MEDIUM_LIMIT = 100
HARD_LIMIT = 1000

EASY_TRIES = 5
MEDIUM_TRIES = 8
HARD_TRIES = 10


def display_title():
    print("=============== Guess the number! ===============")
    print("=================================================")
    print()

def greetPlayer():
    print("=================================================")
    name = input("Hello player! What is your name? ")
    print ("Welcome to the game, " + name + ".")
    return name


def displayScore(name, wins, losses):
    print("================== SCOREBOARD ====================")
    print("\t" + name + "'s WINS: \t" + str(wins))
    print("\t"  + name + "'s LOSSES: \t" + str(losses))
    print("==================================================")


def playGame():
    print("\n=================================================\n")   
    # Tell player how difficulty works
    input("If you don't guess the number before you hit the 'tries limit', "
          "you lose the game. So don't lose!"
                "\nInput any key to continue.")
    print("=================================================\n")   
    
    diff = 0
    # Validate difficulty input. Explain difficulties
    while (int(diff) != 1 and int(diff) != 2 and int(diff) != 3):
        diff = input("\nWhat difficulty would you like? "
                    "\n\teasy = range of 1 to 10, Number of guesses: 5."
                    "\n\tmedium = range of 1 to 100, Number of guesses: 8."
                    "\n\thard = range of 1 to 1000, Number of guesses: 10."
                    "\n\n\tType in '1' for easy, '2' for medium, and '3' for hard: ")

    # Set limit and tries based on difficulty selction
    limit = 0
    tries = 0
    if (int(diff) == 1):
        limit = EASY_LIMIT
        tries = EASY_TRIES
    elif (int(diff) == 2):
        limit = MEDIUM_LIMIT
        tries = MEDIUM_TRIES
    elif (int(diff) == 3):
        limit = HARD_LIMIT
        tries = HARD_TRIES

    # generate random number between 1 and value of limit
    number = random.randint(1, limit)
    print(f"I'm thinking of a number from 1 to {limit}\n")
    count = 0

    # player inputs a guess. Checks if it is correct. Given feedback if is/isn't correct
    # returns 1 or 0 depending on if player wins or loses. 
    while (count <= tries) :
        guess = int(input("Your guess: ")) 
        count += 1

        if guess < number:
            print("Too low.")
        elif guess > number:
            print("Too high.")
        else:
            print("You guessed it in " + str(count) + " tries.\n")
            return 1
        
        if (count == tries):
            print("You have hit the tries limit of " + str(tries) + "."
                  "\n\t Good luck next game!")
            return 0
                        

def main():
    display_title()
    name = greetPlayer()
    again = "y"
    wins = 0
    totalGames = 0
    while again.lower() == "y":
        wins += playGame()
        totalGames+=1
        #losses = totalGames - wins
        displayScore(name, wins, totalGames - wins)
        
        print("\n=================================================\n")   
        again = input("Would you like to play again, " + name + "? (y/n): ")
        print("\n=================================================\n")   
    print("Bye, " + name + "!")

# if started as the main module, call the main function
if __name__ == "__main__":
    main()

