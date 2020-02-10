#ifndef IPUBLISHER_HPP
#define IPUBLISHER_HPP

#include "IObserver.hpp"

class IPublisher
{
public:
	virtual ~IPublisher() = default;
	virtual void attach(IObserver *observer) = 0;
	virtual void detach(IObserver *observer) = 0;
	virtual void notify() = 0;
};

#endif /* IPUBLISHER_HPP */
