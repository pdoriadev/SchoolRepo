#########################################################################

# Kaiju Data

#########################################################################



# Traits given based on size. Kaiju of their given size receive all these traits
COLOSSAL_TRAITS = ["Lumbering", "Ignore Half-damage", "Cannot dodge", "Carry Buildings"]
MONSTROUS_TRAITS = ["Dexterous", "Dodge", "Leap"]
AGILE_TRAITS = ["Acrobatic", "Dodge", "Climb", "Hide", "Leap", "Takes Double Damage"]
ALL_SIZE_TYPES_NAMES = ["COLOSSAL", "MONSTROUS", "AGILE"]
ALL_SIZE_TYPES = [COLOSSAL_TRAITS, MONSTROUS_TRAITS, AGILE_TRAITS]
SIZE_TYPE_IN_METERS = [100, 60, 10]

# Different moves depending on the traversal type
AERIAL_MOVES = ["Supersonic", "Dive-bomb", "Air-dodge"]
AQUATIC_MOVES = ["Hold-breath", "Sonar", "Submerge"]
DIGGING_MOVES = ["Ground Shake", "Burrow", "Internal Gyroscope"]
ALL_TRAVERSAL_TYPES = [AERIAL_MOVES, AQUATIC_MOVES, DIGGING_MOVES]
ALL_TRAVERSAL_TYPES_NAMES = ["AERIAL ", "AQUATIC", "DIGGING"]

# Different abilities based on the kaiju type
BRAWLER_MOVES = ["Headbutt", "Tail Whip", "Punch", "Claw", "Bite", "Grapple", "Leap"]
SPIRIT_MOVES = ["Channel Past Lives", "Transfer Spirit", "Biting Essence", "Meditation", "Prophecy"]
ATOMIC_MOVES = ["Atomic Breath", "Absorb Energy", "Atomic Immolation", "Fast Healing"]
ROBOT_MOVES = ["Finger-missiles", "Force-field", "Eye-beams", "Shocking Grasp", "Emergency Repair", "Chainsaw Hand"]   
ALL_MOVE_TYPES = [BRAWLER_MOVES, SPIRIT_MOVES, ATOMIC_MOVES, ROBOT_MOVES]
ALL_MOVE_TYPES_NAMES = ["BRAWLER", "SPIRIT", "ATOMIC", "ROBOT"]

    # TO-DO: Make a move class that has damage or other info??
        # move types - damage, heal, etc. Feels like should be enum??? 



        
class Kaiju:
    name = ""

    sizeType = -1
    sizeTraits = []
    
    traversalType = -1
    traversalTraits = []

    moveTypes = []
    moveset1 = []
    moveset2 = []

    def __init__(_name, _sizeType, _sizeTraits, _traversalType, 
                   _traversalTraits, _moveTypes, _moveSets,
                   _legs, _arms, _hands):
        name = _name

        sizeType = _sizeType
        sizeTraits = _sizeTraits
    
        traversalType = _traversalType
        traversalTraits = _traversalTraits

        moveTypes = _moveTypes
        moveSets = _moveSets

      
        
