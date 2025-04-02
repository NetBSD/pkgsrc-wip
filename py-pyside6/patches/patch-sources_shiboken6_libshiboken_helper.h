$NetBSD$

Use pthread_t type on NetBSD.

--- sources/shiboken6/libshiboken/helper.h.orig	2025-01-27 08:28:26.000000000 +0000
+++ sources/shiboken6/libshiboken/helper.h
@@ -61,7 +61,11 @@ class AutoArrayPointer
         T *data;
 };
 
+#ifdef __NetBSD__
+using ThreadId = pthread_t;
+#else
 using ThreadId = unsigned long long;
+#endif
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
