#pragma once
#include "iostream"
#include "vector"


namespace Pattern {
	namespace DepedencyInjection {
		class IServiceExample {
		public:
			virtual int Run(int x) = 0;
		};
		class StandardServiceExample :public IServiceExample
		{
		public:
			virtual int Run(int x) {
				std::cout << "StandardFlow";
				return x + x;
			}
		};
		class TestingServiceExample :public IServiceExample
		{
		public:
			int m_x = 1;
			virtual int Run(int x) {
				std::cout << "TestingFlowExample";
				return m_x;
			}
		};

		class ExampleController {
		private:
			IServiceExample* service;
		public:
			ExampleController(IServiceExample* service) :service(service) {

			}
			~ExampleController() {
				delete service;
			}
			void RunProcess() {
				std::cout << "StartProcess";
				int x = service->Run(12);
				std::cout << "efect from service=" << x;
			}

		};

		void PrimaryFlow() {
			StandardServiceExample* interfaceToService = new StandardServiceExample();
			ExampleController* exampleControler = new ExampleController(interfaceToService);
			exampleControler->RunProcess();
		}
		void SecondaryFlow() {
			//for example mocking, or other flows
			TestingServiceExample* interfaceToService = new TestingServiceExample();
			interfaceToService->m_x = 42;
			ExampleController* exampleController = new ExampleController(interfaceToService);
			exampleController->RunProcess();
		}
	}
}