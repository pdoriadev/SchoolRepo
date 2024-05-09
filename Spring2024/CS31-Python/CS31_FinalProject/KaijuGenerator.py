##############################################################################################################

# Kaiju Generation Business Logic

##############################################################################################################
import kaiju
import random

def generateKaiju() :
    name = str(input ("What would you like to name your kaiju: "))
    name = name.upper()
    kaijuTraits = generatePrimaryTraits()
    limbsAndHeads = generateLimbsAndHeads()

# Every kaiju has 4 randomly selected primary traits which can randomly select 
#   additional identifiers depending on the given trait (i.e. size vs Kaiju Type):
# 1.  Size (inherits all traits of specified size)
# 2.  Traversal Type (inherits all tratis of specified size)
# 3.  Kaiju Type 1 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# 4.  Kaiju Type 2 (gives monster identity beyond size or traversal. Defines moves for combat or otherwise)
# Note: Each kaiju has two kaijuTypes. This gives each kaiju a unique identity.
#          (i.e. Atomic Robot, Spirit Brawler, Atomic Spirit, etc.)
# Note: A kaiju does not inherit all moves of an inherited type. It only inherits a few moves per type.          
def generatePrimaryTraits():

    # Randomly select size traits for kaiju
    size = random.randrange(0, len(kaiju.SIZE_TYPES) - 1, 1)
    sizeTraits = []
    sizeTraits.append(kaiju.SIZE_TYPES[size])
    if (size == 0):
        sizeTraits.append(kaiju.COLOSSAL_TRAITS)
    elif (size == 1):
        sizeTraits.append(kaiju.MONSTROUS_TRAITS)
    elif (size == 2):
        sizeTraits.append(kaiju.AGILE_TRAITS)
    else: 
        assert("Not handled case")

    # Randomly select traversal traits for kaiju
    traversal = random.randrange(0, len(kaiju.TRAVERSAL_TYPES) - 1, 1)
    traversalTraits = []
    traversalTraits.append(kaiju.TRAVERSAL_TYPES[traversal])
    if (traversal == 0):
        traversalTraits.append(kaiju.AERIAL_MOVES)
    elif (traversal == 1):
        traversalTraits.append(kaiju.AQUATIC_MOVES)
    elif (traversal == 2):
        traversalTraits.append(kaiju.DIGGING_MOVES)
    else:
        assert ("Not handled case")
    

    # Randomly select moves from list based on kaiju's first type
    kaijuType1 = random.randrange(0, len(kaiju.MOVESETS) - 1, 1)
    kaijuType1Moves = []
    kaijuType1Moves.append(kaiju.MOVESETS[kaijuType1])
    move1 = ""
    move2 = ""
    if (kaijuType1 == 0):
        move1 = random.choice(kaiju.BRAWLER_MOVES)
        move2 = random.choice(kaiju.BRAWLER_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.BRAWLER_MOVES)
    elif (kaijuType1 == 1):
        move1 = random.choice(kaiju.SPIRIT_MOVES)
        move2 = random.choice(kaiju.SPIRIT_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.SPIRIT_MOVES)
    elif (kaijuType1 == 2):
        move1 = random.choice(kaiju.ATOMIC_MOVES)
        move2 = random.choice(kaiju.ATOMIC_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.ATOMIC_MOVES)
    elif (kaijuType1 == 3):
        move1 = random.choice(kaiju.ROBOT_MOVES)
        move2 = random.choice(kaiju.ROBOT_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.ROBOT_MOVES)
    else:
        assert("Case not accounted for.")
        
    kaijuType1Moves.append(move1)
    kaijuType1Moves.append(move2)
    
    # Randomly select moves from list based on kaiju's second type
    kaijuType2 = random.randrange(0, len(kaiju.MOVESETS) - 1, 1)
    while kaijuType2 == kaijuType1:
        kaijuType2 = random.randrange(0, len(kaiju.MOVESETS) - 1, 1)    
    kaijuType2Moves = []
    kaijuType2Moves.append(kaiju.MOVESETS[kaijuType2])
    move1 = ""
    move2 = ""
    if (kaijuType2 == 0):
        move1 = random.choice(kaiju.BRAWLER_MOVES)
        move2 = random.choice(kaiju.BRAWLER_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.BRAWLER_MOVES)  
    elif (kaijuType2 == 1):
        move1 = random.choice(kaiju.SPIRIT_MOVES)
        move2 = random.choice(kaiju.SPIRIT_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.SPIRIT_MOVES)
    elif (kaijuType2 == 2):
        move1 = random.choice(kaiju.ATOMIC_MOVES)
        move2 = random.choice(kaiju.ATOMIC_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.ATOMIC_MOVES)
    elif (kaijuType2 == 3):
        move1 = random.choice(kaiju.ROBOT_MOVES)
        move2 = random.choice(kaiju.ROBOT_MOVES)
        while move2 == move1:
            move2 = random.choice(kaiju.ROBOT_MOVES)
    
    kaijuType2Moves.append(move1)
    kaijuType2Moves.append(move2)
    
    # append trait lists into a nested list
    kaijuTraits = []
    kaijuTraits.append(sizeTraits)
    kaijuTraits.append(traversalTraits)
    kaijuTraits.append(kaijuType1Moves)
    kaijuTraits.append(kaijuType2Moves)
    
    return kaijuTraits


def generateLimbsAndHeads():
    limbsAndHeads = []
    limbsAndHeads.append(random.randrange(0,8,2))
    limbsAndHeads.append(random.randrange(2,4,2))
    limbsAndHeads.append(random.randrange(1, 3, 2))
    return limbsAndHeads