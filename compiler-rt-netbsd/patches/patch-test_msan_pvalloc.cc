$NetBSD$

--- test/msan/pvalloc.cc.orig	2017-10-17 18:35:26.000000000 +0000
+++ test/msan/pvalloc.cc
@@ -4,7 +4,7 @@
 // RUN: MSAN_OPTIONS=allocator_may_return_null=0 not %run %t psm1 2>&1 | FileCheck %s
 // RUN: MSAN_OPTIONS=allocator_may_return_null=1     %run %t psm1 2>&1
 
-// UNSUPPORTED: win32, freebsd
+// UNSUPPORTED: win32, freebsd, netbsd
 
 // Checks that pvalloc overflows are caught. If the allocator is allowed to
 // return null, the errno should be set to ENOMEM.
