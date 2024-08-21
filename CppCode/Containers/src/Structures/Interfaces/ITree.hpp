#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface ITree :
		IInsertable<TData>,
		IRootElement<TData>,
		IContain<TData>,
		IDeepCheckable,
		IEmptyCheckable,
		IPrintable {};
}