#pragma once
#include <string>

namespace DataStructures {
	__interface IPrintable {
public:
	virtual std::string Print() const = 0;
	};

	template<typename TData>
	__interface IInsertable {
public:
	virtual void Insert(TData input) = 0;
	};

	template<typename TData>
	__interface IInsertableBack {
public:
	virtual void InsertBack(TData input) = 0;
	};

	template<typename TData>
	__interface IInsertableFront {
public:
	virtual void InsertFront(TData input) = 0;
	};

	template<typename TData>
	__interface IPopable {
public:
	virtual const bool Pop() = 0;
	};

	template<typename TData>
	__interface IFrontPopable {
public:
	virtual const bool PopFront() = 0;
	};

	template<typename TData>
	__interface IBackPopable {
public:
	virtual const bool PopBack() = 0;
	};


	template<typename TData>
	__interface ITargetPopable {
public:
	virtual const bool Pop(TData input) = 0;
	};

	template<typename TData>
	__interface ITopElement {
public:
	virtual TData Top() const = 0;
	};
	
	template<typename TData>
	__interface IRootElement {
public:
	virtual TData Root() const = 0;
	};

	template<typename TData>
	__interface ITakeElement {
public:
	virtual TData Take(TData Take) const = 0;
	};

	template<typename TData>
	__interface IContain {
public:
	virtual const bool Contain(TData input) = 0;
	};

	__interface IDeepCheckable {
public:
	virtual const size_t Depth() const = 0;
	};

	__interface IEmptyCheckable {
public:
	virtual const size_t Count() const = 0;
	virtual const bool IsEmpty() const = 0;
	};

	template<typename TData>
	__interface IHashable {
public:
	virtual unsigned int GetHash(TData input) const = 0;
	};
}