$NetBSD$

--- mono/metadata/w32file-unix.c.orig	2017-08-02 13:16:42.000000000 +0000
+++ mono/metadata/w32file-unix.c
@@ -4055,7 +4055,7 @@ mono_w32file_create_pipe (gpointer *read
 	return(TRUE);
 }
 
-#ifdef HAVE_GETFSSTAT
+#if defined(HAVE_GETFSSTAT) && !defined(__NetBSD__)
 /* Darwin has getfsstat */
 gint32
 mono_w32file_get_logical_drive (guint32 len, gunichar2 *buf)
