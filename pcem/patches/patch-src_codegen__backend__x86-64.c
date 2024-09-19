$NetBSD$

Assume non-Windows is unixy.

--- src/codegen_backend_x86-64.c.orig	2020-12-01 20:40:51.000000000 +0000
+++ src/codegen_backend_x86-64.c
@@ -10,14 +10,13 @@
 #include "codegen_reg.h"
 #include "x86.h"
 
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
 
 void *codegen_mem_load_byte;
 void *codegen_mem_load_word;
