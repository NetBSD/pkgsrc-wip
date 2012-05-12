$NetBSD: patch-src_util.c,v 1.1.1.1 2012/05/12 13:29:06 pebog Exp $

--- src/util.c.orig	2012-01-24 12:19:08.000000000 +0000
+++ src/util.c
@@ -675,7 +675,10 @@ util_pidfile(char *path)
 
 	if (util_file_exists(path))
 	{
-		log_die(EX_SOFTWARE, "util_pidfile: %s exists", path);
+		if (unlink(path))
+		{
+			log_error("mopherd: unlink");
+		}
 	}
 
 	pid = getpid();
