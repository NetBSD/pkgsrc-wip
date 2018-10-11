$NetBSD$

--- test/msan/fork.cc.orig	2018-08-21 21:25:23.000000000 +0000
+++ test/msan/fork.cc
@@ -14,6 +14,9 @@
 // UNSUPPORTED: powerpc64-target-arch
 // UNSUPPORTED: powerpc64le-target-arch
 
+// Somtimes hangs
+// UNSUPPORTED: netbsd
+
 #include <pthread.h>
 #include <unistd.h>
 #include <stdio.h>
