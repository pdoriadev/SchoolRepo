/*
Generate and post listing of stocks
Produce two listings
	One sotrted by stock symbol
	One sorted by percent gaini from highest to lowest
Input file provided

Design and implement stock object

Call the class that captures the various characteristics of a stock object
	store:
		*stock sybmol
		*stock price
		*number of shares
	output:
		opening price
		closing price
		high price
		low price
		previous price
		percent gain/loss for the day
	Operations
		set stock information
		print stock info
		show different prices
		calculate and print percent gain/loss
		Show number of shares
		Overload relational operators to compare two stock objects by their symbols
			Compare closing price
		Overload insertion operator, <<, for easy output
		Overloas stream extraction operator, >>, for easy input
i.e.
	infile >> myStock;
	reads data from the input file and stores it in the object "myStock".

*/



#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "round.h"

class stock
{
private:
	std::string symbol = "";
	double openingPrice = -1;
	double closingPrice = -1;
	double sharePrice = -1;
	double highPrice = -1;
	double lowPrice = -1;
	double previousPrice = -1;
	double percentGainLoss = -1;
	int totalShares = -1;

public:

	stock() { }

	// sets stock information
	stock(double opening, double closing, double high, double low,
		double previous, double percent, int shares) {

		openingPrice = opening;
		closingPrice = closing;
		sharePrice = closing;
		highPrice = high;
		lowPrice = low;
		previousPrice = previous;
		percentGainLoss = percent;
		totalShares = shares;
	}

	// getters
	double getOpeningPrice()	{ return openingPrice; }
	double getClosingPrice()	{ return closingPrice; }
	double getHighPrice()		{ return highPrice; }
	double getPreviousPrice()	{ return previousPrice; }
	double getPercentGainLoss() { return percentGainLoss; }
	double getSharePrice()		{ return sharePrice; }
	int getTotalShares()		{ return totalShares; }

	void printStockInfo()
	{
		// need to right/left justify and fill where needed. 
		std::cout << symbol << std::to_string(openingPrice) << std::to_string(closingPrice) << std::to_string(highPrice) 
			<< std::to_string(previousPrice) << std::to_string(percentGainLoss) << std::to_string(sharePrice)
			<< std::to_string(totalShares);
	}

	// print functions
	void printSymbol()			{ std::cout << symbol; }
	void printOpeningPrice()	{ std::cout << std::to_string(openingPrice);  }
	void printClosingPrice()	{ std::cout << std::to_string(closingPrice); }
	void printSharePrice()		{ std::cout << std::to_string(sharePrice); }
	void printHighPrice()		{ std::cout << std::to_string(highPrice); }
	void printLowPrice()		{ std::cout << std::to_string(lowPrice); }
	void printPreviousPrice()	{ std::cout << std::to_string(previousPrice); }
	void printPercentGainLoss() { std::cout << std::to_string(percentGainLoss); }
	void printTotalShares()		{ std::cout << std::to_string(totalShares); }
		
	/*set stock information
		*print stock info
		*show different prices
		calculate and print percent gain / loss?? BUT percentGainLoss is given???
		*Show number of shares*/
};

void printStocks()
{
	double closingAssets;

	std::cout << "**********   Financial Report	  **********\n"
		<< "Stock				Today				Previous  Percent\n"
		<< "Symbol   Open    Close   High    Low    Close     Gain          Volume\n"
		<< "_______  ______  ______  ______  _____  ________  __________    _______\n"
		<< std::endl;

	std::cout << "Closing Assets: ";
}

int main()
{

	stock stocks[5];

	std::ifstream file;
	file.open("stock.txt");
	assert(file.is_open() && "Failed to open file");

	int index = 0;
	std::string line;
	while (!file.eof())
	{
		std::string symbol = "";
		double openingPrice;
		double closingPrice;
		double highPrice;
		double lowPrice;
		double previousPrice;
		double percentGainLoss;
		int totalShares;

		std::string variable;
		for (int i = 0; i < 8; i++)
		{
			file >> variable;
			if (i == 0) symbol = variable;
			else if (i == 1) openingPrice = std::stod(variable);
			else if (i == 2) closingPrice = std::stod(variable);
			else if (i == 3) highPrice = std::stod(variable);
			else if (i == 4) lowPrice = std::stod(variable);
			else if (i == 5) previousPrice = std::stod(variable);
			else if (i == 6) percentGainLoss = std::stod(variable);
			else if (i == 7) totalShares = std::stoi(variable);
			else assert("Case not handled");
		}

		stocks[index] = stock(openingPrice, closingPrice, highPrice, lowPrice,
			previousPrice, percentGainLoss, totalShares);

		index++;
	}

	file.close();


}