$NetBSD$

Support NetBSD.

--- src/threads.h.orig	2026-10-28 21:51:11.000000000 +0000
+++ src/threads.h
@@ -231,6 +231,13 @@ enum {
     unsigned long _scgetthread_tid = (unsigned long)GetCurrentThreadId(); \
 	_scgetthread_tid; \
 })
+#elif __NetBSD__
+#define SCGetThreadIdLong(...) ({ \
+    pthread_t tpid; \
+    tpid = pthread_self(); \
+    unsigned long _scgetthread_tid = (unsigned long)tpid; \
+    _scgetthread_tid; \
+})
 #elif OS_WIN32
 #define SCGetThreadIdLong(...) ({ \
     unsigned long _scgetthread_tid = (unsigned long)GetCurrentThreadId(); \
@@ -279,6 +286,9 @@ extern thread_local char t_thread_name[THREAD_NAME_LEN
     })
 #elif defined __OpenBSD__ /* OpenBSD */
 /** \todo Add implementation for OpenBSD */
+#define SCSetThreadName(n) ({ strlcpy(t_thread_name, n, sizeof(t_thread_name)); })
+#elif defined __NetBSD__ /* NetBSD */
+/** \todo Add implementation for NetBSD */
 #define SCSetThreadName(n) ({ strlcpy(t_thread_name, n, sizeof(t_thread_name)); })
 #elif defined OS_WIN32 /* Windows */
 /** \todo Add implementation for Windows */
