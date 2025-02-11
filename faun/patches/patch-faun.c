$NetBSD$

Add NetBSD support.

--- faun.c.orig	2025-01-04 16:35:20.000000000 +0000
+++ faun.c
@@ -42,7 +42,7 @@
 
 #ifdef ANDROID
 #include "sys_aaudio.c"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
 #include "sys_pulseaudio.c"
 #elif defined(_WIN32)
 #include "sys_wasapi.c"
