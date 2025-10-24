$NetBSD$

--- src/base/string_conv.cpp.orig	2025-10-24 11:43:42.756193937 +0000
+++ src/base/string_conv.cpp
@@ -9,6 +9,9 @@
 #  include <Windows.h>
 #else
 #  include <iconv.h>
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #  include <langinfo.h>
 #  include <locale.h>
 #endif
