import kaiju
from abc import ABC

class AbstractStatus(ABC):
    def activate(kaiju: kaiju.Kaiju):
        pass

class BurningStatus(AbstractStatus):
    burningDamage = -1
    def activate (kaiju: kaiju.Kaiju):
        kaiju.takeDamage(burningDamage, "BURNING STATUS")

    def __init__(_burningDamage):
        burningDamage = _burningDamage


class AbstractMove(ABC):
    def activate(kaiju: kaiju.Kaiju):
        pass

class AtomicBreath(AbstractMove):
    cost = 3
    additionalDice = -1
    def activate(targetKaiju: kaiju.Kaiju):
        targetKaiju.takeDamage()

    def __init__(_cost, _additionalDice):
        cost = _cost
        additionalDice = _additionalDice

class KaijuBattleInstance:
    _BASE_KAIJU = None
    _health = -1

    _statuses = []
    _statusTime = []

    _availableMoves = []

    def __init__(_kaiju):
        baseKaiju = _kaiju
        maxHealth = kaiju.SIZE_TYPE_IN_METERS(_kaiju.sizeType)
        health = maxHealth
        baseDiceNumber = baseKaiju.sizeType + 1

    def getBaseKaiju():         return _BASE_KAIJU
    def getHealth():            return _health
    def getAvailableMoves():    return _availableMoves
    def getStatuses():          return _statuses

    def shuffleAvailableMoves():
        print()

    def takeDamage(amount: int):
        pass
    
    def heal(amount: int):
        pass
    



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
                
def AIBattle(kaijuA, kaijuB):
    print()



def playerBattle(playerKaiju, AIKaiju):
    print()
    # Smaller kaiju goes first
    playerTurn = playerKaiju.sizeType <= AIKaiju.sizeType

    while playerKaiju.getHealth() > 0 and AIKaiju.getHealth() > 0:
        if (playerTurn):
            playerKaiju.shuffleAvailableMoves()
            print(playerKaiju.getAvailableMoves.split())
        else :
            print()


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
        

   