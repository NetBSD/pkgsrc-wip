$NetBSD$

--- xlators/performance/write-behind/src/write-behind.c.orig	2020-01-09 18:05:13.730258054 +0000
+++ xlators/performance/write-behind/src/write-behind.c
@@ -2489,7 +2489,11 @@ wb_mark_readdirp_start(xlator_t *this, i
 
     wb_directory_inode = wb_inode_create(this, directory);
 
+#if defined(__NetBSD__)
+    if (!wb_directory_inode || !wb_directory_inode->lock.spinlock.pts_spin)
+#else
     if (!wb_directory_inode || !wb_directory_inode->lock.spinlock)
+#endif
         return;
 
     LOCK(&wb_directory_inode->lock);
@@ -2509,7 +2513,11 @@ wb_mark_readdirp_end(xlator_t *this, ino
 
     wb_directory_inode = wb_inode_ctx_get(this, directory);
 
+#if defined( __NetBSD__ )
+    if (!wb_directory_inode || !wb_directory_inode->lock.spinlock.pts_spin)
+#else
     if (!wb_directory_inode || !wb_directory_inode->lock.spinlock)
+#endif
         return;
 
     LOCK(&wb_directory_inode->lock);
