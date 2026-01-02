$NetBSD$

Also use cast on pthread_self for NetBSD.

--- sources/shiboken6/libshiboken/helper.cpp.orig	2026-01-01 03:11:05.257821627 +0000
+++ sources/shiboken6/libshiboken/helper.cpp
@@ -600,7 +600,7 @@ ThreadId currentThreadId()
 {
 #if defined(_WIN32)
     return GetCurrentThreadId();
-#elif defined(__APPLE_CC__)
+#elif defined(__APPLE_CC__) || defined(__NetBSD__)
     return reinterpret_cast<ThreadId>(pthread_self());
 #else
     return pthread_self();
