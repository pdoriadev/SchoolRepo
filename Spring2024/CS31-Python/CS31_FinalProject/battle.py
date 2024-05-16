import kaiju


class KaijuBattleInstance:
    _BASE_KAIJU: kaiju.Kaiju
    _health = -1
    _energy = -1
    _attackDiceBonus = 0
    _defenseDiceBonus = 0

    def __init__(self, kai: kaiju.Kaiju):
        self._BASE_KAIJU = kai
        self._health = kai.maxHealth
        self.baseDiceNumber = kai.sizeType + 1
        self._energy = kai.baseEnergy

    def getBaseKaiju():         return _BASE_KAIJU
    def getHealth():            return _health
    def getEnergy():            return _energy
    def getAttackDice():        return _BASE_KAIJU.BASE_ATTACK_DICE + _attackDiceBonus
    def getDefenseDice():       return _BASE_KAIJU.BASE_DEFENSE_DICE + _defenseDiceBonus
    
    def getStatuses():          return _statuses
    def getAvailableMoves():    return _availableMoves

    def setHealth(h: int): _health = h
    def setEnergy(e: int): _energy = e
    
   
        

class Referee:
    _kaijuInBattle = []
    
    _statuses = []
    _availableMoves = []
    _whoseTurn: KaijuBattleInstance

    def shuffleAvailableMoves(kai: kaiju.Kaiju):
        # TO-DO - rewrite to shuffle moves instead of giving all moves. 
        
        for i in range(0, len(_kaijuInBattle) - 1):
            _availableMoves[i] = _kaijuInBattle[i].getBaseKaiju().KAIJU_MOVESETS
            

        # if a status has beginnning of turn and end of turn effects. It effectively activates twice.
        # if those activations are at different times

    def addStatus(kai: kaiju.Kaiju, status: kaiju.Status):
        i = 0
        while True:
            if kai == _kaijuInBattle[i]:
                _statuses[i].append(status)
                break
    
    # activate all statuses with the given activation time
        # should statuses be activated in a certain order?
    def activateStatuses (activationTime: kaiju.ActivationTime, data: DamageData):
        for status in _statuses:
            match time:
                case kaiju.ActivationTime.START_TURN:
                    pass
                case kaiju.ActivationTime.END_TURN:
                    pass
                case kaiju.ActivationTime.ON_DAMAGE_TAKEN:
                    pass
                case kaiju.ActivationTime.ON_HIT_OPPONENT:
                    pass
                case kaiju.ActivationTime.ON_OPPONENT_HIT:
                    pass
                case kaiju.ActivationTime.ON_MISS:
                    pass
                case kaiju.ActivationTime.ON_OPPONENT_MISS:
                    pass
                case kaiju.ActivationTime.ON_MOVE_ACTIVATION:
                    pass
                case _:
                    assert("Case not accounted for")
                 
    def removeStatus():
        pass
     
    def __init__ (self, startingKaiju: []):
        self._kaijuInBattle = startingKaiju
        
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
    MOVE_OR_STATUS
    DAMAGE_TAKEN = 0
    DAMAGED_KAIJU: kaiju.Kaiju
    
    def __init__(self, moveOrStatus, damageTaken: int, damagedKaiju: kaiju.Kaiju): 
        self.MOVE_OR_STATUS = moveOrStatus
        self.DAMAGE_TAKEN = damageTaken
        self.DAMAGED_KAIJU = damagedKaiju

class BattleUIView():
    # if move activates
    # if damage taken
    # if new status happens
    # if status affect activates
    pass
                
def AIBattle(kaijuA, kaijuB):
    print()


def playerBattle(playerBaseKaiju, AIBaseKaiju):
    # Smaller kaiju goes first
    playerTurn = playerBaseKaiju.sizeType <= AIBaseKaiju.sizeType
    
    pKai = KaijuBattleInstance(playerBaseKaiju)
    aiKai = KaijuBattleInstance(AIBaseKaiju)

    while pKai.getHealth() > 0 and aiKai.getHealth() > 0:
        while (playerTurn):
            #TOD0 - shuffle move functionality
            print()
            availMoves = pKai.getAvailableMoves()
            i = 1
            for move in availMoves:
                print(str(i) + " " + move.name)
                
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
            
            # TODO - If kaiju out of energy, playerTurn = false
                
        else :
            pass


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
        

   