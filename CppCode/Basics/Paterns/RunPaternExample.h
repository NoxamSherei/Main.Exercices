#pragma once
#include "iostream"
#include "vector"
#include "Builder.h"
#include "DependencyInjection.h"
#include "State.h"

namespace Pattern {
	void doExample() {
		DepedencyInjection::PrimaryFlow();
		DepedencyInjection::SecondaryFlow();
		State::RunStateExample();
		Builder::Construct();
	}
}