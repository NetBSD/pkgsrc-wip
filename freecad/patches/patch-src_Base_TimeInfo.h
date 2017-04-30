$NetBSD$

--- src/Base/TimeInfo.h.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/Base/TimeInfo.h
@@ -29,6 +29,7 @@
 
 #include <stdio.h>
 #include <sys/timeb.h>
+#include <sys/time.h>
 #include <time.h>
 
 #ifdef __GNUC__
