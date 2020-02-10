#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

#include "IObserver.hpp"
#include "Publisher.hpp"

class Observer : public IObserver
{
public:
	virtual ~Observer();
	Observer(Publisher &subject);
	void update(const std::string &message) override;
	void removeFromObservers();
	
private:
	Publisher &subject_;
	std::string message_;
	static int observers_amount_;
	int number_;
};

#endif /* OBSERVER_HPP */
