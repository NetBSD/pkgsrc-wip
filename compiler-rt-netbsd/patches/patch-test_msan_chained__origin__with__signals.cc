$NetBSD$

--- test/msan/chained_origin_with_signals.cc.orig	2018-08-21 21:25:23.000000000 +0000
+++ test/msan/chained_origin_with_signals.cc
@@ -10,6 +10,9 @@
 // RUN:     not %run %t >%t.out 2>&1
 // RUN: FileCheck %s < %t.out
 
+// Reported deadly signal due to stack-overflow
+// XFAIL: netbsd
+
 #include <signal.h>
 #include <stdio.h>
 #include <sys/types.h>
