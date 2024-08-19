#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface IHashTable :
		IInsertable<TData>,
		IContain<TData>,
		IDeepCheckable<TData>,
		ICountable<TData>,
		IEmptyCheckable<TData>,
		IPrintable<TData>,
		IHashable<TData>{};
}