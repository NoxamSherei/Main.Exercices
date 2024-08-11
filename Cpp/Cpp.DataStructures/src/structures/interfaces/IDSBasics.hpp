#pragma once
#include "../Node.hpp"
#include <string>

namespace DataStructures {
	template<typename TData>
	__interface IPrintable {
public:
	virtual std::string Print() const = 0;
	};

	template<typename TData>
	__interface IPushable {
public:
	virtual void Push(TData input) = 0;
	};

	template<typename TData>
	__interface IBackPushable {
public:
	virtual void PushBack(TData input) = 0;
	};

	template<typename TData>
	__interface IFrontPushable {
public:
	virtual void PushFront(TData input) = 0;
	};

	template<typename TData>
	__interface IFrontPopable {
public:
	virtual bool PopFront() = 0;
	};

	template<typename TData>
	__interface IBackPopable {
public:
	virtual bool PopBack() = 0;
	};

	template<typename TData>
	__interface IPopable {
public:
	virtual bool Pop() = 0;
	};

	template<typename TData>
	__interface ITopElement {
public:
	virtual TData Top() const = 0;
	};

	template<typename TData>
	__interface ITakeElement {
public:
	virtual TData Take(TData Take) const = 0;
	};

	template<typename TData>
	__interface IExtractNode {
public:
	virtual Node<TData> Take(TData Take) const = 0;
	};

	template<typename TData>
	__interface IContain {
public:
	virtual bool Contain(TData input) = 0;
	};

	template<typename TData>
	__interface ICountable {
public:
	virtual size_t Count() const = 0;
	};

	template<typename TData>
	__interface IDeepCheckable {
public:
	virtual size_t Deep() const = 0;
	};

	template<typename TData>
	__interface IEmptyCheckable {
public:
	virtual bool IsEmpty() const = 0;
	};
}