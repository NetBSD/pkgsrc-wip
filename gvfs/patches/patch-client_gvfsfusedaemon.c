$NetBSD$

--- client/gvfsfusedaemon.c.orig	2017-03-28 14:05:33.000000000 +0000
+++ client/gvfsfusedaemon.c
@@ -2443,7 +2443,9 @@ vfs_init (struct fuse_conn_info *conn)
   subthread = g_thread_new ("gvfs-fuse-sub", (GThreadFunc) subthread_main, NULL);
 
   /* Indicate O_TRUNC support for open() */
+#ifdef FUSE_CAP_ATOMIC_O_TRUNC
   conn->want |= FUSE_CAP_ATOMIC_O_TRUNC;
+#endif
 
   /* Prevent out-of-order readahead */
   conn->async_read = 0;
