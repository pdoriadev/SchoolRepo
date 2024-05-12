# BEFORE SUBMITTING, check that you:

#     added your name, date, class number, and project name to your code
#     included test case data for at least 3 inputs and fixed any errors that 
#       came up (you can create a separate file in REPL called README.md and 
#       type your information directly into it. - see example below
#     commented your code - at minimum, describe each function
#     started your program using a main function
#     applied formatting to your input and output
#     checked for typos/spelling errors

# You will submit a Trinket URL for this homework assignment. Be sure that your 
#   program is running free of errors before submitting it. Test it with different 
#   inputs and make sure your inputs are being stored as the correct data type. 
#   Include test data and outcomes for at least THREE different inputs within your 
#   program code within a README.md file. Take a look at the example below - 
#   open it in Trinket so you can see the files. 


#####################################################################################

# Character battle sim AKA Kaiju Battle Sim
# https://lbcc.instructure.com/courses/98308/assignments/1660533?module_item_id=4003993
# https://lbcc.instructure.com/courses/98308/pages/character-generator-battle-simulator

# This option can be built off of your original character generator game or you can create
#    a new character generator game for the purpose of this activity. 

# You will be building a program using Python and a CSV file that will store all of your 
#   characters and their battle stats. 

# -> Overhaul old kaiju generator
#       Organize by kaiju class
#       Limit use of obfuscated multidimensional list


# Create a menu system that has the following functions:

# Pre-battle
#    - Create a new Character. Randomly assign values for the character. (10 points)
#    - List all Characters - display a nicely formatted list of characters and 
#      their stats. (10 points)
#           -> Randomly generate set of kaiju
#           -> Need test case csv to test against different characters.
#                   What exactly am I testing?
#    - Search for a Character by name and display their stats and wins/losses for their 
#      battle history. (10 points)
#    - Delete a Character and all of its stats (5 points)
# Battle and Post-battle - (35 points)
#    - Battle
#       - Ask the user if they would like to pick the two characters to battle or if 
#             they would like to create a random battle between two existing characters. 
#       - Ask the user if they would like to control the turn based battle system where 
#             you give them choices on what to do (strike, run, heal, etc.) or if they 
#             would like the system to automatically battle for them. 
#             -> If battle system is limited to menus. Hmmm. How to make good.
#                   Dice rolls?
#                   Make a 2D ASCII visual?? Would entail a lot. 
#                       Lot of work. Probably not worth it?
#                       Might be easy with colorama module? https://pypi.org/project/colorama/
#                   Timer / timing-based moves. Different moves more/less effective 
#                         at different numbers?
#                         time module
#                   How much damage per attack?
#       - Randomly generate strikes based on your character stats and deduct those values 
#             from their hit/health points each turn
#       - Allow the character to heal themselves by creating a random value and adding 
#             it to their hit/health points
#       - Record each action on the screen for the user to watch - consider using the time 
#             module to pause the game for a second so the user can see each action. 
#            Have fun and make it creative and engaging for your player
#       - Record the hit points and any other stats that you think is important for 
#             your battle.
#
#   - Post-battle
#       - Depending on the outcome of the battle, allow your character to increase 
#             their stats and record them to the CSV file
#       - Record the history of wins and losses for the character into the CSV file

#####################################################################################
# If using features from outside class (i.e. dictionary, classes, etc.), thoroughly
#    comment that code. 

# You have the creative license to add to this program however you wish. Be sure that the 
#   above features are working. You can add additional functionality to the program if you 
#   would like to and may be awarded some extra credit if you make it really good! 

# Do your best to meet the requirements of the project, but if you cannot get a particular 
#   function to work, turn in what does work. Do one function at a time and test. Once you 
#   know that function works, move onto the next. 

# - Be sure to create a menu driven system that lists all of the function options and has 
#       an option to exit. Validate the entry. (5 points)
# - Ensure that there is a minimum of 6 characters already in your system for me to test 
#       your program with. (5 points)
# - Validate your inputs. Test for invalid inputs and handle as necessary. (5 points)
# - Be sure to consider the user experience and the formatting of the output. (10 points)
# - Comment your code and name your functions appropriately. (5 points)

# Have fun with this! 

# The program must do the following: 

#     *Comment your code with your name, date, assignment title, and class. 
#     Comment your code to document your code process. 
#     *Ask if the user would like to generate a character (or whatever your program will do). 
#     *Ask for a character name. Or provide a name for them. 
#     *Import and use the random module.
#     *Generate at least 5 different characteristics of a character (such as strength, intellect, hit points, wisdom, charisma, etc.) and assign a random value to each of them. 
#     *Use at least one list.
#     *Use at least TWO functions. One function must pass a parameter. 
#     *Use a random number and if statement to generate a class/race or character type (such as human warrior, or alien from Mars, etc.) 
#     *Output the character information and all of their stats in a user friendly format. 
#     *Ask if the user would like to create a different character. 

# Comment code and functions!

#==============================================================================

# Peter Doria
# 4/25/2024
# Programming Project 3: Random Character Generator
# CS31 - 33880

# for choosing options from list randomly
import random
import kaiju


# prints generated kaiju data to the console for the user to see. 
#   Selects data from nested lists depending on the desired stat for output.
def printKaijuData(_kaiju):
    print("================ KAIJU GENERATED ================\n")
    
    print("NAME:\t\t\t" + name)
    print("LEGS:\t\t\t" + str(limbsAndHeads[0]))
    print("ARMS:\t\t\t" + str(limbsAndHeads[1]))
    print("HEADS:\t\t\t" + str(limbsAndHeads[2]))

    print("\nSIZE:\t\t\t" + traits[0][0])
    index = 0
    while index < len(traits[0][1]):
        print(traits[0][0] + " TRAIT " + str(index+1) + ":\t" + traits[0][1][index])
        index+=1
    
    print("\nTRAVERSAL TYPE:\t\t" + traits[1][0])
    index = 0
    while index < len(traits[1][1]):
        print(traits[1][0] + " TRAIT " + str(index+1) + ":\t" + traits[1][1][index])
        index+=1
        
    print("\nTYPE 1:\t\t\t" + traits[2][0])
    index = 1
    while index < len(traits[2]):
        print(traits[2][0] + " MOVE " + str(index) + ":\t\t" + traits[2][index])
        index+=1
    
    print("\nTYPE 2:\t\t\t" + traits[3][0])
    index = 1
    while index < len(traits[3]):
        print(traits[3][0] + " MOVE " + str(index) + ":\t\t"  + traits[3][index])
        index+=1
    
    print("\nCONFIGURATION: " + traits[0][0] + " " + traits[1][0] 
        + " " + traits[2][0] + " " + traits[3][0])
        
    print("\n====================== END =====================\n")




def main():
    print("!!!!!!!!!!! KAIJU GENERATOR !!!!!!!!!!")
    print()
    
# LOAD KAIJU LIST from CSV. All Kaiju must be valid. 
  
# TITLE / Pre-Battle Menu
#   - Lists all kaiju (color code them)
#       - Max kaiju of 26 (alphabetized)
#   - Options: 
#       - Generate new kaiju --> Kaiju Generation View
#       - Delete kaiju --> Kaiju deletion menu
#       - Get more info on kaiju (type in number next to associated kaiju)
#       - MELEE --> Kaiju Select Menu   
#       - Random AI Melee --> BATTLE GENERATION
#       - Quit        
#   - Options v2: Input the kaiju's letter and the number action you want to do    
#       1 - KAIJU BATTLE (input two letters, one for each kaiju going into battle.
#           First kaiju input is yours. Second is the AI's. (i.e. "1AZ", "1XI"))
#           ---> BATTLE GENERATION
#       2 - RANDOM KAIJU BATTLE (i.e. 2) --> BATTLE GENERATION
#       3 - GENERATE NEW kaiju (i.e. 3) --> Kaiju Generation Seqence / Menu    
#       4 - DELETE KAIJU (i.e. 4A deletes kaiju with 'A' next to them)
#       5 - KAIJU DATA (input letter of associated kaiju, (i.e. '5A' gets data on kaiju with 'A' next to it))
#           ---> KAIJU DATA OUTPUT
#       6 Quit --> Are you sure you want to Quit Menu

###################################    
# Kaiju Generation
#
#   - Kaiju Generation View    
#       - Ask for a number between 1 and 100 from player
#       - Generate Kaiju Sequence (Do fun timer stuff)... let player skip to end if they want
#           - give player mini-quiz that if they get stuff right will... have not affect. But they won't know that hehe                    
#       - Kaiju Generated Menu
#           - Display new kaiju stats
#           - Display madlibs style generated background    
#           - Save Kaiju Choice: Do you want to save this kaiju? If yes, save to CSV. If not, move back to pre-battle menu     
#               - If kaiju list + 1 > maxKaiju, then have to delete a kaiju.     
#    
#   - Kaiju Generation Model
#       - Looks at set of currently generated kaiju. Somehow biased to generate things that are not represented
#           in current pool of kaiju. 
#               - Requires list of things not represented. Probably create list(s) on loading in CSV. 
#       - Generate Kaiju
#       - If kaiju is saved, update list of things not represented in kaiju pool.     
#           

#################################
# Kaiju Battle - turn-based
#       -- Dice: D6
#       -- Kaiju Stats (all influenced by Kaiju's traits)
#           - Health
#           - Size
#    
#       -- One 'move' per turn
#           - Moves pulled from different traits
#    
#       -- Attacking Result = Attack - Defend
#           - Positive number = SUCCESS
#           - 0 or less = FAIL   
#           - Attack Roll: (Number of dice * (size+1) do a Dice Roll + special state from moves 
#           - Defend Roll: (Number of dice * (number of sizes - size)) do a Dice Roll + special state from moves
#
#       -- Special Move = Roll against special move's DC
#           - Meets it beats it    
#           - Use HP to empower a special move    
    
    
    
    




# TO-DO - save kaiju list into csv  

        

    print("\n\nRAWR...")
    
    
    

if __name__ == "__main__":
    main()