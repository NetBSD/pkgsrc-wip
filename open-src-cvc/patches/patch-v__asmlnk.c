$NetBSD$

linux/sched.h inclusion logic restricted to Linux

--- v_asmlnk.c.orig	2023-07-16 21:42:51.000000000 +0000
+++ v_asmlnk.c
@@ -167,6 +167,9 @@ OF SUCH DAMAGE.
 /*
  * compiler asm gen routines - routines for post lowering asm gen here
  */
+#if defined(__linux)
+#define _GNU_SOURCE
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -186,7 +189,11 @@ OF SUCH DAMAGE.
 #include <sched.h>
 // SJM 05-30-13 - valut 4x does not support this include
 #ifndef __RHEL4X__
+#if defined(__linux)
 #include <linux/sched.h>
+#else
+#include <signal.h>
+#endif
 #endif
 
 /* AIV 03/28/12 - this is needed for some systems for clone call */
