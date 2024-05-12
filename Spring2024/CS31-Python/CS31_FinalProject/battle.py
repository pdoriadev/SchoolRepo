import kaiju

class KaijuBattleInstance:
    m_maxHealth
    m_health 
    
    baseKaiju 

    def __init__(_kaiju):
        baseKaiju = _kaiju
        m_maxHealth = kaiju.SIZE_TYPE_IN_METERS(_kaiju.sizeType)
        m_health = m_maxHealth


   #TO-DO: Moves or traits based on number of legs, arms, or heads. 
    #Or maybe it's just a multiplier? i.e. legs faster, arms more damage, heads more vision, 
        # heads multi-attack if using a bite or something like that