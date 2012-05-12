$NetBSD: patch-src_mopherd.c,v 1.1.1.1 2012/05/12 13:29:06 pebog Exp $

--- src/mopherd.c.orig	2012-01-24 12:19:08.000000000 +0000
+++ src/mopherd.c
@@ -71,6 +71,14 @@ main(int argc, char **argv)
 	log_init(BINNAME, loglevel, 1, foreground);
 
 	/*
+	 * Write PID file.
+	 */
+	if (pidfile)
+	{
+		util_pidfile(pidfile);
+	}
+
+	/*
 	 * Initialize milter
 	 */
 	milter_init();
@@ -86,30 +94,11 @@ main(int argc, char **argv)
 		return 0;
 	}
 
-	/*
-	 * Write PID file.
-	 */
-	if (pidfile)
-	{
-		util_pidfile(pidfile);
-	}
-
 	log_error("started");
 
 	r = milter();
 
 	/*
-	 * Remove PID file
-	 */
-	if (pidfile)
-	{
-		if (unlink(pidfile))
-		{
-			log_error("mopherd: unlink");
-		}
-	}
-
-	/*
 	 * Cleanup
 	 */
 	milter_clear();
