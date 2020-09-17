$NetBSD$

Make this more generic.

--- libpcsxcore/ix86_64/ix86_cpudetect.c.orig	2019-03-06 11:37:17.000000000 +0000
+++ libpcsxcore/ix86_64/ix86_cpudetect.c
@@ -145,7 +145,7 @@ u64 GetCPUTick( void ) 
 #endif
 }
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
 
 #include <sys/time.h>
 #include <errno.h>
