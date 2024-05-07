#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

bool isPalindrome(std::string s, int place)
{
	if (place < (s.length() - 1) / 2)
	{
		if (isPalindrome(s, place + 1) == false)
		{
			return false;
		}
	}

	if (s[s.length() - place - 1] == s[place])
	{
		return true;
	}

	return false;
}

int main()
{
	std::vector<std::string> palindromes =
	{
		"madam",
		"racecar",
		"hannah",
		"tat",
		"I",
		"deed",
		"esse",
		"malayalam"
	};

	std::vector<std::string> notPalindromes =
	{
		"kite",
		"it",
		"racecoar",
		"ontotonto",
		"levesel",
		"marjoram",
		"peeseweep",
		"xerox",
		"catalitic"

	};


	int shift = 28;
	
	std::cout << "PALINDROMES\n============\n";
	for (int i = 0; i < palindromes.size(); i++)
	{
		int originalShift = shift;
		if (shift - palindromes[i].length() < 0)
		{
			shift = shift + (palindromes[i].length() - shift + 1);
		}

		std::cout << std::left   
			<< "Is " << palindromes[i] << std::setw(shift - palindromes[i].length()) << " a palindrome: "
			<< isPalindrome(palindromes[i], 0) << '\n';
	
		shift = originalShift;
	}

	std::cout << "\nNOT PALINDROMES\n================\n";
	for (int i = 0; i < notPalindromes.size(); i++)
	{
		int originalShift = shift;
		if (shift - notPalindromes[i].length() < 0)
		{
			shift = shift + (notPalindromes[i].length() - shift + 1);
		}

		std::cout << std::left 
			<< "Is " << notPalindromes[i] << std::setw(shift - notPalindromes[i].length()) << " a palindrome: "
			<< isPalindrome(notPalindromes[i], 0) << '\n';
		
		shift = originalShift;
	}

}