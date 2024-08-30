#pragma once
#include <cstdint>
#include "iostream"
#include "sstream"
#include "array"
#include "IIPv4.hpp"

using std::uint8_t;
using std::cout;
using std::endl;

class IPv4 : public IIPv4 {
private:
	std::array<uint8_t, IPv4::adressSize> adress;
public:
	//constructors
	IPv4() = default;
	IPv4(const IPv4&) = default;
	IPv4(IPv4&&) = default;
	IPv4(std::array<uint8_t, IPv4::adressSize> ipAdress);
	IPv4(uint32_t ipAdress);

	//set methods
	virtual void SetAdressSegment(uint8_t value, int index) override;
	virtual void SetAdress(uint32_t value) override;
	virtual void SetAdress(std::array<uint8_t, IPv4::adressSize> value) override;

	//get methods
	uint32_t GetAdressValue() override;
	std::array<uint8_t, IPv4::adressSize>& GetAdressAsArray() override;
	uint8_t& GetSegmentOfAdress(size_t index) override;

	//print metods
	virtual void PrintOnConsole() const override;
	virtual std::string ToString() const override;

	//operators
	IPv4& operator=(std::array<uint8_t, IPv4::adressSize> value);
	IPv4& operator=(uint32_t value);
	uint8_t& operator[](size_t index);
	friend std::ostream& operator<<(std::ostream& os, const IPv4& dt);
};