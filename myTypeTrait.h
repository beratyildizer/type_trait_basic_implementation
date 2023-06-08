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
class isArray : public FalseType {};

template<typename T>
class isArray<T[]> : public TrueType {};

template<typename T>
auto constexpr isArray_v = isArray<T>::value;


template<typename T>
class IsVoid : public FalseType {};

template<>
class IsVoid<void> : public TrueType {};

template<typename T>
auto constexpr IsVoid_v = IsVoid<T>::value;


template<typename T>
class IsNullPointer : public FalseType {};

template<>
class IsNullPointer<std::nullptr_t> : public TrueType {};

template<typename T>
auto constexpr IsNullPointer_v = IsNullPointer<T>::value;


template<typename T>
class IsIntegral : public FalseType {};

template<>
class IsIntegral<int> : public TrueType {};

template<typename T>
auto constexpr IsIntegral_v = IsIntegral<T>::value;


template<typename T>
class IsFloatingPoint : public FalseType {};

template<>
class IsFloatingPoint<int> : public TrueType {};

template<typename T>
auto constexpr IsFloatingPoint_v = IsFloatingPoint<T>::value;


template<typename T>
class IsPointer : public FalseType {};

template<typename T>
class IsPointer<T*> : public TrueType {};

template<typename T>
auto constexpr IsPointer_v = IsPointer<T>::value;


template<typename T>
class IsConst : public FalseType {};

template<typename T>
class IsConst<const T> : public TrueType {};

template<typename T>
auto constexpr IsConst_v = IsConst<T>::value;


template<typename T, typename U>
class IsSame : public FalseType {};

template<typename T>
class IsSame<T,T> : public TrueType {};

template<typename T>
auto constexpr IsSame_v = IsSame<T>::value;








