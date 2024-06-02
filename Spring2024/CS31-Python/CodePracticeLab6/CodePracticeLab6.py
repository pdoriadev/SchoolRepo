# Modify the get_scores() function so the test scores are stored in a list named scores. 
#   This list should be returned by the function when all scores have been entered. 
#   The function should still make sure that the entries are valid, but the score_total and 
#   count variables aren’t needed and shouldn’t be updated.
# Modify the process_scores() function so the scores list is its only argument. Then, this 
#   function should use a for statement to total the scores in the list. It should use the 
#   len() function to get the number of scores in the list. And it should get the average by 
#   dividing the total scores by the length.
# Modify the main() function so the list that’s returned by the get_scores() function is stored 
#   in a variable. Then, modify the call to the process_scores() function so it passes just the scores list to it.
# Test this program to make sure everything is working right.
# Enhance this program by getting and displaying all of the other statistics shown above. For an odd number of scores, 
#   the median score is the score that has the same number of scores below it as above it. For an even number of scores, 
#   calculate the median by taking the average of the two middle 

import statistics


# Starting file for Exercise 6.1 in our textbook
def display_welcome():
    print("The Test Scores program")
    print("Enter 'x' to exit")
    print("")


def get_scores():
    scores = []
    counter = 0
    while True:
        newScore = input("Enter test score: ")
        if newScore == "x":
            return  scores
        else:
            newScore = int(newScore)
            if newScore >= 0 and newScore <= 100:
                scores.append(newScore)
            else:
                print("Test score must be from 0 through 100. " +
                      "Score discarded. Try again.")

def process_scores(scores):
    
    scoreTotal = 0
    for element in scores:
        scoreTotal += element

    # calculate average score
    average = scoreTotal / len(scores)
                
    # format and display the result
    print()
    print("Score total:       ", scoreTotal)
    print("Number of Scores:  ", len(scores))
    print("Average Score:     ", average)
    print("Highest Score:     ", max(scores))
    print("Lowest Score:      ", min(scores))
    print("Median Score:      ", statistics.median(scores))

def main():
    display_welcome()
    scores = get_scores()
    process_scores(scores)
    print("")
    print("Bye!")

# if started as the main module, call the main function
if __name__ == "__main__":
    main()
