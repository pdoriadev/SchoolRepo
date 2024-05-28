# car = "PORSCHE"
# color = "red"
# my_car = car.join(color)
# print(my_car)

# ?
# arr = ["ki", "qu", "ro", "bi", "kn", "pa"]
# arr.sort()
# print (arr)

#4

import csv
with open('eggs.csv', 'w', newline='') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=' ',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
    spamwriter.writerow(['Spam'] * 5 + ['Baked Beans'])
    spamwriter.writerow(['Spam', 'Lovely Spam', 'Wonderful Spam'])


import math

# print(math.floor(19.95))

data = [5,10, 15, 20, 25, 30, 34, 40]
print(data[-4:-2]) 

# print(3**2)
# print (3*2)
for week in range(1, 5):
    print(week) 

print (-3 ** 2)

val = False
print(val)

# logical operation precedence
# 1. not
# 2. and
# 3. or

print("\nFormatted Percent Strings")
percentNum = .15605
print("{:.2%}".format(percentNum))
print("{:.0%}".format(percentNum))

print("\nFormatted Decimal Strings")
numWithDec = 3237945.76
print("{:,.2f}".format(numWithDec))
print("{:.2f}".format(numWithDec))
print("{:,.4f}".format(numWithDec))
print("{:25,.9f}".format(numWithDec))

print("\nUnicode Char Conversion")
char = 'a'
print ("char == a")
matchingUnicode = ord(char)
print ("char's matching unicode int = " + str(matchingUnicode))
print("Convert unicode back to char = " + chr(matchingUnicode))

print("\nExceptions. File not found.")
import csv
import sys
FILENAME = "names.csv"
try:
    names = []
    with open(FILENAME, newline="") as file:
        reader = csv.reader(file)
        for row in reader:
                names.append(row)
except FileNotFoundError as e:
    print ("Could not find " + FILENAME + " file.") 
    sys.exit()
except Exception as e:
    print (type(e), e) 
    sys.exit()
print(names)




