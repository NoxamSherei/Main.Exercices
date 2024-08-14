#pragma once
#include "IDSBasics.hpp"

namespace DataStructures {
	template<typename TData>
	__interface ITwoWayList :
		IPushable<TData>,
        IFrontPushable<TData>,
        IBackPushable<TData>,
        IFrontPopable<TData>,
        IBackPopable<TData>,
        ITargetPopable<TData>,
		ITopElement<TData>,
		IContain<TData>,
		ICountable<TData>,
		IEmptyCheckable<TData>,
		IPrintable<TData> {};
}