$NetBSD: patch-libstdc++-v3_config_os_bsd_dragonfly_ctype__inline.h,v 1.1 2013/03/24 10:15:20 keckhardt Exp $

--- libstdc++-v3/config/os/bsd/dragonfly/ctype_inline.h.orig	2012-06-22 10:35:30.000000000 +0000
+++ libstdc++-v3/config/os/bsd/dragonfly/ctype_inline.h
@@ -0,0 +1,161 @@
+// Locale support -*- C++ -*-
+
+// Copyright (C) 2000, 2003, 2004, 2005, 2009, 2010
+// Free Software Foundation, Inc.
+//
+// This file is part of the GNU ISO C++ Library.  This library is free
+// software; you can redistribute it and/or modify it under the
+// terms of the GNU General Public License as published by the
+// Free Software Foundation; either version 3, or (at your option)
+// any later version.
+
+// This library is distributed in the hope that it will be useful,
+// but WITHOUT ANY WARRANTY; without even the implied warranty of
+// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+// GNU General Public License for more details.
+
+// Under Section 7 of GPL version 3, you are granted additional
+// permissions described in the GCC Runtime Library Exception, version
+// 3.1, as published by the Free Software Foundation.
+
+// You should have received a copy of the GNU General Public License and
+// a copy of the GCC Runtime Library Exception along with this program;
+// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
+// <http://www.gnu.org/licenses/>.
+
+/** @file bits/ctype_inline.h
+ *  This is an internal header file, included by other library headers.
+ *  Do not attempt to use it directly. @headername{locale}
+ */
+
+//
+// ISO C++ 14882: 22.1  Locales
+//
+
+// ctype bits to be inlined go here. Non-inlinable (ie virtual do_*)
+// functions go in ctype.cc
+
+namespace std _GLIBCXX_VISIBILITY(default)
+{
+_GLIBCXX_BEGIN_NAMESPACE_VERSION
+
+  bool
+  ctype<char>::
+  is(mask __m, char __c) const
+  {
+    if (_M_table)
+      return _M_table[static_cast<unsigned char>(__c)] & __m;
+    else
+      return __libc_ctype_ [__c + 1] & __m;
+  }
+
+  const char*
+  ctype<char>::
+  is(const char* __low, const char* __high, mask* __vec) const
+  {
+    if (_M_table)
+      while (__low < __high)
+	*__vec++ = _M_table[static_cast<unsigned char>(*__low++)];
+    else
+      for (;__low < __high; ++__vec, ++__low)
+	{
+	  mask __m = 0;
+	  if (this->is(upper, *__low))  __m |= upper;
+	  if (this->is(lower, *__low))  __m |= lower;
+	  if (this->is(alpha, *__low))  __m |= alpha;
+	  if (this->is(digit, *__low))  __m |= digit;
+	  if (this->is(xdigit, *__low)) __m |= xdigit;
+	  if (this->is(space, *__low))  __m |= space;
+	  if (this->is(print, *__low))  __m |= print;
+	  if (this->is(graph, *__low))  __m |= graph;
+	  if (this->is(cntrl, *__low))  __m |= cntrl;
+	  if (this->is(punct, *__low))  __m |= punct;
+	  // Do not include explicit line for alnum mask since it is a
+	  // pure composite of masks on DragonFly.
+	  *__vec = __m;
+	}
+    return __high;
+  }
+
+  const char*
+  ctype<char>::
+  scan_is(mask __m, const char* __low, const char* __high) const
+  {
+    if (_M_table)
+      while (__low < __high
+	     && !(_M_table[static_cast<unsigned char>(*__low)] & __m))
+	++__low;
+    else
+      while (__low < __high && !this->is(__m, *__low))
+	++__low;
+    return __low;
+  }
+
+  const char*
+  ctype<char>::
+  scan_not(mask __m, const char* __low, const char* __high) const
+  {
+    if (_M_table)
+      while (__low < __high
+	     && (_M_table[static_cast<unsigned char>(*__low)] & __m) != 0)
+	++__low;
+    else
+      while (__low < __high && this->is(__m, *__low) != 0)
+	++__low;
+    return __low;
+  }
+
+#ifdef _GLIBCXX_USE_WCHAR_T
+  inline bool
+  ctype<wchar_t>::
+  do_is(mask __m, wchar_t __c) const
+  {
+    return __libc_ctype_ [__c + 1] & __m;
+  }
+
+  inline const wchar_t*
+  ctype<wchar_t>::
+  do_is(const wchar_t* __lo, const wchar_t* __hi, mask* __vec) const
+  {
+    for (; __lo < __hi; ++__vec, ++__lo)
+    {
+      mask __m = 0;
+      if (isupper (*__lo)) __m |= _CTYPEMASK_U;
+      if (islower (*__lo)) __m |= _CTYPEMASK_L;
+      if (isdigit (*__lo)) __m |= _CTYPEMASK_D;
+      if (isspace (*__lo)) __m |= _CTYPEMASK_S;
+      if (ispunct (*__lo)) __m |= _CTYPEMASK_P;
+      if (isblank (*__lo)) __m |= _CTYPEMASK_B;
+      if (iscntrl (*__lo)) __m |= _CTYPEMASK_C;
+      if (isalpha (*__lo)) __m |= _CTYPEMASK_A;
+      if (isgraph (*__lo)) __m |= _CTYPEMASK_G;
+      if (isprint (*__lo)) __m |= _CTYPEMASK_R;
+      if (isxdigit(*__lo)) __m |= _CTYPEMASK_X;
+      /* alnum already covered = alpha | digit */
+
+      *__vec = __m;
+    }
+    return __hi;
+  }
+
+  inline const wchar_t*
+  ctype<wchar_t>::
+  do_scan_is(mask __m, const wchar_t* __lo, const wchar_t* __hi) const
+  {
+    while (__lo < __hi && !(__libc_ctype_ [*__lo + 1] & __m))
+      ++__lo;
+    return __lo;
+  }
+
+  inline const wchar_t*
+  ctype<wchar_t>::
+  do_scan_not(mask __m, const char_type* __lo, const char_type* __hi) const
+  {
+    while (__lo < __hi && (__libc_ctype_ [*__lo + 1] & __m))
+      ++__lo;
+    return __lo;
+  }
+#endif
+
+_GLIBCXX_END_NAMESPACE_VERSION
+} // namespace
