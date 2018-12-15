$NetBSD$

--- test/msan/pthread_getname_np.cc.orig	2018-08-21 21:25:23.000000000 +0000
+++ test/msan/pthread_getname_np.cc
@@ -1,7 +1,7 @@
 // RUN: %clangxx_msan -std=c++11 -O0 %s -o %t && %run %t
 // The main goal is getting the pthread name back and
 // FreeBSD based do not support this feature
-// UNSUPPORTED: android, netbsd, freebsd
+// UNSUPPORTED: android, freebsd
 
 // Regression test for a deadlock in pthread_getattr_np
 
