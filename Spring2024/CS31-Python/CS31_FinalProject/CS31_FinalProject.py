

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

# Create a menu system that has the following functions:

# Pre-battle
#    - Create a new Character. Randomly assign values for the character. (10 points)
#    - List all Characters - display a nicely formatted list of characters and 
#      their stats. (10 points)
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

#====================================================================================================================================

# Peter Doria
# 5/29/2024
# Final Project: Random Character Generator - Kaiju Generator (https://en.wikipedia.org/wiki/Kaiju)
# CS31 - 33880

# for choosing options from list randomly
import random
# csv saving and loading kaiju characters
import csv
# easier to reason menu options with enum. 
from enum import Enum
# mainly for sleep function
import time
# currently for 'real-time' printing
import utils
# data on kaiju
import kaiju
# battle functionality
import battle


kaijuNames =  ["godzilla", "gojira", "gigan", "anguirus", "mechagodzilla", "kiryu", "king ceasar", \
                     "jet jaguar", "monster x", "king ghidorah", "king kong", "manda", "hedorah", \
                     "megaguirus", "biolante", "space godzilla", "monster omega", "ebirah", \
                     "kamacurus", "kumonga", "rodan", "mothra", "minila", "gypsy danger", "megazord", "Gabara", \
                     "Baragon", "Fire Rodan", ]

sillyNames = ["jay jay the jet plane", "miss piggy", "kermit", "dostoevsky", "timzilla", "christoughman", \
                    "tony stark", "danny de vito", "Terry Crews", "Andy Samberg", \
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


##############################################################################
# Passed to generation function.
# Like ordering a coffee, you might want it made a certain way. Give an instance
#   of this order class to the generateKaiju function to tell it how you want your
#   kaiju made. 
# Doesn't affect the final outcome of a kaiju beyond name. Other params affect
#   how fast or quietly a kaiju is generated. 
class kaijuGenerationOrder():
    AUTO :bool = False
    SILLY :bool = False
    FAST_GEN :bool = False
    SILENT_GEN :bool = False
    
    def __init__(self, isAuto = False, isSilly = False, fastGen = False, silentGen = False):
        self.AUTO = isAuto
        self.SILLY = isSilly
        self.FAST_GEN = fastGen
        self.SILENT_GEN = silentGen

###########################################################
# Kaiju generation function. All kaiju start here.       
#
# Every kaiju has 4 randomly selected primary traits which can randomly select 
#   additional identifiers depending on the given trait (i.e. size vs Kaiju Type):
# 1.  Size (inherits all traits of specified size)
# 2.  Traversal Type (inherits all traits of specified traversal type)
# 3.  Kaiju Type 1 (gives kaiju an identity beyond size or traversal. Defines moves for combat or otherwise)
# 4.  Kaiju Type 2 (gives kaiju an identity beyond size or traversal. Defines moves for combat or otherwise)
# Note: Each kaiju has two kaijuTypes. This gives each kaiju a unique identity.
#          (i.e. Atomic Robot, Spirit Brawler, Atomic Spirit, etc.)
# Note: A kaiju does not inherit all moves of an inherited type. It only inherits a few moves per type.          
def generateKaiju(order: kaijuGenerationOrder):   

    name = ""
    if (order.AUTO):
        if(order.SILLY):
            name = random.choice(sillyNames).upper()
        else:
            name = random.choice(kaijuNames).upper()
    else:
        utils.simulatedTypePrinting("\n" + "~" * 8 + " KAIJU GENERATOR " + "~" * 8 + "\n", 6)  
        if (order.FAST_GEN == False):
            time.sleep(0.3)
            
        while name == "":
            utils.simulatedTypePrinting("KAIJU NAME: ", 6)
            name = input().upper()
            for i in range(0, len(kaijus)):
                if (name == kaijus[i].NAME):
                    utils.simulatedTypePrinting("\nA kaiju with that name already exists. Try a new name.\n")
                    name = ""
                    break
            
    # Randomly select size traits for kaiju
    sizeType = random.randint(0, len(kaiju.ALL_SIZE_TYPES) - 1)
    sizeTraits = kaiju.ALL_SIZE_TYPES[sizeType]
 
    # Randomly select traversal traits for kaiju
    traversalType = random.randint(0, len(kaiju.ALL_TRAVERSAL_TYPES) - 1)
    traversalTraits = kaiju.ALL_TRAVERSAL_TYPES[traversalType]

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
    
    if (order.SILENT_GEN == False):        
        if (order.FAST_GEN == False):
            utils.simulatedTypePrinting("Generating", 10)
            for i in range (0, 3):
                time.sleep(0.5)
                print(" .", end = "")
            print()
        else:
            utils.simulatedTypePrinting("Fast Generation . . . \n")

        utils.simulatedTypePrinting("Generated " + kai.NAME + "!" + " The " + kai.CONFIGURATION + " kaiju!\n")

    return kai

#######################################################################################
# prints kaiju data to the console for the user to see. 
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
        
    for i in range(0, len(kai.KAIJU_TYPES)):
        utils.simulatedTypePrinting("\nMOVE TYPE " + str(i+1) + ":\t\t" + kaiju.ALL_KAIJU_MOVES_NAMES[kai.KAIJU_TYPES[i]] + "\n", 8)
        j = 0
        while j < len(kai.KAIJU_MOVESETS[i]):
            utils.simulatedTypePrinting(kaiju.ALL_KAIJU_MOVES_NAMES[i] + " MOVE " + str(j+1) + ":\t\t" + kai.KAIJU_MOVESETS[i][j] + "\n", 2)
            j+=1
        i+=1
    
    print()
    utils.simulatedTypePrinting("LEGS:\t\t\t" + str(kai.LEGS) + "\n", 4)
    utils.simulatedTypePrinting("ARMS:\t\t\t" + str(kai.ARMS) + "\n", 4)
    utils.simulatedTypePrinting("HEADS:\t\t\t" + str(kai.HEADS) + "\n", 4)
    
    print()
    utils.simulatedTypePrinting("WINS: \t\t\t" + str(kai.WINS) + "\n", 8)
    utils.simulatedTypePrinting("LOSSES: \t\t" + str(kai.LOSSES) + "\n", 8)
        
    utils.simulatedTypePrinting("\n" + " " * 12 +  "DATA END" + " " * 12 + "\n", 8)    

##################################        
# Alphabetizes list of kaijus
def alphabetizeKaijus(kaijus: []) :
    for i in range(0, len(kaijus)):
        for j in range(0, len(kaijus)):
            if (kaijus[i].NAME < kaijus[j].NAME):
                k = kaijus[i]
                kaijus[i] = kaijus[j]
                kaijus[j] = k 

###############################
# MenuOptions class
# Inherits from enum. Makes it easier to consolidate
#   menu logic into something readable and consistent.
# Each enum value matches the input for a menu option.                
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


def mainMenu(firstTime:bool):

    ################################################################
    # Different menu text depending on kaiju state   
    menuTextNoKaiju = "\n" + " " * 23 + " MAIN MENU (NO KAIJU)" + \
        "\n\n" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + " - " + MenuOptions.GENERATE_NEW_KAIJU.name.replace("_", " ") + "  - Input: \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\"" + \
        "\n" + str(MenuOptions.QUIT.value) +  " - " + MenuOptions.QUIT.name.replace("_", " ") + \
        "\n\nUH-OH!!! Not enough kaiju for battle. Generate new ones!"
    menuTextNotEnoughKaiju = "\n" + " "  * 14 + " MAIN MENU (NOT ENOUGH KAIJU FOR BATTLE)" + \
        "\n\n" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + " - " + MenuOptions.GENERATE_NEW_KAIJU.name.replace("_", " ") + "  - Input: \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\"" + \
        "\n" + str(MenuOptions.DELETE_KAIJU.value) + " - " + MenuOptions.DELETE_KAIJU.name.replace("_", " ") + "Example Input: \"" + str(MenuOptions.DELETE_KAIJU.value) + "a\"" + \
        "\n" + str(MenuOptions.KAIJU_DATA.value) + " - " + MenuOptions.KAIJU_DATA.name.replace("_", " ") + "    - Example Input:  \"" + str(MenuOptions.KAIJU_DATA.value) + "h\"" + \
        "\n" + str(MenuOptions.QUIT.value) +  " - " + MenuOptions.QUIT.name.replace("_", " ") + \
        "\n\nUH-OH!!! Not enough kaiju for battle. Generate new ones!"
    menuText = "\n" + " "  * 23 + " MAIN MENU " + \
        "\n\n" + str(MenuOptions.PLAYER_VS_AI_BATTLE.value) + " - " + MenuOptions.PLAYER_VS_AI_BATTLE.name.replace("_", " ") + ", Example Input: \"" + str(MenuOptions.PLAYER_VS_AI_BATTLE.value) + "ab\" (First letter is player's kaiju)" + \
        "\n" + str(MenuOptions.FULLY_RANDOM_AI_BATTLE.value) + " - " + MenuOptions.FULLY_RANDOM_AI_BATTLE.name.replace("_", " ") + ", Input: \"" + str(MenuOptions.FULLY_RANDOM_AI_BATTLE.value) + "\"" + \
        "\n" + str(MenuOptions.SELECTED_AI_BATTLE.value) + " - " + MenuOptions.SELECTED_AI_BATTLE.name.replace("_", " ") +  ", Example Input: \"" + str(MenuOptions.SELECTED_AI_BATTLE.value) + "ad\"" + \
        "\n" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + " - " + MenuOptions.GENERATE_NEW_KAIJU.name.replace("_", " ") + ", Input: \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\"" + \
        "\n" + str(MenuOptions.DELETE_KAIJU.value) + " - " + MenuOptions.DELETE_KAIJU.name.replace("_", " ") + ", Example Input: \"" + str(MenuOptions.DELETE_KAIJU.value) + "a\"" + \
        "\n" + str(MenuOptions.KAIJU_DATA.value) + " - " + MenuOptions.KAIJU_DATA.name.replace("_", " ") + ", Example Input:  \"" + str(MenuOptions.KAIJU_DATA.value) + "f\"" + \
        "\n" + str(MenuOptions.QUIT.value) +  " - " + MenuOptions.QUIT.name.replace("_", " ")

    alphabetizeKaijus(kaijus)

    ###############################################################
    # Tutorial Settings
    doMenuTutorial: bool = False
    doKaijuListTutorial: bool = False
    if (firstTime):
        doMenuTutorial = True
        doKaijuListTutorial = True
     
    ###############################################################
    # Main menu loop
    shouldQuit = False
    userInput = ""    
    invalidInfo = ""
    requestDeniedInfo = ""
    while(shouldQuit == False):              
        
        ###########################################################
        # Setup Menu - menu text    
        utils.simulatedTypePrinting('\n' + "~" * 60, 10)
        utils.simulatedTypePrinting('\n' + "~" * 60 + '\n', 10)

        if (len(kaijus) == 0):
            utils.simulatedTypePrinting(menuTextNoKaiju, 2)
        elif (len(kaijus) < 2):
            utils.simulatedTypePrinting (menuTextNotEnoughKaiju, 2)
        else:
            utils.simulatedTypePrinting(menuText, 3)
            
        print()

        if (doMenuTutorial == True):
            utils.simulatedTypePrinting("\n" + "*" * 60 + "\n")
            time.sleep(3)
            utils.simulatedTypePrinting("Look at the list of menu options.",50)
            time.sleep(3)
            utils.simulatedTypePrinting(" Each option has a number to the left of it.\n", 50)
            time.sleep(3)
            utils.simulatedTypePrinting("\tAlways start your main menu inputs with one of those numbers.", 80)
            time.sleep(3)
            print()
            utils.simulatedTypePrinting("*" * 60)
            utils.simulatedTypePrinting("\nInput anything to continue . . .", 10)
            input()
            
            doMenuTutorial = False
        
        ###########################################################
        # Setup Menu - kaiju selection list
        # print in rows and columns with corresponding letter   
        if (len(kaijus) > 0):
        
            rows = int(len(kaijus)/ 2)
        
            isOdd:int = 0
            if (len(kaijus) % 2 == 1):
                isOdd = 1
                rows +=1
        
            longestCol1:int = 0
            for i in range(0, int((len(kaijus) / 2) + (1 * isOdd))):
                if (len(kaijus[i].NAME) > longestCol1):
                    longestCol1 = len(kaijus[i].NAME)
        
            longestCol2:int = 0
            for i in range((int(len(kaijus)/2) - 1 + (1 * isOdd)), len(kaijus)):
                if (len(kaijus[i].NAME) > longestCol2):
                    longestCol2 = len(kaijus[i].NAME)
                
            totalWidth = longestCol2 + longestCol1
            utils.simulatedTypePrinting("\n" + " " * int((longestCol1 / 2) + (longestCol2 / 4))  + " KAIJU SELECTION " , 10)
            time.sleep(0.1)
            print()
    
            letterOrd = ord('A')   
            i = -1
            while (i + rows) < len(kaijus):
                i += 1 
                if (i + rows < len(kaijus)):
                    utils.simulatedTypePrinting(chr(letterOrd + i) + " - " + kaijus[i].NAME, 1)    
                    print((8 + longestCol1 - len(kaijus[i].NAME)) * " ", end = "")
                    utils.simulatedTypePrinting(chr(letterOrd + i + rows) + " - " + kaijus[i+rows].NAME, 1)
                    print()
                else: 
                    if(isOdd == 1):
                        utils.simulatedTypePrinting(chr(letterOrd + i) + " - " + kaijus[i].NAME, 1)        
                        print()
                
                    break
        
        if (doKaijuListTutorial == True and len(kaijus) > 0):
            utils.simulatedTypePrinting("\n" + "*" * 60, 30)
            print()
            time.sleep(5)
            utils.simulatedTypePrinting("Look at the list of kaiju.", 50) 
            time.sleep(3)
            utils.simulatedTypePrinting(" Each kaiju has a letter next to it.", 50)
            time.sleep(3)
            utils.simulatedTypePrinting("\nUse those letters to pick kaiju for battle, to delete, or any other appropriate menu option.", 50)
            time.sleep(2)
            
            utils.simulatedTypePrinting("\n\tExample: ", 50)
            time.sleep(1)
            if (len(kaijus) > 1):
                utils.simulatedTypePrinting("Inputting \"" + str(MenuOptions.SELECTED_AI_BATTLE.value) + "ab\" selects " + kaijus[0].NAME + " and " + kaijus[1].NAME + " for a " + MenuOptions.SELECTED_AI_BATTLE.name.replace('_', ' ') + "."
                                        , 100)
            elif (len(kaijus) == 1):
                utils.simulatedTypePrinting("Inputting \"" + str(MenuOptions.KAIJU_DATA.value) + "a\" selects" + kaijus[0].NAME + " for " + MenuOptions.SELECTED_AI_BATTLE.name.replace('_', ' ')) + "."
            
            time.sleep(4)
            utils.simulatedTypePrinting('\n' + "*" * 60, 40)
            
            doKaijuListTutorial = False
            
        if (firstTime and (doMenuTutorial == False and doKaijuListTutorial == False)):
            utils.simulatedTypePrinting('\n' + "*" * 60, 40)
            time.sleep(1)
            utils.simulatedTypePrinting("\n\nLet's Review", 50)
            utils.simulatedTypePrinting("\n\nFirst, find the menu option you want,", 60)
            time.sleep(0.5)
            utils.simulatedTypePrinting("\n\tthen enter the number next to that option.", 80)
            time.sleep(2)
            utils.simulatedTypePrinting("\n\nIf that option requires selecting kaiju,", 60)
            time.sleep(2)
            utils.simulatedTypePrinting("\n\tfind the letter next to each kaiju you want to select.", 60)
            time.sleep(1)
            utils.simulatedTypePrinting("\n\nFinally, add the letter(s) to your input.", 60)
            time.sleep(3)
            utils.simulatedTypePrinting("\n\nAfter that, press \"ENTER\".", 60)
            time.sleep(1)
            utils.simulatedTypePrinting('\n' + "*" * 60, 30)
            time.sleep(1)
            utils.simulatedTypePrinting("\nInput anything to continue . . . ", 10)
            input()
            
            firstTime = False
            

            
        
        utils.simulatedTypePrinting("\n" + "~" * 60, 30)
        print()
        ################################################################################
        # Invalid input info output to console    
        if (invalidInfo != ""):
            time.sleep(0.4)
            utils.simulatedTypePrinting("Input was invalid: " , 8)
            time.sleep(0.3)
            utils.simulatedTypePrinting(invalidInfo, 8)
            print()
            invalidInfo = ""
        elif (requestDeniedInfo != ""):
            time.sleep(0.3)
            utils.simulatedTypePrinting(requestDeniedInfo, 8)
        
        #################################################################################
        # User Input - input and initial validation
        utils.simulatedTypePrinting('\n' + "~" * 60 + '\n')
        utils.simulatedTypePrinting("\nInput a menu option: ")    
        
        userInput = input().upper()
        userInput.strip()
        userInput.replace(" ", "")
        
        if (len(userInput) == 0):
            invalidInfo = "Input zero characters."
            continue

        if (userInput[0].isdigit() == False):
            invalidInfo = "The first character must be a number."
            continue    
        

        ################################################################################
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
                invalidInfo = "That number does not match any menu options. Pick a new number."
                continue
            
        ################################################################################
        # If-else chain for different menu options. 
        if (optionChosen == MenuOptions.PLAYER_VS_AI_BATTLE or optionChosen == MenuOptions.SELECTED_AI_BATTLE):
            ################################################################################
            # Input Validation
            if (len(kaijus) < 2):
                requestDeniedInfo = "Not enough kaiju for " + optionChosen.name.replace('_',' ') + " . Input \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value) + "\" to generate more.\n" + \
                    "\tExample: " + str(MenuOptions.GENERATE_NEW_KAIJU.value)
                continue
            
            if (len(userInput) != 3):
                invalidInfo = optionChosen.name.replace('_',' ') + " requires two kaiju inputs. Look at the list of kaiju. Each kaiju has a letter next to it. Use those letters to pick kaiju for battle." + \
                                "\tExample: Inputting \"" + str(optionChosen.value) + "ab\" selects " + kaijus[0].NAME + " and " + kaijus[1].NAME + " for a " + optionChosen.name.replace('_', ' ') + "."
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
            
            ################################################################################
            # Battle Prep + Logic
            utils.simulatedTypePrinting("\n" * 10 + "\t\tYou have chosen battle.")
            for i in range(0,4):                
                time.sleep(1)
                print("\n\t\t\t" + str(3 - i))
                
            time.sleep(1)

            k1 = kaijus[ord(userInput[1]) - ord('A')]
            k2 = kaijus[ord(userInput[2]) - ord('A')]
            victor = battle.doBattle(k1, k2, optionChosen == MenuOptions.SELECTED_AI_BATTLE)
            if (victor == 0):
                k1.WINS += 1
                k2.LOSSES +=1
            else:
                k1.LOSSES += 1
                k2.WINS +=1
            
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

            utils.simulatedTypePrinting("\n" * 10 + "\t\tYou have chosen battle.")
            for i in range(0,4):                
                time.sleep(1)
                print("\n\t\t\t" + str(3 - i))
                
            victor = battle.doBattle(k1, k2, True)
            if (victor == 0):
                k1.WINS += 1
                k2.LOSSES +=1
            else:
                k1.LOSSES += 1
                k2.WINS +=1
                
        elif (optionChosen == MenuOptions.DELETE_KAIJU or optionChosen == MenuOptions.KAIJU_DATA):
            ################################################################################
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

            ################################################################################
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
                    utils.simulatedTypePrinting("\nYou have chosen to spare " + kaijus[chosenKai].NAME + ".")
                    for i in range (0, 3):
                        time.sleep(0.4)
                        print(". ", end = "")
                    print(" For now ", end = "")
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
            ################################################################################
            # Input Validation
            if (len(userInput) != 1):
                invalidInfo = "GENERATE NEW KAIJU requires one input." + \
                                "\n\t Example: \"" + str(MenuOptions.GENERATE_NEW_KAIJU.value + "\"") 
                continue
                    
            if (len(kaijus) == MAX_KAIJU_SELECTION):
                requestDeniedInfo = "Already at max number of kaiju ("+ MAX_KAIJU_SELECTION + "). Delete kaiju in order to generate more."
                continue

            ################################################################################
            # Business Logic
            kaijus.append(generateKaiju(kaijuGenerationOrder(False, False)))
            
            utils.simulatedTypePrinting("~" * 14 + "NEW KAIJU" + "~" * 14)
            printKaijuData(kaijus[len(kaijus) - 1])
            
            alphabetizeKaijus(kaijus)
            
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
   
    ################################################################################
    # Load kaiju from CSV 
    with open("kaiju.csv", newline = "") as kaijuCSV:
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
        wins = -1
        losses = -1

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
                case 13:
                    wins = int(line[0])
                case 14:
                    losses = int(line[0])                    
            
            i+=1
            if (i == 15):
                i = 0
                kaijus.append(kaiju.Kaiju(name, sizeType, sizeTraits.copy(), traversalType, traversalTraits.copy(), 
                                          kaijuTypes.copy(), kaijuMovesets.copy(), legs, arms, heads, configuration,
                                          wins, losses))   
                
                sizeTraits.clear()
                traversalTraits.clear()
                kaijuTypes.clear()
                kaijuMovesets.clear()
                       

    ################################################################################
    # Generates n kaiju. Makes for easy testing.    
    # for i in range(1,20):
    #     if (i > MAX_KAIJU_SELECTION):
    #         break
        
    #     newK :kaiju.Kaiju
    #     while True:
    #         if (i % 2 == 1):
    #             newK = generateKaiju(kaijuGenerationOrder(True, False, True, True))
    #         else:
    #             newK = generateKaiju(kaijuGenerationOrder(True, True, True, True))
            
    #         alreadyHave = False
    #         for k in kaijus:
    #             if(k.NAME == newK.NAME):
    #                 alreadyHave = True
    #                 break
            
    #         if (alreadyHave == False):
    #             break            
            
    #     kaijus.append(newK)
    
    ################################################################################  
    # Title
    utils.simulatedTypePrinting("~" * 60 + "\n\n", 10 )       
    print(" " * 23, end = "")
    utils.simulatedTypePrinting("KAIJU BATTLE\n\n", 60)
    utils.simulatedTypePrinting("~" * 60 + "\n", 10 )       

    ################################################################################  
    # Tutorial Prompt
    time.sleep(0.5)
    utils.simulatedTypePrinting("\nHave you played Kaiju Battle before?\n\n", 20)
    time.sleep(1)
    utils.simulatedTypePrinting("Input 'y' for yes.", 25) 
    time.sleep(0.5)
    utils.simulatedTypePrinting(" Input anything else for no: ", 30)  
    uInput = input()
    firstTime = True
    if (uInput.upper() == "Y"):
        firstTime = False
    
    ################################################################################
    mainMenu(firstTime)
        
    ################################################################################
    # Saving all kaiju to csv
    with open("kaiju.csv", "w", newline = "") as kaijusCSV:
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
            writer.writerow(str(kai.WINS))
            writer.writerow(str(kai.LOSSES))


    ################################################################################
    # Goodbye        
    utils.simulatedTypePrinting("\n\nRAWR ")
    for i in range(0, 4):
        time.sleep(1)
        print(". ", end = "")
    
    
    

if __name__ == "__main__":
    main()
    
  




        
