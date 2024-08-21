#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface ISimpleContainer :
		IPopable<TData>,
		IEmptyCheckable <TData>,
		IInsertable<TData>,
		ITopElement<TData>,
		IContain<TData>,
		ICountable<TData>,
		IPrintable<TData> {
	};
}