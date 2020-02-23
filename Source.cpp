#include <atomic>
#include <future>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "Observer.hpp"
#include "Publisher.hpp"

using atomic_bool = std::atomic<bool>;
int Observer::observers_amount_ = 0;
atomic_bool readyFlag(false);

int main(int argc, char** argv)
{
	Publisher *publisher = new Publisher;
	
	Observer *observer1 = new Observer(*publisher);
	Observer *observer2 = new Observer(*publisher);
	
	/* Without async thread - uncomment below
	publisher->createMessageAndTriggerTask("Some action and notification started"); */

	std::async(std::launch::async, &Publisher::createMessageAndTriggerTask, publisher, "Some action and notification started");

	observer2->removeFromObservers();

	::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}