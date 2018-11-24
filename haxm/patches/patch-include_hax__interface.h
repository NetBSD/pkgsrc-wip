$NetBSD$

--- include/hax_interface.h.orig	2018-11-21 06:34:18.000000000 +0000
+++ include/hax_interface.h
@@ -45,6 +45,9 @@
 #ifdef HAX_PLATFORM_LINUX
 #include "linux/hax_interface_linux.h"
 #endif
+#ifdef HAX_PLATFORM_NETBSD
+#include "netbsd/hax_interface_netbsd.h"
+#endif
 #ifdef HAX_PLATFORM_WINDOWS
 #include "windows/hax_interface_windows.h"
 #endif
