def getInputWordAndValidate(inputMessage):
    while True:
        str = input(inputMessage)

        # no input
        if (str.len() == 0):
            print("INVALID INPUT. Please input either letters, dashes, or spaces.")
            continue

        validCharPos = list()
            
        #find all spaces
        startSearchPos = 0
        while True:
            pos = string.find(' ', startSearchPos)
            if (pos == -1):
                break

            validCharPos.append(pos)
            startSearchPos = pos
            
        #find all dashes
        startSearchPos = 0
        while True:
            pos = string.find('-', startSearchPos)
            if (pos == -1):
                break
            
            validCharPos.append(pos)
            startSearchPos = pos
        
        # find all letters
        pos = 0
        while True:
            if(pos == str.len()):
                break

            if (str[pos].isalpha()):
                validCharPos.append(pos)

            pos+=1

        # If valid chars list's length is equal to string length,
        #   then all characters in string are valid. If valid chars
        #   list length is less than string length, then there 
        #   are invalid characters in the string. 
        # If the valid chars list's length is greater than the
        #   string length, then we have encountered some unexpected
        #   behavior.
        if (validCharPos.len() == str.len()):
            return str
        
        assert validCharPos.len() < str.len(), "Number of valid characters is greater than characters in string. IMPOSSIBLE. Must be logic issue."
            
        print("INVALID INPUT. Please input either letters, dashes, or spaces.")
        

def getInputDigitAndValidate(inputMessage):
    while True:
        dig = input(inputMessage)
        if (dig.isdigit()):
            return dig
        
        print("That is invalid input. Please enter a number")


game1Title = "To __, or not to __" 
game2Title = "Help me, ___, you're my only hope"
def gameDriver(name):
    print("\n\n")
    print("================================")
    print("\t WELCOME, " + name + "!")
        
    while True:
        choice = input ("\nWe have TWO silly games, here! That's just how silly we are. " \
                "\nInput the number next to the game's title to play it." \
                "\n\t1 - Game 1: " + game1Title + \
                "\n\t2 - Game 2: " + game2Title + \
                "\n\nGame Choice: ")
        if (int(choice) != 1 and int(choice) != 2):
            print("INVALID INPUT - That doesn't match any of the games we have - *you silly bean*.")
            continue

        break
    if (int(choice) == 1):
        print("=======================================")
        print("======== " + game1Title + " ==========")
        print("=======================================")

        
        verb1 = getInputWordAndValidate("Enter a verb:")
        verb2 = getInputWordAndValidate("Enter a verb:")
        noun1 = getInputWordAndValidate("Enter a plural noun: ")
        number1 = input("Enter a number: ")
        adjective1 = input("Enter an adjective: ")
        dangerItem1, dangerItem2 = input("Enter two *dangerous items* separated by a space: ").split()
        emotion1 = input("Enter an emotion: ")
        weapon = input("Enter a weapon: ")
        groupOfPeople1 = input("Enter any group of people: ")

        groupOfPeople1 = groupOfPeople[0].upper() + groupOfPeople1[1:]

        print("\nYOUR ORIGINAL STORY HAS BEEN PROCESSED")
        input("\nPRESS ANY KEY TO REAP THE REWARDS OF YOUR CREATIVITY")

        print("\n===================== YOUR ORIGINAL STORY =========================")
        
        print("To " + verb1 + ", or not to " + verb1 + ", that is the question:"                \
            "\nWhether 'tis nobler in the mind to suffer"                                       \
            "\nThe slings and arrows of outrageous fortune,"                                    \
            "\nOr to take arms against a sea of " + noun1 + ""                                  \
            "\nAnd by opposing end them. To die—to " + verb2 + ","                              \
            "\nNo more; and by a " + verb2 + " to say we end"                                   \
            "\nThe heart-ache and the " + number1 , adjective1 , "shocks"                       \
            "\nThat flesh is heir to: 'tis a consummation"                                      \
            "\nDevoutly to be wish'd. To die, to " + verb2 + ";"                                \
            "\nTo " + verb2 + ", perchance to dream—ay, there's the rub:"                       \
            "\nFor in that " + verb2 + " of death what dreams may come, "                       \
            "\nWhen we have shuffled off this mortal coil,"                                     \
            "\nMust give us pause—there's the respect"                                          \
            "\nThat makes calamity of so long life."                                            \
            "\nFor who would bear the " + dangerItem1 + " and " + dangerItem2 + " of time, "    \
            "\nTh'oppressor's wrong, the proud man's " + emotion1 + ","                         \
            "\nThe pangs of " + adjective1 + "  love, the law's delay,"                         \
            "\nThe insolence of office, and the spurns"                                         \
            "\nThat patient merit of th'unworthy takes,"                                        \
            "\nWhen he himself might his quietus make"                                          \
            "\nWith a " + adjective1,  weapon + "? Who would fardels bear,"                     \
            "\nTo grunt and sweat under a weary life,"                                          \
            "\nBut that the dread of something after death,"                                    \
            "\nThe undiscovere'd country, from whose bourn"                                     \
            "\nNo traveller returns, puzzles the will,"                                         \
            "\nAnd makes us rather bear those ills we have"                                     \
            "\nThan " + verb2 + " to others that we know not of?"                               \
            "\nThus conscience doth make " + groupOfPeople1 + " of us all,"                     \
            "\nAnd thus the native hue of resolution"                                           \
            "\nIs sicklied o'er with the pale cast of thought,"                                 \
            "\nAnd enterprises of great pith and moment"                                        \
            "\nWith this regard their currents turn awry"                                       \
            "\nAnd lose the name of action.")

    elif (int(choice) == 2):
        print("=======================================")
        print("== " + game2Title + " ==")
        print("=======================================\n")
        firstName = input("Enter a first name: ")
        lastName = input("Enter a last name: ")
        noun1 = input("Enter a noun: ")
        hostileForce = input ("Enter the name of what you consider a hostile force (fiction, or otherwise): ")
        againstHostile = input("Enter the name of something against the hostile force (fiction, or otherwise): ")
        vehicle = input ("Enter a vehicle: ")
        place = input("Enter a place: ")
        electronicDevice = input("Enter an electronic device: ")

        print("\nYOUR ORIGINAL STORY HAS BEEN PROCESSED")
        input("\nPRESS ANY KEY TO REAP THE REWARDS OF YOUR CREATIVITY")
        print("\n===================== YOUR ORIGINAL STORY =========================")
        
        noun1 = noun1[0].upper() + noun1[1:]
        hostileForce = hostileForce[0].upper() + hostileForce[1:]
        againstHostile = againstHostile[0].upper() + againstHostile[1:]
        place = place[0].upper() + place[1:]

        print("General " + lastName + ", years ago you served"              \
            "\nmy father in the " + noun1 + " Wars. Now he"                 \
            "\nbegs you to help him in his struggle"                        \
            "\nagainst the " + hostileForce + ". I regret that I"           \
            "\nam unable to present my father's"                            \
            "\nrequest to you in person, but my"                            \
            "\n" + vehicle + " has fallen under attack and I'm"             \
            "\nafraid my mission to bring you to"                           \
            "\n" + place + " has failed. I have placed"                     \
            "\ninformation vital to the survival of"                        \
            "\nthe " + againstHostile + " into the memory systems"          \
            "\nof this " + electronicDevice + ". My father will know"       \
            "\nhow to retrieve it. You must see"                            \
            "\nthis " + electronicDevice + " safely delivered to him"       \
            "\non " + place + ". This is our most"                          \
            "\ndesperate hour. Help me, " + firstName +                     \
            "\n" + lastName + ", you're my only hope.")

print("\n========================== THE END ===============================")
input("\nPress any key to continue.")
    