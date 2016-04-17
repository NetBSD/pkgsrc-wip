$NetBSD$

--- mono/io-layer/io.c.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/io-layer/io.c
@@ -3422,7 +3422,7 @@ gboolean CreatePipe (gpointer *readpipe,
 	return(TRUE);
 }
 
-#ifdef HAVE_GETFSSTAT
+#ifdef HAVE_GETFSSTATx
 /* Darwin has getfsstat */
 gint32 GetLogicalDriveStrings (guint32 len, gunichar2 *buf)
 {
