
#                                   Exercise 7-1
# 1. You will modify the Miles Per Gallon program so that it stores the input data
#       for each calculation in a CSV file. (How exciting!) Then you will use this 
#       program file to complete Exercise 7-2.  
# 2. The program output will not need to have any edits made to the display 
#       input/output. Everything you add will be behind the scenes. 
# 3. Review the code and run the program so that you understand the starting point. 
# 4. Enhance the program so that it creates a simple two-dimensional list. You 
#       should be saving the distance, gallons, and calculated MPG in each row of 
#       the list. 
# 5. Enhance the program so that it saves the data from the list (for all inputs) 
#       in a file named trips.csv. Do not save the data until the user is done 
#       inputting values. 
# 6. Test the program to make sure it works. You can view the .csv file in REPL's 
#       code editor or an associated program like Notepad or Excel if you are 
#       working with a local code editor on your computer.

#                                   Exercise 7-2
# Follow the instructions in the book to create the following functions:
#   1.  write_trips() which is similar to the function created in program 1. 
#           Writes data from two-dimensional list that's passed to it as an
#           argument. The list contains the data for each trip entered, and it
#           should be written to a CSV file named trips.csv. As the console above
#           shows, the data for each trip consists of miles driven, gallons of gas
#           used, and the calculated MPG value. Be sure to write the trip after 
#           every input.
#   2.  read_trips() that will read the data in the existing trips.csv file and store 
#           to the trips list before asking for any additional inputs.
#   3.  list_trips() which will display the data in the trips list before adding any 
#           trips to the list.                                 

import csv

def get_miles_driven():
    while True:
        miles_driven = float(input("Enter miles driven :     "))                    
        if miles_driven > 0:       
            return miles_driven
        else:
            print("Entry must be greater than zero. Please try again.\n")
            continue
    
def get_gallons_used():
    while True:
        gallons_used = float(input("Enter gallons of gas:     "))                    
        if gallons_used > 0:       
            return gallons_used
        else:
            print("Entry must be greater than zero. Please try again.\n")
            continue
        
def read_trips():
    trips = []
    with open("trips.csv", 'r') as tripsCSV:
        reader = csv.reader(tripsCSV)
        for line in reader: 
            trips.append(line)
    
    return trips

def list_trips(tripsList):
    print("============= Past Trips List ============")
    print("Distance         Gallons         MPG")
    for trip in tripsList:
        # print("Miles: " + str(element[0]) + ", Gallons: " + str(element[1]) + ", MPG: " + str(element[2]))
        print(f"{trip[0]} \t\t {trip[1]} \t\t {trip[2]}")        

def write_trips(tripsList):
    with open("trips.csv", 'w') as tripsCSV: 
        writer = csv.writer(tripsCSV)
        writer.writerows(tripsList)
            
def main():
    # display a welcome message
    print("==== The Miles Per Gallon Application ====")
    print()

    trips = read_trips()
    if len(trips) > 0 :
        list_trips(trips)
        print('\n')

    more = "y"
    while more.lower() == "y":
        miles_driven = get_miles_driven()
        gallons_used = get_gallons_used()

        mpg = round((miles_driven / gallons_used), 2)
        print("Miles Per Gallon:\t" + str(mpg))
        print()
        
        trips.append([miles_driven, gallons_used, mpg])      
        
        list_trips(trips)
        print()
        
        more = input("More entries? (y or n): ")
    
    write_trips(trips)

    print("Bye")

if __name__ == "__main__":
    main()


