/**
 * Unit Tests for the class
**/
#include <iostream>
#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){
		std::string secret;
		secret = "hello";
		game = new Guesser(secret);
		} //sets up before each test (after constructor)
		virtual void TearDown(){
		delete game;
		} //clean up after each test, (before destructor)
		Guesser* game;
		std::string secret;
};


// Example test
TEST_F(GuesserTest, Matching)
{
	EXPECT_FALSE(game->match("world"));

	EXPECT_FALSE(game->match("testing"));
}

TEST_F(GuesserTest, Remaining)
{
	game->match("tiger");
	EXPECT_EQ(game->remaining(), 3);

	game->match("lions");
	EXPECT_EQ(game->remaining(), 3);

	game->match("bears");
	EXPECT_EQ(game->remaining(), 3);
}

TEST_F(GuesserTest, Dist)
{
	EXPECT_EQ(game->distance("hello"), 0);
}

TEST_F(GuesserTest, Dist1)
{
	EXPECT_EQ(game->distance("heya"), 3);
}

TEST_F(GuesserTest, Guess)
{
	EXPECT_FALSE(game->match("terribleguess"));
}

TEST_F(GuesserTest, Matches)
{
	EXPECT_FALSE(game->match(""));
}

TEST_F(GuesserTest, Dist2)
{
	EXPECT_EQ(game->distance("test"), 4);
}

