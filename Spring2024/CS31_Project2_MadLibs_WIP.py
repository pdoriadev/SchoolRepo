# 
# Your program should, at minimum, do the following:

#     Output a title for the game.
#     Ask if the user would like to play a game.
#     Ask for the players name. Greet the player.
#     Ask the player to choose from TWO story ideas you have created.  
#           Use an if statement here to separate the code for each choice.
#     Ask the player to input between 6 to 10 names/words/numbers to fill in spots for your story. 
#           Please do not go over 10 inputs because it can get very long to run/test the programs! 
#     Create a short story to go along with the gameplay, substituting their inputted words into the story. 
#           Each story should be different and ask for different inputs. Do not reuse the same inputs for 
#           each story please. Your stories should be at a minimum of 4 sentences. 
#     Ask if the user would like to play again (use a loop for this). Validate the user input as 
#           being y/n. If they input something that is NOT one of your options, ask the player to try again. 
#     Validate the user input for the story selection. If they input something that is NOT one of your options, 
#           ask the player to try again. 
#     Create a counter to record how many stories they have created. Display the counter before 
#           asking if they would like to play again. 
#     Spend time formatting your output so that it looks nice. 

# To Submit

# You will submit a Trinket.io URL for this homework assignment. Submit your program in Trinket 
#   when you have finished it. Be sure that your program is running free of errors before submitting it. 

import game

playedOnce = False

def wouldYouLikeToPlay():
    choice = ""
    if (playedOnce):
        print("Would you like to play the siweeist of siweeweeist of games?")
    else:
        print("Would you like to play a silly\nSiLLy\n\t\tSiWEE game? \n\n Input 'n' for no. Input anything else for yes.")
    choice = input("\n\n Input 'n' for no. Input anything else for yes.")
        
    if (choice == 'n'):
        return False
    else: 
        return True
    

def goodbye():
    print("Goodbye! May you have the silliest, no good, all great day.")

def main():
    print ("============================");
    print ("========= Mad Libs =========");
    print ("============================");
    
    if (wouldYouLikeToPlay()):
       game()
    

    


if _name_ == "_main_":
    main()