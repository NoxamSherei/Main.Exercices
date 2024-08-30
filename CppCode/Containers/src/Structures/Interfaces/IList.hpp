#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface IList :
		IInsertable<TData>,
		IInsertableBack <TData>,
		IInsertableFront <TData>,
		IRemoveable<TData>,
		IFrontRemovable<TData>,
		IBackRemovable<TData>,
		IPrintable,
		IEmptyCheckable,
		IContain<TData> {
	};
}