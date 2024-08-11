#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface ITree :
		IPushable<TData>,
		ITopElement<TData>,
		IContain<TData>,
		IDeepCheckable<TData>,
		ICountable<TData>,
		IEmptyCheckable<TData>,
		IPrintable<TData> {};
}