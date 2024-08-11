#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface IHashTable :
		IPushable<TData>,
		IContain<TData>,
		IDeepCheckable<TData>,
		ICountable<TData>,
		IEmptyCheckable<TData>,
		IPrintable<TData>,
		IHashable<TData>{};
}