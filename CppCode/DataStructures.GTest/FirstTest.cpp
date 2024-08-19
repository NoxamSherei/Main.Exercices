#include "pch.h"
#include <windows.h>  
#include <iostream>

class MockTest {
public:
	MOCK_METHOD(void, SomeMethod, ());
};

TEST(TestCaseName, MockSimpleTest) {
	MockTest mock;
	EXPECT_CALL(mock, SomeMethod);
	mock.SomeMethod();
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

class SomethingTest :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[ SETUP    ]";
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << " setup step start\n";
	}

	virtual void TearDown()
	{
		HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[ TEARDOWN ]\n";
		SetConsoleTextAttribute(hConsole, 7);
	}
};

TEST_F(SomethingTest, TestWithUsingAFixture) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}