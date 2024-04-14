
# A new marketing company is launching a new product or service for their website and want you to code a prototype FAKE Artificial Intelligence (AI) ChatBot for them. 
# Simulate a "sales conversation" with a customer who will be purchasing the product or service from your ChatBot.

# Your code must do the following:

#     Only use code statements that you have learned so far from Chapters 1 - 3 of our textbook. 
#     Greet your customer and introduce the ChatBot.
#     Before starting the "conversation" ask the user if they would like to learn more about a specific product or service. 
#       If they say yes, proceed to tell them about your product or service. If they say no, end the conversation and provide a farewell. 
#     Build this chat conversation around a specific product or service. Provide a paragraph overview of your product or service.
#        Be creative - make some stuff up. Have a fun and engaging "conversation" with your user. Output the overview to the screen with a nice formatting of your choice - for example, break up a long overview into multiple lines. Make this as serious or as silly a scenario as you want it to be. This is an important step to "SELL" the product or service.
#     Ask if the user would be interested in purchasing your product or service. Build this around an if statement. 
#       If yes - continue with the sales conversation. If no, provide a closing statement and farewell.

# Closing the Sale

#     Ask for the customer's first and last name. Store the values input to separate variables such as firstName and lastName.
#     Ask for their email address. Store the value input to a variable. Don't worry about validating the format of the input.
#     Ask for their phone number.  Store the value input to a variable. Don't worry about enforcing formatting on the input. 
#     Ask for how many of the product/service they would like to purchase. Be sure to tell the customer how much the product/service costs BEFORE asking how many they would like to purchase. Store the values input to a variable.
#     Calculate and display their current total based on the quantity they would like to purchase. Store the values input to a variable.
#     Apply 10% tax for the total bill. 


# Peter Doria, 3/27/2024, Project 1 - Fake AI "Sales Chatbot"
# Difficulty: Not too bad

price = 99.99
tax = 1.1
isValuedSourceOfCashFlow = True
vibesCheckerTM = "\"Vibes Checker TM\""

#Get customer's information
print("\n=============================================================================\n")
firstName = input("Hello there, \"Valued Source of Cash Flow\". Welcome to VibesCorp." + 
       "\n\n\nBefore we enter a transaction that will give both of us equal happiness and I, with more money, please tell us your first name: ")
lastName = input("And your surname, \"Valued Source of Cash Flow\"? ")
print("Thank you, \"Valued Source of Cash Flow\". We have your name.")
print("\n------------------------------------------\n")

email = input("\nHow about your email address? Selling information is what puts a real " 
              "\n\tgenuine smile on our bottom-- I MEAN - *face*. ")
print("\n------------------------------------------\n")
phone = input("\nHow about your personal cell phone number? 'If it ain't personal, then it ain't worth it, " 
              " \n\tam I right'? ")
print("\n------------------------------------------\n")


choice = input ("\nNow then, you're a good person, right? Our \"Vibes Checker TM\" " 
                "\n\tchecks the vibes of people around you *and yourself*." 
                "\n\t It lets you know who's safe to associate with *before* the pressure of society - LOL! " 
                "\n\t Would you like a product description? Enter \"n\" for no. Enter anything else for yes: ")

#  Describe product to customer.
loop = 0
while (choice.lower() != "n" and loop < 3):
    if(loop == 0) :
        print(    " \n\t Ever get up in the morning and just think: \"I just don't look right, today. People will see my vibe.\"" 
                  " \n\tNow, with the \"Vibes Checker TM\", you can leave the safety of your own home with confidence." 
                  " \n\tBefore you leave your house, take a picture of yourself with your \"Vibes Checker TM\" and listen for the *Happy Beep*." 
                  " \n\tWhen you hear the *Happy Beep*, you're ready to go outside your home with a vibe that is safe for the approval of others."
                  " \n\tIf you hear the *Sad Beep*, "
                  " \n\t\t your vibe just isn't right, "
                  " \n\t\t\t and it's time to change it up. ;)"
                  " \n\n\tDo you want to know how to avoid *non-ideal* co-worker relationships?")
    if (loop == 1) :
        print(    " \n\tIf you want to make sure your new co-worker passes the vibe check, take your \"Vibes Checker TM\" and take a selfie with them." 
                  " \n\tIf you hear the *Happy Beep*, you know your vibes are compatible. "
                  " \n\tIf you hear a *Sad Beep*, that new coworker just isn't right for you ): " 
                  " \n\t-- and maybe isn't right for the company. " 
                  " \n\tMaybe you should talk to HR about it? (:"
                  " \n\n\tDo you want to know how to avoid romantic relationships based on the aggregate moral standing of the day?\t" )
    if (loop == 2) :         
        print(    " \n\tNot sure if your sibling's new significant other is right for them? \"Vibes Checker TM\" will sort it out! No need for " 
                  " \n\thonest conversations when you have the \"Vibes Checker TM\" to sus out who's right for you - for the rest of your life.")
    
    if (loop < 2):
        choice = input("\tEnter \"n\" for no. Enter anything else for yes: ")
    else:
        choice = input("\n\n\tInput any key to continue.")
     
    loop+=1
    
    
    print("\n------------------------------------------\n")
    

print("The \"Vibes Checker TM\" is at a low low price of" 
      " $" + str(price) + " per year - in perpetuity - and will adjust for inflation.")

print("\n------------------------------------------\n")

choice = input("\n\n\t Input any key to continue.")

print("\n------------------------------------------\n")

# Answer customer questions
questions = [ "What is the " + vibesCheckerTM + "'s competetive price-point?"
           ,"What powers the innovative technology of the " + vibesCheckerTM + "?"
           ,"Can the " + vibesCheckerTM + " vibe-check my fashion?"
           ,"Can the " + vibesCheckerTM + " vibe-check my personal items?"
           ,"How is this legal?"]

answers = ["The \"Vibes Checker TM\" is at a low low price of" \
            " $" + str(price) + " per year - in perpetuity - and will adjust for inflation."
           ,"The " + vibesCheckerTM + " is powered by cutting edge image-recognition technology." \
           "\n\tWith just one photo, the " + vibesCheckerTM + " cross-checks against VibesCorp relevant databases " \
           "\n\tlike those used by large social credit firms (i.e. facebook, twitter, instagram, etc.) " \
           "\n\tto infer who is in the picture. Using this information, " + vibesCheckerTM + \
           "\n\tcreates a base-level identity profile and cross-checks that against the aggregate" \
           "\n\tmoral standing of the day using our proprietary 'how to judge while posturing' software." 
           ,"Yes! Any images that include you wearing clothes will be instantly vibe-checked " \
           "\n\t for your own confidence."
           ,"Yes! Any images that include discrete personal items will be instantly vibe-checked " \
           "\n\t so you know what to keep under wraps around other Source of Cash Flows - or, better " \
           "\n\t yet, you can leave your discrete personal items behind at a designated VibesCorp drop-off " \
           "\n\t location for those with the appropriate social credit level."
           , "It doesn't matter *how* it's legal, just know that it *is* legal, and " \
           "\n\tyour representatives use technology like the " + vibesCheckerTM + \
           "\n\t as instrumental pieces of their competitive re-election strategy." ]

print("\n\tHere are some common questions other Valuable Source of Cash Flows have:" )
loops = 0
while(loops < len(questions)):
    if (loops < 2):
        print("\n\t  1: " + questions[0] +\
              "\n\t  2: " + questions[1] +\
              "\n\t  3: " + questions[2] +\
              "\n\t  4: " + questions[3])
    else:
        print("\n\t  1: " + questions[0] +\
              "\n\t  2: " + questions[1] +\
              "\n\t  3: " + questions[2] +\
              "\n\t  4: " + questions[3] +\
              "\n\t  5: " + questions[4])
    
    choice = input ("\n\tPlease input the question's corresponding number (i.e. '1', '2')." + \
                    "If you have no further questions, input anything else: ")
    
    print()
    if(choice == "1"):
        print("\nQUESTION: " + questions[0] + \
              "\nANSWER: " + answers[0])
    elif(choice == "2"):
        print("\nQUESTION: " + questions[1] + \
              "\nANSWER: " + answers[1])
    elif(choice == "3"):
        print("\nQUESTION: " + questions[2] + \
              "\nANSWER: " + answers[2])
    elif(choice == "4"):
        print("\nQUESTION: " + questions[3] + \
              "\nANSWER: " + answers[3])
    elif(choice == "5"):
        print("\nQUESTION: " + questions[4] + \
              "\nANSWER: " + answers[4])
    else: 
        break
    
    loops+=1;
    print("\nDo you want to know more?")
    print("\n------------------------------------------\n")


print("\n------------------------------------------\n")

# Get quantity from customer
quantity = input("Please input the number of " + vibesCheckerTM + "'s you'd like to purchase: ")


# Upsell
attempts = 0
while (int(quantity) < 2 and int(attempts) < 3):
    print()
    if (attempts == 0):
        if (int(quantity) == 1) :            
            print("Are you sure you don't need more than " + str(quantity) + " \"Vibes Checker TM\"? "
                  "\"Vibes Checker TM\" is an incredible social value asset.")
        else:
            print("Come on! I know you don't mean that. Special people always find an essential use for \"Vibes Checker TM\"! " \
                    " Aren't you special?")
    elif (attempts == 1):
        print("\n Remember: We at VibesCorp are good people. We help people in commercials, and our " \
                    "paid actors are as happy as you could ever wish you were. Help us - help you - buy more.")
    elif (attempts == 2):
        print("\n\tAn independently conducted study we financed says this: " \
                    "\n\t\"People identified as \"hip\" or \"with it\" buy an additional 'Vibes Checker' for their kids " \
                    "\n\t so they can brag about it to their \"friends\".\" \n\n You're hip, right?")
        
    quantity = input("\n\nHow many \"Vibes Checker TM\"s will you buy (:   ")  
    
    attempts+=1

# "Thank you" messages
print()
if (int(quantity) == 0 ) : 
    print ("I thought you were coooool... Don't you want to contribute to our bottom line - to society?")
    isValuedSourceOfCashFlow = False
elif (int(quantity) == 1)  :
    print("Weird. I thought you were different... I guess you're not \"Valued Source of Cash Flow\". You're just just... "\
            "\"Source of Cash Flow\".")
    isValuedSourceOfCashFlow = False
elif (int(quantity) == 2) :
    print("Ah, I knew you were different from the others, \"Valued Source of Cash Flow\". " 
          "\n\t Special thanks from VibesCorp.")
elif (int(quantity) > 2) :
    print("A whale! -I MEAN- Thank you \"Valued Source of Cash Flow\".")
    
input ("\n\tInput any key to continue")
    
print("\n------------------------------------------\n")


# Calculate subtotal and total amounts
subtotal = round(price * float(quantity), 2)
total = round(subtotal * tax,2) 
print("\n Your total due is: $" + str(total) + "." )

#Receipt output
print("\n\n================================================================")
print("\n\n\t\tVibesCorp\n\n")
if (isValuedSourceOfCashFlow):
    print("\n\tVSCF:\t\t\t" + firstName + " " + lastName)
else :
    print("\n\tSCF:\t\t\t" + firstName + " " + lastName)
print("\n\tPhone:\t\t\t" + phone)
print("\n\tEmail:\t\t\t" + email)
print("\t---------------------------------")
print("\n\n\t2  \"Vibes Checker TM\"\t $" + str(price))
print("\t---------------------------------")
print("\n\n\tSubtotal:\t\t $" + str(subtotal))
print("\n\n\tTax:     \t\t " + str(tax) + "%")
print("\n\n\tTotal:   \t\t $" + str(total))
print("\n\n================================================================")

# Farewell messages
if (isValuedSourceOfCashFlow):
    print("\n\n And remember, \"Valued Source of Cash Flow\" - we love you - tand will pressure you to buy products based on politically " 
          "\n\tconvenient lucrative moralities based on your purchase preferences and PII's (Personal Identifiable Information) like "
          "\n\twhat country you live in, search history, where you drive every day, 'How fast are you driving?', etc. - because we care "
          "\n\t - about our share price.")


print("\n\nVibesCorp will remember your moral contribution.")

if (isValuedSourceOfCashFlow):
    print ("\n\nTil next time, Valued Source of Cash Flow.")
else:
    print ("\n\nTil next time, 'Source' of Cash Flow.")
print("\n======================================================================================================================================")
