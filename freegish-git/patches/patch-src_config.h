$NetBSD$

Use Linux code on *BSD as well.

--- src/config.h.orig	2020-02-08 14:45:35.000000000 +0000
+++ src/config.h
@@ -5,6 +5,10 @@
  #define LINUX 1
 #endif
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+ #define LINUX 1
+#endif
+
 #ifdef _WIN32
   #define WINDOWS 1
 #endif
