# You will modify the Create Account program so that the program gets a valid 
#   email address and phone number. Use the starting Trinket file to complete 
#   this Lab Activity. Follow the instructions carefully and test as you go along. 

# Alternately, if you are using your local computer for development, open the 
#   mpg_write.py file in the following folder: 
#   murach_python > exercises > ch10 > create_account.py from the downloaded 
#   textbook files. Note: You will still need to use the starting Trinket 
#   code and submit your project through Trinket for review. 

#     Review the code and run the program so that you understand the starting point. 
#     
#     Create and use a function to get a valid email address. To be valid, the 
#       address has to contain an @ sign and end with ".com" -- I do realize 
#       that email addresses can end in something other than .com, let's just 
#       pretend here for this exercise that .com is the only one. :) 
#     
#     Create and use a function to get a valid phone number. To do that, remove 
#       all spaces, dashes, parentheses, and periods from the number. Then, check 
#       to make sure that the phone number consists of 10 characters that are digits. 
#     
#     When all of the entries are valid, display a message similar to the one in the 
#       example, including the phone number format that uses dots to group the digits. 
#     
#     You have creative license for the display/text and validation messages in this 
#       program. As long as you are using functions and calling them to validate your 
#       email and phone number, and outputting the formatted phone number, we are good! 

#     Ensure that you have a title/greeting in your output. 
#     Be sure to have an exit message too. 

#     Test and debug the program to make sure it works. 
#     Be sure to comment your code to explain the process. Include your name, date, class and assignment name in the comments at the top of the program. 

# Example output:

# Account Validation Program

#   Enter full name:          Joel Murach
#   Enter password:           password12345
#   Enter email address:      joelmurach.com
#   Please enter a valid email address.
#   Enter email address:      joel@murach.com
#   Enter phone number:       (555) 555-555
#   Please enter a 10-digit phone number.
#   Enter phone number:       (555) 555-SPAM
#   Please enter a 10-digit phone number.
#   Enter phone number:       (555) 555-5555

#   Hi Joel, thanks for creating an account.
#   We'll text your confirmation code to this number: 555.555.5555

# Starting file for Exercise 10-1

         
    
def inputFullName():
    while True:
        name = input("Enter full name:       ").strip()
        if " " in name:
            return name
        else:
            print("You must enter your full name.")
    
def getFirstName(fullName):
    index1 = fullName.find(" ")
    firstName = fullName[:index1]
    return firstName
    
def inputPassword():
    while True:
        digit = False
        cap_letter = False
        password = input("Enter password:        ").strip()
        for char in password:
            if char.isdigit():
                digit = True
            elif char.isupper():
                cap_letter = True
        if digit == False or cap_letter == False or len(password) < 8:
            print(f"Password must be 8 characters or more \n"
                  f"with at least one digit and one uppercase letter.")
        else:
            return password
        

# ends with .com
# includes @ symbol
# text before @ symbol
# text in-between @ symbol and .com     
# one '.'. Must be before "com"   
def inputEmail():
    while True:
        email = input("Enter email:        ").strip()
        
        # .com is four characters. @ symbol is one.
        # There must be at least one letter on each side of the
        #   @ symbol. Therefore, a valid email address has at least
        #   seven characters. 
        if (len(email) < 7):
            print("Email format is incorrect. Follow the following format: " \
                  "\n\t youremail@hostingsite.com")

        if (email[-4:-1] + email[-1] != ".com"):
            print("Email format is incorrect. Email must end with \".com\"")
            continue
        
        dotPos = email.find('.')
        if (email[dotPos] != email[-4]):
            print("Email format is incorrect. Only period should be in \".com\" at the end.")
            
        atSymbolPos = -1
        atSymbolPos = email.find('@')
        if (atSymbolPos == -1):
            print("Email format is incorrect. Email must include @ symbol")
            continue
        
        if (atSymbolPos == 0):
            print("Email format is incorrect. Missing 'youremail' in the format. Follow" \
                  "\n the following format: " \
                  "\n\t youremail@hostingsite.com")
            continue
            
        return email

def inputPhoneNumber():
    phone = ""
    while True:
        phone = input("Enter phone number:        ").strip()
        for char in " -()./":
            # replace each bad character with nothing
            phone = phone.replace(char,"") 
        if (len(phone)) != 10 or phone.isdigit() == False:
            print("Phone number is invalid. Please enter a 10-digit phone number.")
        break
    
    phone = phone[0:3] + "." + phone[3:6] + "." + phone[6:]
    return phone        
        
def main():
    fullName = inputFullName()
    print()
    
    password = inputPassword()
    print()
    
    email = inputEmail()
    print()
    
    phone = inputPhoneNumber()
    print()

    firstName = getFirstName(fullName)   
    print(f"Hi {firstName}, thanks for creating an account.")    
    print(f"We will text your confirmation code ot this number: {phone}.")

if __name__ == "__main__":
    main()






