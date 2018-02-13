$NetBSD$

Support NetBSD.

--- apps/openmw/crashcatcher.cpp.orig	2017-11-15 17:20:40.000000000 +0000
+++ apps/openmw/crashcatcher.cpp
@@ -24,7 +24,7 @@
 #ifndef PR_SET_PTRACER
 #define PR_SET_PTRACER 0x59616d61
 #endif
-#elif defined (__APPLE__) || defined (__FreeBSD__) || defined(__OpenBSD__)
+#elif defined (__APPLE__) || defined (__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 
