//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// type_traits

// is_reference

#include <type_traits>
#include <cstddef>         // for std::nullptr_t
#include "test_macros.h"

template <class T>
void test_is_reference()
{
    static_assert( std::is_reference<T>::value, "");
    static_assert( std::is_reference<const T>::value, "");
    static_assert( std::is_reference<volatile T>::value, "");
    static_assert( std::is_reference<const volatile T>::value, "");
#if TEST_STD_VER > 2014
    static_assert( std::is_reference_v<T>, "");
    static_assert( std::is_reference_v<const T>, "");
    static_assert( std::is_reference_v<volatile T>, "");
    static_assert( std::is_reference_v<const volatile T>, "");
#endif
}

template <class T>
void test_is_not_reference()
{
    static_assert(!std::is_reference<T>::value, "");
    static_assert(!std::is_reference<const T>::value, "");
    static_assert(!std::is_reference<volatile T>::value, "");
    static_assert(!std::is_reference<const volatile T>::value, "");
#if TEST_STD_VER > 2014
    static_assert(!std::is_reference_v<T>, "");
    static_assert(!std::is_reference_v<const T>, "");
    static_assert(!std::is_reference_v<volatile T>, "");
    static_assert(!std::is_reference_v<const volatile T>, "");
#endif
}

class incomplete_type;

class Empty
{
};

class NotEmpty
{
    virtual ~NotEmpty();
};

union Union {};

struct bit_zero
{
    int :  0;
};

class Abstract
{
    virtual ~Abstract() = 0;
};

enum Enum {zero, one};

typedef void (*FunctionPtr)();


int main(int, char**)
{
    test_is_reference<int&>();
    test_is_reference<int&&>();
    test_is_not_reference<std::nullptr_t>();
    test_is_not_reference<void>();
    test_is_not_reference<int>();
    test_is_not_reference<double>();
    test_is_not_reference<char[3]>();
    test_is_not_reference<char[]>();
    test_is_not_reference<void *>();
    test_is_not_reference<FunctionPtr>();
    test_is_not_reference<Union>();
    test_is_not_reference<incomplete_type>();
    test_is_not_reference<Empty>();
    test_is_not_reference<bit_zero>();
    test_is_not_reference<int*>();
    test_is_not_reference<const int*>();
    test_is_not_reference<Enum>();
    test_is_not_reference<NotEmpty>();
    test_is_not_reference<Abstract>();
    test_is_not_reference<int(int)>();
    test_is_not_reference<int Empty::*>();
    test_is_not_reference<void (Empty::*)(int)>();


  return 0;
}
