$NetBSD$

--- test/msan/fork.cc.orig	2018-10-26 19:41:04.814752153 +0000
+++ test/msan/fork.cc
@@ -17,6 +17,9 @@
 // Sometimes hangs
 // UNSUPPORTED: netbsd
 
+// Somtimes hangs
+// UNSUPPORTED: netbsd
+
 #include <pthread.h>
 #include <unistd.h>
 #include <stdio.h>
