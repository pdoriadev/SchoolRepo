

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
from re import A
import kaiju
import battle
from enum import Enum

kaijuNames =  ["godzilla", "gojira", "gigan", "anguirus", "mechagodzilla", "kiryu", "king ceasar", \
                     "jet jaguar", "monster x", "king ghidorah", "king kong", "manda", "hedorah", \
                     "megaguirus", "biolante", "space-godzilla", "monster omega", "ebirah", \
                     "kamacurus", "kumonga", "rodan", "mothra", "minila", "gypsy danger"]
sillyNames = ["jay jay the jet plane", "miss piggy", "kermit", "dostoevsky", "timzilla", "christoughman", \
                    "kaiju-man", "kaiju-woman", "non-binary kaiju", "male-presenting kaiju", "danny de vito", \
                    "captain kirk", "hercules", "captain america", "mister", "batman", "robin", \
                    "remy (from pixar's \"ratatouille\")", "an innocent man", "a lecherous gecko", \
                    "odysseus", "tony stark", "the blues brothers", "lisan al gaib", "orientalist music", \
                    "tchaikovsky", "debussy", "john williams", "vivaldi", "mozart", "beethoven", \
                    "jean-luc picard", "obi-wan kenobi", "mr. peanut", "the yello telletubbie", \
                    "barney (from \"barney\")", "spongebob", "danikus manikus", "james bond", "teddy roosevelt", \
                    "abraham lincoln", "abraham lincoln: vampire slayer", "captain nemo", "scarlet o'hara", \
                    "optimus prime", "every member of the band \"rush\"", "an endangered species", \
                    "the beast from 20,000 fathoms", "the road warrior", "ryan reynolds", "tommy wiseau", \
                    "jim (from \"the office\")", "michael scott", "bill hayder", "frederick nietzsche", \
                    "baby godzilla"]

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

#TO-DO: # Kaiju creator. random chance that the player is going to get a bonus thing?
#TO-DO: Suspense between creations vs. quick-generate
def generateKaiju(order: kaijuGenerationOrder):   

    name = ""
    if (order.AUTO):
        if(order.SILLY):
            name = random.choice(sillyNames).upper()
        else:
            name = random.choice(kaijuNames).upper()
    else:
        print("&" * 8 + " KAIJU GENERATOR " + "&" * 8)  
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
    
    configuration = kaiju.ALL_SIZE_TYPES_NAMES[sizeType] + " " + kaiju.ALL_TRAVERSAL_TYPES_NAMES[traversalType] + " " \
        + kaiju.ALL_KAIJU_MOVES_NAMES[moveTypes[0]] + " " + kaiju.ALL_KAIJU_MOVES_NAMES[moveTypes[1]]
    
    kai =  kaiju.Kaiju(name, sizeType, sizeTraits, traversalType, traversalTraits, moveTypes, moveSets, legs, arms, heads, configuration)
    print("GENERATED " + kai.NAME + "!" + " The " + kai.CONFIGURATION + "kaiju!")

    return kai

# prints generated kaiju data to the console for the user to see. 
#   Selects data from nested lists depending on the desired stat for output.
def printKaijuData(kai):
    print("================ KAIJU DATA ================\n")
    
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
    

    print("\nCONFIGURATION: " + kai.configuration)
        
    print("\n====================== END =====================\n")
    
def printKaijuSelectionList(simple):
    # print in rows and columns with corresponding letter   
  
    # TODO
        # need to get kaiju with longest name in given column so columns are evenly spaced when printing rows. 
            # spacing after every kaiju should match total spaces needed for longest-named kaiju in that column.        
        # color code them  
    i = ord("A")
    if (simple):
        numberOfColumns = 2
        numberOfRows = int(len(kaijus)/ numberOfColumns)
        letterOrd = ord('A')
        for i in range(0, int(len(kaijus) / numberOfColumns)):
            namesInRow = []
            j = i
            while j < len(kaijus):
                if (j + numberOfRows>= len(kaijus)):
                    print(chr(letterOrd) + " - " + kaijus[j].NAME)
                else:
                    print(chr(letterOrd) + " - " + kaijus[j].NAME, end = " " * 6)    
                letterOrd += 1
                j += numberOfRows     
    else: 
        for kai in kaijus:
            print(chr(i) + " - " + kai.name)
            print("\n\tCONFIGURATION: " + kai.configuration)
     
# Creating Alphabetized list of kaijus
def alphabetizeKaijus(kaijus: []) :
    for i in range(0, len(kaijus)):
        for j in range(0, len(kaijus)):
            if (kaijus[i].NAME < kaijus[j].NAME):
                k = kaijus[i]
                kaijus[i] = kaijus[j]
                kaijus[j] = k 


class MenuOptions(Enum):
    PLAYER_BATTLE = 1
    FULLY_RANDOM_BATTLE = 2
    SELECTED_AI_BATTLE = 3
    GENERATE_NEW_KAIJU = 4
    DELETE_KAIJU = 5
    KAIJU_DATA = 6
    QUIT = 10

def mainMenu():
    # Menu Options and Selection
    menuTextNotEnoughKaiju = "~" * 23 + " MAIN MENU " + "~" * 23 + \
        "\n\n" + str(MenuOptions.GENERATE_NEW_KAIJU) + " - GENERATE NEW kaiju (i.e. 4) --> Kaiju Generation Seqence / Menu" + \
        "\n" + str(MenuOptions.QUIT) +  " - QUIT" + \
        "\n\n\tUH-OH!!! Not enough kaiju for battle. Generate new ones!" + \
        "\n" + "~" * 60
    menuText = "~" * 23 + " MAIN MENU " + "~" * 23 + \
        "\n\n" + str(MenuOptions.PLAYER_BATTLE) + "- KAIJU BATTLE (input \"1\" plus two letters, one for each kaiju going into battle." + \
        "\n\tFirst kaiju input is yours. Second is the AI's. (i.e. \"1AZ\", \"1XI\"))" + \
        "\n" + str(MenuOptions.FULLY_RANDOM_BATTLE) + " - FULLY RANDOM AI KAIJU BATTLE (i.e. \"2\")" + \
        "\n" + str(MenuOptions.SELECTED_AI_BATTLE) + " - SELECTED AI KAIJU BATTLE (i.e. \"3AD\")" + \
        "\n" + str(MenuOptions.GENERATE_NEW_KAIJU)+ " - GENERATE NEW kaiju (i.e. 4) --> Kaiju Generation Seqence / Menu" + \
        "\n" + str(MenuOptions.DELETE_KAIJU) + " - DELETE KAIJU (i.e. 5A deletes kaiju with 'A' next to them)" + \
        "\n" + str(MenuOptions.KAIJU_DATA) + " - KAIJU DATA (input 6 plus letter of associated kaiju, " + \
                        "\n\t(i.e. '6A' gets data on kaiju that is adjacent to 'A'))" + \
        "\n" + str(MenuOptions.KAIJU_DATA) +  " - QUIT" + \
        "\n" + "~" * 60
    
    alphabetizeKaijus(kaijus)
    
    shouldQuit = False
    while(shouldQuit == False):      
        printKaijuSelectionList(True)

        if (len(kaijus) < 3):
            print (menuTextNotEnoughKaiju)
        else:
            print(menuText)
        
        userInput = ""    
        invalidInfo = ""
        while True: 
            if (invalidInfo != ""):
                print("Input is invalid. Please give valid input based on menu option descriptions." +
                      "\n\tInvalid Info: " + invalidInfo )
                invalidInfo = ""
    
            userInput = input("Input a menu option.").upper()
            userInput.strip()
            userInput.replace(" ", "")

            # checks
            if (len(userInput) == 0):
                invalidInfo = "Input zero characters."
                continue

            if (userInput[0].isdigit == False):
                invalidInfo = "The first character must be a number."
                continue

            match userInput[0]:
                case 1:
                    if (len(userInput) != 3):
                        invalidInfo = "KAIJU BATTLE requires three inputs." + \
                                        "\n\t 1AB" 
                        continue
                case 2:                    
                    pass
                case 3:
                    if (len(userInput) != 3):
                        invalidInfo = "KAIJU BATTLE requires 2 monster inputs."
                    pass
                case 4:
                    pass
                case 5:
                    pass
                case 6:
                    pass
                case 7:
                    pass
                # TODO - case for testmode
                case _:
                    invalidInfo = "That is not a valid input."
                    
            # FULLY RANDOM AI BATTLE
                # Randomly select kaiju for battle.
                # Call battle function with AI on functionality
            # SELECTED AI BATTLE
                # CAll battle function with AI on functionality. 
            # GENERATE NEW KAIJU
                # Generate new kaiju. Ask for name. 
                    # Confirm if they want this kaiju. 
                    # If not, re-loop.
                    # If yes, add kaiju to kaijus array.                    
            # DELETE KAIJU
                # Ask if they are sure they want to delete that kaiju. If confirmed, then delete kaiju.
            # KAIJU DATA
                # hook-up
            # Quit
                        
            # if selection check passes, break out of loop

    
##################
# GLOBAL VARIABLES 

kaijus = []

def main():
    # TO-DO - Run in auto-test mode - auto-battles a given number of kaiju. Battle outcome and stats are
        # saved to a file.
        # Battle stats
            # Which moves did most damage
            # Did certain moves do more damage when preceded by 
        # Different test types
            # Test x configurations vs y configurations
            #

    # Load in all kaiju
    with open("kaijus.txt") as kaijuCSV:
        reader = csv.reader(kaijuCSV)
        for line in reader:
            pass

    # TODO - add kaijus from csv into array

    ########################################## - Delete this for loop once csv stuff is working.
    # for i in range(1, 11):
    #     newK :kaiju.Kaiju
    #     while True:
    #         newK = generateKaiju(kaijuGenerationOrder(True, False))
            
    #         alreadyHave = False
    #         for k in kaijus:
    #             if(k.NAME == newK.NAME):
    #                 alreadyHave = True
    #                 break
            
    #         if (alreadyHave == False):
    #             break            
            
    #     kaijus.append(newK)
            
    mainMenu()
        
    # with open("kaijus.txt") as kaijusCSV:
    #     writer = csv.writer(kaijusCSV)
    #     for kai in kaijus:
    #         writer.writerow("======")

    #         writer.writerow(kai.name)
    #         writer.writerow(str(kai.sizeType))
    #         for trait in kai.sizeTraits
    #             writer.writerow(trait.)
    #         # Check for different types: https://stackoverflow.com/questions/152580/whats-the-canonical-way-to-check-for-type-in-python
    #         writer.writerow(traversalType)
            

    print("\n\nRAWR...")
    
    
    

if __name__ == "__main__":
    main()



    # - Options v2: Input the kaiju's letter and the number action you want to do    
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
  





        
