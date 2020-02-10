#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <atomic>
#include <list>
#include <string>

#include "IObserver.hpp"
#include "IPublisher.hpp"

class Publisher : public IPublisher
{
public:
	virtual ~Publisher();
	void attach(IObserver *observer) override;
	void detach(IObserver *observer) override;
	void notify() override;

	void createMessageAndTriggerTask(std::string message);
	void performTask(const char *file);
	void observersNumber();

private:
	std::list<IObserver*> observers_list;
	std::string message_;
};

#endif /* PUBLISHER_HPP */
