#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface ISimpleContainer :
		IPopable<TData>,
		IEmptyCheckable,
		IInsertable<TData>,
		ITopElement<TData>,
		IContain<TData>,
		IPrintable {
	};
}