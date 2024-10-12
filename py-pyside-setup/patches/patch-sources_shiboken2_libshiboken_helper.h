$NetBSD$

Need a pointer for the thread private data on NetBSD.

--- sources/shiboken2/libshiboken/helper.h.orig	2024-10-11 23:19:44.504367762 +0000
+++ sources/shiboken2/libshiboken/helper.h
@@ -92,7 +92,11 @@ class AutoArrayPointer
         T *data;
 };
 
+#ifdef __NetBSD__
+using ThreadId = void *;
+#else
 using ThreadId = unsigned long long;
+#endif
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
