##############################################################################################################

# Kaiju Generation Business Logic

##############################################################################################################
import kaiju
import random

def generateKaiju() :
    name = str(input ("What would you like to name your kaiju: "))
    name = name.upper()
    kaijuTraits = generateKaiju()
    limbsAndHeads = generateLimbsAndHeads()

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
def generateKaiju():

    name = input ("KAIJU NAME: ")

    # Randomly select size traits for kaiju
    sizeType = random.choice(kaiju.ALL_SIZE_TYPES)
    sizeTraits = []
    sizeTraits.append(kaiju.ALL_SIZE_TYPES_NAMES[sizeType])
 
    # Randomly select traversal traits for kaiju
    traversalType = random.choice(kaiju.ALL_TRAVERSAL_TYPES)
    traversalTraits = []
    traversalTraits.append(kaiju.ALL_TRAVERSAL_TYPES_NAMES[traversalType])   

    #TO-DO: Variable number of kaiju types or moves for a given kaiju??
        # Maybe always four moves, but can be split between types any way
        # that works. 

    # Randomly select moves from list based on kaiju's first type
    kaijuType1 = random.choice(kaiju.ALL_MOVE_TYPES)
    kaijuType1Moves = []
    move = random.choice(kaiju.ALL_MOVE_TYPES[kaijuType1])
    kaijuType1Moves.append(move)
    move = random.choice(kaiju.ALL_MOVE_TYPES[kaijuType1])
    kaijuType1Moves.append(move)
    while kaijuType1Moves[0] == kaijuType1Moves[1] :
        move = random.choice(kaiju.ALL_MOVE_TYPES[kaijuType1])
        kaijuType1Moves.append(move)
    
    # Randomly select moves from list based on kaiju's second type
    kaijuType2 = random.choice(kaiju.ALL_MOVE_TYPES)
    kaijuType2Moves = []
    move = random.choice(kaiju.ALL_MOVE_TYPES[kaijuType2])
    kaijuType1Moves.append(move)
    move = random.choice(kaiju.ALL_MOVE_TYPES[kaijuType2])
    kaijuType2Moves.append(move)
    while kaijuType2Moves[0] == kaijuType2Moves[1] :
        move = random.choice(kaiju.ALL_MOVE_TYPES[kaijuType1])
        kaijuType1Moves.append(move)

    moveTypes = [kaijuType1, kaijuType2]
      
    legs = random.randrange(0,8,2)
    arms = random.randrange(2,4,2)
    heads = random.randrange(1, 3, 2)
    
    return Kaiju(name, sizeType, sizeTraits, traversalType,
                 traversalTraits, moveTypes, )


def generateLimbsAndHeads():

    return limbsAndHeads