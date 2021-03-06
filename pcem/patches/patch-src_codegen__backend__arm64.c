$NetBSD$

Assume non-Windows is unixy.

--- src/codegen_backend_arm64.c.orig	2020-12-01 20:40:51.000000000 +0000
+++ src/codegen_backend_arm64.c
@@ -11,12 +11,11 @@
 #include "x86.h"
 #include "x87.h"
 
-#if defined(__linux__) || defined(__APPLE__)
-#include <sys/mman.h>
-#include <unistd.h>
-#endif
 #if defined WIN32 || defined _WIN32 || defined _WIN32
 #include <windows.h>
+#else
+#include <sys/mman.h>
+#include <unistd.h>
 #endif
 
 void *codegen_mem_load_byte;
@@ -278,7 +277,7 @@ void codegen_backend_init()
 {
 	codeblock_t *block;
         int c;
-#if defined(__linux__) || defined(__APPLE__)
+#ifndef _WIN32
 	void *start;
 	size_t len;
 	long pagesize = sysconf(_SC_PAGESIZE);
