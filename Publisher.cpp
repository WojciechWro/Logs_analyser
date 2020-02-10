#include <atomic>
#include <chrono>
#include <future>
#include <fstream>
#include <iostream>
#include <string>
#include <list>

#include "Publisher.hpp"
#include "IObserver.hpp"

const char* fileName = "AccountsSummary_2020.txt";
extern std::atomic_bool readyFlag;

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
	std::ifstream AtomicFile(fileName);

	if (!AtomicFile.is_open())
	{
		std::cout << "File cannot be open!!!" << std::endl;
	}
	else
	{
		std::cout << "\n*** File " << fileName << " content *** \n" << std::endl;

		std::string line;
		while (getline(AtomicFile, line)) {
			std::cout << line << std::endl;
		}

		std::cout << "\n*** End of File ***\n"<< std::endl;
	}
	AtomicFile.close();
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
