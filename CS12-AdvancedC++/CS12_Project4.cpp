/*

Write a program that prompts the user to enter a person’s date of birth in
	numeric form such as 8-27-1980.
The program then outputs the date of birth in the form: August 27, 1980.
Your program must contain at least two exception classes:
	invalidDay and invalidMonth.

If the user enters an invalid value for day, then the program should
	throw and catch an invalidDay object. Similar conventions for
	the invalid values of month and year.
	(Note that your program must handle a leap year.)

what() functions for each class
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
#include <assert.h>

static const std::vector<unsigned int> daysPerMonth = { 31, 28, 31, 30, 31, 30, 31,
	31, 30, 31, 30, 31 };
static const std::string monthStrings[] = { "January", "February", "March", "April", "May"
	"June", "July", "August", "September", "October", "November", "December" };

static const std::vector<char> validInputs = { '0', '1', '2', '3', '4','5', '6',
	'7', '8', '9' };



int gCurrentMonth()
{
	static const std::string monthMatch[] = { "Jan", "Feb", "Mar",
"Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	time_t now = time(0);
	std::string time = (std::ctime(&now));
	std::string month = time.substr(4, 3);
	for (int i = 0; i < 12; i++)
	{
		if (monthMatch[i] == month)
		{
			return i + 1;
		}
	}

	assert(false && "No matching month was found");
}

/*
Throws error cases:
- non-numerical input,
- input greater than current year,
- input that indicates impossible age (age > 122)
- input is not equal to 4 characters

*/
class invalidYear {
	bool valid = true;
	std::string errorMessage = "ERROR(S): ";

public:

	invalidYear(std::string* birthYear) {
		short length = birthYear->length();

		// validate character input validation and length
		if (length == 4) {
			bool validChar[4];
			validChar[0] = false;
			validChar[1] = false;
			validChar[2] = false;
			validChar[3] = false;

			for (int i = 0; i < validInputs.size(); i++) {
				bool stillChecking = false;
				if (validChar[0] != true) {
					stillChecking = true;
					if (birthYear->at(0) == validInputs[i]) {
						validChar[0] = true;
					}
				}
				if (validChar[1] != true) {
					stillChecking = true;
					if (birthYear->at(1) == validInputs[i]) {
						validChar[1] = true;
					}
				}
				if (validChar[2] != true) {
					stillChecking = true;
					if (birthYear->at(2) == validInputs[i]) {
						validChar[2] = true;
					}
				}
				if (validChar[3] != true) {
					stillChecking = true;
					if (birthYear->at(3) == validInputs[i]) {
						validChar[3] = true;
					}
				}

				if (stillChecking == false) break;
			}

			for (int i = 0; i < 4; i++) {
				if (validChar[i] == false) {
					std::string yearChar = std::to_string(birthYear->at(i));
					errorMessage += "\n		'";
					errorMessage += birthYear->at(i);
					errorMessage += "' is not a valid character. Input must be a number.";
					valid = false;
				}
			}
		}
		else {
			valid = false;
			errorMessage += "Year must be 4 digits. Input a year that is 4 digits.";
		}

		// valid age validation
		if (valid) {
			const std::time_t now = std::time(0);
			std::string time = (std::ctime(&now));
			int currentYear = std::stoi(time.substr(time.length() - 5, 4));

			int age = currentYear - std::stoi(*birthYear);
			if (age < 0)
			{
				errorMessage += "\n		Your birth year is invalid or you gotta get back to the future, Doc. \nInput a valid year.";
				valid = false;
			}

			// max age based on oldest person to live on record: Jeanne Calment of France
			if (age > 122) {
				errorMessage += "\n		Invalid age based on year. Oldest person recorded was 122. Your age exceeds that. \nInput a valid year.";
				valid = false;
			}
		}

		if (valid) {
			errorMessage += "No Error.";
		}
	}


	bool isValid() {
		return valid;
	}

	std::string what() {
		return errorMessage;
	}
};

/* 
Throws error cases:
- non-numerical input, 
- input length equal to 0 or greater than 2.
- input value less than 1 or greater than 12
- if born in the future of this year
*/ 
class invalidMonth {
	bool valid = true;
	std::string errorMessage = "ERROR(S): ";

public:

	invalidMonth(std::string* month, short yearNum) {
		const short length = month->length();

		// validate input characters and length
		if (length == 1) {
			bool validChar = false;
			for (int i = 0; i < validInputs.size(); i++) {
				if (validInputs[i] == month->at(0)) {
					validChar = true;
					break;
				}
			}

			if (validChar == false) {
				errorMessage += "\n		'";
				errorMessage += month->at(0);
				errorMessage += "' is not a valid character. Input must be a number.";
				valid = false;
			}
		}
		else if (length == 2) {
			bool validChar[2];
			validChar[0] = false;
			validChar[1] = false;
			for (int i = 0; i < validInputs.size(); i++) {
				if (validInputs[i] == month->at(0)) {
					validChar[0] = true;
				}
				if (validInputs[i] == month->at(1)) {
					validChar[0] = true;
				}

				if (validInputs[0] && validInputs[1]) {
					break;
				}
			}

			if (validChar[0] == false) {
				errorMessage += "\n		'";
				errorMessage += month->at(0);
				errorMessage += "' is not a valid character. Input must be a number.";
				valid = false;
			}
			if (validChar[1] == false) {
				errorMessage += "\n		'";
				errorMessage += month->at(1);
				errorMessage += "' is not a valid character. Input must be a number.";
				valid = false;
			}
		}
		else {
			valid = false;
			errorMessage += "Month input must be 1 or 2 digits in length depending on the month.";
		}

		short monthNum = 0;

		// validate value of month input
		if (valid) {
			monthNum = std::stoi(*month);
			if (monthNum < 0 || monthNum > 13) {
				errorMessage += "\n		Invalid month. Months are between 1 and 12 (inclusive).";
				valid = false;
			}
		}

		// born in the future check
		if (valid)
		{
			time_t now = time(0);
			std::string time = (std::ctime(&now));
			int currentYear = std::stoi(time.substr(time.length() - 5, 4));
			if (currentYear == yearNum)
			{
				if (gCurrentMonth() < monthNum)
				{
					errorMessage += "\n Looks like you are born later this year, which is hmm - \"odd\". Input a valid month.";
					valid = false;
				}
			}
			
		}

		if (valid) {
			errorMessage += "No Error.";
		}
	}

	bool isValid()	{
		return valid;
	}

	std::string what() {
		return errorMessage;
	}

};

/*
Throw Error Cases:
- non-numerical input
- input length equal to 0 or greater than 2 digits
- input value less than 1 or greater than specified month's max day.
- day chosen indicates birthday is in the future
*/
class invalidDay {
	bool valid = true;
	std::string errorMessage = "ERROR(S): ";

public:

	invalidDay(std::string* day, short monthNum, short yearNum) {
		short length = day->length();

		// validate input characters and length
		if (length == 1) {
			bool validChar = false;
			for (int i = 0; i < validInputs.size(); i++) {
				if (day->at(0) == validInputs[i]) {
					validChar = true;
					break;
				}
			}

			if (validChar == false) {
				errorMessage += "\n		'";
				errorMessage += day->at(0);
				errorMessage += "' is not a valid character. Input must be a number.";
				valid = false;
			}
		}
		else if (length == 2) {
			bool validChar[2];
			validChar[0] = false;
			validChar[1] = false;
			for (int i = 0; i < validInputs.size(); i++) {
				if (validInputs[i] == day->at(0)) {
					validChar[0] = true;
				}
				if (validInputs[i] == day->at(1)) {
					validChar[1] = true;
				}

				if (validChar[0] == true && validChar[1] == true) {
					break;
				}
			}

			if (validChar[0] == false) {
				errorMessage += "\n		'";
				errorMessage += day->at(0);
				errorMessage += "' is not a valid character. Input must be a number.";
				valid = false;
			}
			if (validChar[1] == false) {
				errorMessage += "\n		'";
				errorMessage += day->at(1);
				errorMessage += "' is not a valid character. Input must be a number.";
				valid = false;
			}
		}
		else {
			valid = false;
			errorMessage += "Input must be 1 or 2 characters long depending on the day.";
		}

		// validate value of input based on month. day range check changes based on month
		if (valid) {
			short dayNum = std::stoi(*day);

			// check leap year day.
			if (dayNum <= 0)
			{
				errorMessage += "\n		Invalid day input. Day must be greater than zero.";
				valid = false;
			}
			else if (yearNum % 4 == 0 && monthNum == 2)
			{
				if (dayNum > 29)
				{
					errorMessage += "\n		Invalid day input. February must have 1 to 29 days (inclusive) for leap years.";
					valid = false;
				}
			}
			else
			{
				if (dayNum > daysPerMonth[monthNum - 1])
				{
					errorMessage += "\n		Invalid day input. Input must between 1 and " + std::to_string(daysPerMonth[monthNum-1])
						+ " (inclusive) for the month of " + monthStrings[monthNum - 1] + ".";
					valid = false;
				}
			}
		}

		// born in future check
		if (valid) {
			
			time_t now = time(0);
			std::string time = (std::ctime(&now));
			int currentYear = std::stoi(time.substr(time.length() - 5, 4));
			int currentMonth = gCurrentMonth();
			if (currentYear == yearNum && currentMonth == monthNum)
			{
				int today = std::stoi(time.substr(8, 2));
				if (today < std::stoi(*day)) {
					errorMessage += "\n Hmm. Looks like you're from the future... or you can input a valid day (;";
					valid = false;
				}
			}
		}
	}

	bool isValid() {
		return valid;
	}

	std::string what() {
		return errorMessage;
	}
};

int main() {

	std::string input = "";


	while (true)
	{
		std::cout << "\n==========================";
		std::cout << "\nWhat year were you born (Please provide 4 characters): ";
		std::cin >> input;
		try {
			invalidYear y = invalidYear(&input);
			if (y.isValid() == false) throw y;
			
			break;
		}
		catch (invalidYear y) {
			std::cout << y.what();
		}
	}
	int yearNum = std::stoi(input);


	input = "";
	while (true)
	{
		std::cout << "\n\n==========================";
		std::cout << "\nWhat month were you born. Input a number between 1 and 12 (inclusive): ";
		std::cin >> input;
		try {
			invalidMonth m = invalidMonth(&input, yearNum);
			if (m.isValid() == false) throw m;
			
			break;
		}
		catch (invalidMonth m) {
			std::cout << m.what();
		}
	}
	int monthNum = std::stoi(input);


	input = "";
	while (true)
	{
		std::cout << "\n\n==========================";
		std::cout << "\nWhich day in " << monthStrings[monthNum - 1] << " were you born: ";
		std::cin >> input;
		try {
			invalidDay d = invalidDay(&input, monthNum, yearNum);
			if (d.isValid() == false) throw d;
			break;
		}
		catch (invalidDay d) {
			std::cout << '\n' << d.what();
		}
	}
	int dayNum = std::stoi(input);


	std::string birthday = monthStrings[monthNum-1] + " " + std::to_string(dayNum) + ", " + std::to_string(yearNum);
	std::cout << "\n\n==========================";
	std::cout << "\nYour birthday is: " + birthday + "\n\n==========================";

}


