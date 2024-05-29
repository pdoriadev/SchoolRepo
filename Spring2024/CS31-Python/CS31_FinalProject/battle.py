# import curses.ascii
import kaiju
import random
import time

from utils import simulatedTypePrinting

####################################################################
# Instance class for given kaiju. Takes base kaiju data. From there,
#   generates, stores, and transforms whatever data a kaiju needs 
#   for battle
class KaijuBattleInstance:
    _BASE_KAIJU :kaiju.Kaiju
    _health = -1
    _attackDiceBonus = 0
    _defenseDiceBonus = 0

    def __init__(self, kai):
        self._BASE_KAIJU = kai
        self._health = kai.MAX_HEALTH
        self.baseDiceNumber = kai.SIZE_TYPE + 1

    def getBaseKaiju(self):         
        return self._BASE_KAIJU
    def getHealth(self):            
        return self._health
    def getAttackDice(self):        return self._BASE_KAIJU.BASE_ATTACK_DICE + self._attackDiceBonus
    def getDefenseDice(self):       return self._BASE_KAIJU.BASE_DEFENSE_DICE + self._defenseDiceBonus
    
    def getAvailableMoves(self):    return self._BASE_KAIJU.KAIJU_MOVESETS

    def takeDamage(self, d: int): 
        if (self._BASE_KAIJU == 2):
            self._health -= d * 2
        else:
            self._health -= d


#################################################################################################################
# Kaiju Battle System - turn-based
#       -- Each round has one attacker and one defender.
#           
#       -- Dice: D6
#       -- Kaiju Stats 
#           - Health
#           - Size
#               > starting kaiju
#               > number of attack and defense dice 
#    
#       -- One 'move' per turn
#           - Moves pulled from different traits (All moves are the same right now. Ran out of time.)
#    
#       -- Attacking Result = Attack - Defend
#           - Positive number = SUCCESS
#           - 0 or less = FAIL   
#           - Attack Roll: (Number of dice * (size+1) do a Dice Roll + special state from moves 
#           - Defend Roll: (Number of dice * (number of sizes - size)) do a Dice Roll + special state from moves
#   
def doBattle(playerBaseKaiju: kaiju.Kaiju, AIBaseKaiju: kaiju.Kaiju, isAIBattle: bool):
    print("\n" * 5)
    
    # Generating kaiju that can be used for battle
    kaiInBattle = [KaijuBattleInstance(playerBaseKaiju), KaijuBattleInstance(AIBaseKaiju)]
    # Smaller kaiju goes first
    attackingKai: int = 0 if (kaiInBattle[0].getBaseKaiju().SIZE_TYPE > kaiInBattle[1].getBaseKaiju().SIZE_TYPE) else 1

    roundNum = 0
    
    ############################################
    # Battle Loop
    while kaiInBattle[0].getHealth() > 0 and kaiInBattle[1].getHealth() > 0:
        
        ############################################
        # Battle UI generation
        roundNum +=1
        simulatedTypePrinting("\n=========================================================\n")
        simulatedTypePrinting("ROUND " + str(roundNum) + "\n", 20)

        simulatedTypePrinting("~" + " " * 6 + "ATTACKING" + " " * 6 + "~"    + " " * 6 +     "~" + " " * 6 + "DEFENDING" + " " * 6 + "~" + "\n", 10)
        simulatedTypePrinting("[" + " " * 6 + kaiInBattle[attackingKai].getBaseKaiju().NAME + " " * 10 + "]"     + " " * 6 +     "[" + " " * 6 + kaiInBattle[attackingKai - 1].getBaseKaiju().NAME + " " * 6 + "]\n", 10)
        time.sleep(0.3)
        simulatedTypePrinting("HEALTH: " + str(kaiInBattle[attackingKai].getHealth()) + " / " + str(kaiInBattle[attackingKai].getBaseKaiju().MAX_HEALTH) +  " " * 10 + " " * len(kaiInBattle[attackingKai].getBaseKaiju().NAME)      \
                            + "HEALTH: " + str(kaiInBattle[attackingKai - 1].getHealth()) + " / " + str(kaiInBattle[attackingKai - 1].getBaseKaiju().MAX_HEALTH) + "\n", 5)
        simulatedTypePrinting(kaiInBattle[attackingKai].getBaseKaiju().CONFIGURATION    + " " * len(kaiInBattle[attackingKai].getBaseKaiju().NAME) +   kaiInBattle[attackingKai - 1].getBaseKaiju().CONFIGURATION + "\n\n", 5)

        time.sleep(0.3)
        ############################################
        # Move selection
        choice = ""
        if (isAIBattle == False and attackingKai == 0):
            numberOfMoves = 0
            for movesets in kaiInBattle[0].getAvailableMoves():
                for move in movesets:
                    numberOfMoves+=1
                    simulatedTypePrinting(str(numberOfMoves) + " " + move + "\n", 5)
             
            while choice == "":
                simulatedTypePrinting("Select your move (input the corresponding number): ", 10)
                choice = input()
                if (choice.isdigit() == False):
                    choice = ""
                    simulatedTypePrinting("Invalid input. You must input a number.\n")
                    continue

                if (numberOfMoves < int(choice) or int(choice) < 1):
                    choice = ""
                    simulatedTypePrinting("Invalid input. Input a number that corresponds to a move.\n")
                    continue
        else:
            choice = random.choice(random.choice(kaiInBattle[1].getAvailableMoves()))
        
        ###############################################
        # Attacker's dice roll sequence    
        simulatedTypePrinting(kaiInBattle[attackingKai].getBaseKaiju().NAME + " chooses " + choice + "\n", 5)
        time.sleep(0.3)
        simulatedTypePrinting("\n" + kaiInBattle[attackingKai].getBaseKaiju().NAME + " ROLLS FOR ATTACK\n", 10)
        time.sleep(0.3)

        attackResult = 0
        sleepTime = 1 / kaiInBattle[attackingKai].getAttackDice() 
        for i in range(0, kaiInBattle[attackingKai].getAttackDice()):
            for i in range (0,3):
                print(" .", end = "")
                time.sleep(sleepTime)
            roll = random.choice(range(1,7,1))
            attackResult += roll
            print(" " + str(roll), end = "")
                
        time.sleep(0.3)
        simulatedTypePrinting("\nTOTAL ATTACK: ", 5)
        time.sleep(0.3)
        simulatedTypePrinting(str(attackResult) + "\n", 20)
                
        ###############################################
        # Defender's dice roll sequence
        simulatedTypePrinting("\n" + kaiInBattle[attackingKai - 1].getBaseKaiju().NAME + " ROLLS FOR DEFENSE\n", 10)
        defenseResult = 0
        sleepTime = 1 / kaiInBattle[attackingKai - 1].getDefenseDice()
        for i in range(0, kaiInBattle[attackingKai - 1].getDefenseDice()):
            for i in range (0,3):
                print(" .", end = "")
                time.sleep(sleepTime)
            roll = random.choice(range(1,7,1))
            defenseResult += roll
            print(" " + str(roll), end = "")

        time.sleep(0.3)
        simulatedTypePrinting("\nTOTAL DEFENSE: ", 5)
        time.sleep(0.3)
        simulatedTypePrinting(str(defenseResult) + "\n", 20)
        
        #############################################
        # Attack result
        result = attackResult - defenseResult
        if (result > 0):            
            kaiInBattle[attackingKai - 1].takeDamage(result)
            simulatedTypePrinting("\n" + kaiInBattle[attackingKai - 1].getBaseKaiju().NAME + " takes " + str(result) + " damage!\n", 5)
        else:
            simulatedTypePrinting("\n" + kaiInBattle[attackingKai].getBaseKaiju().NAME + " misses.\n" + kaiInBattle[attackingKai].getBaseKaiju().NAME + " scrapes the ground.\n", 5)            

        #############################################
        # Switch turns    
        match attackingKai:
            case 0:
                attackingKai = 1
            case 1:
                attackingKai = 0          
                
    ###################################################
    # Victory UI        
    victor = -1
    for i in range(0, 2):
        if (kaiInBattle[i].getHealth() > 0) :
            victor = i
     
    simulatedTypePrinting("\n====================================================================\n")  
    simulatedTypePrinting(kaiInBattle[victor].getBaseKaiju().NAME + " IS VICTORIOUS!\n")
    simulatedTypePrinting("====================================================================\n")
    time.sleep(0.4)
    
    return victor
            
###############################################################################
# Unused Ideas / Code
###############################################################################

# All moves available to kaiju (unless a random event opens a new move)
    # exist in the base kaiju

# Give the kaiju to the status. The status then applies everything to the kaiju. 
    # Each status could have an "Activate" function that gets called every round    
        # Each status has limited number of activations. 
        # Upon activating, tells kaiju what to do / effects kaiju state. 
        # Kaiju has reference to the status within itself.

   #

   #TO-DO: Moves or traits based on number of legs, arms, or heads. 
    #Or maybe it's just a multiplier? i.e. legs faster, arms more damage, heads more vision, 
        # heads multi-attack if using a bite or something like that
        # Maybe cut legs, arms, heads from battle system? 

   #FUN TO-DO: random events
        # a random, already generated kaiju attacks 
        # a random, already generated kaiju helps one of you
        # helicopter glides by high above you
        # The people running below scream your name in terror: "_Your name_!"
        # The people recognize X as the good guy. Y is the bad guy.
        # The military has launched an attack. They will arrive in X turns.
            # Once they arrive, random roll to see if they do damage
        # The military has taken control of _Insert kaiju_, they will arrive
            # in X turns
            # Once they arrive, random roll to see if they do damage. 
        # Climate Change strikes, the city has flooded!
    
class DamageData():
    MOVE_OR_STATUS = 0
    DAMAGE_TAKEN = 0
    DAMAGED_KAIJU = 0
    
    def __init__(self, moveOrStatus, damageTaken: int, damagedKaiju): 
        self.MOVE_OR_STATUS = moveOrStatus
        self.DAMAGE_TAKEN = damageTaken
        self.DAMAGED_KAIJU = damagedKaiju

class BattleUIView():
    # if move activates
    # if damage taken
    # if new status happens
    # if status affect activates
    pass

 # TO-DO - Smart AI
         # Knows not to use certain moves with certain HP level (i.e. moves that sacrifice half health)
            
# TODO - Lower sleep / faster roll-time for smaller kaiju

# TODO - speed-up mode for testing (no sleeps)

# TODO - If roll total is greater than opponent's roll, cancel rest of rolls. 

# TODO - Keep track of number of rounds

# TOOD - Sweet spot roll inputs like in Super Mario RPG. Gives +1 to roll. 

#TOD0 - shuffle move functionality
# print()
# availMoves = pKai.getAvailableMoves()
# i = 1
# for move in availMoves:
#     print(str(i) + " " + move.name)
                
# TODO - input validation loop
            
# TODO - select move
    # should include all information to execute that move
    # move should include description
        # Type number next to move plus "D" (i.e. )
            
# TODO - get move and kaiju data related data for dice rolls and DC
            
# TODO - Dice rolls. Calculate result. 
    # UI sequence    
            
# TODO - If result is success, activate move.
    # UI to show success - keep as simple as possible. Just text.
    # Kaiju should activate any hit-related statuses    
            
# TODO - If result is failure, miss. Activate any miss-related statuses.
            
# TODO - If kaiju out of energy, attackingKai = false
            



    # Maybe have battle on a timer?? Player has to decide move in X time. 

    # # It's _____'s turn!
    # Randomly generate moveset for this round? Are moves just cards?
        # yes. 
        # each kaiju has X energy per round. Each move expends X energy? 
        # Can do as many moves as they want until they run out of energy. 
        # Turn ends when they run out of energy or choose to end their turn.

    # If Player Kaiju's Turn
        # Look through moves
            # TO-DO - should have move description
        # Select move
            # Calculate move result
        # Do move
    # else If AI's turn
        # AI pause for anticipation(like "KAIJU_NAME is thinking..." then do action.)
        # Randomly select move
            # Calculate move result
        # Do move
    # Switch turns unless a kaiju's health is at or below 0
    
    # If kaiju has fallen, do kaiju has victory / defeat sequence

    # TO-DO: Design note -- need to keep scale of kaiju in player's heads. Either text or visual. 
        # Always insert the kaiju's size when they do something or when their name is displayed

    # Show both kaiju's health and energy?

    # TODO - output battle logs to a file.
        

       # TO-DO - Run in auto-test mode - auto-battles a given number of kaiju. Battle outcome and stats are
        # saved to a file.
        # Battle stats
            # Which moves did most damage
            # Did certain moves do more damage when preceded by 
        # Different test types
            # Test x configurations vs y configurations