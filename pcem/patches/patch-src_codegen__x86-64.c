$NetBSD$

Assume non-Windows is unixy.

--- src/codegen_x86-64.c.orig	2020-12-01 20:40:51.000000000 +0000
+++ src/codegen_x86-64.c
@@ -15,12 +15,11 @@
 #include "codegen_ops.h"
 #include "codegen_ops_x86-64.h"
 
-#if defined(__linux__) || defined(__APPLE__)
-#include <sys/mman.h>
-#include <unistd.h>
-#endif
 #if WIN64
 #include <windows.h>
+#else
+#include <sys/mman.h>
+#include <unistd.h>
 #endif
 
 int codegen_flat_ds, codegen_flat_ss;
@@ -63,7 +62,7 @@ void codegen_init()
 {
         int c;
 
-#if defined(__linux__) || defined(__APPLE__)
+#ifndef WIN64
 	void *start;
 	size_t len;
 	long pagesize = sysconf(_SC_PAGESIZE);
@@ -83,7 +82,7 @@ void codegen_init()
         for (c = 0; c < BLOCK_SIZE; c++)
                 codeblock[c].pc = BLOCK_PC_INVALID;
 
-#if defined(__linux__) || defined(__APPLE__)
+#ifndef WIN64
 	start = (void *)((long)codeblock & pagemask);
 	len = ((BLOCK_SIZE * sizeof(codeblock_t)) + pagesize) & pagemask;
 	if (mprotect(start, len, PROT_READ | PROT_WRITE | PROT_EXEC) != 0)
