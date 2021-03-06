// { dg-options "-x c -shared-libgcc -lstdc++" }

// Copyright (C) 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <cassert>
#include <stdatomic.h>

// libstdc++/40826
// libstdc++/40654
int main()
{
  atomic_flag f = ATOMIC_FLAG_INIT;

  atomic_flag_clear(&f); // set to false
  assert( false == atomic_flag_test_and_set(&f) ); // return previous false, set to true
  assert( true == atomic_flag_test_and_set(&f) ); // return true

  return 0;
}
