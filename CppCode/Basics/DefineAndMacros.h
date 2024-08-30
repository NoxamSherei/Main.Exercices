#pragma once
#include "iostream"
#include "string"

#define DefaultValue 42

#define SQRT(x) x*x

#define PROPFULL(valueType, valueName)\
valueType get_##valueName() {\
    return valueName;\
}\
void set_##valueName(valueType value) {\
    valueName=value;\
}\

#define ENUM(EnumName, valueName, ...)\
enum class EnumName{\
	__VA_ARGS__\
};\
private:\
EnumName valueName;\
public:\
PROPFULL(EnumName,valueName)\

namespace DefineAndMacro {

	class UniverseLifeAndEverything {
		std::string name;
		std::string desc;
		int age;
	public:
		ENUM(Testing, m_enum, value1, value2)

		const int ansfer = DefaultValue;
		const int sqrtTwo = SQRT(2);
		PROPFULL(std::string, name)
		PROPFULL(std::string, desc)
		PROPFULL(int, age)
	};
	void doExample() {
		UniverseLifeAndEverything a;
		a.set_age(10);
		a.set_desc("XYZ");
		a.set_name("ABC");
		a.set_m_enum(UniverseLifeAndEverything::Testing::value1);
		std::cout << a.get_name() << a.get_desc() << a.get_age() << (int)a.get_m_enum() << std::endl;
	}
}