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
import csv
from re import A
import kaiju
import battle
import copy

#TO-DO: # Kaiju creator. random chance that the player is going to get a bonus thing?

# Every kaiju has 4 randomly selected primary traits which can randomly select 
#   additional identifiers depending on the given trait (i.e. size vs Kaiju Type):
# 1.  Size (inherits all traits of specified size)
# 2.  Traversal Type (inherits all tratis of specified size)
# 3.  Kaiju Type 1 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# 4.  Kaiju Type 2 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# Note: Each kaiju has two kaijuTypes. This gives each kaiju a unique identity.
#          (i.e. Atomic Robot, Spirit Brawler, Atomic Spirit, etc.)
# Note: A kaiju does not inherit all moves of an inherited type. It only inherits a few moves per type.          
def generateKaiju(generateRandom):

    name = input ("KAIJU NAME: ").upper()

    # Randomly select size traits for kaiju
    sizeType = random.randint(0, len(kaiju.ALL_SIZE_TYPES) - 1)
    sizeTraits = kaiju.ALL_SIZE_TYPES[sizeType]
 
    # Randomly select traversal traits for kaiju
    traversalType = random.randint(0, len(kaiju.ALL_TRAVERSAL_TYPES) - 1)
    traversalTraits = kaiju.ALL_TRAVERSAL_TYPES[traversalType]

    #TO-DO: Variable number of kaiju types or moves for a given kaiju??
        # Maybe always four moves, but can be split between types any way
        # that works. 


    # Randomly select moves from list based on kaiju's first type
    kaijuType1 = random.randint(0, len(kaiju.ALL_KAIJU_MOVES) - 1)
    kaijuType1Moves = []
    move = random.choice(kaiju.ALL_KAIJU_MOVES[kaijuType1])
    kaijuType1Moves.append(move)
    move = random.choice(kaiju.ALL_KAIJU_MOVES[kaijuType1])
    kaijuType1Moves.append(move)
    while kaijuType1Moves[0] == kaijuType1Moves[1] :
        move = random.choice(kaiju.ALL_KAIJU_MOVES[kaijuType1])
        kaijuType1Moves[1] = (move)
    
    # Randomly select moves from list based on kaiju's second type
    
    kaijuType2 = kaijuType1
    while kaijuType2 == kaijuType1:
        kaijuType2 = random.randint(0, len(kaiju.ALL_KAIJU_MOVES) - 1)
    kaijuType2Moves = []
    move = random.choice(kaiju.ALL_KAIJU_MOVES[kaijuType2])
    kaijuType2Moves.append(move)
    move = random.choice(kaiju.ALL_KAIJU_MOVES[kaijuType2])
    kaijuType2Moves.append(move)
    while kaijuType2Moves[0] == kaijuType2Moves[1] :
        move = random.choice(kaiju.ALL_KAIJU_MOVES[kaijuType2])
        kaijuType2Moves[1] = move

    moveTypes = [kaijuType1, kaijuType2]
    moveSets = [kaijuType1Moves, kaijuType2Moves]
      
    legs = random.randrange(0,8,2)
    arms = random.randrange(2,4,2)
    heads = random.randrange(1, 3, 2)
    
    kai =  kaiju.Kaiju(name, sizeType, sizeTraits, traversalType, traversalTraits, moveTypes, moveSets, legs, arms, heads)
    return kai

# prints generated kaiju data to the console for the user to see. 
#   Selects data from nested lists depending on the desired stat for output.
def printKaijuData(kai):
    print("================ KAIJU GENERATED ================\n")
    
    print("NAME:\t\t\t" + kai.name)
    print("LEGS:\t\t\t" + str(kai.legs))
    print("ARMS:\t\t\t" + str(kai.arms))
    print("HEADS:\t\t\t" + str(kai.heads))

    print("\nSIZE:\t\t\t" + kaiju.ALL_SIZE_TYPES_NAMES[kai.sizeType])
    j = 0
    while j < len(kai.sizeTraits) - 1:
        print(kaiju.ALL_SIZE_TYPES_NAMES[kai.sizeType] + " TRAIT " + str(j+1) + ":\t" + kai.sizeTraits[j])
        j+=1
    
    print("\nTRAVERSAL TYPE:\t\t" + kaiju.ALL_TRAVERSAL_TYPES_NAMES[kai.traversalType])
    j = 0
    while j < len(kai.traversalTraits):
        print(kaiju.ALL_TRAVERSAL_TYPES_NAMES[kai.traversalType] + " TRAIT " + str(j+1) + ":\t" + kai.traversalTraits[j])
        j+=1
        
    i = 0
    for moveType in kai.moveTypes:
        print("\nMOVE TYPE " + str(i+1) + ":\t\t" + kaiju.ALL_KAIJU_MOVES_NAMES[moveType])
        j = 0
        while j < len(kai.moveSets[i]):
            print(kaiju.ALL_KAIJU_MOVES_NAMES[moveType] + " MOVE " + str(j+1) + ":\t\t" + kai.moveSets[i][j])
            j+=1
        i+=1
    
    print("\nCONFIGURATION: " + kaiju.ALL_SIZE_TYPES_NAMES[kai.sizeType] + " " + kaiju.ALL_TRAVERSAL_TYPES_NAMES[kai.traversalType] + " " \
        + kaiju.ALL_KAIJU_MOVES_NAMES[kai.moveTypes[0]] + " " + kaiju.ALL_KAIJU_MOVES_NAMES[kai.moveTypes[1]])
        
    print("\n====================== END =====================\n")
    
def printKaijuList(simple):
    # print in rows and columns with corresponding letter
        # A unicode is 41
    i = ord("A")
    if (simple):
        for kai in kaijus:
            print(chr(i) + " - " + kai.name)       
    else: 
        for kai in kaijus:
            print(chr(i) + " - " + kai.name)
            print("\n\tCONFIGURATION: " + kaiju.ALL_SIZE_TYPES_NAMES[kai.sizeType] + " " + kaiju.ALL_TRAVERSAL_TYPES_NAMES[kai.traversalType] + " " \
        + kaiju.ALL_KAIJU_MOVES_NAMES[kai.moveTypes[0]] + " " + kaiju.ALL_KAIJU_MOVES_NAMES[kai.moveTypes[1]])
     

kaijus = []
kaijusSelectors = []

menuOptions = [1, 2, 3, 4, 5, 6]


def main():
    # Load in all kaiju
    with open("kaijus.txt") as kaijuCSV:
        reader = csv.reader(kaijuCSV)
        for line in reader:
            pass
         
             

    
    # TITLE / Pre-Battle Menu
    print("!!!!!!!!!!! KAIJU GENERATOR !!!!!!!!!!")  
    #   - Lists all kaiju (color code them)
#       - Ge
#       - Max kaiju of 26 (alphabetized)
#           A - Godzilla
#           B - King Kong    
    shouldQuit = False
    while(shouldQuit == False):
        print("~~~~~~ MENU OPTIONS ~~~~~~")
        print("\n" + str(menuOptions[0]) + "- KAIJU BATTLE (input 1 plus two letters, one for each kaiju going into battle." + 
              "\n\tFirst kaiju input is yours. Second is the AI's. (i.e. \"1AZ\", \"1XI\"))" + 
              "\n" + str(menuOptions[1]) + " - RANDOM AI KAIJU BATTLE (i.e. \"2\")" + 
              "\n" + str(menuOptions[2]) + " - GENERATE NEW kaiju (i.e. 3) --> Kaiju Generation Seqence / Menu" + 
              "\n" + str(menuOptions[3]) + " - DELETE KAIJU (i.e. 4A deletes kaiju with 'A' next to them)" + 
              "\n" + + str(menuOptions[4]) + " - KAIJU DATA (input 5 plus letter of associated kaiju, " + 
              "\n\t(i.e. '5A' gets data on kaiju with 'A' next to it))" + 
              "\n" + str(menuOptions[5]) +  " - QUIT" 
              )
        

        userInput = ""    
        invalid = False
        invalidInfo = ""
        while True:
            userInput = input("Input a menu option.").upper()
            userInput.strip()
            userInput.replace(" ", "")
            if (invalid == True):
                print("Input is invalid. Please give valid input based on menu option descriptions." +
                      "\n\tInvalid Info: " + invalidInfo
                      )

            # checks
            if (len(userInput) == 0):
                invalidInfo = "Input zero characters."
                continue

            match userInput[0]:
                case 1:
                    if (len(userInput) != 3):
                        invalid = True
                        invalidInfo = "KAIJU BATTLE requires 2 monster inputs."
                        
                    
                    
                    invalid = False
                case 2:
                    invalid = False
                case 3:
                    invalid = False
                case 4:
                    invalid = False
                case 5:
                    invalid = False
                case 6:
                    invalid = False
            # if selection check passes, break out of loop
            


        kai = generateKaiju()
        printKaijuData(kai)
        
    with open("kaijus.txt") as kaijusCSV:
        writer = csv.writer(kaijusCSV)
        for kai in kaijus:
            writer.writerow("======")
            writer.writerow(kai.name)
            writer.writerow(str(kai.sizeType))
            for trait in kai.sizeTraits
                writer.writerow(trait.)
            # Check for different types: https://stackoverflow.com/questions/152580/whats-the-canonical-way-to-check-for-type-in-python
            writer.writerow(traversalType)
            

    print("\n\nRAWR...")
    
    
    

if __name__ == "__main__":
    main()
#   - Options v2: Input the kaiju's letter and the number action you want to do    
#       1 - KAIJU BATTLE (input two letters, one for each kaiju going into battle.
#           First kaiju input is yours. Second is the AI's. (i.e. "1AZ", "1XI"))
#           ---> BATTLE GENERATION
#       2 - RANDOM AI KAIJU BATTLE (i.e. 2) --> BATTLE GENERATION
#       3 - GENERATE NEW kaiju (i.e. 3) --> Kaiju Generation Seqence / Menu    
#       4 - DELETE KAIJU (i.e. 4A deletes kaiju with 'A' next to them)
#       5 - KAIJU DATA (input letter of associated kaiju, (i.e. '5A' gets data on kaiju with 'A' next to it))
#           ---> KAIJU DATA OUTPUT
#       6 Quit --> Are you sure you want to Quit Menu


  

    
# LOAD KAIJU LIST from CSV. All Kaiju must be valid. 
  


###################################    
# Kaiju Generation
#
#   - Kaiju Generation View    
#       - MUST mimic anticipation of dice roll for each set of traits.    
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
#           - etc.    
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

        
