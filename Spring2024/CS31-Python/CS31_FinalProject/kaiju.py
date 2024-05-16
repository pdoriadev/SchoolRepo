#########################################################################

# Kaiju Data

#########################################################################
from enum import Enum
from abc import ABC

# thinking about moves as like a restaurant order
    # first we choose what we want to eat
    # we pay the cost
    # The order gets sent to the kitchen. 
    # The order gets botched or made.
    # If made, customer gets burger.    

# If we are making burgers, and there are a bunch of different kinds of burgers and we could order burgers
    #   meant for different people, need to track: What are the different kinds of burgers, and who are the 
    #   burgers for. 
    
# What are the ingredients? IS THIS ALL I NEED????
    # statuses
    # damage
    # Healing

# How do you pay? 
    # With energy? Or health?       

# Move
    # cost
    # description
    # activate()
        

# MoveInstance (factors in the base attack and all other modifiers from statuses or traits)
    # has specific 
    # 


class AbstractStatus(ABC):
    def activate(kaiju: Kaiju):
        pass

class BurningStatus(AbstractStatus):
    burningDamage = -1
    def activate (kaiju: Kaiju):
        kaiju.takeDamage(burningDamage, "BURNING STATUS")

    def __init__(_burningDamage):
        burningDamage = _burningDamage
        


# Burning Status
    # Take damage each turn.    
    # Damage decreases on subsequent turns.
    # Turns remaining is equal to damage this turn - 1 (like Slay the Spire)        
# Stun Status        
    # Defensive dice = base defensive dice - 1
    # Defensive dice minimum is 0.    
# Grappled Status
    # Defensive dice = base defensive dice - 1
    #         

class AbstractMove(ABC):
    def activate(kaiju: Kaiju):
        pass


# Size Traits
# class SizeTrait(TraitType):
#     pass

# class CollossalTrait(SizeTrait):
#     pass

# #Traversal Traits
# class TraversalTrait(TraitType):
#     pass

# class AerialTrait(TraversalTrait):
#     pass

# class DiggingTrait(TraversalTrait):
#     pass

# class 

# #
# class KaijuTypeTrait(TraitType):
#     pass

# class AtomicTrait(KaijuTypeTrait):
#     pass

# class AtomicBreath(AbstractMove):
#     cost
#     additionalDice
#     abstractStatus = BurningStatus()
#     def activate(targetKaiju: Kaiju):
#         targetKaiju.takeDamage()
#         targetKaiju.addStatus(burningStatus)

#     def __init__(_cost, _additionalDice):
#         cost = _cost
#         additionalDice = _additionalDice




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
SPIRIT_MOVES = ["Channel Past Lives", "Focus Spirit", "Biting Essence", "Meditation", "Prophesy", "Kaiju Avatar"]
#Channel past lives
    # Gain random move for the rest of the battle. Can only be used once.
# Focus Spirit
    # Go twice in a row. Lose half health. 
    # Non-attack.
# Biting Essence
    # If successful, drains energy from target.
    # Energy drain equal to number of heads?
# Meditation
    # Save up to X energy for next turn.
# Prophesy
    # Gain up to 2 dice for next defensive roll. 
# Kaiju Avatar
    # Pick between three kaiju to assume the form of. Avatar drops after losing X health. 
ATOMIC_MOVES = ["Atomic Breath", "Nuclear Fusion", "Atomic Immolation", "Fast Healing", "Quantum Entanglement"]
# Atomic Breath
    # Attack
    # Fire beam of atomic energy at target kaiju.
    # One roll for each head <-- attack dice / number of heads (rounded up)
    # Applies Burning damage over time status
    # Add X energy to increase dice
# Nuclear Fusion
    # Double energy output of next X attack
# Atomic Immolation
    # Turn your body into a nuclear meltdown. Take X damage. 
    # X Attack move. 
    # Apply X burning damage per turn to any other kaiju.
# Fast Healing
    # Heal X * 3 health
# Quantum Entanglement
    # Any damage you take, half will be applied to target for one turn. 
ROBOT_MOVES = ["Finger-missiles", "Force-field", "Eye-beams", "Shocking Grasp", "Emergency Repair", "Burning Chainsaw"]   
# Finger-missiles
    # Shoot finger-missiles out of of your hands. 
# Force-field
    # Gain barrier. Next attack that succeeds must exceed defensive roll + X damage to apply damage and/or statuses.
# Eye-beams
    # Shoot eye-beams at target. Chance to apply stun status effect. 
# Shocking Grasp
    # Grab opponent and apply stun status. 
# Emergency Repair
    # Consume all remaining energy to heal X * 3
# Chainsaw Hand
    # Chainsaw your opponent. Apply burning status.
ALL_KAIJU_MOVES = [BRAWLER_MOVES, SPIRIT_MOVES, ATOMIC_MOVES, ROBOT_MOVES]
ALL_KAIJU_MOVES_NAMES = ["BRAWLER", "SPIRIT", "ATOMIC", "ROBOT"]

    # TO-DO: Make a move class that has damage or other info??
        # move types - damage, heal, etc. Feels like should be enum??? 
    # To-Do: Kaiju of same element take half damage from same element attacks?

# FUN IDEAS
    # Brawler doesn't have an energy resource to manage?
    # Spirit energy needs to be cultivated
    # Atomic energy builds??? will take damage if have too much energy
    # Robot's energy is drained more by certain moves. 
    # All have same energy resource that comes from different 


#TO-DO need status effects
        
# split things up into different things
    # i.e. colossal attacks, colossal 

    #different move types (i.e. healing, attack, defense, things that change number of dice using)

ALL_TRAITS = [ALL_SIZE_TYPES, ALL_TRAVERSAL_TYPES, ALL_KAIJU_MOVES]
ALL_TRAITS_NAMES = [ALL_SIZE_TYPES_NAMES, ALL_TRAVERSAL_TYPES_NAMES, ALL_KAIJU_MOVES_NAMES]


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

      
        
