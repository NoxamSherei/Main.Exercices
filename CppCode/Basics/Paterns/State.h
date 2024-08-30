#pragma once
#include "iostream"
#include "vector"

namespace Pattern {
	namespace State {
		class IState
		{
		public:
			virtual void DoStateProcess() = 0;
		};
		class PrimaryState :public IState
		{
		public:
			virtual void DoStateProcess() {
				std::cout << "PrimaryState do jobs...";
			}
		};
		class SecondaryState :public IState
		{
		public:
			virtual void DoStateProcess() {
				std::cout << "SecondaryState do jobs...";
			}
		};

		class StateMachine {
		private:
			int m_stateId = 0;
			std::vector<IState*> m_states;
		public:
			StateMachine(std::vector<IState*> nom) :m_states(nom) {

			}
			void RunProcess() {
				std::cout << "StateRun";
				m_states[m_stateId]->DoStateProcess();
				m_stateId = m_stateId == 0 ? 1 : 0;
				std::cout << std::endl;
			}

		};

		void RunStateExample() {
			std::vector<IState*> states;
			states.push_back(new PrimaryState());
			states.push_back(new SecondaryState());
			StateMachine* stateMachine = new StateMachine(states);
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
			stateMachine->RunProcess();
		}
	}
}