$NetBSD$

--- test/msan/ftime.cc.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/msan/ftime.cc
@@ -1,6 +1,6 @@
 // RUN: %clangxx_msan -O0 -g %s -o %t && %run %t
 
-// ftime() is deprecated on FreeBSD.
+// ftime() is deprecated on FreeBSD/NetBSD.
 // XFAIL: freebsd
 
 #include <assert.h>
