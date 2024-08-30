#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface ISimpleContainer :
		IRemoveable<TData>,
		IEmptyCheckable,
		IInsertable<TData>,
		ITopElement<TData>,
		IContain<TData>,
		IPrintable {
	};
}