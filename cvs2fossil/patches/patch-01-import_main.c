$NetBSD$

Fix usage to match supported options.

--- 01-import/main.c.orig	2011-04-18 23:32:07.000000000 +0000
+++ 01-import/main.c
@@ -772,7 +772,7 @@ parsedir(sqlite3 *db, const char *path, 
 static void
 usage(void)
 {
-	fprintf(stderr, "Usage: %s [-aqs] database directory", getprogname());
+	fprintf(stderr, "Usage: %s [-amqs] database directory", getprogname());
 	exit(1);
 }
 
