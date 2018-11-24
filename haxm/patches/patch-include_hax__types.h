$NetBSD$

--- include/hax_types.h.orig	2018-11-21 06:34:18.000000000 +0000
+++ include/hax_types.h
@@ -78,6 +78,10 @@
 #elif defined(__linux__)
 #define HAX_PLATFORM_LINUX
 #include "linux/hax_types_linux.h"
+// NetBSD
+#elif defined(__NetBSD__)
+#define HAX_PLATFORM_NETBSD
+#include "netbsd/hax_types_netbsd.h"
 // Windows
 #elif defined(_WIN32)
 #define HAX_PLATFORM_WINDOWS
