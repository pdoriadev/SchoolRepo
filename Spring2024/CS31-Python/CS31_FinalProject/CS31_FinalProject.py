

# Deckbuilding RPG references
    # Dawncaster: https://apps.apple.com/us/app/dawncaster-deckbuilding-rpg/id1555459868
    # Legendfall: https://www.legendfall.com/
    # 
# RPG references
    # caves of qud
# Deckbuilding references
    # slay the spire
    


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
# 5/25/2024
# Programming Project 3: Random Character Generator
# CS31 - 33880

# for choosing options from list randomly
import random
import csv
from turtle import delay
import kaiju
import battle
from enum import Enum
import time
import utils

kaijuNames =  ["godzilla", "gojira", "gigan", "anguirus", "mechagodzilla", "kiryu", "king ceasar", \
                     "jet jaguar", "monster x", "king ghidorah", "king kong", "manda", "hedorah", \
                     "megaguirus", "biolante", "space godzilla", "monster omega", "ebirah", \
                     "kamacurus", "kumonga", "rodan", "mothra", "minila", "gypsy danger", "megazord", "Gabara", \
                     "Baragon", "Fire Rodan", ]

sillyNames = ["jay jay the jet plane", "miss piggy", "kermit", "dostoevsky", "timzilla", "christoughman", \
                    "tony stark", "danny de vito", \
                    "captain kirk", "hercules", "captain america", "mister", "batman", "robin", \
                    "remy (from pixar's \"ratatouille\")", "an innocent man", "a lecherous gecko", \
                    "odysseus", "tony stark", "the blues brothers", "lisan al gaib", \
                    "tchaikovsky", "debussy", "john williams", "vivaldi", "mozart", "beethoven", \
                    "jean-luc picard", "obi-wan kenobi", "mr. peanut", "the yellow telleytubbie", \
                    "barney (from \"barney\")", "spongebob", "danikus manikus", "james bond", "teddy roosevelt", \
                    "abraham lincoln", "abraham lincoln: vampire slayer", "captain nemo", "scarlet o'hara", \
                    "optimus prime", "every member of the band \"rush\"", "the last of an endangered species", \
                    "the beast from 20,000 fathoms", "the road warrior", "ryan reynolds", "tommy wiseau", \
                    "jim (from \"the office\")", "michael scott", "bill hayder", "frederick nietzsche", \
                    "baby godzilla", "weird barbie"]

# Every kaiju has 4 randomly selected primary traits which can randomly select 
#   additional identifiers depending on the given trait (i.e. size vs Kaiju Type):
# 1.  Size (inherits all traits of specified size)
# 2.  Traversal Type (inherits all tratis of specified size)
# 3.  Kaiju Type 1 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# 4.  Kaiju Type 2 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# Note: Each kaiju has two kaijuTypes. This gives each kaiju a unique identity.
#          (i.e. Atomic Robot, Spirit Brawler, Atomic Spirit, etc.)
# Note: A kaiju does not inherit all moves of an inherited type. It only inherits a few moves per type.          

class kaijuGenerationOrder():
    AUTO :bool = False
    SILLY :bool = False
    
    def __init__(self, isAuto, isSilly):
        self.AUTO = isAuto
        self.SILLY = isSilly

#TODO: # Kaiju creator. random chance that the player is going to get a bonus thing?
#TODO: Suspense between creations vs. quick-generate
def generateKaiju(order: kaijuGenerationOrder):   

    name = ""
    if (order.AUTO):
        if(order.SILLY):
            name = random.choice(sillyNames).upper()
        else:
            name = random.choice(kaijuNames).upper()
    else:
        utils.simulatedTypePrinting("\n" + "~" * 8 + " KAIJU GENERATOR " + "~" * 8 + "\n", 6)  
        time.sleep(0.3)
        utils.simulatedTypePrinting("KAIJU NAME: ", 6)
        name = input().upper()

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
    
    configuration = kaiju.ALL_SIZE_TYPES_NAMES[sizeType] + " " + kaiju.ALL_TRAVERSAL_TYPES_NAMES[traversalType] + " " \
        + kaiju.ALL_KAIJU_MOVES_NAMES[moveTypes[0]] + " " + kaiju.ALL_KAIJU_MOVES_NAMES[moveTypes[1]]
    
    kai =  kaiju.Kaiju(name, sizeType, sizeTraits, traversalType, traversalTraits, moveTypes, moveSets, legs, arms, heads, configuration)
    
    utils.simulatedTypePrinting("Generating", 10)
    for i in range (0, 3):
        time.sleep(0.5)
        print(" .", end = "")
    print()
    
    utils.simulatedTypePrinting("Generated " + kai.NAME + "!" + " The " + kai.CONFIGURATION + " kaiju!\n")

    return kai

# prints generated kaiju data to the console for the user to see. 
#   Selects data from nested lists depending on the desired stat for output.
def printKaijuData(kai):
    time.sleep(0.4)
    utils.simulatedTypePrinting("\n" + " " * 12 + kai.NAME + "'s " "DATA" + "\n", 8)
    utils.simulatedTypePrinting("\nCONFIGURATION: \t\t" + kai.CONFIGURATION + "\n", 8)


    utils.simulatedTypePrinting("\nSIZE:\t\t\t" + kaiju.ALL_SIZE_TYPES_NAMES[kai.SIZE_TYPE] + "\n", 8)
    j = 0
    while j < len(kai.SIZE_TRAITS):
        utils.simulatedTypePrinting(kaiju.ALL_SIZE_TYPES_NAMES[kai.SIZE_TYPE] + " TRAIT " + str(j+1) + ":\t\t" + kai.SIZE_TRAITS[j] + "\n", 2)
        j+=1
    
    utils.simulatedTypePrinting("\nTRAVERSAL TYPE:\t\t" + kaiju.ALL_TRAVERSAL_TYPES_NAMES[kai.TRAVERSAL_TYPE] + "\n", 8)
    j = 0
    while j < len(kai.TRAVERSAL_TRAITS):
        utils.simulatedTypePrinting(kaiju.ALL_TRAVERSAL_TYPES_NAMES[kai.TRAVERSAL_TYPE] + " TRAIT " + str(j+1) + ":\t" + kai.TRAVERSAL_TRAITS[j] + "\n", 2)
        j+=1
        
    i = 0
    for moveType in kai.KAIJU_MOVESETS:
        utils.simulatedTypePrinting("\nMOVE TYPE " + str(i+1) + ":\t\t" + kaiju.ALL_KAIJU_MOVES_NAMES[i] + "\n", 8)
        j = 0
        while j < len(kai.KAIJU_MOVESETS[i]):
            utils.simulatedTypePrinting(kaiju.ALL_KAIJU_MOVES_NAMES[i] + " MOVE " + str(j+1) + ":\t\t" + kai.KAIJU_MOVESETS[i][j] + "\n", 2)
            j+=1
        i+=1
    
    print()
    utils.simulatedTypePrinting("LEGS:\t\t\t" + str(kai.LEGS) + "\n", 4)
    utils.simulatedTypePrinting("ARMS:\t\t\t" + str(kai.ARMS) + "\n", 4)
    utils.simulatedTypePrinting("HEADS:\t\t\t" + str(kai.HEADS) + "\n", 4)
        
    utils.simulatedTypePrinting("\n" + " " * 12 +  "DATA END" + " " * 12 + "\n", 8)    
        
# Alphabetizes list of kaijus
def alphabetizeKaijus(kaijus: []) :
    for i in range(0, len(kaijus)):
        for j in range(0, len(kaijus)):
            if (kaijus[i].NAME < kaijus[j].NAME):
                k = kaijus[i]
                kaijus[i] = kaijus[j]
                kaijus[j] = k 


class MenuOptions(Enum):
    PLAYER_VS_AI_BATTLE = 1
    FULLY_RANDOM_AI_BATTLE = 2
    SELECTED_AI_BATTLE = 3
    GENERATE_NEW_KAIJU = 4
    DELETE_KAIJU = 5
    KAIJU_DATA = 6
    QUIT = 10

##########################
# GLOBAL VARIABLES    
kaijus = []
MAX_KAIJU_SELECTION = 26





def mainMenu():

    # Menu Options and Selection
    menuTextNoKaiju = "\n" + "~" * 23 + " MAIN MENU " + "~" * 23 + \
        "\n Select the option you want by inputting the number that is to the left of it." + \
        "\n\n" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + " - " + MenuOptions.GENERATE_NEW_KAIJU.name.replace("_", " ") + "(i.e. \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\")" + \
        "\n" + str(MenuOptions.QUIT.value) +  " - " + MenuOptions.QUIT.name.replace("_", " ") + \
        "\n\nUH-OH!!! Not enough kaiju for battle. Generate new ones!" + \
        "\n" + "~" * 60
    menuTextNotEnoughKaiju = "\n" + "~"  * 23 + " MAIN MENU " + "~" * 23 + \
        "\n Select the option you want by inputting the number that is right next to it." + \
        "\n\n" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + " - " + MenuOptions.GENERATE_NEW_KAIJU.name.replace("_", " ") + "(i.e. \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\")" + \
        "\n" + str(MenuOptions.DELETE_KAIJU.value) + " - " + MenuOptions.DELETE_KAIJU.name.replace("_", " ") + "(i.e. \"" + str(MenuOptions.DELETE_KAIJU.value) + "A\")" + \
        "\n" + str(MenuOptions.KAIJU_DATA.value) + " - " + MenuOptions.KAIJU_DATA.name.replace("_", " ") + "(i.e. \"" + str(MenuOptions.KAIJU_DATA.value)+ "h\")" + \
        "\n" + str(MenuOptions.QUIT.value) +  " - " + MenuOptions.QUIT.name.replace("_", " ") + \
        "\n\nUH-OH!!! Not enough kaiju for battle. Generate new ones!" + \
        "\n" + "~" * 60
    menuText = "\n" + "~"  * 23 + " MAIN MENU " + "~" * 23 + \
        "\n Select the option you want by inputting the number that is right next to it." + \
        "\n\n" + str(MenuOptions.PLAYER_VS_AI_BATTLE.value) + " - " + MenuOptions.PLAYER_VS_AI_BATTLE.name.replace("_", " ") + "  (First letter is player's kaiju - i.e. \"1ab\")" + \
        "\n" + str(MenuOptions.FULLY_RANDOM_AI_BATTLE.value) + " - " + MenuOptions.FULLY_RANDOM_AI_BATTLE.name.replace("_", " ") + "  (i.e. \"" + str(MenuOptions.FULLY_RANDOM_AI_BATTLE.value) + "\")" + \
        "\n" + str(MenuOptions.SELECTED_AI_BATTLE.value) + " - " + MenuOptions.SELECTED_AI_BATTLE.name.replace("_", " ") +  "  (i.e. \"" + str(MenuOptions.SELECTED_AI_BATTLE.value) + "ad\")" + \
        "\n" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + " - " + MenuOptions.GENERATE_NEW_KAIJU.name.replace("_", " ") + "  (i.e. \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\")" + \
        "\n" + str(MenuOptions.DELETE_KAIJU.value) + " - " + MenuOptions.DELETE_KAIJU.name.replace("_", " ") + "  (i.e. \"" + str(MenuOptions.DELETE_KAIJU.value) + "a\")" + \
        "\n" + str(MenuOptions.KAIJU_DATA.value) + " - " + MenuOptions.KAIJU_DATA.name.replace("_", " ") + "  (i.e. \"" + str(MenuOptions.KAIJU_DATA.value) + "f\")" + \
        "\n" + str(MenuOptions.QUIT.value) +  " - " + MenuOptions.QUIT.name.replace("_", " ") + \
        "\n" + "~" * 60
    
    alphabetizeKaijus(kaijus)

    shouldQuit = False
    userInput = ""    
    invalidInfo = ""
    requestDeniedInfo = ""
    while(shouldQuit == False):              

        ################################
        # Setup Menu - kaiju list
        # TODO
            # need to get kaiju with longest name in given column so columns are evenly spaced when printing rows. 
                # spacing after every kaiju should match total spaces needed for longest-named kaiju in that column.        
            # color code them  
        # print in rows and columns with corresponding letter   
        utils.simulatedTypePrinting("\n\n" + "~" * 23 + " KAIJU SELECTION " + "~" * 23 + "", 10)
        print()
    
        letterOrd = ord('A')   

        COLUMNS = 2
        rows = int(len(kaijus)/ COLUMNS)
        
        isOdd:bool = False
        if (len(kaijus) % 2 == 1):
            isOdd = True
            rows +=1
        
        i = -1
        while (i + rows) < len(kaijus):
            i += 1 
            if (i + rows < len(kaijus)):
                utils.simulatedTypePrinting(chr(letterOrd + i) + " - " + kaijus[i].NAME, 1)    
                print(" " * 6, end = "")
                utils.simulatedTypePrinting(chr(letterOrd + i + rows) + " - " + kaijus[i+rows].NAME, 1)
                print()
            else: 
                if(isOdd):
                    utils.simulatedTypePrinting(chr(letterOrd + i) + " - " + kaijus[i].NAME, 1)        
                    print()
                
                break
            
        
        ################################
        # Setup Menu - menu text    
        if (len(kaijus) == 0):
            utils.simulatedTypePrinting(menuTextNoKaiju)
        elif (len(kaijus) < 3):
            utils.simulatedTypePrinting (menuTextNotEnoughKaiju)
        else:
            utils.simulatedTypePrinting(menuText, 1)
            
        print()
            
        if (invalidInfo != ""):
            time.sleep(0.3)
            utils.simulatedTypePrinting("Input was invalid: " + invalidInfo, 8)
            print()
            invalidInfo = ""
        elif (requestDeniedInfo != ""):
            time.sleep(0.3)
            utils.simulatedTypePrinting(requestDeniedInfo, 8)
        
        ############################################
        # User Input - input and initial validation
        utils.simulatedTypePrinting("Input a menu option: ")    
        userInput = input().upper()
        userInput.strip()
        userInput.replace(" ", "")
        
        if (len(userInput) == 0):
            invalidInfo = "Input zero characters."
            continue

        if (userInput[0].isdigit() == False):
            invalidInfo = "The first character must be a number."
            continue    
        

        ###############################
        # Determining user choice
        optionValue = -1
        digitsFromInput = ""
        for i in range(0, len(userInput)):
            if (userInput[i].isdigit() == False):
                break
            
            digitsFromInput += userInput[i]

            
        optionValue = int(digitsFromInput)
        
        optionChosen: MenuOptions
        match (optionValue):
            case MenuOptions.PLAYER_VS_AI_BATTLE.value:
                optionChosen = MenuOptions.PLAYER_VS_AI_BATTLE
            case MenuOptions.FULLY_RANDOM_AI_BATTLE.value:
                optionChosen = MenuOptions.FULLY_RANDOM_AI_BATTLE
            case MenuOptions.SELECTED_AI_BATTLE.value:
                optionChosen = MenuOptions.SELECTED_AI_BATTLE
            case MenuOptions.GENERATE_NEW_KAIJU.value:
                optionChosen = MenuOptions.GENERATE_NEW_KAIJU
            case MenuOptions.DELETE_KAIJU.value:
                optionChosen = MenuOptions.DELETE_KAIJU
            case MenuOptions.KAIJU_DATA.value:
                optionChosen = MenuOptions.KAIJU_DATA
            case MenuOptions.QUIT.value: 
                optionChosen = MenuOptions.QUIT
            # TODO - case for testmode (i.e. test a bunch of battles and output to a log)
            case _:
                invalidInfo = "That is not a valid input."
                continue
            
        ##############################################################
        # If-else chain for different menu options. 
        if (optionChosen == MenuOptions.PLAYER_VS_AI_BATTLE or optionChosen == MenuOptions.SELECTED_AI_BATTLE):
            #################################
            # Input Validation
            if (len(kaijus) < 2):
                requestDeniedInfo = "Not enough kaiju for " + optionChosen.name + " . Input \"" + \
                    str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\" to generate more."
                continue
            
            if (len(userInput) != 3):
                invalidInfo = optionChosen.name + " require two kaiju inputs. Example: \"" + str(optionChosen.value) + "ab\"" 
                continue
            
            if (userInput[1].isalpha() == False or userInput[2].isalpha() == False):
                invalidInfo = "Kaiju inputs must be letters."
                continue
            
            lastLetterUsedOrd = ord('A') + (len(kaijus) - 1 )
            for i in range(len(userInput) - len(str(optionChosen.value)) - 1, len(userInput)):
                if (ord(userInput[i]) < ord('A') or ord(userInput[i]) > lastLetterUsedOrd):
                    invalidInfo = "The letter \"" + userInput[i] + "\" does not have an associated kaiju."
            if invalidInfo != "":
                continue
            
            #################################
            # Battle Prep + Logic
            utils.simulatedTypePrinting("\n" * 10 + "\t\tYou have chosen battle.")
            for i in range(0,4):                
                time.sleep(1)
                print("\n\t\t\t" + str(3 - i))
                
            time.sleep(1)

            k1 = kaijus[ord(userInput[1]) - ord('A')]
            k2 = kaijus[ord(userInput[2]) - ord('A')]
            battle.doBattle(k1, k2, optionChosen == MenuOptions.SELECTED_AI_BATTLE)
            
        elif(optionChosen == MenuOptions.FULLY_RANDOM_AI_BATTLE ):
            if (len(kaijus) < 2):
                requestDeniedInfo = "Not enough kaiju for " + optionChosen.name + " . Input \"" + \
                    str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\" to generate more."
                continue
            
            k1 = random.choice(kaijus)
            while True:
                k2 = random.choice(kaijus)
                if (k2.NAME != k1.NAME):
                    break 

            battle.doBattle(k1, k2, True)        
            
        elif (optionChosen == MenuOptions.DELETE_KAIJU or optionChosen == MenuOptions.KAIJU_DATA):
            #####################################
            # Input validation    
            optionVerbStr = "" 
            if (optionChosen == MenuOptions.DELETE_KAIJU):
                optionVerbStr = "delete"
            else:
                optionVerbStr = "get kaiju data on"

            if (len(userInput) != 2):
                    invalidInfo = optionChosen.name.replace('_', ' ') + " requires an input for the kaiju you want to " + optionVerbStr + "." + \
                                    "\n\t Example: \"" + str(optionChosen.value) + "c\""
                    continue

            if (userInput[1].isalpha() == False):
                invalidInfo = "Input a letter for the kaiju you wish to " + optionVerbStr + "."
                    
            lastLetterUsedOrd = ord('A') + (len(kaijus) - 1)
            if (ord(userInput[1]) < ord('A') or ord(userInput[1]) > lastLetterUsedOrd):
                invalidInfo = "\""+ userInput[1] + "\" does not have an associated kaiju."
                continue

            #####################################
            # Business Logic           
            chosenKai = ord(userInput[1]) - ord('A')

            if (optionChosen == MenuOptions.DELETE_KAIJU):
                utils.simulatedTypePrinting("\nYou have chosen to delete " + kaijus[chosenKai].NAME + ".\n" +
                                       "Are you sure? Input \"y\" to delete: ", 5)
                choice = input()
                
                if (choice.upper() == "Y"):
                    name = kaijus[chosenKai].NAME
                    kaijus.pop(chosenKai)
                    
                    utils.simulatedTypePrinting(name)
                    time.sleep(0.8)
                    utils.simulatedTypePrinting(" is no more ")
                    for i in range (0, 3):
                        time.sleep(0.8)
                        print(". ", end = "")
                    time.sleep(0.5)
                else:
                    utils.simulatedTypePrinting("\nYou have chosen to spare " + kaijus[chosenKai] + ".")
                    for i in range (0, 3):
                        time.sleep(0.4)
                        print(". ", end = "")
                    print(" For now ")
                    for i in range (0, 3):
                        time.sleep(0.8)
                        print(". ", end = "")
                    time.sleep(0.5)
            else:
                
                utils.simulatedTypePrinting("\nProcessing data on " + kaijus[chosenKai].NAME + " ")
                for i in range (0, 3):
                    time.sleep(0.4)
                    print(". ", end = "")
                utils.simulatedTypePrinting("Data is processed.")
                time.sleep(0.8)
                print("\n")
                printKaijuData(kaijus[chosenKai])
   
        elif(optionChosen == MenuOptions.GENERATE_NEW_KAIJU):
            ###########################
            # Input Validation
            if (len(userInput) != 1):
                invalidInfo = "GENERATE NEW KAIJU requires one input." + \
                                "\n\t Example: \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value + "\"") 
                continue
                    
            if (len(kaijus) == MAX_KAIJU_SELECTION):
                requestDeniedInfo = "Already at max number of kaiju ("+ MAX_KAIJU_SELECTION + "). Delete kaiju in order to generate more."
                continue

            #########################
            # Business Logic
            kaijus.append(generateKaiju(kaijuGenerationOrder(False, False)))
            alphabetizeKaijus(kaijus)
            utils.simulatedTypePrinting("~" * 14 + "NEW KAIJU" + "~" * 14)
            printKaijuData(kaijus[len(kaijus) - 1])
            
        elif (optionChosen == MenuOptions.QUIT):
            utils.simulatedTypePrinting("\nAre you sure you want to quit? Input \"y\" to confirm: ")
            choice = input()          
            if (choice.upper() == "Y"):
                shouldQuit = True

        if (optionChosen != MenuOptions.QUIT):
            time.sleep(0.3)
            utils.simulatedTypePrinting("\n\nInput anything to continue back to main menu . . .", 3)
            input()
        
            
    return



def main():
    # TO-DO - Run in auto-test mode - auto-battles a given number of kaiju. Battle outcome and stats are
        # saved to a file.
        # Battle stats
            # Which moves did most damage
            # Did certain moves do more damage when preceded by 
        # Different test types
            # Test x configurations vs y configurations
    
    ##############################################################
    # Load kaiju from CSV 
    with open("kaijus.txt", newline = "") as kaijuCSV:
        lines = csv.reader(kaijuCSV)
        
        i = 0
        
        name = ""
        sizeType = -1
        sizeTraits = []
        traversalType = -1
        traversalTraits = []
        kaijuTypes = []
        kaijuMovesets = []
        legs = -1
        arms = -1
        heads = -1
        configuration = ""

        for line in lines:
            match i:
                case 0:
                    name = line[0]
                case 1:
                    sizeType = int(line[0])
                case 2:
                    sizeTraits = line
                case 3:
                    traversalType = int(line[0])
                case 4:
                    traversalTraits = line
                case 5:
                    kaijuTypes.append(int(line[0]))
                case 6:
                    kaijuMovesets.append(line)
                case 7:
                    kaijuTypes.append(int(line[0]))
                case 8:
                    kaijuMovesets.append(line)
                case 9:
                    legs = int(line[0])
                case 10:
                    arms = int(line[0])
                case 11:
                    heads = int(line[0])
                case 12:
                    configuration = line[0]
            
            i+=1
            if (i == 13):
                i = 0
                kaijus.append(kaiju.Kaiju(name, sizeType, sizeTraits.copy(), traversalType, traversalTraits.copy(), 
                                          kaijuTypes.copy(), kaijuMovesets.copy(), legs, arms, heads, configuration))   
                
                sizeTraits.clear()
                traversalTraits.clear()
                kaijuTypes.clear()
                kaijuMovesets.clear()
                       

    ############################################
    # Generates n kaiju. Makes for easy testing.    
    for i in range(1,1):
        if (i > MAX_KAIJU_SELECTION):
            break
        
        newK :kaiju.Kaiju
        while True:
            newK = generateKaiju(kaijuGenerationOrder(True, False))
            
            alreadyHave = False
            for k in kaijus:
                if(k.NAME == newK.NAME):
                    alreadyHave = True
                    break
            
            if (alreadyHave == False):
                break            
            
        kaijus.append(newK)
            
    mainMenu()
        

    with open("kaijus.txt", "w", newline = "") as kaijusCSV:
        writer = csv.writer(kaijusCSV)
        for kai in kaijus:

            writer.writerow([kai.NAME])
            
            writer.writerow(str(kai.SIZE_TYPE))
            writer.writerow(kai.SIZE_TRAITS)
            
            writer.writerow(str(kai.TRAVERSAL_TYPE))
            writer.writerow(kai.TRAVERSAL_TRAITS)
                    
            for i in range(0, len(kai.KAIJU_TYPES)):
                writer.writerow(str(kai.KAIJU_TYPES[i]))
                writer.writerow(kai.KAIJU_MOVESETS[i])

            writer.writerow(str(kai.LEGS))
            writer.writerow(str(kai.ARMS))
            writer.writerow(str(kai.HEADS))
            writer.writerow([kai.CONFIGURATION])
            # Check for different types: https://stackoverflow.com/questions/152580/whats-the-canonical-way-to-check-for-type-in-python
            

    utils.simulatedTypePrinting("\n\nRAWR ", end = "")
    for i in range(0, 4):
        time.sleep(1)
        print(". ", end = "")
    
    
    

if __name__ == "__main__":
    main()
    
  




        
