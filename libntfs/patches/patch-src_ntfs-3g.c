$NetBSD$

NetBSD is missing some functions, so omit them.

--- src/ntfs-3g.c.orig	2016-09-11 13:30:43.881461740 +0000
+++ src/ntfs-3g.c	2016-09-11 13:32:35.574063705 +0000
@@ -3705,9 +3705,11 @@
 	fh = fuse_new(ctx->fc, &args , &ntfs_3g_ops, sizeof(ntfs_3g_ops), NULL);
 	if (!fh)
 		goto err;
-	
+
+#if !defined(__NetBSD__)	
 	if (fuse_set_signal_handlers(fuse_get_session(fh)))
 		goto err_destory;
+#endif
 out:
 	fuse_opt_free_args(&args);
 	return fh;
