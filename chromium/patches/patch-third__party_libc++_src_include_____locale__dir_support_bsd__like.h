$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/include/__locale_dir/support/bsd_like.h.orig	2025-05-30 19:50:32.000000000 +0000
+++ third_party/libc++/src/include/__locale_dir/support/bsd_like.h
@@ -24,7 +24,11 @@
 #  include <wctype.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <locale.h>
+#else
 #include <xlocale.h>
+#endif
 
 #if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
 #  pragma GCC system_header
