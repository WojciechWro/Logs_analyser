#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <string>

class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void update(const std::string &message) = 0;
};

#endif /* IOBSERVER_HPP */
