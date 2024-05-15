#########################################################################

# Kaiju Data

#########################################################################

from enum import Enum

# Traits given based on size. Kaiju of their given size receive all these traits
COLOSSAL_TRAITS = ["Cannot dodge", "Carry Building", "Throw Building", "CATACLYSMIC ROAR"]

# Cannot Dodge
    # Permanent Status
    # Always takes at least 1 damage unless attacker rolls crit fail. 
        # Minimum damage taken is equal to number of dice rolled by attacker. 

# Carry building
    # Status?
    # If X damage taken while carrying building, drop building on top of themselves
    # Throw building will always be an option on next turn if carrying building.
    # Say the exact building they have picked up. Make it a landmark.
        # Hotel(which hotel?)? The Chinese Theatre? 

# Throw building
    # Attack
    # If carrying building, can throw. removes pick-up building 

# Ten-mile Roar
    # Intimidate opponent. 
    # 

MONSTROUS_TRAITS = ["Dexterous", "Intimidate"]
# 

AGILE_TRAITS = ["Double Dodge", "Takes Double Damage"]
# Acrobatic - CAn


ALL_SIZE_TYPES_NAMES = ["COLOSSAL", "MONSTROUS", "AGILE"]
ALL_SIZE_TYPES = [COLOSSAL_TRAITS, MONSTROUS_TRAITS, AGILE_TRAITS]
SIZE_TYPE_IN_METERS = [50, 36, 20]

# Different moves depending on the traversal type
AERIAL_MOVES = ["Supersonic", "Dive-bomb", "Air-dodge"]
AQUATIC_MOVES = ["Hold-breath", "Sonar", "Submerge"]
DIGGING_MOVES = ["Ground Shake", "Burrow", "Internal Gyroscope"]
ALL_TRAVERSAL_TYPES = [AERIAL_MOVES, AQUATIC_MOVES, DIGGING_MOVES]
ALL_TRAVERSAL_TYPES_NAMES = ["AERIAL ", "AQUATIC", "DIGGING"]

# Different abilities based on the kaiju type
BRAWLER_MOVES = ["Headbutt", "Tail Whip", "Punch", "Claw", "Bite", "Grapple"]
# Headbutt
    # Attack
    # Should account for number of heads on attacker

# Tail Whip
    # Attack
    # Could knock down opponent <-- TOO OP?

# Punch
    # Attack
    # Accounts for number of arms. Multipunch?

# Claw
    # Attack
    # Bleed damage? 

# Bite
    # Attack
    # Accounts for number of heads
    # Accounts of if Atomic, Spirit, or Robot

# Grapple
    # Attack
    # Accounts for size difference 
        #   if try to grapple a creature bigger than you, then it kicks you.
        #   if try to grapple a creature smaller than you, has high chance to get
            # out of

# Atomic Breath
    # Attack
    # Accounts for number of heads?
    # Burning damage over time
    # How much energy does this reduce? <-- unless can simplify to something easy. Too much work. 

SPIRIT_MOVES = ["Channel Past Lives", "Transfer Spirit", "Biting Essence", "Meditation", "Prophecy, Embody (another kaiju)"]
ATOMIC_MOVES = ["Atomic Breath", "Absorb Energy", "Atomic Immolation", "Fast Healing"]
ROBOT_MOVES = ["Finger-missiles", "Force-field", "Eye-beams", "Shocking Grasp", "Emergency Repair", "Chainsaw Hand"]   
ALL_KAIJU_MOVES = [BRAWLER_MOVES, SPIRIT_MOVES, ATOMIC_MOVES, ROBOT_MOVES]
ALL_KAIJU_MOVES_NAMES = ["BRAWLER", "SPIRIT", "ATOMIC", "ROBOT"]

    # TO-DO: Make a move class that has damage or other info??
        # move types - damage, heal, etc. Feels like should be enum??? 
    # To-Do: Kaiju of same element take half damage from same element attacks?

# Brawler doesn't have an energy resource to manage?
# Spirit energy needs to be cultivated
# Atomic energy builds??? will take damage if have too much energy
# Robot's energy is drained more by certain moves. 
# All have same energy resource that comes from different 


#TO-DO need status effects
        


    #different move types (i.e. healing, attack, defense, things that change number of dice using)

        


class Kaiju:
    name = ""
    sizeType = -1
    sizeTraits = []   
    traversalType = -1
    traversalTraits = []
    moveTypes = []
    moveSets = []
    legs = -1
    arms = -1
    heads = -1

    maxHealth = -1
    baseDiceNumber = -1

    def __init__(self, _name, _sizeType, _sizeTraits, _traversalType, _traversalTraits, _moveTypes, _moveSets, _legs, _arms, _heads):
        self.name = _name

        self.sizeType = _sizeType
        self.sizeTraits = _sizeTraits
    
        self.traversalType = _traversalType
        self.traversalTraits = _traversalTraits

        self.moveTypes = _moveTypes
        self.moveSets = _moveSets

        self.legs = _legs
        self.arms = _arms
        self.heads = _heads

        self.maxHealth = SIZE_TYPE_IN_METERS[self.sizeType]
        self.baseDiceNumber = self.sizeType + 1

      
        
