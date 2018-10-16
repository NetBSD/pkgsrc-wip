$NetBSD$

--- src/lib/evloop/procmon.c.orig	2018-09-20 20:13:23.000000000 +0000
+++ src/lib/evloop/procmon.c
@@ -21,6 +21,8 @@
 #include <errno.h>
 #endif
 
+#include <time.h>
+
 #ifdef _WIN32
 #include <winsock2.h>
 #include <windows.h>
