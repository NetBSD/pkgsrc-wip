$NetBSD$

Assume non-Windows is unixy.

--- src/codegen_allocator.c.orig	2020-12-01 20:40:51.000000000 +0000
+++ src/codegen_allocator.c
@@ -1,11 +1,10 @@
-#if defined(__linux__) || defined(__APPLE__)
+#if defined WIN32 || defined _WIN32 || defined _WIN32
+#include <windows.h>
+#else
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdlib.h>
 #endif
-#if defined WIN32 || defined _WIN32 || defined _WIN32
-#include <windows.h>
-#endif
 
 #include "ibm.h"
 #include "codegen.h"
