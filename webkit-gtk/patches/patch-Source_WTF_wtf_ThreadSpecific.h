$NetBSD$

--- Source/WTF/wtf/ThreadSpecific.h.orig	2017-08-14 09:04:46.000000000 +0000
+++ Source/WTF/wtf/ThreadSpecific.h
@@ -52,6 +52,11 @@
 #if OS(HURD)
 // PTHREAD_KEYS_MAX is not defined in bionic nor in Hurd, so explicitly define it here.
 #define PTHREAD_KEYS_MAX 1024
+#elif OS(NETBSD)
+// PTHREAD_KEYS_MAX is not defined in 5.x
+#ifndef PTHREAD_KEYS_MAX
+#define PTHREAD_KEYS_MAX 256
+#endif
 #else
 #include <limits.h>
 #endif
