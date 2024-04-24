# Starting file for Exercise 6.2 from our textbook

# Be sure to follow the instructions in our book to complete this lab activity.

# Additionally, add a program title to the output please for the best user experience.

# For your last practice activity of the week, you will make some changes to the 
#   two-dimensional list by adding a third column for each movie. You will be adding 
#   a column for the movie price. 
# 
# You will also build a new COMMAND "find" that will search and display all movies 
#   by a particular input year. 
# Additional:
#    Enhance the program so it provides for the price column that’s shown below.
#    Enhance the program so it provides a find by year function that lists all of the movies that were released in the year that the user requests, as shown below.
#    Test this program to make sure everything is working right.


def display_menu():
    
    print("=== COMMAND MENU ===")
    print("find - Find Movie by Year")
    print("list - List all movies")
    print("add -  Add a movie")
    print("del -  Delete a movie")
    print("exit - Exit program")
    print()    


def find(movie_list):
    if len(movie_list) == 0:
        print("There are no movies in the list.\n")
        return
    
    year = ""
    while True:
        year = int(input("Input a year between 1900 and 2024, and we'll give you a matching movie (if one exists): "))
        if (year < 1900 or year > 2024):
            print("Invalid year. Please input a year between 1900 and 2024")
        else:
            break
            
    matches = []
    for movie in movie_list:
        if (movie[1] == year):
            matches.append(movie)
            
    if (len(matches) == 0):
        print ("No matching movies ):")
    else:
        print((str(len(matches))) + " matching movies: ")
        i = 1
        for movie in matches:
            print("    " + str(i) + " - " + str(movie[0]) + " was released in " + str(year))
            i+=1
    

def list(movie_list):
    if len(movie_list) == 0:
        print("There are no movies in the list.\n")
        return
    else:
        i = 1
        for movie in movie_list:
            row = movie
            print(str(i) + ". " + row[0] + " (" + str(row[1]) + ")" + " @ " + str(row[2]))
            i += 1
        print()

def add(movie_list):
    name = input("Name: ")
    year = int(input("Year: "))
    price = input("Price: ")
    
    movie = []
    movie.append(name)
    movie.append(year)
    movie.append(price)
    
    movie_list.append(movie)
    print(movie[0] + " was added.\n")
    
def delete(movie_list):
    number = int(input("Number: "))
    if number < 1 or number > len(movie_list):
        print("Invalid movie number.\n")
    else:
        movie = movie_list.pop(number-1)
        print(movie[0] + " was deleted.\n")
        
def main():
    print ("The Spectacular Movie List Database\n")

    movie_list = [["Monty Python and the Holy Grail", 1975, 9.99],
                  ["On the Waterfront", 1954, 9.99],
                  ["Cat on a Hot Tin Roof", 1958, 9.99]]
    
    display_menu()
    while True:        
        command = input("Command: ")
        if command == "list":
            list(movie_list)
        elif command == "find":
            find(movie_list)
        elif command == "add":
            add(movie_list)
        elif command == "del":
            delete(movie_list)
        elif command == "exit":
            break
        else:
            print("Not a valid command. Please try again.\n")
    print("Bye!")

if __name__ == "__main__":
    main()