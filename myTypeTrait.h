#pragma once

template<typename T, T val>
class IntegralConstant {
public:
	constexpr static T value = val;
	using value_type = T;
	using type = IntegralConstant;
};

using TrueType = IntegralConstant<bool, true>;
using FalseType = IntegralConstant<bool, false>;


template<typename T>
void doSomething(T x, TrueType y)
{
	std::cout << typeid(y).name() << "\n";
}

template<typename T>
void doSomething(T x, FalseType y)
{
	std::cout << typeid(y).name() << "\n";
}

template<typename T>
class IsVoid : public FalseType {};

template<>
class IsVoid<void> : public TrueType {};

template<typename T>
class IsNullPointer : public FalseType {};

template<>
class IsNullPointer<std::nullptr_t> : public TrueType {};

template<typename T>
class IsIntegral : public FalseType {};

template<>
class IsIntegral<int> : public TrueType {};

template<typename T>
class IsFloatingPoint : public FalseType {};

template<>
class IsFloatingPoint<int> : public TrueType {};

template<typename T>
class IsPointer : public FalseType {};

template<typename T>
class IsPointer<T*> : public TrueType {};

template<typename T>
class IsConst : public FalseType {};

template<typename T>
class IsConst<const T> : public TrueType {};

template<typename T, typename U>
class IsSame : public FalseType {};

template<typename T>
class IsSame<T,T> : public TrueType {};






