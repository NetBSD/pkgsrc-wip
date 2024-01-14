$NetBSD$

Avoid assuming linux on arm.  For now, assume neon.

Fix time types (sizes).

--- src/zm_utils.cpp.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_utils.cpp
@@ -26,7 +26,7 @@
 #include <stdarg.h>
 #include <fcntl.h> /* Definition of AT_* constants */
 #include <sys/stat.h>
-#if defined(__arm__)
+#if defined(__arm__) && defined(__linux__)
 #include <sys/auxv.h>
 #endif
 
@@ -305,6 +305,7 @@ void hwcaps_detect() {
     Debug(1,"Detected a x86\\x86-64 processor");
   } 
 #elif defined(__arm__)
+#  if defined(__linux__)
   // ARM processor in 32bit mode
   // To see if it supports NEON, we need to get that information from the kernel
   unsigned long auxval = getauxval(AT_HWCAP);
@@ -314,6 +315,10 @@ void hwcaps_detect() {
   } else {
     Debug(1,"Detected ARM (AArch32) processor");
   }
+#  else
+    Debug(1,"!!ASSUMING!! ARM (AArch32) processor with Neon");
+    neonversion = 1;
+#  endif
 #elif defined(__aarch64__)
   // ARM processor in 64bit mode
   // Neon is mandatory, no need to check for it
@@ -397,7 +402,7 @@ char *timeval_to_string( struct timeval 
   nowtime = tv.tv_sec;
   nowtm = localtime(&nowtime);
   strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d %H:%M:%S", nowtm);
-  snprintf(buf, sizeof buf, "%s.%06ld", tmbuf, tv.tv_usec);
+  snprintf(buf, sizeof buf, "%s.%06jd", tmbuf, (intmax_t) tv.tv_usec);
   return buf;
 }
 
