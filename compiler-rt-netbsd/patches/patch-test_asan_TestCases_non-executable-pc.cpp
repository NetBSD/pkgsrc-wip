$NetBSD$

--- test/asan/TestCases/non-executable-pc.cpp.orig	2017-06-03 23:53:56.000000000 +0000
+++ test/asan/TestCases/non-executable-pc.cpp
@@ -2,8 +2,8 @@
 // RUN: not %run %t 0 2>&1 | FileCheck %s
 // RUN: not %run %t n 2>&1 | FileCheck %s -check-prefix=CHECK -check-prefix=NON_EXEC
 
-// Only Linux and FreeBSD list every memory region in MemoryMappingLayout, for now.
-// REQUIRES: linux || freebsd
+// Only Linux, FreeBSD and NetBSD list every memory region in MemoryMappingLayout, for now.
+// REQUIRES: linux || freebsd || netbsd
 
 #include <assert.h>
 
