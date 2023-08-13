$NetBSD$

# Stand-in for pthread_main_np()

--- ncbi-vdb/libs/kproc/bsd/sysmgr.c.orig	2023-08-13 20:43:27.391870168 +0000
+++ ncbi-vdb/libs/kproc/bsd/sysmgr.c
@@ -30,6 +30,19 @@
 #include <pthread.h>
 #include <unistd.h>
 
+/*
+ * NetBSD lacks non-POSIX POSIX threads functions (pthread_np)
+ */
+
+#ifdef __NetBSD__
+int	pthread_main_np(void)
+
+{
+    // FIXME: Return a real value
+    return 0;
+}
+#endif
+
 /* OnMainThread
  *  returns true if running on main thread
  */
