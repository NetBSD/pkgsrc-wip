$NetBSD$

--- src/threads.h.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/threads.h
@@ -231,6 +231,11 @@ enum {
     unsigned long _scgetthread_tid = (unsigned long)GetCurrentThreadId(); \
 	_scgetthread_tid; \
 })
+#elif __NetBSD__
+#define SCGetThreadIdLong(...) ({    \
+    pthread_t tpid = pthread_self();	\
+    tpid; \
+})
 #elif OS_WIN32
 #define SCGetThreadIdLong(...) ({ \
     unsigned long _scgetthread_tid = (unsigned long)GetCurrentThreadId(); \
@@ -280,6 +285,9 @@ extern thread_local char t_thread_name[T
 #elif defined __OpenBSD__ /* OpenBSD */
 /** \todo Add implementation for OpenBSD */
 #define SCSetThreadName(n) ({ strlcpy(t_thread_name, n, sizeof(t_thread_name)); })
+#elif defined __NetBSD__ /* NetBSD */
+/** \todo Add implementation for NetBSD */
+#define SCSetThreadName(n) ({ strlcpy(t_thread_name, n, sizeof(t_thread_name)); })
 #elif defined OS_WIN32 /* Windows */
 /** \todo Add implementation for Windows */
 #define SCSetThreadName(n) ({ strlcpy(t_thread_name, n, sizeof(t_thread_name)); })
