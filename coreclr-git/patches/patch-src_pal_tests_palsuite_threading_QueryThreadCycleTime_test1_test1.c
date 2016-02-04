$NetBSD$

--- src/pal/tests/palsuite/threading/QueryThreadCycleTime/test1/test1.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/threading/QueryThreadCycleTime/test1/test1.c
@@ -13,9 +13,7 @@
 **
 **=========================================================*/
 
-#define _GNU_SOURCE
 #include <palsuite.h>
-#include <sched.h>
 
 int __cdecl main(int argc, char *argv[]) {
     int ret = FAIL;
@@ -98,6 +96,3 @@ int __cdecl main(int argc, char *argv[])
 EXIT:
     return ret;
 }
-
-
-
