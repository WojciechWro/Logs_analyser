#include "Publisher.hpp"
#include "Observer.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PublisherTest : public ::testing::Test
{
protected:
	void SetUp() override{}
	void TearDown() override {};
};

const char* file = "someFile";

TEST_F(PublisherTest, verifyFilename)
{
	Publisher publish;

	ASSERT_NO_THROW(publish.performTask(file)) << "file name incorrect: "
		<< ::testing::PrintToString(file);
}
