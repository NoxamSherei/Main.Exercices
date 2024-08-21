#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface IHashTable :
		IInsertable<TData>,
		IContain<TData>,
		IDeepCheckable,
		IEmptyCheckable,
		IPrintable,
		IHashable<TData>{};
}