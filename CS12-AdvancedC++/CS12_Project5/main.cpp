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
#include <vector>
#include <fstream>
#include "round.h"

void printStockInfoHeader()
{
	std::cout << "**********   Financial Report	  **********\n"
		<< "Stock               Today                         Previous  Percent\n"
		<< "Symbol    Open      Close     High      Low       Close     Gain        Volume\n"
		<< "________  ________  ________  ________  ________  ________  ________    _______\n"
		<< std::endl;
}

class stockType
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

	stockType() { }

	// sets stock information
	stockType(std::string _symbol, double opening, double closing, double high, double low,
		double previous, int shares) {

		symbol = _symbol;
		openingPrice = opening;
		closingPrice = closing;
		sharePrice = closing;
		highPrice = high;
		lowPrice = low;
		previousPrice = previous;
		totalShares = shares;

		percentGainLoss = ((closing - opening) / opening) * 100;
	}

	// getters
	std::string getSymbol()		{ return symbol; }
	double getOpeningPrice()	{ return openingPrice; }
	double getClosingPrice()	{ return closingPrice; }
	double getHighPrice()		{ return highPrice; }
	double getPreviousPrice()	{ return previousPrice; }
	double getPercentGainLoss() { return percentGainLoss;}
	double getSharePrice()		{ return sharePrice; }
	int getTotalShares()		{ return totalShares; }

	void printStockInfo()
	{
		std::string openStr = "$" + roundToPlace(std::to_string(openingPrice), 2);
		std::string closeStr = "$" + roundToPlace(std::to_string(closingPrice), 2);
		std::string highStr  = "$" + roundToPlace(std::to_string(highPrice), 2);
		std::string lowStr = "$" + roundToPlace(std::to_string(lowPrice), 2);
		std::string previousStr = "$" + roundToPlace(std::to_string(previousPrice), 2);
		std::string percentStr = roundToPlace(std::to_string(percentGainLoss), 2) + "%";
		std::string sharePriceStr = "$" + roundToPlace(std::to_string(sharePrice), 2);

		std::cout << std::setw(8) << symbol << "  "
			<< std::setw(8) << openStr << "  "
			<< std::setw(8) << closeStr << "  "
			<< std::setw(8) << highStr << "  "
			<< std::setw(8) << lowStr << "  "
			<< std::setw(8) << previousStr << "  "
			<< std::setw(8) << percentStr << " "
			<< std::setw(8) << std::to_string(totalShares);
	}
};

namespace printTypes
{
	enum type
	{
		AS_IS,	//0
		SYMBOL,	//1 
		PERCENT	//2
	};
}

void printStocks(stockType *stockArr, int arrSize, printTypes::type type)
{

	printStockInfoHeader();

	switch (type)
	{
		case printTypes::AS_IS:
			// print in order
			break;
		case printTypes::SYMBOL:
			for (int i = 0; i < arrSize - 1; i++)
			{
				int insertPos = 0;
				for (int j = i + 1; j > -1; j--)
				{
					if (stockArr[i + 1].getSymbol() > stockArr[j].getSymbol())
					{
						insertPos = j + 1;
						break;
					}
				}
				stockType temp = stockArr[i + 1];

				for (int p = i; p >= insertPos; p--)
				{
					stockArr[p + 1] = stockArr[p];
				}
				stockArr[insertPos] = temp;
			}
			break;
		case printTypes::PERCENT:
			for (int i = 0; i < arrSize - 1; i++)
			{
				int insertPos = 0;
				for (int j = i + 1; j > -1; j--)
				{
					if (stockArr[i + 1].getPercentGainLoss() > stockArr[j].getPercentGainLoss())
					{
						insertPos = j + 1;
						break;
					}
				}
				stockType temp = stockArr[i + 1];

				for (int p = i; p >= insertPos; p--)
				{
					stockArr[p + 1] = stockArr[p];
				}
				stockArr[insertPos] = temp;
			}
			break;
		default:
			assert("Case unaccounted for.");
	}

	double closingAssets = 0;
	for (int i = 0; i < arrSize; i++)
	{
		stockArr[i].printStockInfo();
		std::cout << "\n";
		closingAssets += stockArr[i].getSharePrice() * stockArr[i].getTotalShares();
	} 

	std::cout << "\nClosing Assets: $" << std::to_string(closingAssets) << "\n";
}

int main()
{
	stockType stocks[5];

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
		int totalShares;

		std::string variable;
		for (int i = 0; i < 7; i++)
		{
			file >> variable;
			if (i == 0) symbol = variable;
			else if (i == 1) openingPrice		= std::stod(variable);
			else if (i == 2) closingPrice		= std::stod(variable);
			else if (i == 3) highPrice			= std::stod(variable);
			else if (i == 4) lowPrice			= std::stod(variable);
			else if (i == 5) previousPrice		= std::stod(variable);
			else if (i == 6) totalShares		= std::stoi(variable);
			else assert("Case not handled");
		}

		stocks[index] = stockType(symbol, openingPrice, closingPrice, highPrice, lowPrice,
			previousPrice, totalShares);

		index++;
	}
	file.close();

	printStocks(stocks, 5, printTypes::AS_IS);
	printStocks(stocks, 5, printTypes::SYMBOL);
	printStocks(stocks, 5, printTypes::PERCENT);
}