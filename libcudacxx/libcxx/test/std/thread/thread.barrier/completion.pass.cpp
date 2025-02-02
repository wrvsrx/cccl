//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <barrier>

#include <barrier>
#include <cassert>
#include <thread>

#include "test_macros.h"

int main(int, char**)
{
  int x = 0;
  auto comp = [&]() { x += 1; };
  std::barrier<decltype(comp)> b(2, comp);

  std::thread t([&](){
      for(int i = 0; i < 10; ++i)
        b.arrive_and_wait();
  });

  for(int i = 0; i < 10; ++i)
    b.arrive_and_wait();

  assert(x == 10);
  t.join();
  return 0;
}
