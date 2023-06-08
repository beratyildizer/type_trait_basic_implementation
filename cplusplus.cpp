#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <typeinfo>
#include "myTypeTrait.h"



int main()
{
    doSomething(5, IsVoid<void>::type{});
    doSomething(5, IsVoid<void*>::type{});
    doSomething(5, IsNullPointer<nullptr_t>::type{});
    doSomething(5, IsNullPointer<nullptr_t*>::type{});
    doSomething(5, IsIntegral<int>::type{});
    doSomething(5, IsIntegral<int*>::type{});
    doSomething(5, IsFloatingPoint<float>::type{});
    doSomething(5, IsFloatingPoint<float*>::type{});
    doSomething(5, IsPointer<double*>::type{});
    doSomething(5, IsPointer<double>::type{});
    doSomething(5, IsConst<const double* const>::type{});
    doSomething(5, IsConst<const double*>::type{});
    doSomething(5, IsConst<const double>::type{});
    doSomething(5, IsSame<const int, const int>::type{});
    doSomething(5, IsSame<const double, double>::type{});

    
	
    return 0;
}

