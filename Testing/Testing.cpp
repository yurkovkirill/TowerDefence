// Testing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\TD\Game.h"
#include "gtest\gtest.h"

//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

TEST(testTemplateConstructor, InitFileConstructor3) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	STable<3> tmp("configTowers.txt");
	int test = tmp.STable::getVal(0).cost;
	EXPECT_EQ(test, 100);
	test = tmp.STable::getVal(1).cost;
	EXPECT_EQ(test, 150);
	test = tmp.STable::getVal(2).cost;
	EXPECT_EQ(test, 200);

	test = tmp.STable::getVal(0).dmg;
	EXPECT_EQ(test, 25);
	test = tmp.STable::getVal(1).dmg;
	EXPECT_EQ(test, 40);
	test = tmp.STable::getVal(2).dmg;
	EXPECT_EQ(test, 65);

	float test2 = tmp.STable::getVal(0).rad;
	EXPECT_EQ(test2, 4.0);
	test2 = tmp.STable::getVal(1).rad;
	EXPECT_EQ(test2, 6.0);
	test2 = tmp.STable::getVal(2).rad;
	EXPECT_EQ(test2, 10.0);

	test = tmp.STable::getVal(0).rate;
	EXPECT_EQ(test, 8);
	test = tmp.STable::getVal(1).rate;
	EXPECT_EQ(test, 6);
	test = tmp.STable::getVal(2).rate;
	EXPECT_EQ(test, 4);
}
TEST(testTemplateConstructor, InitFileConstructor2) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	STable<2> tmp("forTemplateTest2.txt");
	int test = tmp.STable::getVal(0).cost;
	EXPECT_EQ(test, 100);
	test = tmp.STable::getVal(1).cost;
	EXPECT_EQ(test, 150);


	test = tmp.STable::getVal(0).dmg;
	EXPECT_EQ(test, 25);
	test = tmp.STable::getVal(1).dmg;
	EXPECT_EQ(test, 40);


	float test2 = tmp.STable::getVal(0).rad;
	EXPECT_EQ(test2, 4.0);
	test2 = tmp.STable::getVal(1).rad;
	EXPECT_EQ(test2, 6.0);


	test = tmp.STable::getVal(0).rate;
	EXPECT_EQ(test, 8);
	test = tmp.STable::getVal(1).rate;
	EXPECT_EQ(test, 6);
}

TEST(testTemplateConstructor, ExceptionTest) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	STable<2> tmp("forTemplateTest2.txt");
	int test = tmp.STable::getVal(0).cost;
	EXPECT_EQ(test, 100);
	ASSERT_THROW(tmp.STable::getVal(4), std::range_error);
}
//
//TEST(testConstructor, DefaultConstructor1) {
//	Dice d1;
//	ASSERT_EQ(10, d1.getS());
//}
//TEST(testConstructor, InitConstructor2) {
//	Dice d1(8);
//	ASSERT_EQ(8, d1.getS());
//}
//
//
//}
//TEST(testConstructor, TestException) {
//	Dice a1;
//	ASSERT_THROW(Dice(-1), std::exception);
//}



int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(nullptr));
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}