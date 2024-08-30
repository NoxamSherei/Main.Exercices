#pragma once
#include "iostream"
#include "vector"


namespace Pattern {
	namespace Builder {
		class Cat {
			std::string m_name;
			std::string m_race;
			std::string m_state;
			int m_age;
		public:
			Cat(std::string name, std::string race, std::string state, int age) :
				m_name(name),
				m_race(race),
				m_state(state),
				m_age(age)
			{}
			void print() {
				std::cout << "Cat:[" << m_name << "," << m_race << "," << m_state << "," << m_age << "]"<<std::endl;
			}
		};

		class CatBuilder {
			std::string m_name = "";
			std::string m_race = "";
			std::string m_state = "";
			int m_age = 0;
		public:
			CatBuilder* SetName(std::string name) {
				m_name = name;
				return this;
			}
			CatBuilder* SetRace(std::string race) {
				m_race = race;
				return this;
			}
			CatBuilder* SetState(std::string state) {
				m_state = state;
				return this;
			}
			CatBuilder* setAge(int age) {
				m_age = age;
				return this;
			}
			Cat* Build() {
				return new Cat(m_name, m_race, m_state, m_age);
			}
		};

		void Construct() {
			CatBuilder builder;

			std::vector<Cat*> cats;
			cats.push_back(builder.
				SetName("Vayana")->
				SetRace("MaineCoon")->
				SetState("Sleep")->
				setAge(3)->Build());
			cats.push_back(builder.
				SetName("Varuna")->
				SetRace("MaineCoon")->
				SetState("Hungry")->
				setAge(3)->Build());
			cats.push_back(builder.
				SetName("Valergen")->
				SetRace("European")->
				SetState("Crazy")->
				setAge(1)->Build());
			for(auto& cat : cats)
			{
				cat->print();
			}
		}
	}
}