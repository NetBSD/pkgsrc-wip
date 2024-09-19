$NetBSD$

--- mono/io-layer/io.c.orig	2016-08-08 17:23:32.000000000 +0000
+++ mono/io-layer/io.c
@@ -3563,23 +3563,40 @@ gboolean CreatePipe (gpointer *readpipe,
 	return(TRUE);
 }
 
-#ifdef HAVE_GETFSSTAT
+#if defined(HAVE_GETFSSTAT) || defined(__NetBSD__)
 /* Darwin has getfsstat */
 gint32 GetLogicalDriveStrings (guint32 len, gunichar2 *buf)
 {
+#if defined(__NetBSD__)
+	struct statvfs *stats;
+#else
 	struct statfs *stats;
+#endif
 	int size, n, i;
 	gunichar2 *dir;
 	glong length, total = 0;
 	
+#if defined(__NetBSD__)
+	n = getvfsstat (NULL, 0, MNT_NOWAIT);
+#else
 	n = getfsstat (NULL, 0, MNT_NOWAIT);
+#endif
 	if (n == -1)
 		return 0;
+#if defined(__NetBSD__)
+	size = n * sizeof (struct statvfs);
+	stats = (struct statvfs *) g_malloc (size);
+#else
 	size = n * sizeof (struct statfs);
 	stats = (struct statfs *) g_malloc (size);
+#endif
 	if (stats == NULL)
 		return 0;
+#if defined(__NetBSD__)
+	if (getvfsstat (stats, size, MNT_NOWAIT) == -1){
+#else
 	if (getfsstat (stats, size, MNT_NOWAIT) == -1){
+#endif
 		g_free (stats);
 		return 0;
 	}
