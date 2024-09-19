$NetBSD: patch-libstdc++-v3_config_os_bsd_dragonfly_ctype__base.h,v 1.2 2013/01/31 20:07:17 marino Exp $

--- libstdc++-v3/config/os/bsd/dragonfly/ctype_base.h.orig	2012-06-22 10:35:30.000000000 +0000
+++ libstdc++-v3/config/os/bsd/dragonfly/ctype_base.h
@@ -0,0 +1,60 @@
+// Locale support -*- C++ -*-
+
+// Copyright (C) 2000, 2003, 2009, 2010 Free Software Foundation, Inc.
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
+//
+// ISO C++ 14882: 22.1  Locales
+//
+
+// Information as gleaned from /usr/include/ctype.h on DragonFly.
+// Full details can be found from git repo at:
+// http://gitweb.dragonflybsd.org/dragonfly.git/blob_plain/HEAD:/include/ctype.h
+
+namespace std _GLIBCXX_VISIBILITY(default)
+{
+_GLIBCXX_BEGIN_NAMESPACE_VERSION
+
+  /// @brief  Base class for ctype.
+  struct ctype_base
+  {
+    // Non-standard typedefs.
+    typedef const int*		__to_type;
+
+    // NB: Offsets into ctype<char>::_M_table force a particular size
+    // on the mask type. Because of this, we don't use an enum.
+    typedef uint16_t		mask;
+    static const mask upper	= _CTYPEMASK_U;
+    static const mask lower	= _CTYPEMASK_L;
+    static const mask alpha	= _CTYPEMASK_A;
+    static const mask digit	= _CTYPEMASK_D;
+    static const mask xdigit	= _CTYPEMASK_X;
+    static const mask space	= _CTYPEMASK_S;
+    static const mask print	= _CTYPEMASK_R;
+    static const mask graph	= _CTYPEMASK_G;
+    static const mask cntrl	= _CTYPEMASK_C;
+    static const mask punct	= _CTYPEMASK_P;
+    static const mask alnum	= _CTYPEMASK_A | _CTYPEMASK_D;
+  };
+
+_GLIBCXX_END_NAMESPACE_VERSION
+} // namespace
