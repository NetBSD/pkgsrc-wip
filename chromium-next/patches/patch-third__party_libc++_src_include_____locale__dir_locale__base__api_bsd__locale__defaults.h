$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/include/__locale_dir/locale_base_api/bsd_locale_defaults.h.orig	2025-02-17 21:09:38.000000000 +0000
+++ third_party/libc++/src/include/__locale_dir/locale_base_api/bsd_locale_defaults.h
@@ -25,6 +25,8 @@
 // what headers have been included up to that point.
 #if defined(__APPLE__) || defined(__FreeBSD__)
 #  include <xlocale.h>
+#elif defined(__NetBSD__)
+#  include <locale.h>
 #endif
 
 #include <__config>
