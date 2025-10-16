$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/include/__locale_dir/locale_base_api.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/libc++/src/include/__locale_dir/locale_base_api.h
@@ -113,7 +113,7 @@
 
 #  if defined(__APPLE__)
 #    include <__locale_dir/support/apple.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__NetBSD__)
 #    include <__locale_dir/support/freebsd.h>
 #  elif defined(_LIBCPP_MSVCRT_LIKE)
 #    include <__locale_dir/support/windows.h>
