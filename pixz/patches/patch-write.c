$NetBSD: patch-write.c,v 1.1 2015/06/20 19:27:52 ishit Exp $

fix "warning: 'archive_read_support_compression_none' is deprecated" from github.

--- write.c.orig	2013-01-09 04:25:03.000000000 +0000
+++ write.c
@@ -135,7 +135,7 @@ static void read_thread() {
     
     if (gTar) {
 		struct archive *ar = archive_read_new();
-	    archive_read_support_compression_none(ar);
+	    prevent_compression(ar);
 	    archive_read_support_format_tar(ar);
 	    archive_read_support_format_raw(ar);
 	    archive_read_open(ar, NULL, tar_ok, tar_read, tar_ok);
@@ -159,7 +159,7 @@ static void read_thread() {
 	    }
 		if (archive_read_header_position(ar) == 0)
 			gTar = false; // probably spuriously identified as tar
-    	archive_read_finish(ar);
+    	finish_reading(ar);
 	}
 	if (!feof(gInFile)) {
 		const void *dummy;
