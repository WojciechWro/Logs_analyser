#include "InterfaceMocks.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

using ::testing::AtLeast;
using ::testing::MatchesRegex;
using ::testing::SafeMatcherCast;
using ::testing::StartsWith;
using ::testing::TypedEq;

const char* file = "AccountsSummary_2020.txt";

TEST(DataFile, verifyTextFile)
{
	ASSERT_THAT(file, "AccountsSummary_2020.txt");
	EXPECT_THAT(file, StartsWith("Accounts"));
	EXPECT_THAT(file, MatchesRegex("AccountsSummary_\\d+\\.\\w+"));
}

TEST(IPublisherMock, verifyNotifyMethod)
{
	IPublisherMock publisher_mock;
	
	EXPECT_CALL(publisher_mock, notify)
		.Times(AtLeast(1));

	publisher_mock.notify();
}

TEST(IPublisherMock, verifyAttachMethod)
{
	IPublisherMock publisher_mock;
	IObserverMock* obs_mock;

	EXPECT_CALL(publisher_mock, attach(SafeMatcherCast<IObserver*>(obs_mock)))
		.Times(0);
}

TEST(IOserverMock, veriyNotifyMethod) 
{
	const std::string message = "someMessage_update";
	IObserverMock obs_mock;

	EXPECT_THAT(message, MatchesRegex("someMessage_\\w+"));

	EXPECT_CALL(obs_mock, update(TypedEq<const std::string&>("someMessage")))
		.Times(AtLeast(1));
	
	obs_mock.update("someMessage");
}