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

# Kaiju creator. random chance that the player is going to get a bonus thing.
SIZE_TYPES = ["COLOSSAL", "MONSTROUS", "AGILE"]
SIZE_TYPE_IN_METERS = [100, 60, 10]

# Traits given based on size. Kaiju of their given size receive all these traits
COLOSSAL_TRAITS = ["Slow Movement", "Ignore Half-damage", "Cannot dodge", "Carry Buildings"]
MONSTROUS_TRAITS = ["Mid Movement", "Dodge", "Leap"]
AGILE_TRAITS = ["Dextrous", "Dodge", "Climb", "Hide", "Leap", "Takes Double Damage"]

# Different moves depending on the traversal type
TRAVERSAL_TYPES = ["AERIAL ", "AQUATIC", "DIGGING"]
AERIAL_MOVES = ["Supersonic", "Dive-bomb", "Air-dodge"]
AQUATIC_MOVES = ["Hold-breath", "Sonar", "Submerge"]
DIGGING_MOVES = ["Ground Shake", "Burrow", "Internal Gyroscope"]

# Different abilities based on the kaiju type
KAIJU_TYPES = ["BRAWLER", "SPIRIT", "ATOMIC", "ROBOT"]
BRAWLER_MOVES = ["Headbutt", "Tail Whip", "Punch", "Claw", "Bite", "Grapple", "Leap"]
SPIRIT_MOVES = ["Channel Past Lives", "Transfer Spirit", "Biting Essence", "Meditation", "Prophecy"]
ATOMIC_MOVES = ["Atomic Breath", "Absorb Energy", "Atomic Immolation", "Fast Healing"]
ROBOT_MOVES = ["Finger-missiles", "Force-field", "Eye-beams", "Shocking Grasp", "Emergency Repair"]               

legs = random.randrange(0,8,2)
arms = random.randrange(2,4,2)
heads = random.randrange(1, 3, 2)


# Every kaiju has 4 primary traits:
# 1.  Size (inherits all traits of specified size)
# 2.  Traversal Type (inherits all tratis of specified size)
# 3.  Kaiju Type 1 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# 4.  Kaiju Type 2 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# Note: Each kaiju has two kaijuTypes. This gives each kaiju a unique identity.
#          (i.e. Atomic Robot, Spirit Brawler, Atomic Spirit, etc.)
# Note: A kaiju does not inherit all moves of an inherited type. It only inherits a few moves per type.          
def generateKaijuTraits():
    
    # Randomly select size traits for kaiju
    size = random.randrange(0, len(SIZE_TYPES) - 1, 1)
    sizeTraits = []
    sizeTraits.append(SIZE_TYPES[size])
    if (size == 0):
        sizeTraits.append( COLOSSAL_TRAITS)
    elif (size == 1):
        sizeTraits.append(MONSTROUS_TRAITS)
    elif (size == 2):
        sizeTraits.append(AGILE_TRAITS)
    else: 
        assert("Not handled case")

    # Randomly select traversal traits for kaiju
    traversal = random.randrange(0, len(TRAVERSAL_TYPES) - 1, 1)
    traversalTraits = []
    traversalTraits.append(TRAVERSAL_TYPES[traversal])
    if (traversal == 0):
        traversalTraits.append(AERIAL_MOVES)
    elif (traversal == 1):
        traversalTraits.append(AQUATIC_MOVES)
    elif (traversal == 2):
        traversalTraits.append(DIGGING_MOVES)
    else:
        assert ("Not handled case")
    

    # Randomly select moves from list based on kaiju's first type
    kaijuType1 = random.randrange(0, len(KAIJU_TYPES) - 1, 1)
    kaijuType1Moves = []
    kaijuType1Moves.append(KAIJU_TYPES[kaijuType1])
    move1 = ""
    move2 = ""
    if (kaijuType1 == 0):
        move1 = random.choice(BRAWLER_MOVES)
        move2 = random.choice(BRAWLER_MOVES)
        while move2 == move1:
            move2 = random.choice(BRAWLER_MOVES)
    elif (kaijuType1 == 1):
        move1 = random.choice(SPIRIT_MOVES)
        move2 = random.choice(SPIRIT_MOVES)
        while move2 == move1:
            move2 = random.choice(SPIRIT_MOVES)
    elif (kaijuType1 == 2):
        move1 = random.choice(ATOMIC_MOVES)
        move2 = random.choice(ATOMIC_MOVES)
        while move2 == move1:
            move2 = random.choice(ATOMIC_MOVES)
    elif (kaijuType1 == 3):
        move1 = random.choice(ROBOT_MOVES)
        move2 = random.choice(ROBOT_MOVES)
        while move2 == move1:
            move2 = random.choice(ROBOT_MOVES)
    else:
        assert("Case not accounted for.")
        
    kaijuType1Moves.append(move1)
    kaijuType1Moves.append(move2)
    
    # Randomly select moves from list based on kaiju's second type
    kaijuType2 = random.randrange(0, len(KAIJU_TYPES) - 1, 1)
    while kaijuType2 == kaijuType1:
        kaijuType2 = random.randrange(0, len(KAIJU_TYPES) - 1, 1)    
    kaijuType2Moves = []
    kaijuType2Moves.append(KAIJU_TYPES[kaijuType2])
    move1 = ""
    move2 = ""
    if (kaijuType2 == 0):
        move1 = random.choice(BRAWLER_MOVES)
        move2 = random.choice(BRAWLER_MOVES)
        while move2 == move1:
            move2 = random.choice(BRAWLER_MOVES)  
    elif (kaijuType2 == 1):
        move1 = random.choice(SPIRIT_MOVES)
        move2 = random.choice(SPIRIT_MOVES)
        while move2 == move1:
            move2 = random.choice(SPIRIT_MOVES)
    elif (kaijuType2 == 2):
        move1 = random.choice(ATOMIC_MOVES)
        move2 = random.choice(ATOMIC_MOVES)
        while move2 == move1:
            move2 = random.choice(ATOMIC_MOVES)
    elif (kaijuType2 == 3):
        move1 = random.choice(ROBOT_MOVES)
        move2 = random.choice(ROBOT_MOVES)
        while move2 == move1:
            move2 = random.choice(ROBOT_MOVES)
    
    kaijuType2Moves.append(move1)
    kaijuType2Moves.append(move2)
    
    # append trait lists into a nested list
    kaijuTraits = []
    kaijuTraits.append(sizeTraits)
    kaijuTraits.append(traversalTraits)
    kaijuTraits.append(kaijuType1Moves)
    kaijuTraits.append(kaijuType2Moves)
    
    return kaijuTraits

    
# prints generated kaiju data to the console for the user to see
def printKaijuData(name, traits):
    print("================ KAIJU GENERATED ================\n")
    
    print("\nNAME:\t\t\t" + name)
    
    print("\nSIZE:\t\t\t" + traits[0][0])
    index = 0
    while index < len(traits[0][1]):
        print(traits[0][0] + " TRAIT " + str(index) + ":\t" + traits[0][1][index])
        index+=1
    
    print("\nTRAVERSAL TYPE:\t\t" + traits[1][0])
    index = 0
    while index < len(traits[1][1]):
        print(traits[1][0] + " TRAIT " + str(index) + ":\t" + traits[1][1][index])
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
    
    shouldGenerate = input("Would you like to generate a kaiju? " + \
                                "Input 'n' for no. Input anything else for yes: ")
    while shouldGenerate != "n" :
        kaijuTraits = generateKaijuTraits()
        name = input ("What would you like to name your kaiju: ")
        name = name.upper()
        printKaijuData(name, kaijuTraits)
        
        shouldGenerate = input("\n\nWould you like to create a new kaiju? " + \
                                "Input 'n' for no. Input anything else for yes: ")
        

    print("\n\nRAWR... bye")
    
    
    

if __name__ == "__main__":
    main()

