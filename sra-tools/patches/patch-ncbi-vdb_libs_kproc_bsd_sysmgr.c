$NetBSD$

# NetBSD: Add pthread_main_np() implementation

--- ncbi-vdb/libs/kproc/bsd/sysmgr.c.orig	2023-08-12 23:35:46.000000000 +0000
+++ ncbi-vdb/libs/kproc/bsd/sysmgr.c
@@ -30,6 +30,23 @@
 #include <pthread.h>
 #include <unistd.h>
 
+/*
+ * NetBSD lacks non-POSIX POSIX threads functions (pthread_np)
+ */
+
+#ifdef __NetBSD__
+
+// This should be initialized to pthread_self() at the start of main()
+// If the thread ID of this thread is the same, then this is the main thread
+extern pthread_t _thr_main;
+
+int	pthread_main_np(void)
+
+{
+    return pthread_equal(pthread_self(), _thr_main);
+}
+#endif
+
 /* OnMainThread
  *  returns true if running on main thread
  */
