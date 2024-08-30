#pragma once
#include <cstdint>
#include "iostream"
#include "sstream"
#include "array"
#include "IPv4Adress.hpp"

using std::uint8_t;
using std::cout;
using std::endl;

IPv4::IPv4(std::array<uint8_t, IPv4::adressSize> ipAdress) {
	SetAdress(ipAdress);
};
IPv4::IPv4(uint32_t ipAdress) {
	SetAdress(ipAdress);
};

void IPv4::SetAdressSegment(uint8_t value, int index) {
	adress[index] = value;
}

void IPv4::SetAdress(uint32_t value) {
	for (int i = 0; i < IIPv4::adressSize; i++) {
		adress[3 - i] = (value >> i * 8) & 0xFF;
	}
}

void IPv4::SetAdress(std::array<uint8_t, IPv4::adressSize> value) {
	adress = value;
}

IPv4& IPv4::operator=(std::array<uint8_t, IPv4::adressSize> value) {
	SetAdress(value);
	return *this;
}

IPv4& IPv4::operator=(uint32_t value) {
	SetAdress(value);
	return *this;
}

uint32_t IPv4::GetAdressValue() {
	uint32_t result = 0;
	for (size_t i = 0; i < IPv4::adressSize; i++)
	{
		result |= adress[IPv4::adressSize - 1 - i] << i * 8;
	}
	return result;
}

std::array<uint8_t, IPv4::adressSize>& IPv4::GetAdressAsArray() {
	return adress;
}

uint8_t& IPv4::GetSegmentOfAdress(size_t index) {
	return adress[index];
}

uint8_t& IPv4::operator[](size_t index) {
	return GetSegmentOfAdress(index);
}

void IPv4::PrintOnConsole() const {
	cout << ToString() << endl;
}

std::string IPv4::ToString() const {
	std::ostringstream os;
	int times = 3;
	for (const auto& segment : adress) {
		os << static_cast<int>(segment);
		if (times-- != 0) {
			os << '.';
		}
	}
	return os.str();
}

std::ostream& operator<<(std::ostream& os, const IPv4& obj)
{
	os << obj.ToString();
	return os;
}