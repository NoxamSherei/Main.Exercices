#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "CtorDtor.h"
#include "Multithreading.h"
#include "Rules.h"
#include "Template.h"

int main()
{
	Rules::DoExample();
	CtorDtor::DoExample();
	Multithreading a;
	a.DoExample();
	Templates::DoExample();
}