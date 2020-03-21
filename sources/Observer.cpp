#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#include "Observer.hpp"

extern std::atomic_bool readyFlag;

Observer::~Observer(){};

Observer::Observer(Publisher &subject): subject_(subject)
{
	this->subject_.attach(this);

	std::cout << "Observer " << ++Observer::observers_amount_ << " attached to list" << std::endl;
	this->number_ = Observer::observers_amount_;
}

void Observer::update(const std::string &message)
{
	message_ = message;
	std::cout << "Observer " << this->number_ << " triggered with new message from subject: " 
		<< this->message_ << std::endl;

	while (!readyFlag.load())
	{
		std::cout.put('.').flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	// [TO DO]: custom method to analyse file content or generate report
	std::cout << "Some expected action was performed " << std::endl;
};

void Observer::removeFromObservers()
{
	subject_.detach(this);
	std::cout << "\nObserver " << this->number_  << " was removed from list!" << std::endl;
};
