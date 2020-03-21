#include "gmock/gmock.h"

#include "../interfaces/IObserver.hpp"
#include "../interfaces/IPublisher.hpp"

class IPublisherMock : public IPublisher {
public:
	MOCK_METHOD(void, attach, (IObserver *observer), (override));
	MOCK_METHOD(void, detach, (IObserver *observer), (override));
	MOCK_METHOD(void, notify, (), (override));
};

class IObserverMock : public IObserver {
public:
	MOCK_METHOD(void, update, (const std::string &message), (override));
};
