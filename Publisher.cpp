#include <atomic>
#include <chrono>
#include <future>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <regex>
#include <numeric>
#include <iomanip>

#include "Publisher.hpp"
#include "IObserver.hpp"

const char *fileName = "AccountsSummary_2020.txt";
const char* SummaryFile = "ReportSummary.txt";

extern std::atomic_bool readyFlag;

std::regex pattern("\\s+\\d+\\.\\d{2}");
std::smatch matches;

Publisher::~Publisher() 
{};

void Publisher::attach(IObserver *observer) 
{
	observers_list.push_back(observer);
};

void Publisher::detach(IObserver *observer)
{
	observers_list.remove(observer);
};

void Publisher::performTask(const char *file) 
{
	std::ifstream AtomicFile(fileName); //move outside function to fail gtest with throw assertion
	std::ofstream reportFile(SummaryFile);

	if (!AtomicFile.is_open())
	{
		throw std::out_of_range("Data file cannot be open!!!");
	}
	else if (!reportFile.is_open()) 
	{
		throw std::out_of_range("Summary file cannot be open!!!");
	}
	else
	{
		std::cout << "\n*** File " << fileName << " content *** \n" << std::endl;

		int lineNumber = 0;
		double sum = 0;
		std::string line;

		while (getline(AtomicFile, line)) {
			++lineNumber;
			std::cout << line << std::endl;

			if (std::regex_search(line, matches, pattern)){
			
				reportFile << "Pattern found in line " << lineNumber << ": " << matches[0] << std::endl;
				sum += stod(matches[0]);
			}
			else
			{
				reportFile << line << std::endl;
			}
		}
		reportFile << "\nSum of all valid values is: " << std::setprecision(7) << sum << std::endl;
		std::cout << "\n*** End of File ***\n" << std::endl;
	}
	AtomicFile.close();
	reportFile.close();
};

void Publisher::observersNumber() 
{
	std::cout << "Observers number: " << observers_list.size()  <<  "\n" << std::endl;
};

void Publisher::notify()
{
	for (auto i : observers_list)
	{
		readyFlag.store(true); // if flag=false only dots "...." will be printed
		i->update(message_);
	}
};

void Publisher::createMessageAndTriggerTask(std::string message)
{
	this->message_ = message;
	observersNumber();
	performTask(fileName);
	notify();
}
