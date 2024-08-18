#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface IOneWayList :
		IInsertable<TData>,
        IInsertableFront<TData>,
        IInsertableBack<TData>,
        IFrontPopable<TData>,
        IBackPopable<TData>,
        ITargetPopable<TData>,
		ITopElement<TData>,
		IContain<TData>,
		ICountable<TData>,
		IEmptyCheckable<TData>,
		IPrintable<TData> {};
}