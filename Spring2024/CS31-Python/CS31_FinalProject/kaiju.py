#########################################################################

# Kaiju Data

#########################################################################


# Kaiju creator. random chance that the player is going to get a bonus thing.
SIZE_TYPES = ["COLOSSAL", "MONSTROUS", "AGILE"]
SIZE_TYPE_IN_METERS = [100, 60, 10]

# Traits given based on size. Kaiju of their given size receive all these traits
COLOSSAL_TRAITS = ["Lumbering", "Ignore Half-damage", "Cannot dodge", "Carry Buildings"]
MONSTROUS_TRAITS = ["Dexterous", "Dodge", "Leap"]
AGILE_TRAITS = ["Acrobatic", "Dodge", "Climb", "Hide", "Leap", "Takes Double Damage"]

# Different moves depending on the traversal type
TRAVERSAL_TYPES = ["AERIAL ", "AQUATIC", "DIGGING"]
AERIAL_MOVES = ["Supersonic", "Dive-bomb", "Air-dodge"]
AQUATIC_MOVES = ["Hold-breath", "Sonar", "Submerge"]
DIGGING_MOVES = ["Ground Shake", "Burrow", "Internal Gyroscope"]

# Different abilities based on the kaiju type
MOVESETS = ["BRAWLER", "SPIRIT", "ATOMIC", "ROBOT"]
BRAWLER_MOVES = ["Headbutt", "Tail Whip", "Punch", "Claw", "Bite", "Grapple", "Leap"]
SPIRIT_MOVES = ["Channel Past Lives", "Transfer Spirit", "Biting Essence", "Meditation", "Prophecy"]
ATOMIC_MOVES = ["Atomic Breath", "Absorb Energy", "Atomic Immolation", "Fast Healing"]
ROBOT_MOVES = ["Finger-missiles", "Force-field", "Eye-beams", "Shocking Grasp", "Emergency Repair", "Chainsaw Hand"]   
    # TO-DO: Make a move class that has damage or other info??
        # move types - damage, heal, etc. Feels like should be enum??? 


#TO-DO: Moves or traits based on number of legs, arms, or heads. 
    #Or maybe it's just a multiplier? i.e. legs faster, arms more damage, heads more vision, 
        # heads multi-attack if using a bite or something like that

#TO-DO: Something that determines movement rules? 
#   i.e. kaiju tells move function they want to move. Kaiju gives move function necessary data
#           to move that kaiju correctly (movement different between colossal and agile, kaiju
#           with different traversal types, etc.)

class Kaiju:
    sizeType = -1
    sizeTraits = []
    
    traversalType = -1
    traversalTraits = []

    moveType1 = -1
    moveset1 = []
    moveType2 = -1
    moveset2 = []

    def __init__():
        print()
        
