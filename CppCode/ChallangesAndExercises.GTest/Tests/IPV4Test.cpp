#pragma once
#include "..\pch.h"
#include <IPv4\IPv4Adress.hpp>

class IPv4TestFixture : public ::testing::Test {
protected:
	std::shared_ptr<IPv4> ipAdress = std::make_shared<IPv4>();
	std::array<uint8_t, IIPv4::adressSize> expectedArray = { 0,0,0,0 };
	std::string expectedString = "0.0.0.0";
	uint32_t expectedValue = 0;
	void VerifyAdress(std::array<uint8_t, IIPv4::adressSize> asArray, std::string asString, uint32_t asValue) {

		EXPECT_EQ(ipAdress->GetSegmentOfAdress(0), asArray[0]);
		EXPECT_EQ(ipAdress->GetSegmentOfAdress(1), asArray[1]);
		EXPECT_EQ(ipAdress->GetSegmentOfAdress(2), asArray[2]);
		EXPECT_EQ(ipAdress->GetSegmentOfAdress(3), asArray[3]);
		EXPECT_EQ(ipAdress->GetAdressAsArray(), asArray);
		EXPECT_EQ(ipAdress->ToString(), asString);
		ASSERT_EQ(ipAdress->GetAdressValue(), asValue);
	}
};

TEST_F(IPv4TestFixture, Ctor) {
	ASSERT_TRUE(ipAdress);
	VerifyAdress(expectedArray, expectedString, expectedValue);

	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;//192.168.0.1

	ipAdress.reset();
	ipAdress = std::make_shared<IPv4>(expectedArray);
	ASSERT_TRUE(ipAdress);
	VerifyAdress(expectedArray, expectedString, expectedValue);


	ipAdress.reset();
	ipAdress = std::make_shared<IPv4>(expectedValue);
	ASSERT_TRUE(ipAdress);
	VerifyAdress(expectedArray, expectedString, expectedValue);
}

TEST_F(IPv4TestFixture, SettingsAsSegment) {
	ASSERT_TRUE(ipAdress);
	expectedArray = { 192,0,0,0 };
	expectedString = "192.0.0.0";
	expectedValue = 3221225472;

	ipAdress->SetAdressSegment(192, 0);
	VerifyAdress(expectedArray, expectedString, expectedValue);

	expectedArray = { 192,168,0,0 };
	expectedString = "192.168.0.0";
	expectedValue = 3232235520;

	ipAdress->SetAdressSegment(168, 1);
	VerifyAdress(expectedArray, expectedString, expectedValue);
	ipAdress->SetAdressSegment(0, 2);
	VerifyAdress(expectedArray, expectedString, expectedValue);

	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;

	ipAdress->SetAdressSegment(1, 3);
	VerifyAdress(expectedArray, expectedString, expectedValue);
}

TEST_F(IPv4TestFixture, SettingsAsArray) {
	ASSERT_TRUE(ipAdress);
	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;

	ipAdress->SetAdress(expectedArray);
	VerifyAdress(expectedArray, expectedString, expectedValue);
}

TEST_F(IPv4TestFixture, SettingsAsValue) {
	ASSERT_TRUE(ipAdress);
	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;

	ipAdress->SetAdress(expectedValue);
	VerifyAdress(expectedArray, expectedString, expectedValue);

	expectedArray = { 192,168,0,2 };
	expectedString = "192.168.0.2";
	expectedValue++;

	ipAdress->SetAdress(expectedValue);
	VerifyAdress(expectedArray, expectedString, expectedValue);
}

TEST_F(IPv4TestFixture, SettingsViaOperators) {
	ASSERT_TRUE(ipAdress);
	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;

	*ipAdress = expectedValue;
	VerifyAdress(expectedArray, expectedString, expectedValue);

	expectedArray = { 192,168,0,2 };
	expectedString = "192.168.0.2";
	expectedValue++;

	*ipAdress = expectedValue;
	VerifyAdress(expectedArray, expectedString, expectedValue);


	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;

	*ipAdress = expectedArray;
	VerifyAdress(expectedArray, expectedString, expectedValue);
}

TEST_F(IPv4TestFixture, SettingsViaOperatorsSegment) {
	ASSERT_TRUE(ipAdress);
	expectedArray = { 192,168,0,1 };
	expectedString = "192.168.0.1";
	expectedValue = 3232235521;

	*ipAdress = expectedValue;
	VerifyAdress(expectedArray, expectedString, expectedValue);

	expectedArray = { 192,168,0,2 };
	expectedString = "192.168.0.2";
	expectedValue++;

	(*ipAdress)[3] = 2;
	VerifyAdress(expectedArray, expectedString, expectedValue);
}