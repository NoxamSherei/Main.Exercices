#pragma once
#include <cstdint>
#include "iostream"
#include "sstream"
#include "array"

class IIPv4 {
public:
	static const std::size_t adressSize = 4;
	virtual ~IIPv4() = default;
	virtual void PrintOnConsole() const = 0;
	virtual std::string ToString() const = 0;
	virtual void SetAdress(std::uint32_t value) = 0;
	virtual void SetAdressSegment(std::uint8_t value, int index) = 0;
	virtual void SetAdress(std::array<std::uint8_t, IIPv4::adressSize> value) = 0;
	virtual std::uint32_t GetAdressValue() = 0;
	virtual std::array<uint8_t, IIPv4::adressSize>& GetAdressAsArray() = 0;
	virtual std::uint8_t& GetSegmentOfAdress(size_t index) = 0;
};