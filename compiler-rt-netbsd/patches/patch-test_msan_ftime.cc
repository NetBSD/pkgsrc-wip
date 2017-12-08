$NetBSD$

--- test/msan/ftime.cc.orig	2017-10-17 18:35:26.000000000 +0000
+++ test/msan/ftime.cc
@@ -1,7 +1,7 @@
 // RUN: %clangxx_msan -O0 -g %s -o %t && %run %t
 
-// ftime() is deprecated on FreeBSD.
-// XFAIL: freebsd
+// ftime() is deprecated on FreeBSD and NetBSD.
+// UNSUPPORTED: freebsd, netbsd
 
 #include <assert.h>
 #include <sys/timeb.h>
